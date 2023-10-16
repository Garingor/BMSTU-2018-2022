#ifndef OOP_1_ACTION_H
#define OOP_1_ACTION_H

#include "coordinates.h"

typedef struct
{
    double deg_x;
    double deg_y;
    double deg_z;
} t_rotate;

typedef struct
{
    double kx;
    double ky;
    double kz;
} t_scale;

int move_dots(t_coordinate &c, dot &offset);
int rotate_dots(t_coordinate &c, t_rotate rotate);
int scale_dots(t_coordinate &c, t_scale scale);

#endif //OOP_1_ACTION_H
