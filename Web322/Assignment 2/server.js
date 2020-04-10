/***********************************************************************************************
* WEB322 - Assignment 02.
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* Of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Huu Duc Mai     Student ID: 121367189   Date: January 25th, 2020.
*
* Online (Heroku) Link: https://afternoon-waters-55434.herokuapp.com/
*
************************************************************************************************/
var express = require("express");
var app = express();
var path = require("path");
var myMod = require("./data-service.js")

var HTTP_PORT = process.env.PORT || 8080;

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}

app.get("/", function (req, res) {
    res.sendFile(path.join(__dirname, "./views/home.html"));
})

app.get("/about", function (req, res) {
    res.sendFile(path.join(__dirname, "./views/about.html"));
})

app.get("/people", function (req, res) {
    myMod.getAllPeople().then(function (data) {
        res.json(data);
    }).catch((err) => {
        res.json(err);
    })
});
app.get("/cars", function (req, res) {
    myMod.getCars().then(function (data) {
        res.json(data);
    }).catch((err) => {
        res.json(err);
    })
});

app.get("/stores", function (req, res) {
    myMod.getStores().then(function (data) {
        res.json(data);
    }).catch((err) => {
        res.json(err);
    })
})

app.use((req, res) => {
    res.status(404).send("Page Not Found");
});


//setup http server to listen on http_port
myMod.initialize()
.then(() => {app.listen(HTTP_PORT,onHttpStart);})
.catch((data)=>{console.log("Something is wrong, try contacting developer if this happens.");})