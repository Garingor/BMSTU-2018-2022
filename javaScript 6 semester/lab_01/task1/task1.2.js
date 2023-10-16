"use strict";

function CREATE(storage, number, group, marks)
{
    if (number in storage)
        console.log("Студент с таким номером студенческого билета уже есть в хранилище");
    else
        storage[number] = {"group": group, "marks": marks};
}

function READ(storage, number)
{
    if (number in storage)
        console.log("Номер студенческого билета: " + number + 
                    ", группа: " + storage[number].group + 
                    ", оценки: " + storage[number].marks.join(","));
    else
      console.log("Студента с таким номером студенческого билета нет в хранилище");
}

function UPDATE(storage, number, group, marks)
{
    if (number in storage)
        storage[number] = {"group": group, "marks": marks};   
    else
        console.log("Студента с таким номером студенческого билета нет в хранилище");
}

function DELETE(storage, number)
{
    if (number in storage)
        delete storage[number];    
    else
        console.log("Студента с таким номером студенческого билета нет в хранилище");
}

function averageMark(storage, number)
{
    let marks = storage[number].marks;
    if (marks.length)
    {
        let sum = 0;
        for (let i = 0; i < marks.length; i++)
            sum += marks[i];
        console.log("Средняя оценка студента " + number + ": " + sum / marks.length);
    }
    else
        console.log("У студента " + number + " нет оценок");
    console.log();
}

function infoAllStudentsInGroup(storage, group)
{
    let flag = true;
    for (let number in storage)
    {
        if (storage[number].group === group)
        {
            if (flag)
            {
                console.log("Студенты группы " + group + ":");
                flag = false;
            }
            READ(storage, number);
        }
    }

    if (flag)
        console.log("В хранилище нет студентов из группы " + group);

    console.log();
}

function studentWithMaxCountMarksInGroup(storage, group)
{
    let maxNumber = null;
    for (let number in storage)
        if (storage[number].group === group && 
            storage[number].marks.length > storage[maxNumber].marks.length)
            maxNumber = number;

    if (maxNumber)
        console.log("В группе " + group + " максимальное количество оценок у студента " + maxNumber);
    else
        console.log("В хранилище нет студентов из группы " + group);

    console.log();
}

function studentWithoutMarks(storage)
{
    let flag = true;
    for (let number in storage)
    {
        if (storage[number].marks.length === 0)
        {
            if (flag)
            {
                console.log("Студенты без оценок:");
                flag = false;
            }
            READ(storage, number);
        }
    }

    if (flag)
        console.log("В хранилище нет студентов без оценок");

    console.log();
}

let storage = {};
/*
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
childrenWithSurnameFirstLetterVowel(storage);*/