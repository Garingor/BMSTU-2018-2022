#include "const.h"
#ifndef LAB_10_TEST_STRUCT_MEMORY_H
#define LAB_10_TEST_STRUCT_MEMORY_H
void free_line(schoolboy ***, int);
void free_struct(schoolboy ***, int, int);
int realloc_struct(schoolboy ***, int *, int);
int malloc_struct(schoolboy ***, int *, int);
int realloc_dmas_marks(schoolboy **, int);
int realloc_line(schoolboy **, int);
int expansion_struct(schoolboy ***, int, int *, int *);
#endif //LAB_10_TEST_STRUCT_MEMORY_H
