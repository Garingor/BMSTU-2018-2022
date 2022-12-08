
#include <stdio.h>

#define N 10
#define SUCCESS 0
#define INV_INPUT -1

int input_arr(int *a, int *n)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;
    if (*n <= 0 || *n > N)
        return -1;
    for (int i = 0;i < *n;i++)
    {
        if (scanf("%d", &a[i]) != 1)
            return INV_INPUT;
    }

    return *n;
}

void bubble_sort(int *a, int *n)
{
    int temp;

    for (int j = 0; j < *n - 1;j++)
        for (int i = 0; i < *n - 1 - j;i++)
            if (a[i] > a[i + 1])
            {
                temp = a[i];
                a[i] = a[i + 1];
                a[i + 1] = temp;
            }
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
        bubble_sort(a, &n);

    output_arr(a, &n);

    return SUCCESS;
}
