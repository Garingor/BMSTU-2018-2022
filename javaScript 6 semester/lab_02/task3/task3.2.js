"use strict"

const fs = require("fs");
const readlineSync = require('readline-sync');

const nameFile = readlineSync.question("Enter name of file: ");
const jsonStr = fs.readFileSync(nameFile, "utf-8");

let vowelStrArr = jsonStr.match(/\b[aeiouy]{1,}\b/gi) || [];

if (vowelStrArr.length)
{
    console.log("Strings of vowels:");
    for (let i = 0; i < vowelStrArr.length; i++)
        console.log(vowelStrArr[i]);
}
else
    console.log("There are no strings of vowels");