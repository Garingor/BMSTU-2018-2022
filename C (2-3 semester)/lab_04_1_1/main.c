#include <stdio.h>

#define N 10
#define SUCCESS 0
#define INV_INPUT -1

int input_arr(int *a, int *n)
{
    int fl1 = 0;

    if (scanf("%d", n) != 1)
        return INV_INPUT;

    if (*n <= 0 || *n > N)
        return INV_INPUT;

    for (int i = 0;i < *n; i++)
    {
        if (scanf("%d", &a[i]) != 1)
            return INV_INPUT;
        if (a[i] % 2 != 0)
            fl1 = 1;
    }

    if (fl1 == 0)
        return INV_INPUT;

    return *n;
}

int product_elem(int *a, int *n)
{
    int comp = 1;

    for (int i = 0; i < *n; i++)
        if (a[i] % 2 != 0)
            comp *= a[i];

    return comp;
}

void output_arr(int elem)
{
    printf("%d ", elem);
}

int main()
{
    int a[N], n;
    n = input_arr(a, &n);
    if (n == INV_INPUT)
        return INV_INPUT;
    else
        output_arr(product_elem(a, &n));
    return SUCCESS;
}
