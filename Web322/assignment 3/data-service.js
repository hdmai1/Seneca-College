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
//assignment 3 begins:

//part 3 step 3:
module.exports.addPeople = (peopleData) => {
    return new Promise((resolve, reject) => {
        peopleData.id = people.length + 1;
        people.push(peopleData);
        resolve();
    })
}

//part 5 step 1:

module.exports.getPeopleByVin = (Vin) => {
    var arr =[];
    return new Promise ((resolve, reject) => {
        people.forEach(person => {
            if (Vin == person.vin) {
                arr.push(person);
            }
        })
        if (arr.length == 0) {
            reject({ message: "Errors. No People results returned with the expected VIN" });
        }
        else {
            resolve(arr);
        }
    })
}

//part 5 step 2:
module.exports.getCarsByVin = (Vin) => {
    var arr = [];
    return new Promise((resolve, reject) => {
        cars.forEach(car => { 
            if (Vin == car.vin) {
                arr.push(car);
            }
        })
        if (arr.length==0){
            reject({message: "No Cars returned with the expected VIN"});
        }
        else {
            resolve(arr);
        }
    })
}

//part 5 step 3:
module.exports.getCarsByMake = (newmake) => {
    var arr = [];
    return new Promise((resolve,reject) => {
        cars.forEach(car => {
            if (newmake == car.make) {
                arr.push(car);
            }
        })
        if (arr.length == 0) {
            reject({message:"Errors. No Cars result returned with the expected Model"});
        }
        else {
            resolve(arr);
        }
    })
}
//part 5 step 4 :
module.exports.getCarsByYear = (newYear) => {
    var arr = [];
    return new Promise((resolve,reject) => {
        cars.forEach(car => {
            if (newYear == car.year) {
                arr.push(car);
            }
        })
        if (arr.length == 0) {
            reject({message:"Errors. No Cars result returned with the expected year"});
        }
        else {
            resolve(arr);
        }
    })
}

//part 5 step 5:
module.exports.getPeopleById = (newID) => {
    var arr =[];
    return new Promise ((resolve, reject) => {
        people.forEach(person => {
            if (newID == person.id) {
                arr.push(person);
            }
        })
        if (arr.length == 0) {
            reject({ message: "Errors. No People results returned with the expected ID" });
        }
        else {
            resolve(arr);
        }
    })
}