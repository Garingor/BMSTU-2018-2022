"use strict";

// импорт библиотек
const express = require("express");
const request = require("request");
const fs = require("fs");

// запускаем сервер
const app = express();
const port = 5001;
app.listen(port);
console.log(`Server B on port ${port}`);

// заголовки в ответ клиенту
app.use(function(req, res, next) {
    res.header("Cache-Control", "no-cache, no-store, must-revalidate");
    res.header("Access-Control-Allow-Headers", "Origin, X-Requested-With, Content-Type, Accept");
    res.header("Access-Control-Allow-Origin", "*");
    next();
});

// функция для отправки POST запроса на другой сервер
async function sendPost(url, body, callback) {
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

app.post("/insert/record", function(request, response) 
{
    loadBody(request, function(body) {
        const obj = JSON.parse(body);
        const nameStorage = obj.nameStorage;
        const arrNamesCar = obj.arrNamesCar;
        const str = fs.readFileSync(__dirname + "/serverBData.txt", "utf-8");
        if (RegExp(`\\b${nameStorage} \\S+\n`).test(str))
        {
            response.end(JSON.stringify({result: false, error: "storage"}));
            return;
        }
        console.log("YES");
        (async () =>
        {
            let flag = true;
            console.log(flag);
            for (let i = 0; i < arrNamesCar.length && flag; i++)
            {
                console.log(i);
                await sendPost("http://localhost:5000/select/record", 
                                JSON.stringify({nameCar: arrNamesCar[i]}),
                                function(answerString) 
                {
                    const answerObject = JSON.parse(answerString);
                    flag = answerObject.result;
                    console.log(flag);
                });
            }
            console.log("YES " + flag);
            if (!flag)
            {
                response.end(JSON.stringify({result: false, error: "car"}));
                return;
            }

            fs.appendFileSync(__dirname + "/serverBData.txt", `${nameStorage} ${arrNamesCar.join(",")}\n`);
            response.end(JSON.stringify({result: true}));
        })();
    });
});

app.post("/select/record", function(request, response) 
{
    loadBody(request, function(body) {
        const obj = JSON.parse(body);
        const nameStorage = obj.nameStorage;
        const str = fs.readFileSync(__dirname + "/serverBData.txt", "utf-8");
        const storage = str.match(RegExp(`\\b${nameStorage} \\S+\n`));
        if (!storage)
        {
            response.end(JSON.stringify({result: false}));
            return;
        }
        
        const arrNamesCar = storage.split(" ")[1].split(",");
        const arrCostsCar = Array(arrNamesCar.length);
        for (let i = 0; i < arrNamesCar.length; i++)
        {
            sendPost("http://localhost:5000/select/record", 
                     JSON.stringify({nameCar: arrNamesCar[i]}),
                     function(answerString) {
                const answerObject = JSON.parse(answerString);
                arrCostsCar[i] = answerObject.costCar;
            });
        }

        response.end(JSON.stringify({result: true,
                                     arrNamesCar: arrNamesCar,
                                     arrCostsCar: arrCostsCar}));
    });
});