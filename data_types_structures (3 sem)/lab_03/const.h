#ifndef LAB_03_CONST_H
#define LAB_03_CONST_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define RED     "\033[1;31m"
#define RESET   "\033[0m"

enum success_codes // функции успешно выполнены
{
    SUCCESS,
    SUCCESS_READ
};

enum error_operations // коды ошибок операций
{
    INV_MALLOC_STRUCT,
    INV_N,
    INV_M,
    INV_M_VECTOR,
    INV_COMPARE_M_VECTOR_M,

    INV_INPUT_MATR_C,
    INV_INPUT_MATR_S,

    INV_MALLOC_MATR_C,

    INV_INPUT_VECTOR_C,
    INV_INPUT_VECTOR_S,

    INV_MALLOC_VECTOR_C,

    INV_MALLOC_MATR,
    INV_PERCENT
};

typedef struct
{
    int *a;
    int *ia;
} matrix;

typedef struct ja {
    struct ja *next;
    int value;
} tja;

typedef struct
{
    int *ja;
    int *a;
} vector;

#endif //LAB_03_CONST_H
