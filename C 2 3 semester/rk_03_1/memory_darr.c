#include "util.h"
#include "input_output.h"
#include "memory_darr.h"
#include "const.h"

int malloc_darr(int ***arr, int n, int m)
{
    *arr = malloc(sizeof(int *) * n);
    if (*arr == NULL)
        return INV_MALLOC;
    for (int i = 0; i < n; i++)
    {
        (*arr)[i] = malloc(sizeof(int) * m);
        if ((*arr)[i] == NULL)
            return INV_MALLOC;
    }
    return SUCCESS;
}

void free_darr(int ***arr, int n)
{
    for(int i = 0; i < n; i++)
        free((*arr)[i]);

    free(*arr);
}

int malloc_darr_new(int ***arr, int n, int m)
{
    int k = 1;
    int count = m - n;
    if (count < 0)
        count = -count;
    count++;

    int flag_n = 0;

    *arr = malloc(sizeof(int *) * n + m - 1);
    if (*arr == NULL)
        return INV_MALLOC;
    for (int i = 0; i < n + m - 1; i++)
    {
        (*arr)[i] = malloc(sizeof(int) * k);
        if ((*arr)[i] == NULL)
            return INV_MALLOC;

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
    return SUCCESS;
}
