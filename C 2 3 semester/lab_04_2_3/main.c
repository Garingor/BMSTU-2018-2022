#include <stdio.h>

#define N 10
#define SUCCESS 0
#define INV_INPUT -1

int input_arr(int *a, int *n)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;

    if (*n <= 0 || *n > N)
        return INV_INPUT;

    for (int i = 0; i < *n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
            return INV_INPUT;
    }

    return *n;
}

int full_square(int *a, int i)
{
    int j = 0, j1 = 1;
    while (j < a[i])
    {
        j += j1;
        j1 += 2;
    }
    return j;
}

int delete_pos(int *a, int i, int *n)
{
    for (int k = i; k < *n - 1; k++)
        a[k] = a[k + 1];
    int m = *n - 1;
    *n = m;
    i--;
    return i;
}

int solution(int *a, int *n)
{
    int i = 0;
    int tek;
    while (i < *n)
    {
        tek = full_square(a, i);
        if (tek == a[i])
        {
            if (i == *n - 1)
            {
                int m = *n - 1;
                *n = m;
                i--;
            }
            else
                i = delete_pos(a, i, n);
        }
        i++;
    }
    if (*n == 0)
        return INV_INPUT;
    return *n;
}

void output_arr(int *a, int *n)
{
    for (int i = 0; i < *n;i++)
        printf("%d ", a[i]);
}

int main()
{
    int a[N], n;
    n = input_arr(a, &n);
    if (n == INV_INPUT)
        return INV_INPUT;
    else
    {
        n = solution(a, &n);
        if (n == INV_INPUT)
            return INV_INPUT;
        else
            output_arr(a, &n);
    }
    return SUCCESS;
}
