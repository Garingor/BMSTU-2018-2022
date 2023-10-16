"use strict";

const fs = require("fs");

const express = require("express");

const app = express();
const port = 5015;
app.listen(port);
console.log("My server on port " + port);

app.get("/me/page", function(request, response) {
    const nameString = __dirname + "/" + request.query.p;
    if (fs.existsSync(nameString)) {
        const contentString = fs.readFileSync(nameString, "utf8");
        response.end(contentString);
    } else {
        const contentString = fs.readFileSync(__dirname + "/bad.html", "utf8");
        response.end(contentString);
    }
});

app.get("/file/objectByIndex", function(request, response) {
    const i = request.query.i;
    const arr = JSON.parse(fs.readFileSync(__dirname + "/arr.json", "utf-8"));
    let answerJSON;
    try
    {
        answerJSON = JSON.stringify(arr[i], null, 4);
    }
    catch
    {
        answerJSON = "Error: out of range";
    }
    response.end(answerJSON);
});