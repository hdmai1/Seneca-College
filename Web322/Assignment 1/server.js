/*
    This is my work alone.
    Name: Huu Duc Mai.
    ID: 121367189.
    Heroku: https://hidden-cliffs-85307.herokuapp.com/
*/

// process.env checks the environment PORT is running on.
// 8080: local port.
var HTTP_PORT = process.env.PORT || 8080;
//require("express") similars to #include in OOP.
var express = require("express");
var app = express();

//set up a route to listen on the default url path
//if we go to the "/", the function will be executed
// (req,res)
app.get("/", (req, res) => {
    res.send("<h1>Huu Duc Mai 121367189</h1>");
});

//setup http server to listen on HTTP_PORT
app.listen(HTTP_PORT);