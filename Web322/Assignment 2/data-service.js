var cars = [];
var people = [];
var stores = [];
fs = require('fs');

module.exports.initialize = () => {
    return new Promise((resolve, reject) => {
        fs.readFile("./data/people.json", 'utf8', (err, data) => {
            if (err) {
                reject({ message: "BadPeople" });
            }
            else {
                people = JSON.parse(data);
            }
            fs.readFile("./data/cars.json", 'utf8', (err, data2) => {
                if (err) {
                    reject({ message: "badCars" });
                }
                else {
                    cars = JSON.parse(data2);
                }
                fs.readFile("./data/stores.json", 'utf8', (err, data3) => {
                    if (err) {
                        reject({ mesage: "badStores" });
                    }
                    else {
                        stores = JSON.parse(data3);
                        resolve();
                    }
                });
            });
        });
    });
}


module.exports.getAllPeople = () => {
    return new Promise((resolve, reject) => {
        if (people.length == 0) {
            reject({ message: "Error, File People.json can't be found!" });
        }
        else {
            resolve(people);
        }
    });
}
module.exports.getCars = () => {
    return new Promise((resolve, reject) => {
        if (cars.length == 0) {
            reject({ message: "File Cars.json can't be found!" });
        }
        else {
            resolve(cars);
        }
    });
}

module.exports.getStores = () => {
    return new Promise((resolve, reject) => {
        if (stores.length == 0) {
            reject({ message: "File Stores.json can't be found!" });
        }
        else {
            resolve(stores);
        }
    })
}


/*  fs.readFile("./data/stores.json", 'utf8', (err3, data) => {
    if (err3) {
        reject({ message: "badstores" });
    }
    else {
        //resolve(JSON.parse(data3));
        stores = JSON.parse(data);
    }
}); */