#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "const.h"

int input_matrix(int64_t ***matr, int *n, int *m)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;

    if (*n <= 0)
        return INV_INPUT;

    if (scanf("%d", m) != 1)
        return INV_INPUT;

    if (*m <= 0)
        return INV_INPUT;

    if (mem_alloc_matr(matr, *n, *m) != SUCCESS)
        return INV_ADDRESS;

    for (int i = 0; i < *n; i++)
        for (int j = 0; j < *m; j++)
            if (scanf("%" SCNd64, &(*matr)[i][j]) != 1)
            {
                free_matrix(matr, *n);
                return INV_INPUT;
            }


    return SUCCESS;
}

int input_alfa_beta(int *alfa, int *beta)
{
    if (scanf("%d", alfa) != 1)
        return INV_INPUT;

    if (*alfa < 0)
        return INV_INPUT;

    if (scanf("%d", beta) != 1)
        return INV_INPUT;

    if (*beta < 0)
        return INV_INPUT;

    return SUCCESS;
}

void print_matrix(int64_t **matr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%" PRId64 " ", matr[i][j]);
        printf("\n");
    }
}
