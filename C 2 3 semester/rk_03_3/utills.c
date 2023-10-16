#include "utills.h"
#include "const.h"
#include <stdio.h>

void reverse_matr(int **matr, int **matr_n, int n)
{
    int m = 0;
    int n_1 = 0;

    while (n + n - 1 != n_1)
    {
        m = 0;
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                if (n_1 == i + j)
                {
                    matr_n[n_1][m] = matr[i][j];
                    m++;
                }
            }
        }
        n_1++;
    }

}

void alloc_matr(int **matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr[i][j] = 0;
}
