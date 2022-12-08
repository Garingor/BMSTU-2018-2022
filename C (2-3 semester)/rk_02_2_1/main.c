#include <stdio.h>

#define N 100
#define INV_INPUT -1
#define OK 0

int input_matr(int a[N][N], int *n, int *m)
{
    if (scanf("%d%d", n, m) != 2)
        return INV_INPUT;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INV_INPUT;
    return OK;
}

void min_max_matr(int a[N][N], int *min_st, int *max_st, int n, int m)
{
    int min_a = a[0][0];
    int max_a = a[0][0];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] > max_a)
            {
                max_a = a[i][j];
                *max_st = j;
            }
            if (a[i][j] < min_a)
            {
                min_a = a[i][j];
                *min_st = j;
            }
        }
}
void change_st(int a[N][N], int min_st, int max_st, int n, int m)
{
    int temp;
    for (int i = 0; i < n; i++)
    {
        temp = a[i][min_st];
        a[i][min_st] = a[i][max_st];
        a[i][max_st] = temp;
    }
}

void output_matr(int a[N][N], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d", a[i][j]);
        printf("\n");
    }
}

int main()
{
    int a[N][N];
    int n, m;
    int check = 0;
    int min_st, max_st;

    check = input_matr(a, &n, &m);
    if (check == -1)
        return INV_INPUT;

    min_max_matr(a, &min_st, &max_st, n, m);
    change_st(a, min_st, max_st, n, m);

    output_matr(a, n, m);
    return OK;
}
