"use strict";

function findMaxNesting(obj, locPath, locDepth)
{
    if (locDepth > globalDepth)
    {
        globalDepth = locDepth;
        globalPath = [locPath];
        //console.log("YES");
    }
    else if (locDepth === globalDepth)
        globalPath.push(locPath);
        //console.log("NO");

    if (typeof(obj) === "object" && obj != null)
        for (let key in obj)
            findMaxNesting(obj[key], locPath + "/" + key, locDepth + 1);
}

const fs = require("fs");
const readlineSync = require('readline-sync');

const file = readlineSync.question("Input name of file: ");
const jsonString = fs.readFileSync(file, "utf8");
const obj = JSON.parse(jsonString);

let globalPath = [];
let globalDepth = 0;
findMaxNesting(obj, "obj", 1);

if (globalPath.length > 1)
    console.log(globalPath.length + " branches with the maximum nesting:");
else
    console.log("Branche with the maximum nesting:");
for (let i = 0; i < globalPath.length; i++)
    console.log(globalPath[i]);