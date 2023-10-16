// Дана точка и треугольник заданный координатами своих вершин.
// Определить лежит ли точка внутри, на границе или вне этого треугольника.

#include <stdio.h>
#include <math.h>

int triangle(float x1, float y1, float x2, float y2, float x3, float y3, float xa, float ya)
{
    float a, b, c;
    a = (x1 - xa) * (y2 - y1) - (x2 - x1) * (y1 - ya);
    b = (x2 - xa) * (y3 - y2) - (x3 - x2) * (y2 - ya);
    c = (x3 - xa) * (y1 - y3) - (x1 - x3) * (y3 - ya);
    if ((a > 0 && b > 0 && c > 0) || (a < 0 && b < 0 && c < 0))
        printf("0");
    else if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0))
        printf("1");
    else
        printf("2");
    return 0;
}

int main()
{
    float x1, y1, x2, y2, x3, y3, xa, ya;
    int rm;
    float a1, b1, c1;
    rm = scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &xa, &ya);
    if (rm != 8)
        return 1;
    a1 = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b1 = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c1 = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));
    if (a1 >= b1 + c1 || b1 >= a1 + c1 || c1 >= a1 + b1)
        return 1;
    triangle(x1, y1, x2, y2, x3, y3, xa, ya);
}
