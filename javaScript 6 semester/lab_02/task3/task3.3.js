"use strict";

const fs = require("fs");
const readlineSync = require('readline-sync');

const extension = readlineSync.question("Input the extension of the required files: ");
const folder = readlineSync.question("Input name of folder: ");

const allFiles = fs.readdirSync(folder).join(" ");
const reg = new RegExp("\\b\\S+\\" + extension + "\\b", "g");
const requiredFiles = allFiles.match(reg) || [];

if (requiredFiles.length)
{
    console.log("Files with this extension:");
    for(let i = 0; i < requiredFiles.length; i++)
        console.log(requiredFiles[i]);
}
else
    console.log("There are no files with this extension");