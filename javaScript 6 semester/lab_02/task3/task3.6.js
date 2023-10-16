"use strict";

let objStart = {};
let depth = 1;
let obj = objStart;
try 
{
    while (true)
    {
        obj.a = {"1" : 0};
        obj = obj.a;
        const jsonStr = JSON.stringify(objStart);
        depth += 1;
    }
}
catch
{
    console.log(depth);
}