#ifndef OOP_1_LINE_H
#define OOP_1_LINE_H

#include "coordinates.h"
#include "scene.h"

typedef struct
{
    double start_x;
    double start_y;
    double end_x;
    double end_y;
} t_line;

int get_line(t_line &line, t_coordinate &c, int first_vertex, int second_vertex);
void draw_line(t_line line, t_scene &sc);
int drawing_line(int connection, int first_vertex, int second_vertex, t_coordinate c, t_scene sc);

#endif //OOP_1_LINE_H
