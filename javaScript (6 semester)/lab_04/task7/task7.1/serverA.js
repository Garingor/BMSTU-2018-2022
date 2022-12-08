"use strict";

// импорт библиотеки
const express = require("express");
const fs = require("fs");

// запускаем сервер
const app = express();
const port = 5000;
app.listen(port);
console.log("Server A on port " + port);

// заголовки для ответа
app.use(function(req, res, next) {
    res.header("Cache-Control", "no-cache, no-store, must-revalidate");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    res.header("Access-Control-Allow-Origin", "*");
    next();
});

// загрузка тела
function loadBody(request, callback) {
    let body = [];
    request.on('data', (chunk) => {
        body.push(chunk);
    }).on('end', () => {
        body = Buffer.concat(body).toString();
        callback(body);
    });
}

// приём запроса
app.post("/insert/record", function(request, response) 
{
    loadBody(request, function(body) {
        const obj = JSON.parse(body);
        const nameCar = obj.nameCar;
        const costCar = obj.costCar;
        const str = fs.readFileSync(__dirname + "/serverAData.txt", "utf-8");
        if (RegExp(`\\b${nameCar} \\S+\n`).test(str))
            response.end(JSON.stringify({result: false}));
        else
        {
            fs.appendFileSync(__dirname + "/serverAData.txt", `${nameCar} ${costCar}\n`);
            response.end(JSON.stringify({result: true}));
        }
    });
});

app.post("/select/record", function(request, response) 
{
    loadBody(request, function(body) {
        const obj = JSON.parse(body);
        const nameCar = obj.nameCar;
        const str = fs.readFileSync(__dirname + "/serverAData.txt", "utf-8");
        const car = str.match(RegExp(`\\b${nameCar} \\S+\n`));
        if (car)
            response.end(JSON.stringify({result: true, costCar: car[0].split(" ")[1]}));
        else
            response.end(JSON.stringify({result: false}));
    });
});