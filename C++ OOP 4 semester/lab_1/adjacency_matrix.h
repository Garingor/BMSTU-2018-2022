#ifndef OOP_1_ADJACENCY_MATRIX_H
#define OOP_1_ADJACENCY_MATRIX_H

#include "file.h"

typedef int** t_adj_m;

typedef struct
{
    t_adj_m p_adj_matr;
    int n;
} t_adj_matrix;

t_adj_matrix init_adjacency_matrix();
int load_adjacency_matrix(t_adj_matrix &adj_m, t_stream stream);
int input_adjacency_matrix(t_adj_m &p_adj_m, int count, t_stream stream);
int input_adjacency_value(int &p_adj_matrix_value, t_stream stream);
void move_value(int &value, int copy_value);
int check_vertex(int vertex);

#endif //OOP_1_ADJACENCY_MATRIX_H
