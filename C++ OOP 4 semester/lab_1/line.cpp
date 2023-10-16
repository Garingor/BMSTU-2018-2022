#include "line.h"
#include "errors_processing.h"
#include "mainwindow.h"
#include "dot.h"
#include "coordinates_memory.h"
#include "check_size.h"

int check_initial_data_line(t_coordinate c, int first_vertex, int second_vertex)
{
    int error = check_malloc_coord(c.p_coord);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_size(c.n);

        if (error == SUCCESS)
        {
            error = check_vertex(first_vertex);

            if (error == SUCCESS)
            {
                error = check_vertex(second_vertex);
            }
        }
    }

    return error;
}

int drawing_line(int connection, int first_vertex, int second_vertex, t_coordinate c, t_scene sc)
{
    int error = SUCCESS;
    t_line line;

    if (connection)
    {
        error = get_line(line, c, first_vertex, second_vertex);

        if (error == SUCCESS)
        {
            draw_line(line, sc);
        }
    }

    return error;
}

void move_line(dot start, dot end, t_line &line)
{
    line.start_x = start.x;
    line.start_y = start.y;
    line.end_x = end.x;
    line.end_y = end.y;
}

int get_line(t_line &line, t_coordinate &c, int first_vertex, int second_vertex)
{
    int error = check_initial_data_line(c, first_vertex, second_vertex);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        dot start, end;

        error = get_dot(start, first_vertex, c.p_coord);

        if (error == SUCCESS)
        {
            error = get_dot(end, second_vertex, c.p_coord);

            if (error == SUCCESS)
            {
                move_line(start, end, line);
            }
        }
    }

    return error;
}

void draw_line(t_line line, t_scene &sc)
{
    sc.scene->addLine(line.start_x, line.start_y, line.end_x, line.end_y, sc.pen);
}