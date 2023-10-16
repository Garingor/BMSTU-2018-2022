#include "util.h"
#include "input_output.h"
#include "memory_darr.h"
#include "const.h"

int input_size(int *n, int *m)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;
    if (*n < 1)
        return INV_INPUT;

    if (scanf("%d",m) != 1)
        return INV_INPUT;
    if(*m < 1)
        return INV_INPUT;

    return SUCCESS;
}

void output_darr(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d", arr[i][j]);
        printf("\n");
    }
}

int input_elem(int **arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (scanf("%d", arr[i][j]) != 1)
                return INV_INPUT;
        }
    }

    return SUCCESS;
}

void output_darr_new(int **matr, int n, int m)
{
    int k = 1;
    int h = 0;
    int count = m - n;
    if (count < 0)
        count = -count;
    count++;

    int flag_n = 0;
    for (int i = 0; i < n; i++)
    {
        while (h < k)
        {
            printf("%d ",matr[i][h]);
            h++;
        }

        if (k < n && flag_n == 0)
            k++;
        if (k == n && count > 0)
        {
            count--;
            flag_n = 1
        }
        else
            k--;

        h = 0;
        printf("\n");
    }
}

void output_darr_fix(int **arr, n, m, i_check)
{
    int k = 1;
    int h = 0;
    int count = m - n;
    if (count < 0)
        count = -count;
    count++;

    int flag_n = 0;
    for (int i = 0; i < n; i++)
    {
        if (i_check == i)
        {
            while (h < n)
            {
                printf("%d ",matr[i][h]);
                h++;
            }
        }
        else
        {
            while (h < k)
            {
                printf("%d ",matr[i][h]);
                h++;
            }

            if (k < n && flag_n == 0)
                k++;
            if (k == n && count > 0)
            {
                count--;
                flag_n = 1
            }
            else
                k--;
        }

        h = 0;
        printf("\n");

    }
}
