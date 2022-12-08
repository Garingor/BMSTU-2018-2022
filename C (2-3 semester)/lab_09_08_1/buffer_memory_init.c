#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "const.h"

int mem_alloc_mas_buffer(int64_t ****mas, int n, int count)
{
    for (int i = 0; i < count; i++)
    {
        (*mas)[i] = (int64_t **)malloc(n * sizeof(int64_t *));

        if ((*mas)[i] == NULL)
            return INV_ADDRESS;

        for (int j = 0; j < n; j++)
        {
            (*mas)[i][j] = (int64_t *)malloc(n * sizeof(int64_t));

            if ((*mas)[i][j] == NULL)
                return INV_ADDRESS;
        }
    }
    return SUCCESS;
}

void free_mas_buffer(int64_t ****mas, int n, int count)
{
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < n; j++)
            free((*mas)[i][j]);
        free((*mas)[i]);
    }
    free(*mas);
}

void memset_buffer_mas(int64_t ***mas, int n, int count)
{
    for (int k = 0; k < count; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                mas[k][i][j] = 0;
}

int malloc_mas_buffer(int64_t ****mas, int count)
{
    *mas = malloc(count * sizeof(int64_t ***));

    if (*mas == NULL)
        return INV_ADDRESS;

    return SUCCESS;
}
