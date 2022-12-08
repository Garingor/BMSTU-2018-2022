//   Три сопротивления R1, R2, R3 соединены параллельно. Найти сопротивление соединения.

#include <stdio.h>

int main()
{
    float r1, r2, r3;
    float r;
    scanf("%f%f%f", &r1, &r2, &r3);
    r = (r1 * r2 * r3) / (r2 * r3 + r1 * r3 + r1 * r2);
    printf("%.5f", r);
    return 0;
}
