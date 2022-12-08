#include "coordinates.h"
#include "errors_processing.h"
#include <cstdio>
#include "size.h"
#include "coordinates_memory.h"
#include "check_size.h"

t_coordinate init_coordinate()
{
    t_coordinate c;
    c.n = 0;
    c.p_coord = NULL;
    return c;
}

int load_coordinates(t_coordinate &c, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS)
    {
        return error;
    }

    error = input_size(c.n, stream);

    if (error == SUCCESS)
    {
        error = malloc_coordinates(c.p_coord, c.n);

        if (error == SUCCESS)
        {
            error = input_coordinates(c.p_coord, c.n, stream);

            if (error != SUCCESS)
            {
                free_coordinates(c.p_coord); //
            }
        }
    }

    return error;
}

int check_initial_data_coord(p_dot dots, int size, t_stream stream)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_malloc_coord(dots);

        if (error == SUCCESS)
        {
            error = check_open_stream(stream);
        }
    }

    return error;
}

int input_coordinates(p_dot &dots, int size, t_stream stream)
{
    int error = check_initial_data_coord(dots, size, stream);

    if (error != SUCCESS) //
    {
        return error;
    }
    else
    {
        for (int i = 0; i < size && error == SUCCESS; i++)
        {
            error = input_coordinate(dots[i], stream);
        }
    }

    return error;
}
void move_coord(dot &dots, double x, double y, double z)
{
    dots.x = x;              //
    dots.y = y;
    dots.z = z;
}

int input_coordinate(dot &dots, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS) //
    {
        return error;
    }
    else
    {
        double x, y, z;
        int right_size_read = 3;

        int size_read = fscanf(stream,"%lf%lf%lf", &x, &y, &z);

        error = check_size_read(size_read, right_size_read);

        if (error == SUCCESS)
        {
            move_coord(dots, x, y, z);
        }
    }

    return error;
}