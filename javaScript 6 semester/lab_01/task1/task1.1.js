"use strict";

function CREATE(storage, surname, age)
{
    if (surname in storage)
        console.log("Ребёнок с такой фамилией уже есть в хранилище");
    else
        storage[surname] = age;
}

function READ(storage, surname)
{
    if (surname in storage)
        console.log("Имя: " + surname + ", возраст: " + storage[surname]);
    else
      console.log("Ребёнка с такой фамилией нет в хранилище");
}

function UPDATE(storage, surname, age)
{
    if (surname in storage)
        storage[surname] = age;    
    else
        console.log("Ребёнка с такой фамилией нет в хранилище");
}

function DELETE(storage, surname)
{
    if (surname in storage)
        delete storage[surname];    
    else
        console.log("Ребёнка с такой фамилией нет в хранилище");
}

function averageAge(storage)
{
    let n = 0;
    let sum = 0;
    for (let surname in storage)
    {
        sum += storage[surname];
        n++;
    }
    if (n)
        console.log("Средний возраст детей в хранилище: " + sum / n);
    else
        console.log("В хранилище нет детей");

    console.log();
}

function maxAge(storage)
{
    let maxAge = 0;
    let maxSurname = 0;
    for (let surname in storage)
    {
        if (storage[surname] > maxAge)
        {
            maxSurname = surname;
            maxAge = storage[surname];
        }
    }
    if (maxAge)
    {
        console.log("Ребёнок с максимальным возрастом в хранилище:");
        READ(storage, maxSurname);
    }
    else
        console.log("В хранилище нет детей");

    console.log();
}

function childrenWithAgeRange(storage, ageMin, ageMax)
{
    let flag = true;
    for (let surname in storage)
    {
        if (ageMin <= storage[surname] && storage[surname] <= ageMax)
        {
            if (flag)
            {
                console.log("Дети, чей возраст от " + ageMin + " до " + ageMax + ":");
                flag = false;
            }
            READ(storage, surname);
        }
    }

    if (flag)
        console.log("В хранилище нет детей, чей возраст от " + ageMin + " до " + ageMax);

    console.log();
}

function childrenWithSurnameFirstLetter(storage, letter)
{
    let flag = true;
    for (let surname in storage)
    {
        if (surname[0] === letter)
        {
            if (flag)
            {
                console.log("Дети, чья фамилия начинается на " + letter + ":");
                flag = false;
            }
            READ(storage, surname);
        }
    }

    if (flag)
        console.log("В хранилище нет детей, чья фамилия начинается на " + letter);

    console.log();
}

function childrenWithSurnameLongerLength(storage, length)
{
    let flag = true;
    for (let surname in storage)
    {
        if (surname.length > length)
        {
            if (flag)
            {
                console.log("Дети, чья фамилия длиннее " + length + " символов:");
                flag = false;
            }
            READ(storage, surname);
        }
    }

    if (flag)
        console.log("В хранилище нет детей, чья фамилия длиннее " + length + " символов");
        
    console.log();
}

function childrenWithSurnameFirstLetterVowel(storage)
{
    let flag = true;
    for (let surname in storage)
    {
        if ("eyuioaEYUIOA".indexOf(surname[0]) !== -1)
        {
            if (flag)
            {
                console.log("Дети, чья фамилия начинается с гласной буквы:");
                flag = false;
            }
            READ(storage, surname);
        }
    }

    if (flag)
        console.log("В хранилище нет детей, чья фамилия начинается с глсной буквы");
        
    console.log();
}

let storage = {};
CREATE(storage, "Irko", 10);
CREATE(storage, "Petrov", 14);
CREATE(storage, "Sokolov", 9);
CREATE(storage, "Yosupov", 11);
CREATE(storage, "Krok", 11)

READ(storage, "Petrov");
UPDATE(storage, "Yosupov", 18);
READ(storage, "Yosupov");
DELETE(storage, "Yosupov");
console.log(storage);
console.log();

averageAge(storage);
maxAge(storage);
childrenWithAgeRange(storage, 8, 12);
childrenWithSurnameFirstLetter(storage, "S");
childrenWithSurnameLongerLength(storage, 6);
childrenWithSurnameFirstLetterVowel(storage);