/*********************************************************************************
* WEB422 – Assignment 02
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part of this
* assignment has been copied manually or electronically from any other source (including web sites) or
* distributed to other students.
*
* Name: Huu Duc Mai - Student ID: 121367189 Date: June 12, 2020
*
********************************************************************************/ 




var page = 1;
const perPage = 10;
var saleData = [];


var saleTableTemplate = _.template(`
    <% _.forEach(saleData, function(obj) { %>
        <tr data-id=<%- obj._id %>>
            <td><%- obj.customer.email %></td>
            <td><%- obj.storeLocation %></td>
            <td><%- obj.items.length %></td>
            <td><%- moment.utc(obj.saleDate).local().format("LLLL") %></td>
        </tr>
    <% }); %>
`);

var saleModalBodyTemplate = _.template(`
    <h4>Customer</h4>
    <strong>email:</strong> <%- customer.email %><br>
    <strong>age:</strong> <%- customer.age %><br>
    <strong>satisfaction:</strong> <%- customer.satisfaction %>/5<br><br>
    <h4> Items: $<%- total.toFixed(2) %></h4>
    <table class="table">
        <thead>
            <tr>
                <th>Product Name</th>
                <th>Quantity</th>
                <th>Price</th>
            </tr>
        </thead>
        <tbody>
            <% _.forEach(items, function(item) { %>
                <tr>
                    <td><%- item.name %></td>
                    <td><%- item.quantity %></td>
                    <td>$<%- item.price %></td>
                </tr>
            <% }); %>
        </tbody>
    </table>
`);
function loadSaleData() {
    fetch(`https://aqueous-sierra-19775.herokuapp.com/api/sales?page=${page}&perPage=${perPage}`)
        .then(response => response.json())
        .then(json => {
            saleData = json;
            var result = saleTableTemplate({ sales: saleData });
            $("#sale-table tbody").html(result);
            $("#current-page").html(page);
        });
}



$(function () {
    loadSaleData();

    $("#sale-table tbody").on("click", "tr", function() {
        var clickedId = $(this).attr("data-id");
        var clickedSale = saleData.find(({ _id }) => _id == clickedId);

        clickedSale.total = 0;

        for (var i = 0; i < clickedSale.items.length; i++) {
            clickedSale.total += (clickedSale.items[i].price*clickedSale.items[i].quantity);
        }

        $("#sale-modal h4").html(`Sale: ${clickedSale._id}`);
        $("#modal-body").html(saleModalBodyTemplate(clickedSale));

        $('#sale-modal').modal({
            keyboard: false,
            backdrop: 'static'
        });
    });


    $("#previous-page").on("click", function() {
        if (page > 1) {
            page--;
        }
        loadSaleData();
    });
    $("#next-page").on("click", function() {
        page++;
        loadSaleData();
    });

});