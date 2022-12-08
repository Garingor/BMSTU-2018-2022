"use strict";

function CREATE(storage, name, x, y)
{
    if (name in storage)
        console.log("Точка с таким именем уже есть в хранилище");
    else
        storage[name] = {"x": x, "y": y};
}

function READ(storage, name)
{
    if (name in storage)
        console.log("Имя точки: " + name + ", x: " + storage[name].x + ", y: " + storage[name].y);
    else
      console.log("Точки с таким именем нет в хранилище");
}

function UPDATE(storage, name, x, y)
{
    if (name in storage)
        storage[name] = {"x": x, "y": y}; 
    else
        console.log("Точки с таким именем нет в хранилище");
}

function DELETE(storage, name)
{
    if (name in storage)
        delete storage[name];    
    else
        console.log("Точки с таким именем нет в хранилище");
}

function PointsWithMaxDist(storage)
{
    let nameMaxFirst = null;
    let nameMaxSec = null;
    let maxDistSqr = -1;
    for (let nameFirst in storage)
        for (let nameSec in storage)
        {
            distSqr = Math.pow(storage[nameFirst].x - storage[nameSec].x, 2);
            if (distSqr > maxDistSqr)
            {
                nameMaxFirst = nameFirst;
                nameMaxSec = nameSec;
            }
        }
    
    if (nameMaxFirst)
    {
        console.log("Точки, между которыми наибольшее расстояние: ");
        READ(storage, nameMaxFirst);
        READ(storage, nameMaxSec);
    }
    else
        console.log("В хранилище нет точек");

    console.log();
}

function pointsByDistanceToPoint(storage, x, y, maxDist)
{
    let flag = true;
    let maxDistSqr = maxDist * maxDist;
    for (let name in storage)
    {
        let distSqr = Math.pow(storage[name].x - x, 2);
        if (distSqr < maxDistSqr)
        {
            if (flag)
            {
                console.log(`Точки, находящиеся от точки (${x}; ${y}) на расстоянии не больше ${maxDist}:`);
                flag = false;
            }
            READ(storage, name);
        }
    }

    if (flag)
        console.log(`В хранилище нет точек, находящичся от точки (${x}; ${y}) на расстоянии не больше ${maxDist}:`);

    console.log();
}

function pointsRelativeCoordinates(storage)
{
    console.log("Точки левее оси OY:");
    for (let name in storage)
        if (storage[name].y < 0)
            READ(storage, name);
    console.log("Точки правее оси OY:");
    for (let name in storage)
        if (storage[name].y > 0)
            READ(storage, name);
    console.log("Точки выше оси OX:");
    for (let name in storage)
        if (storage[name].x > 0)
            READ(storage, name);
    console.log("Точки ниже оси OX:");
    for (let name in storage)
        if (storage[name].x < 0)
            READ(storage, name);
    
    console.log();
}

function pointsInRect(storage, xMin, xMax, yMin, yMax)
{
    let flag = true;
    for (let name in storage)
    {
        if (xMin <= storage[name].x && storage[name].x <= xMax &&
            yMin <= storage[name].y && storage[name].y <= yMax)
        {
            if (flag)
            {
                console.log(`Точки, входящие в прямоугольник ((${xMin}; ${yMax}), (${xMax}); ${yMin}):`);
                flag = false;
            }
            READ(storage, name);
        }
    }

    if (flag)
        console.log(`В хранилище нет точки, входящих в прямоугольник ((${xMin}; ${yMax}), (${xMax}); ${yMin})`);

    console.log();
}
