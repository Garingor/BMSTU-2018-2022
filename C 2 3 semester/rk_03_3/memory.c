#include "memory.h"
#include "const.h"
#include <stdlib.h>

int malloc_matr(int ***matr, int n)
{
    *matr = malloc(sizeof(int *)*n);

    if (*matr == NULL)
        return INV_MALLOC;

    for (int i = 0; i < n; i++)
    {
        (*matr)[i] = malloc(sizeof(int)*n);
        if ((*matr)[i] == NULL)
            return INV_MALLOC;
    }
    return SUCCESS;
}

int malloc_matr_n(int ***matr, int n)
{
    *matr = malloc(sizeof(int *)*(n + n - 1));

    if (*matr == NULL)
        return INV_MALLOC;

    for (int i = 0; i < n; i++)
    {
        (*matr)[i] = malloc(sizeof(int)*n);
        if ((*matr)[i] == NULL)
            return INV_MALLOC;
    }
    return SUCCESS;
}

void free_matr(int ***matr, int n)
{
    for (int i = 0; i <n; i++)
        free((*matr)[i]);
    free(*matr);
}
