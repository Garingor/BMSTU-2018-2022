#ifndef OOP_1_COORDINATES_H
#define OOP_1_COORDINATES_H

#include "dot.h"
#include "file.h"

typedef dot* p_dot;
typedef struct
{
    p_dot p_coord;
    int n;
} t_coordinate;

t_coordinate init_coordinate();
int load_coordinates(t_coordinate &c, t_stream stream);
int input_coordinates(p_dot &dots, int count, t_stream stream);
int input_coordinate(dot &dot, t_stream stream);

#endif //OOP_1_COORDINATES_H
