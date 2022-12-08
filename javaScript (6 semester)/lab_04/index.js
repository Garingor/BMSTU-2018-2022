"use strict";

// импорт библиотек
const express = require("express");
const request = require("request");
const fs = require("fs");

const obj = {name: "qqq",
arr: ["www", "eee", "rrr"]};
const str = JSON.stringify(obj);
const obj2 = JSON.parse(str);
console.log(obj);
console.log(str);
console.log(obj2);