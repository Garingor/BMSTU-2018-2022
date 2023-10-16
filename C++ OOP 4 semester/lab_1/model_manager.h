#ifndef OOP_1_MODEL_MANAGER_H
#define OOP_1_MODEL_MANAGER_H

#include "draw.h"
#include "action.h"
#include "file.h" //

enum t_choose
{
    LOAD_MODEL = 0,
    DRAW_MODEL,
    MOVE_MODEL,
    ROTATE_MODEL,
    SCALE_MODEL,
    FREE_MODEL,
    ERROR_COMMAND
};

typedef struct
{
    t_filename filename;
    t_draw param_draw;
    dot param_move;
    t_scale param_scale;
    t_rotate param_rotate;
} t_param;

int model_manager(t_choose choose, t_param &param);

#endif //OOP_1_MODEL_MANAGER_H
