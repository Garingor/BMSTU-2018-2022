#ifndef OOP_1_ADJACENCY_MATRIX_MEMORY_H
#define OOP_1_ADJACENCY_MATRIX_MEMORY_H

#include "adjacency_matrix.h"

typedef int* p_int;

int malloc_adjacency_matrix(t_adj_m &adj_matrix, int size);
int free_adjacency_matrix(t_adj_m &p_adj_matrix, int size);
int check_malloc_adjacency_matrix(t_adj_m adj_matrix);
int malloc_value_adjacency_matrix(t_adj_m &adj_matrix, int size);
int free_value_adjacency_matrix(t_adj_m &p_adj_matrix, int size);
#endif //OOP_1_ADJACENCY_MATRIX_MEMORY_H
