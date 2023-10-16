#ifndef OOP_1_SCENE_H
#define OOP_1_SCENE_H

#include "QGraphicsView"

typedef QGraphicsScene*  t_QGraphicsScene;

typedef struct
{
    t_QGraphicsScene scene;
    QPen pen;
} t_scene;

int check_address_scene(t_QGraphicsScene sc);

#endif //OOP_1_SCENE_H
