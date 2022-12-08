// Дано натуральное (целое неотрицательное) число a целое положительное число d.
// Вычислить частное q и остаток r при делении a на d, не используя операций / и %.

#include <stdio.h>

int decision(int a, int d)
{
    int q = 0, r;
    r = a;
    while (r >= d)
    {
        r -= d;
        q++;
    }
    printf("%d %d ", q, r);
    return 0;
}

int main()
{
    int a, d;
    int rm;
    rm = scanf("%d%d", &a, &d);
    if (rm != 2 || a <= 0 || d <= 0)
        return 1;
    decision(a, d);
}
