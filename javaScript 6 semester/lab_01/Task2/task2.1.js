"use strict";

class Point {
    constructor(x, y) {
        this.x = x;
        this.y = y;
    }

    printPoint() {
        console.log(`Точка (${this.x}; ${this.y})`);
    }
}

class Line {
    constructor(x1, y1, x2, y2) {
        this.firstPoint = new Point(x1, y1);
        this.secondPoint = new Point(x2, y2);
    }

    printLine() {
        console.log("Отрезок: ");
        this.firstPoint.printPoint();
        this.secondPoint.printPoint();
    }

    length() {
        return Math.sqrt(Math.pow(this.secondPoint.x - this.firstPoint.x , 2) + Math.pow(this.secondPoint.y - this.firstPoint.y , 2));
    }
}

let line = new Line(0, 0, 5, 6);
line.printLine();
console.log(line.length());
