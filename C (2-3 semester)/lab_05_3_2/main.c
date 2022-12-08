#include "stdio.h"

#define N 10
#define OK 0
#define INV_INPUT -1

int input_arr(int (*a)[N], int *n, int *m)
{
    int check;
    if (scanf("%d %d", n, m) != 2 || *n < 1 || *m < 1 || (*m == 1 && *n == 1) || *m > 10 || *n > 10)
        return INV_INPUT;
    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%d", &a[i][j]) != 1)
                return INV_INPUT;
    if (scanf("%d", &check) != 1 || check < 0 || check >= 10)
        return INV_INPUT;
    return check;
}
int delete_column(int (*a)[N], int n, int m, int j)
{
    for (int k = 0; k < n; k++)
        for (int v = j; v < m; v++)
            a[k][v] = a[k][v + 1];
    m--;
    return m;
}

int remove_column_by_num(int (*a)[N], int n, int m, int check)
{
    int copy_num, fl1;
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        while (j < m)
        {
            fl1 = -1;
            copy_num = a[i][j];
            if (copy_num == check)
                fl1 = j;
            if (copy_num < 0)
                copy_num = -copy_num;
            if (check < 0)
                check = -check;
            while (copy_num > 0)
            {
                if (copy_num % 10 == check)
                    fl1 = j;
                copy_num /= 10;
            }
            if (fl1 != -1)
                m = delete_column(a, n, m, j);
            j++;
        }
    }
    if (m == 0)
        return INV_INPUT;
    return m;
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
    int a[N][N], check;
    int n, m;

    check = input_arr(a, &n, &m);
    if (check == -1)
        return INV_INPUT;
    else
    {
        m = remove_column_by_num(a, n, m, check);
        if (m == -1)
            return INV_INPUT;
        else
            output_arr(a, n, m);
    }

    return OK;
}
