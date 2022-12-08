"use strict";

// импортируем необходимые библиотеки
const express = require("express");
const request = require("request");

// запускаем сервер
const app = express();
const port = 5002;
app.listen(port);
console.log(`Server on port ${port}`);

// отправка статических файлов
const way = __dirname + "/static";
app.use(express.static(way));

// заголовки в ответ клиенту
app.use(function(req, res, next) {
    res.header("Cache-Control", "no-cache, no-store, must-revalidate");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    res.header("Access-Control-Allow-Origin", "*");
    next();
});

// функция для отправки POST запроса на другой сервер
function sendPost(url, body, callback) {
    // задаём заголовки
    const headers = {};
    headers["Cache-Control"] = "no-cache, no-store, must-revalidate";
    headers["Connection"] = "close";
    // отправляем запрос
    request.post({
        url: url,
        body: body,
        headers: headers,
    }, function (error, response, body) {
        if(error) {
            callback(null);
        } else {
            callback(body);
        }
    });
}

app.get("/car/insert", function(request, response) {
    const nameCar = request.query.nameCar;
    const costCar = request.query.costCar;
    sendPost("http://localhost:5000/insert/record", 
             JSON.stringify({nameCar: nameCar, costCar: costCar}),
             function(answerString) {
        response.end(answerString);
    });
});

app.get("/car/select", function(request, response) {
    const nameCar = request.query.nameCar;
    sendPost("http://localhost:5000/select/record", 
             JSON.stringify({nameCar: nameCar}),
             function(answerString) {
        response.end(answerString);
    });
});

app.get("/storage/insert", function(request, response) {
    const nameStorage = request.query.nameStorage;
    const arrNamesCar = request.query.arrNamesCar.split(",");
    sendPost("http://localhost:5001/insert/record", 
             JSON.stringify({nameStorage: nameStorage, arrNamesCar: arrNamesCar}),
             function(answerString) {
        response.end(answerString);
    });
});

app.get("/storage/select", function(request, response) {
    const nameStorage = request.query.nameStorage;
    sendPost("http://localhost:5001/select/record", 
             JSON.stringify({nameStorage: nameStorage}),
             function(answerString) {
        response.end(answerString);
    });
});

