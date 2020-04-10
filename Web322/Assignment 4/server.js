/***********************************************************************************************
* WEB322 - Assignment 04.
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* Of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Huu Duc Mai     Student ID: 121367189   Date: March 06, 2019
*
* Online (Heroku) Link: https://safe-everglades-79072.herokuapp.com/
*
************************************************************************************************/

var express = require("express");
var app = express();
var path = require("path");
var myMod = require("./data-service.js")
var multer = require("multer");
const fs = require('fs');
const bodyParser = require('body-parser');
const exphbs = require('express-handlebars');
var HTTP_PORT = process.env.PORT || 8080;
app.use(bodyParser.urlencoded({ extended: true }));
app.use(express.static("public"));
//assignment 4: part 1 step 1:
app.use(function (req, res, next) {
    let route = req.baseUrl + req.path;
    app.locals.activeRoute = (route == "/") ? "/" : route.replace(/\/$/, "");
    next();
})
app.engine('.hbs', exphbs({
    extname: '.hbs',
    defaultLayout: "main",
    helpers: {
        navLink: function (url, options) {
            return '<li' +
                ((url == app.locals.activeRoute) ? ' class="active" ' : '') +
                '><a href="' + url + '">' + options.fn(this) + '</a></li>';
        }
    }
}));
app.set('view engine', '.hbs');
function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}
//update assignment 4, part 1 step 3
app.get("/", function (req, res) {
    res.render('home', {
        layout: 'main'
    })
})
//update assignment 4 part 1 step 3
app.get("/about", function (req, res) {
    res.render('about', {
        layout: 'main'
    })
})
//update part 4, assignment 3, step 1:
app.get("/people", function (req, res) {

    if (req.query.vin) {
        myMod.getPeopleByVin(req.query.vin).then(function (data) {
            res.render("people", { people: data });
        }).catch((err) => {
            res.render({ message: "no results" });
        })
    } else {
        myMod.getAllPeople().then(function (data) {
            res.render("people", { people: data });
        }).catch((err) => {
            res.render({ message: "no results" });
        })
    }
});
app.get("/cars", function (req, res) {
    if (req.query.vin) {
        myMod.getCarsByVin(req.query.vin).then(function (data) {
            res.render("cars",{cars:data});
        }).catch((err) => {
            res.render({ message: "no results" });
        })
    }
    else if (req.query.make) {
        myMod.getCarsByMake(req.query.make).then(function (data) {
            res.render("cars",{cars:data});
        }).catch((err) => {
            res.render({ message: "no results" });
        })
    }
    else if (req.query.year) {
        myMod.getCarsByYear(req.query.year).then(function (data) {
            res.render("cars",{cars:data});
        }).catch((err) => {
            res.render({ message: "no results" });
        })
    }
    else {
        myMod.getCars().then(function (data) {
            res.render("cars", {cars:data});
        }).catch((err) => {
            res.render({ message: "no results" });
        })
    };
});

app.get("/stores", function (req, res) {
    if (req.query.retailer) {
        myMod.getStoresByRetailer(req.query.retailer).then(function (data) {
            res.render("stores", {stores:data});
        }).catch((err) => {
            res.render({ message: "no results" });
        });
    }
    else {
        myMod.getStores().then(function (data) {
            res.render("stores", {stores:data});
        }).catch((err) => {
            res.render({ message: "no results" });
        });
    }
});
app.get("/people/add", function (req, res) {
    res.render('addPeople', {
        layout: 'main'
    })
});
app.get("/pictures/add", function (req, res) {
    res.render('addImage', {
        layout: 'main'
    })
})
const storage = multer.diskStorage({
    destination: "./public/pictures/uploaded",
    filename: function (req, file, cb) {
        cb(null, Date.now() + path.extname(file.originalname));
    }
});
const upload = multer({ storage: storage });

app.post('/pictures/add', upload.single("pictureFile"), (req, res) => {
    res.redirect('/pictures');
})

app.get('/pictures', function (req, res) {
    fs.readdir("./public/pictures/uploaded", (err, files) => {
        res.render('pictures', { arr: files });
    });
})

app.post('/people/add', (req, res) => {
    myMod.addPeople(req.body).then(() => {
        res.redirect('/people');
    });
})


app.get('/person/:id', (req, res) => {
    myMod.getPeopleById(req.params.id).then(function (data) {
        res.render("person", {person:data})
    }).catch((err) => {
        res.render("person", {message:"no results"});
    })
})


app.post("/person/update", (req,res) => {
    myMod.updatePerson(req.body).then( ()=> {
        res.redirect("/people");
    })
});



app.use((req, res) => {
    res.status(404).send("Page Not Found");
});



//setup http server to listen on http_port
myMod.initialize()
    .then(() => { app.listen(HTTP_PORT, onHttpStart); })
    .catch((data) => { console.log("Something is wrong, try contacting developer if this happens."); })