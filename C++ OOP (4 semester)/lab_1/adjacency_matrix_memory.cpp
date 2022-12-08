#include "adjacency_matrix_memory.h"
#include "errors_processing.h"
#include <cstdlib>
#include "size.h"
#include "check_size.h"

int check_malloc_adjacency_matrix(t_adj_m adj_matrix)
{
    int error = SUCCESS;

    if (adj_matrix == NULL)
    {
        error = INV_MALLOC_ADJ_MATR;
    }

    return error;
}

int check_initial_data_adjacency_matrix(t_adj_m adj_matrix, int size)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_malloc_adjacency_matrix(adj_matrix);
    }

    return error;
}

int malloc_adjacency_matrix(t_adj_m &p_adj_matrix, int size)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        p_adj_matrix = (t_adj_m) malloc(size * sizeof(p_int));

        error = check_malloc_adjacency_matrix(p_adj_matrix);

        if (error == SUCCESS)
        {
            error = malloc_value_adjacency_matrix(p_adj_matrix, size);

            if (error != SUCCESS)
            {
                free_adjacency_matrix(p_adj_matrix, size);
            }
        }
    }

    return error;
}

int check_malloc_value_adjacency_matrix(p_int value)
{
    int error = SUCCESS;

    if (value == NULL)
    {
        error = INV_MALLOC_ADJ_MATR;
    }

    return error;
}

int malloc_value_adjacency_matrix(t_adj_m &adj_matrix, int size)
{
    int error = check_initial_data_adjacency_matrix(adj_matrix, size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        for (int i = 0; i < size && error == SUCCESS; i++)
        {
            adj_matrix[i] = (p_int)malloc(size * sizeof(int));

            error = check_malloc_value_adjacency_matrix(adj_matrix[i]);
        }
    }

    return error;
}

int free_adjacency_matrix(t_adj_m &p_adj_matrix, int size)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = free_value_adjacency_matrix(p_adj_matrix, size);

        free(p_adj_matrix);

        p_adj_matrix = NULL;
    }

    return error;
}

int free_value_adjacency_matrix(t_adj_m &p_adj_matrix, int size)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            free(p_adj_matrix[i]);
        }
    }

    return error;
}