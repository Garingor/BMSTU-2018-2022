#include "dot.h"
#include "errors_processing.h"
#include "my_math.h"
#include "line.h"
#include "coordinates_memory.h"
#include "check_size.h"
#include "adjacency_matrix.h"

int check_initial_data_dots(dot* dots, int size)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_malloc_coord(dots);
    }

    return error;
}
int check_initial_data_get_dots(dot* dot, int vertex)
{
    int error = check_malloc_coord(dot);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_vertex(vertex);
    }

    return error;
}

int get_dot(dot &copy_dot, int vertex, dot* &cur_dot)
{
    int error = check_initial_data_get_dots(cur_dot, vertex);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        copy_dot.x = cur_dot[vertex].x;
        copy_dot.y = cur_dot[vertex].y;
        copy_dot.z = cur_dot[vertex].z;
    }

    return error;
}

void offset_dot(dot &cur_dot, dot offset)
{
    cur_dot.x += offset.x;
    cur_dot.y += offset.y;
    cur_dot.z += offset.z;
}

void rotate_dot_x(dot &cur_dot, double deg_x)
{
    double sin_angle = math_sin_angle(deg_x);
    double cos_angle = math_cos_angle(deg_x);

    cur_dot.y =  cur_dot.y + cos_angle + cur_dot.z * sin_angle;
    cur_dot.z =  cur_dot.z * cos_angle - cur_dot.y * sin_angle;
}

void rotate_dot_y(dot &cur_dot, double deg_y)
{
    double sin_angle = math_sin_angle(deg_y);
    double cos_angle = math_cos_angle(deg_y);

    cur_dot.x = cur_dot.x * cos_angle + cur_dot.z * sin_angle;
    cur_dot.z = cur_dot.z * cos_angle - cur_dot.x * sin_angle;
}

void rotate_dot_z(dot &cur_dot, double deg_z)
{
    double sin_angle = math_sin_angle(deg_z);
    double cos_angle = math_cos_angle(deg_z);

    cur_dot.x = cur_dot.x * cos_angle + cur_dot.y * sin_angle;
    cur_dot.y = cur_dot.y * cos_angle - cur_dot.x * sin_angle;
}

void scale_dot(dot &dot, double kx, double ky, double kz)
{
    dot.x *= kx;
    dot.y *= ky;
    dot.z *= kz;
}