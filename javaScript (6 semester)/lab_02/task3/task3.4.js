"use strict";

function reqursiveSearchingFiles(curDir)
{
    let childDirs = fs.readdirSync(curDir, { withFileTypes: true })
                      .filter(d => d.isDirectory())
                      .map(d => curDir + d.name + "/");
    let files = fs.readdirSync(curDir, { withFileTypes: true })
                  .filter(d => d.isFile())
                  .map(d => curDir + d.name);

    childDirs.forEach((item, index, array) => reqursiveSearchingFiles(item));

    files.forEach((item, index, array) => 
    {
        let contentStr = fs.readFileSync(item, "utf8");
        if (contentStr.length < 11)
            console.log(item);
    });
}

const fs = require("fs");
const readlineSync = require('readline-sync');

const dir = readlineSync.question("Input name of folder: ");

console.log("Name of files with content shorter than 11 symbols:");
reqursiveSearchingFiles(dir);

