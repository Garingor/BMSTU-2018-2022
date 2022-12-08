#ifndef OOP_1_DRAW_H
#define OOP_1_DRAW_H

#include "coordinates.h"
#include "adjacency_matrix.h"
#include "scene.h"
#include "view.h"

typedef struct
{
    t_scene sc;
    t_view v;
} t_draw;

int drawing_model(t_scene &sc, t_adj_matrix adj_m, t_coordinate coord);

#endif //OOP_1_DRAW_H
