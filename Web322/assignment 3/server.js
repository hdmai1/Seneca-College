/***********************************************************************************************
* WEB322 - Assignment 03.
* I declare that this assignment is my own work in accordance with Seneca Academic Policy. No part
* Of this assignment has been copied manually or electronically from any other source
* (including 3rd party web sites) or distributed to other students.
*
* Name: Huu Duc Mai     Student ID: 121367189   Date: February 11, 2019
*
* Online (Heroku) Link: https://nameless-brushlands-49901.herokuapp.com/
*
************************************************************************************************/
var express = require("express");
var app = express();
var path = require("path");
var myMod = require("./data-service.js")
var multer = require("multer");
const fs = require('fs');
const bodyParser = require('body-parser')
var HTTP_PORT = process.env.PORT || 8080;
app.use(bodyParser.urlencoded({ extended: true }));

function onHttpStart() {
    console.log("Express http server listening on: " + HTTP_PORT);
}

app.get("/", function (req, res) {
    res.sendFile(path.join(__dirname, "./views/home.html"));
})

app.get("/about", function (req, res) {
    res.sendFile(path.join(__dirname, "./views/about.html"));
})
//update part 4, assignment 3, step 1:
app.get("/people", function (req, res) {

    if (req.query.vin) {
        myMod.getPeopleByVin(req.query.vin).then(function (data) {
            res.json(data);
        }).catch((err) => {
            res.json(err);
        })
    } else {
        myMod.getAllPeople().then(function (data) {
            res.json(data);
        }).catch((err) => {
            res.json(err);
        })
    }
});
//update part 4 B, assignment 3, step 1:
app.get("/cars", function (req, res) {
    if (req.query.vin) {
        myMod.getCarsByVin(req.query.vin).then(function (data) {
            res.json(data);
        }).catch((err) => {
            res.json(err);
        })
    }
    else if (req.query.make) {
        myMod.getCarsByMake(req.query.make).then(function (data) {
            res.json(data);
        }).catch((err) => {
            res.json(err);
        })
    }
    else if (req.query.year) {
        myMod.getCarsByYear(req.query.year).then(function (data) {
            res.json(data);
        }).catch((err) => {
            res.json(err);
        })
    }
    else {
        myMod.getCars().then(function (data) {
            res.json(data);
        }).catch((err) => {
            res.json(err);
        })
    };
});

app.get("/stores", function (req, res) {
    myMod.getStores().then(function (data) {
        res.json(data);
    }).catch((err) => {
        res.json(err);
    })
})

//assignment 3:
//part 1 step 2:
app.get("/people/add", function (req, res) {
    res.sendFile(path.join(__dirname, "./views/addPeople.html"));
});

app.get("/pictures/add", function (req, res) {
    res.sendFile(path.join(__dirname, "/views/addImage.html"));
})

//part 2 step 1
const storage = multer.diskStorage({
    destination: "./public/pictures/uploaded",
    filename: function (req, file, cb) {
        cb(null, Date.now() + path.extname(file.originalname));
    }
});
const upload = multer({ storage: storage });

//part 2 step 2
app.post('/pictures/add', upload.single("pictureFile"), (req, res) => {
    res.redirect('/pictures');
})

//part 2 step 3 
const getPics = '/pictures';
app.get('/pictures', function (req, res) {
    var arr = [];
    fs.readdir("./public/pictures/uploaded", (err, files) => {
        files.forEach(file => {
            arr.push(file);
        });
        res.json({ pictures: arr });
    });
})

//part 3 step 2
app.post('/people/add', (req, res) => {
    myMod.addPeople(req.body).then(() => {
        res.redirect('/people');
    });
})


//part 4 step 2:
app.get('/person/:value', (req, res) => {
    myMod.getPeopleById(req.params.value).then(function (data) {
        res.json(data);
    }).catch((err) => {
        res.json(err);
    })
})

//finish assignment 3.

app.use((req, res) => {
    res.status(404).send("Page Not Found");
});



//setup http server to listen on http_port
myMod.initialize()
    .then(() => { app.listen(HTTP_PORT, onHttpStart); })
    .catch((data) => { console.log("Something is wrong, try contacting developer if this happens."); })