#ifndef OOP_1_VIEW_H
#define OOP_1_VIEW_H

#include "QGraphicsView"

typedef QGraphicsView * t_QGraphicsView;

typedef struct
{
    t_QGraphicsView view;
    int w;
    int h;
} t_view;

#endif //OOP_1_VIEW_H
