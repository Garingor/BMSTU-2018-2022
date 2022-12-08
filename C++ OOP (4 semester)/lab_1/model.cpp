#include "model.h"
#include "adjacency_matrix.h"
#include "file.h"
#include "coordinates.h"
#include "errors_processing.h"
#include "draw.h"
#include "coordinates_memory.h"
#include "adjacency_matrix_memory.h"
#include "check_size.h"

t_model init_model()
{
    t_model m;
    m.adj_m = init_adjacency_matrix();
    m.coord = init_coordinate();
    m.init_model = FALSE;
    return m;
}

int load_model(t_model &model, t_filename filename)
{
    t_stream stream;

    int error = open_stream(stream, filename);

    if (error != SUCCESS)
    {
        return error;
    }
    //
    t_model copy_model = init_model();

    error = input_model(copy_model, stream);

    close_stream(stream);

    if (error == SUCCESS)
    {
        free_model(model);

        move_model(model, copy_model);
    }

    return error;
}

int input_model(t_model &model, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS)
    {
        return error;
    }

    error = load_coordinates(model.coord, stream);   //
    if (error == SUCCESS)
    {
        error = load_adjacency_matrix(model.adj_m, stream); //

        if (error != SUCCESS)
        {
            free_coordinates(model.coord.p_coord); // model.coord
        }
        else
        {
            model.init_model = TRUE; //
        }
    }

    return error;
}

int free_model(t_model &model)
{
    free_coordinates(model.coord.p_coord);

    free_adjacency_matrix(model.adj_m.p_adj_matr, model.adj_m.n);

    return SUCCESS;
}

t_init is_model_empty(t_init init_model)
{
    return init_model;
}

int draw_model(t_model &model, t_draw &dr)
{
    t_init init = is_model_empty(model.init_model);
    int error = INV_INIT_MODEL;

    if (init == FALSE)
    {
        return error;
    }

    error = check_initial_data_model(model); //

    if (error == SUCCESS)
    {
        error = drawing_model(dr.sc, model.adj_m, model.coord);
    }

    return error;
}

int move_model(t_model &model, dot &offset)
{
    t_init init = is_model_empty(model.init_model);
    int error = INV_INIT_MODEL;

    if (init == FALSE)
    {
        return error;
    }
    else
    {
        error = check_initial_data_model(model); //

        if (error == SUCCESS)
        {
            error = move_dots(model.coord, offset);
        }
    }

    return error;
}

int rotate_model(t_model &model, t_rotate rotate)
{
    t_init init = is_model_empty(model.init_model);
    int error = INV_INIT_MODEL;

    if (init == FALSE)
    {
        return error;
    }

    error = check_initial_data_model(model);

    if (error == SUCCESS)
    {
        error = rotate_dots(model.coord, rotate);
    }

    return error;
}

int scale_model(t_model &model, t_scale scale)
{
    t_init init = is_model_empty(model.init_model);
    int error = INV_INIT_MODEL;

    if (init == FALSE)
    {
        return error;
    }
    else
    {
        error = check_initial_data_model(model);

        if (error == SUCCESS)
        {
            error = scale_dots(model.coord, scale);
        }
    }

    return error;
}

int check_initial_data_model(t_model model)
{
    int error = check_malloc_adjacency_matrix(model.adj_m.p_adj_matr);
    
    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_malloc_coord(model.coord.p_coord);

        if (error == SUCCESS)
        {
            error = check_size(model.coord.n);

            if (error == SUCCESS)
            {
                error = check_size(model.adj_m.n);
            }
        }
    }

    return error;
}

void move_model(t_model &model, t_model &copy_model)
{
    model = copy_model;
}