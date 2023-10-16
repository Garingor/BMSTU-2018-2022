#ifndef OOP_1_MODEL_H
#define OOP_1_MODEL_H

#include "model_manager.h"
#include <cstdio>

enum t_init
{
    FALSE = 20,
    TRUE  = 0
};

typedef struct
{
    t_coordinate coord;
    t_adj_matrix adj_m;
    t_init init_model;
} t_model;

t_model init_model();
int load_model(t_model &model, t_filename filename);
int input_model(t_model &model, t_stream stream);
int free_model(t_model &model);
t_init is_model_empty(t_init init_model);
int draw_model(t_model &model, t_draw &draw);
int move_model(t_model &model, dot &move);
int rotate_model(t_model &model, t_rotate rotate);
int scale_model(t_model &model, t_scale scale);
int check_initial_data_model(t_model model);
void move_model(t_model &model, t_model &copy_model);

#endif //OOP_1_MODEL_H
