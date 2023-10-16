#include <stdio.h>
#include <stdint.h>
#include "const.h"

int main()
{
    int64_t **matr_a = NULL;

    int64_t **matr_b = NULL;

    int m, n;

    int m1, n1;

    int alfa, beta;

    int64_t ***mas_buffer = NULL;
    int count_buffer = 5;

    if (input_matrix(&matr_a, &n, &m) != SUCCESS)
        return INV_INPUT;


    if (input_matrix(&matr_b, &n1, &m1) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        return INV_INPUT;
    }

    if (input_alfa_beta(&alfa, &beta) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_INPUT;
    }

    if (delete_min_matrix(&matr_a, &n, &m) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (delete_min_matrix(&matr_b, &n1, &m1) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (insert_new_line(&matr_a, &n, m, n1) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (insert_new_column(&matr_a, n, &m, m1) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (insert_new_line(&matr_b, &n1, m1, n) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (insert_new_column(&matr_b, n1, &m1, m) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (malloc_mas_buffer(&mas_buffer, count_buffer) != SUCCESS)
    {
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }

    if (mem_alloc_mas_buffer(&mas_buffer, n, count_buffer) != SUCCESS)
    {
        free_mas_buffer(&mas_buffer, n, count_buffer);
        free_matrix(&matr_a, n);
        free_matrix(&matr_b, n1);
        return INV_ADDRESS;
    }
    else
        memset_buffer_mas(mas_buffer, n, count_buffer);

    exponentiation(alfa, beta, mas_buffer, n, m, matr_a, matr_b);

    free_mas_buffer(&mas_buffer, n, count_buffer);
    free_matrix(&matr_a, n);
    free_matrix(&matr_b, n1);

    return SUCCESS;
}

