#include "const.h"
#include "in_out.h"
#include <stdio.h>
int input_size(int *n)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;
    if (*n <= 0)
        return INV_INPUT;

    return SUCCESS;
}

int input_matr(int **matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &matr[i][j]) != 1)
                return INV_INPUT;
    return SUCCESS;
}

void output_matr(int **matr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", matr[i][j]);
        printf("\n");
    }
}
