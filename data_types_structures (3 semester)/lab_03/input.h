#include "const.h"
#ifndef LAB_03_INPUT_H
#define LAB_03_INPUT_H
int input_matrix_classic(matrix **, tja **, int **, int, int, int *, int *);
int input_matrix_sparse(matrix **, tja **, int **, int, int, int *, int *);
int input_vector_classic(vector **, int **, int, int *);
int input_vector_sparse(vector **, int **, int, int *);
int input_size(int *, int *, int *);
int generate(matrix **, vector **, tja **, int **, int **,  int, int, int, int *, int *, double, double, int *);
int fill_percent(double *, double *);
#endif //LAB_03_INPUT_H
