#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "const.h"

void free_matrix(int64_t ***matr, int n)
{
    for (int i = 0; i < n; i++)
        free((*matr)[i]);
    free(*matr);
}

int mem_alloc_matr(int64_t ***matr, int n, int m)
{
    *matr = (int64_t **)malloc(n * sizeof(int64_t *));

    if (*matr == NULL)
        return INV_ADDRESS;

    for (int i = 0; i < n; i++)
    {
        (*matr)[i] = (int64_t *)malloc(m * sizeof(int64_t));

        if ((*matr)[i] == NULL)
        {
            free_matrix(matr, n);
            return INV_ADDRESS;
        }
    }

    return SUCCESS;
}
