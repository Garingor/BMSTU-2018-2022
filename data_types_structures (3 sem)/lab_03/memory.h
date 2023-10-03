#ifndef LAB_03_MEMORY_H
#define LAB_03_MEMORY_H
#include "const.h"
int malloc_struct_matrix(matrix **, int);
int malloc_struct_vector(vector **, int);

int mem_alloc_matrix_classic(int ***, int, int);
void free_matrix_classic(int ***, int);

int mem_alloc_vector_classic(int ***, int);
void free_vector_classic(int ***, int);

void free_struct_matrix(matrix **);
void free_struct_vector(vector **);

int add_elem(tja **, int);
void read_head(tja *, int);
void free_head(tja **);
#endif //LAB_03_MEMORY_H
