#include "adjacency_matrix.h"
#include "errors_processing.h"
#include "size.h"
#include "adjacency_matrix_memory.h"
#include "check_size.h"

t_adj_matrix init_adjacency_matrix()
{
    t_adj_matrix adj_m;
    adj_m.n = 0;
    adj_m.p_adj_matr = NULL;
    return adj_m;
}

int check_initial_data_input_adjacency_matrix(t_adj_m p_adj_matr, int size, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_size(size);

        if (error == SUCCESS)
        {
            error = check_malloc_adjacency_matrix(p_adj_matr);
        }
    }

    return error;
}


int load_adjacency_matrix(t_adj_matrix &m, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS)
    {
        return error;
    }
    
    error = input_size(m.n, stream);
    
    if (error == SUCCESS)
    {
        error = malloc_adjacency_matrix(m.p_adj_matr, m.n);
        
        if (error == SUCCESS)
        {
            error = input_adjacency_matrix(m.p_adj_matr, m.n, stream);

            if (error != SUCCESS)
            {
                free_adjacency_matrix(m.p_adj_matr, m.n);
            }
        }
    }
    
    return error;

}

int input_adjacency_matrix(t_adj_m &p_adj_matr, int size, t_stream stream)
{
    int error = check_initial_data_input_adjacency_matrix(p_adj_matr, size, stream);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        for (int i = 0; i < size && error == SUCCESS; i++)
        {
            for (int j = 0; j < size && error == SUCCESS; j++)
            {
                error = input_adjacency_value(p_adj_matr[i][j], stream);
            }
        }
    }

    return error;
}

void move_value(int &value, int copy_value)
{
    value = copy_value;
}

int input_adjacency_value(int &value, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        int copy_value, right_value_read = 1;

        int value_read = fscanf(stream,"%d", &copy_value);

        error = check_size_read(value_read, right_value_read);

        if (error == SUCCESS)
        {
            move_value(value, copy_value);
        }
    }

    return error;
}

int check_vertex(int vertex)
{
    int error = SUCCESS;

    if (vertex < 0)
    {
        error = INV_VERTEX;
    }

    return error;
}