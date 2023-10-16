"use strict";

// импортируем необходимые библиотеки
const express = require("express");
const fs = require("fs");

// запускаем сервер
const app = express();
const port = 5000;
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

// body
function loadBody(request, callback) {
    let body = [];
    request.on('data', (chunk) => {
        body.push(chunk);
    }).on('end', () => {
        body = Buffer.concat(body).toString();
        callback(body);
    });
}

app.post("/directory/append", function(request, response) {
    loadBody(request, function(body) {
        const obj = JSON.parse(body);
        const email = obj["email"];
        const surname = obj["surname"];
        const phoneNum = obj["phoneNum"];
        
        let res = "";
        const str = fs.readFileSync(__dirname + "/directory.txt", "utf-8");
        if (RegExp(`\\b${email} \\S+ \\S+\n`).test(str))
            res = "Content with this email is already saved";
        else if (RegExp(`\\b\\S+ \\S+ ${phoneNum}\n`).test(str))
            res = "Content with this phone number is already saved";
        else
        {
            fs.appendFileSync(__dirname + "/directory.txt", `${email} ${surname} ${phoneNum}\n`);
            res = "Save content ok";
        }
        response.end(JSON.stringify({
            result: res
        }));
    });
});

app.get("/directory/get", function(request, response) {
    const email = request.query.email;
    const str = fs.readFileSync(__dirname + "/directory.txt", "utf-8");
    const res = str.match(RegExp(`\\b${email} \\S+ \\d+\n`));
    if (res)
    {
        const data = res[0].split(" ");
        response.end(JSON.stringify({
            status: true,
            surname: data[1],
            phoneNum: data[2]
        }));
    }
    else
        response.end(JSON.stringify({
            status: false,
            surname: null,
            phoneNum: null
        }));
});