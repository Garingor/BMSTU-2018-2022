/**
 *   Даны основания равнобедренной трапеции и угол при большем основании. Найти
 *   площадь трапеции.
 */

#include <stdio.h>
#include <math.h>

# define PI 3.14159

int main()
{
    float a, b, alpha;
    float s;
    float h, p;
    scanf("%f%f%f", &a, &b, &alpha);
    p = (b - a) / 2;
    alpha = alpha * PI / 180;
    h = p * tan(alpha);
    s = (a + b) * h / 2;
    s = fabs(s);
    printf("%.5f ", s);
    return 0;
}
