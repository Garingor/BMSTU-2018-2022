#include <stdio.h>
#include <math.h>

int row_eps(float x, float eps)
{
    float s = 0, a = x, f, f1;
    int i = 3, n = 1;
    while (fabs(a) > eps)
    {
        s += a;
        a = (-1) * a * (i - 2) * x * x / i;
        i = i + 2;
        n++;
    }
    printf("%f\n", s);
    f = atan(x);
    printf("%f\n", f);
    f1 = fabs(f - s);
    printf("%f\n", f1);
    if (f == 0)
        printf("0.000000\n");
    else
    {
        f1 = fabs((f - s) / f);
        printf("%f\n", f1);
    }
    return 0;
}

int main()
{
    float x, eps;
    int rm;
    rm = scanf("%f%f", &x, &eps);
    if (rm != 2 || fabs(x) > 1 || eps <= 0 || x == eps || eps >= 1)
        return 1;
    row_eps(x, eps);
}
