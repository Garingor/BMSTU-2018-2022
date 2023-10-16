#ifndef LAB_10_TEST_STRUCT_MEMORY_H
#define LAB_10_TEST_STRUCT_MEMORY_H

#include "const.h"

void free_line(schoolboy ***person, int i);
void free_struct(schoolboy ***person, int count);
int realloc_struct(schoolboy ***person, int count);
int malloc_struct(schoolboy ***person, int count);
int realloc_dmas_marks(schoolboy **person, int i);
int realloc_line(schoolboy **person, int i);
int malloc_field_struct(schoolboy ***person, int count);

#endif //LAB_10_TEST_STRUCT_MEMORY_H
