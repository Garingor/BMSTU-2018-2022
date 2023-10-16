#include "stdio.h"

#define N 10
#define OK 0
#define INV_INPUT -1

int input_arr(int (*a)[N], int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2 || *n < 1 || *m < 1 || (*m == 1 && *n == 1) || *m > 10 || *n > 10)
        return INV_INPUT;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INV_INPUT;
    return OK;
}

int sort_str_matr(int (*a)[N], int n, int m)
{
    int comp = 1, comp1 = 1, temp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            comp = 1;
            comp1 = 1;
            for (int k = 0; k < m; k++)
                comp *= a[j][k];
            for (int k = 0; k < m; k++)
                comp1 *= a[j + 1][k];
            if (comp > comp1)
            {
                for (int k = 0; k < m; k++)
                {
                    temp = a[j][k];
                    a[j][k] = a[j + 1][k];
                    a[j + 1][k] = temp;
                }
            }
        }
    }
    return OK;
}

void output_arr(int (*a)[N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[N][N];
    int n, m;

    if (input_arr(a, &n, &m) == INV_INPUT)
        return INV_INPUT;
    else
    {
        sort_str_matr(a, n, m);
        output_arr(a, n, m);
    }

    return OK;
}
