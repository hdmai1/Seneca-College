const Sequelize = require('sequelize');
var sequelize = new Sequelize('d8ohj0hn45rjou', 'kaxgtynmhmswiq', '83edb06cec7c199b2842a95dbf0e2d15159be34f288e442cfb1b67d30ab7dea1', {
    host: 'ec2-52-70-15-120.compute-1.amazonaws.com',
    dialect: 'postgres',
    port: 5432,
    dialectOptions: {
        ssl: true
    }
});
var People = sequelize.define('People', {
    first_name: Sequelize.STRING,
    last_name: Sequelize.STRING,
    phone: Sequelize.STRING,
    address: Sequelize.STRING,
    city: Sequelize.STRING,
});
var Car = sequelize.define('Car', {
    vin: {
        type: Sequelize.STRING,
        primaryKey: true,
        unique: true
    },
    make: Sequelize.STRING,
    model: Sequelize.STRING,
    year: Sequelize.STRING
});

var Store = sequelize.define('Store', {
    retailer: Sequelize.STRING,
    phone: Sequelize.STRING,
    address: Sequelize.STRING,
    city: Sequelize.STRING
});

Car.hasMany(People, { foreignKey: 'vin' });


function nullconvert(data) {
    var x;
    for (x in data){
        if(data[x] == "")
        data[x] = null;
    }
}
module.exports.initialize = () => {
    return new Promise(function (resolve, reject) {
        sequelize.sync().then(function () {
            console.log("CONNECTED DATABASE SUCCESSFULLY");
            resolve('Database connected successfully');
        }).catch(function () {
            reject("Unable to connect to the database");
        })
    })
}


module.exports.getAllPeople = () => {
    return new Promise(function (resolve, reject) {
        People.findAll().then(function (data) {
            resolve(data);
        }).catch(function () {
            reject("No People Returned");
        })
    });
}
module.exports.getCars = () => {
    return new Promise(function (resolve, reject) {
        Car.findAll().then(function (data) {
            resolve(data);
        }).catch(function () {
            reject("No Car founded");
        })
    });
}

module.exports.getStores = () => {
    return new Promise(function (resolve, reject) {
        Store.findAll().then(function(data){
            resolve(data);
        }).catch(function(err){
            reject();
        })
    });
}
module.exports.addPeople = (peopleData) => {
    nullconvert(peopleData);
    return new Promise(function (resolve, reject) {
        console.log(peopleData);
        People.create({
            first_name: peopleData.first_name,
            last_name: peopleData.last_name,
            phone: peopleData.phone,
            address: peopleData.address,
            city: peopleData.city,
            vin: peopleData.vin
        }).then(function (data) {
            resolve(data);
        }).catch(function (err) {
            reject(err);
        })
    })
}


module.exports.getPeopleByVin = (Vin) => {
    return new Promise(function (resolve, reject) {
        People.findAll({
            where: {
                vin: Vin
            }
        }).then(function (data) {
            resolve(data);
        }).catch(function(err) {
            reject(err);
        })
    });
}

module.exports.getCarsByVin = (Vin) => {
    return new Promise(function (resolve, reject) {
        Car.findAll({
            where: {
                vin: Vin
            }
        }).then(function (data) {
            resolve(data);
        }).catch(function(err) {
            reject(err);
        })
    });
}

module.exports.getCarsByMake = (newmake) => {
    return new Promise(function (resolve, reject) {
        Car.findAll({
            where: {
                make: newmake
            }
        }).then(function (data) {
            resolve(data);
        }).catch(function(err){
            reject();
        })
    });
}
module.exports.getCarsByYear = (newYear) => {
    return new Promise(function (resolve, reject) {
        Car.findAll({
            where: {
                year: newYear
            }
        }).then(function (data) {
            resolve(data);
        }).catch(function(err){
            reject(err);
        })
    });
}

module.exports.getPeopleById = (newID) => {
    return new Promise(function (resolve, reject) {
        People.findAll({
            where: {
                id: newID
            }
        }).then(function (data) {
            resolve(data);
        }).catch(function (err) {
            reject(err);
        })
    });
}


module.exports.getStoresByRetailer = (value) => {
    return new Promise(function (resolve, reject) {
        Store.findAll({
            where: {
                retailer: value
            }
        }).then(function (data) {
            resolve(data);
        }).catch(function (err) {
            reject(err);
        })
    });
};
module.exports.updatePerson = (personData) => {
    nullconvert(personData);
    return new Promise(function (resolve, reject) {
        People.update({
            first_name: personData.first_name,
            last_name: personData.last_name,
            phone: personData.phone,
            address: personData.address,
            city: personData.city,
            vin: personData.vin
        }, {
            where: { id: personData.id }
        }).then(function (data) {
            resolve(data);
        }).catch(function (err) {
            reject(err);
        })
    });
};

module.exports.addCars = (carData) => {
    nullconvert(carData);
    return new Promise(function (resolve, reject) {
        Car.create({
            vin: carData.vin,
            make: carData.make,
            model: carData.model,
            year: carData.year
        }).then(function () {
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}

module.exports.updateCar = (carData) => {
    nullconvert(carData);
    return new Promise(function (resolve, reject) {
        Car.update({
            make: carData.make,
            model: carData.model,
            year: carData.year
        }, {
            where: {
                vin: carData.vin
            }
        }).then(function () {
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}

module.exports.deleteCarByVin = (eVin) => {
    return new Promise(function (resolve, reject) {
        Car.destroy({
            where: { vin: eVin }
        }).then(function () {
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}

module.exports.addStore = (storeData) => {
    nullconvert(storeData);
    return new Promise((resolve, reject) => {
        Store.create({
            retailer: storeData.retailer,
            phone: storeData.phone,
            address: storeData.address,
            city: storeData.city
        }).then(function(){
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}

module.exports.updateStore = (storeData) =>{
    nullconvert(storeData);
    return new Promise((resolve, reject) => {
        Store.update({
            retailer: storeData.retailer,
            phone: storeData.phone,
            address: storeData.address,
            city: storeData.city
        }, {
            where: {id:storeData.id}
        }).then(function() {
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}

module.exports.getStoreById = (eId) =>{
    return new Promise((resolve, reject) => {
        Store.findAll({where: {
            id: eId
        }}).then(function(data) {
            resolve(data);
        }).catch(function(err){
            reject(err);
        })
    })
}

module.exports.deleteStoreById = (eId) =>{
    return new Promise((resolve, reject) => {
        Store.destroy({
            where: {
                id: eId
            }
        }).then(function(){
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}


module.exports.deletePeopleById = (eId) => {
    return new Promise((resolve,reject) => {
        People.destroy({
            where: {
                id: eId
            }
        }).then(function() {
            resolve();
        }).catch(function(err){
            reject(err);
        })
    })
}