#include "action.h"
#include "errors_processing.h"

int move_dots(t_coordinate &c, dot &offset)
{
    int error = check_initial_data_dots(c.p_coord, c.n);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        for (int i = 0; i < c.n; i++)
        {
            offset_dot(c.p_coord[i], offset);
        }
    }

    return error;
}

int rotate_dots(t_coordinate &c, t_rotate rotate)
{
    int error = check_initial_data_dots(c.p_coord, c.n);

    if (error != SUCCESS)
    {
        return error;
    }

    for (int i = 0; i < c.n; i++)
    {
        rotate_dot_x(c.p_coord[i], rotate.deg_x);
        rotate_dot_y(c.p_coord[i], rotate.deg_y);
        rotate_dot_z(c.p_coord[i], rotate.deg_z);
    }

    return error;
}

int scale_dots(t_coordinate &c, t_scale scale)
{
    int error = check_initial_data_dots(c.p_coord, c.n);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        for (int i = 0; i < c.n; i++)
        {
            scale_dot(c.p_coord[i], scale.kx, scale.ky, scale.kz);
        }

    }

    return error;
}