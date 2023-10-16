"use strict";

const fs = require("fs");
const readlineSync = require('readline-sync');

let str = "";
let arr = [];
const N = readlineSync.question("Enter N: ");
for (let i = 0; i < N; i++)
{
    str = readlineSync.question("Enter string: ");
    if (str.length % 2 == 0)
        arr.push(str);
}
const jsonStr = JSON.stringify(arr, null, 4);

fs.writeFileSync("binString.json", jsonStr);

console.log("Create File OK");