#ifndef LAB_04_CONST_H
#define LAB_04_CONST_H

#define MAX_SIZE_ARRAY 10000
#define MAX_SIZE_LIST 10000

enum success_codes // функции успешно выполнены
{
    SUCCESS,
    SUCCESS_READ
};

enum error_operations // коды ошибок операций
{
    OVERFLOW = 1,
    INV_INPUT,
    INV_MALLOC
};

typedef struct node {
    struct node *next;
    double value;
} node;

#endif //LAB_04_CONST_H
