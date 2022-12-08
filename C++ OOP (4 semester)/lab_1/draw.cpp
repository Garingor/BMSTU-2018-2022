#include "draw.h"
#include "errors_processing.h"
#include "line.h"
#include "adjacency_matrix_memory.h"
#include "check_size.h"
#include "coordinates_memory.h"

int check_initial_data_draw(t_QGraphicsScene sc, t_adj_matrix m, t_coordinate c)
{
    int error = check_malloc_adjacency_matrix(m.p_adj_matr);

    if (error != SUCCESS)
    {
        return error;
    }

    error = check_malloc_coord(c.p_coord);

    if (error == SUCCESS)
    {
        error = check_size(c.n);

        if (error == SUCCESS)
        {
            error = check_size(m.n);

            if (error == SUCCESS)
            {
                error = check_address_scene(sc);
            }
        }
    }

    return error;
}

int drawing_model(t_scene &sc, t_adj_matrix m, t_coordinate c)
{
    int error = check_initial_data_draw(sc.scene, m, c);

    if (error != SUCCESS)
    {
        return error;
    }

    for (int first_vertex = 0; first_vertex < m.n && error == SUCCESS; first_vertex++)
    {
        for (int second_vertex= first_vertex + 1; second_vertex< m.n && error == SUCCESS; second_vertex++)
        {
            error = drawing_line(m.p_adj_matr[first_vertex][second_vertex], first_vertex, second_vertex, c, sc); // название
        }
    }


    return error;
}

