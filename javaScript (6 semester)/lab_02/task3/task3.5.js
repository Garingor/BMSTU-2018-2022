"use strict";

const fs = require("fs");
const readlineSync = require('readline-sync');

const N = readlineSync.question("Input N: ");
let sumStr = "";
for (let i = 0; i < N; i++)
{
    let nameFile = readlineSync.question("Input name of file: ");
    if (fs.existsSync(nameFile))
        sumStr += fs.readFileSync(nameFile, "utf-8");    
    else
        console.log("File was not found");
}

fs.writeFileSync("sumstr.txt", sumStr);