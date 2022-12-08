#include "darray.h"
#include <stdio.h>
#include <stdlib.h>

int input_arr(int *n, double **start, double **end, int *n_2)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;

    if (*n <= 0)
        return INV_INPUT;

    *start = (double*)malloc((*n) * sizeof(double));

    if (*start == NULL)
        return INV_MEMORY;

    *end = *start + (*n);

    if (*end - *start <= 0)
        return INV_INPUT;

    for (double *p = *start; p < *end; p++)
        if (scanf("%lf", p) != 1)
            return INV_INPUT;

    if (scanf("%d", n_2) != 1)
        return INV_INPUT;

    if ((*n_2) < 0)
        return INV_INPUT;

    return SUCCESS;
}

int detect_delete_elem(double **start, double **end, double aver)
{
    int check_quantity_del = 0;
    double *p = *start;
    double *new_start;

    while (p < *end - check_quantity_del)
    {
        if (*p > aver)
        {
            check_quantity_del++;
            delete_elem_arr(end, p);
        }
        else
            p++;
    }

    long len_arr = *end - *start - check_quantity_del;

    new_start = realloc(*start, len_arr * sizeof(double));
    if (new_start != NULL)
    {
        *start = new_start;
        *end = *start + len_arr;
    }
    else
        return INV_MEMORY;

    if (*end - *start <= 0)
        return INV_DEL;

    return SUCCESS;
}

void delete_elem_arr(double **end, double *ind)
{
    for (double *p = ind; p < *end - 1; p++)
        *p = *(p + 1);
}


double max_value(double *start, double *end)
{
    double max_val = *start;

    for (double *p = start; p < end; p++)
    {
        if (*p > max_val)
            max_val = *p;
    }

    return max_val;
}


int insert_max(double **start, double **end, double max_val, int i)
{
    double *new_start;
    int pos_mas = *end - *start;

    if (*end - *start <= i)
        return INV_INPUT;

    long len_arr = *end - *start + 1;
    new_start = realloc(*start, len_arr * sizeof(double));
    if (new_start != NULL)
    {
        *start = new_start;
        *end = *start + len_arr;
        new_start = NULL;
    }
    else
        return INV_MEMORY;

    for (double *p = *end - 1; p > *start; p--)
    {
        if (pos_mas == i)
        {
            *p = max_val;
            break;
        }
        else
            *p = *(p - 1);
        pos_mas--;
    }
    if (i == 0)
        **start = max_val;
    len_arr = *end - *start + 2;
    new_start = realloc(*start, len_arr * sizeof(double));
    if (new_start != NULL)
    {
        *start = new_start;
        *end = *start + len_arr;
        new_start = NULL;
    }
    else
        return INV_MEMORY;

    for (double *p = *end - 2; p > *start; p--)
        *p = *(p - 1);

    **start = max_val;

    *(*end - 1) = max_val;

    return SUCCESS;
}


double average_value(double *start, double *end)
{
    double aver_v = 0;

    double *start_2 = (double*)malloc((end - start) * sizeof(double));
    double *end_2 = start_2 + (end - start);
    double *p_2 = start;
    for (double *p = start_2; p < end_2; p++)
    {
        *p = *p_2;
        p_2++;
    }

    sort_arr(start_2, end_2);

    for (double *p = start_2; p < end_2; p++)
        aver_v += *p;

    free(start_2);

    aver_v = aver_v / (end - start);

    return aver_v;
}

void sort_arr(double *start, double *end)
{
    double temp;
    for (double *p = start; p < end; p++)
        for (double *p1 = start; p1 < end; p1++)
            if (*p < *p1)
            {
                temp = *p1;
                *p1 = *p;
                *p = temp;
            }
}

void print_arr(double *start, double *end)
{
    for (double *p = start; p < end; p++)
        printf("%8.6lf ", *p);
}

