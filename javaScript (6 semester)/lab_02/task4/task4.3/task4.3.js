"use strict";

const fs = require("fs");
const readlineSync = require('readline-sync');
const { compileFunction } = require("vm");

let resStr = "<!DOCTYPE html>\n\
<html>\n\
<head>\n\
    <meta charset=\"UTF-8\">\n\
    <title>Автоматически собранная страница</title>\n\
</head>\n\
<body>\n";

const N = parseInt(readlineSync.question("Input number of requests: "));
for (let i = 0; i < N; i++)
{
    const address = readlineSync.question("Input address of request: ");
    resStr += "    <form method=\"GET\" action=\"" + address + "\">\n";

    const numAreas = parseInt(readlineSync.question("Input number of input fields of request: "));
    for (let j = 0; j < numAreas; j++)
    {
        const nameArea = readlineSync.question("Input name of input field of request: ");
        resStr += "        <p>" + nameArea + "</p>\n\
        <input name=\"" + i + "." + j + "\" spellcheck=\"false\" autocomplete=\"off\">";
    }

    resStr += "        <br>\n\
    <br>\n\
    <input type=\"submit\">\n\
</form>";
}

resStr += "</body>\n\
</html>\n";

fs.writeFileSync(__dirname + "/auto-compile.html", resStr);