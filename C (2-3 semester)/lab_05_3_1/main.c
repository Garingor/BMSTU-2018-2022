#include "stdio.h"

#define N 10
#define OK 0
#define INV_INPUT -1

int input_arr(int (*a)[N], int *n, int *m)
{
    if (scanf("%d %d", n, m) != 2 || *n < 1 || *m < 1 || *m > N || *n > N)
        return INV_INPUT;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INV_INPUT;
    return OK;
}
void check_monotone_sequence(int (*a)[N], int i, int *correct, int *correct1, int m)
{
    for (int j = 0; j < m - 1; j++)
    {
        if (a[i][j] >= a[i][j + 1])
            (*correct)++;
        if (a[i][j] <= a[i][j + 1])
            (*correct1)++;
    }
}

int matr_sequence(int (*a)[N], int *b, int n, int m)
{
    int correct = 0, correct1 = 0, k = 0, uncrrt = 0;
    for (int i = 0; i < n; i++)
    {
        correct = 0;
        correct1 = 0;
        check_monotone_sequence(a, i, &correct, &correct1, m);
        if (correct == m - 1 || correct1 == m - 1)
        {
            b[k] = 1;
            uncrrt++;
        }
        else
            b[k] = 0;
        k++;
    }
    if (m == 1)
        for (int i = 0; i < k; i++)
            b[i] = 0;
    return k;
}

void output_arr(int *b, int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", b[i]);
}

int main()
{
    int a[N][N], b[N];
    int n, m, k;

    if (input_arr(a, &n, &m) == INV_INPUT)
        return INV_INPUT;
    else
    {
        k = matr_sequence(a, b, n, m);
        if (k == INV_INPUT)
            return INV_INPUT;
        else
            output_arr(b, k);
    }

    return OK;
}
