#ifndef LAB_12_CONST_H
#define LAB_12_CONST_H

#define SUCCESS 0
#define INV_MALLOC 1
#define INV_INPUT 2
#define ERROR 3
#define EMPTY_LIST 4
#define INV_KEY 5
#define UNDERFLOW 6
#define INV_WRITE 7

#define INV_CHECK_FUNC 1
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

#define FAILED 1
#define PASSED 0

#define OUT 1
#define MUL 2
#define SQR 3
#define DIV 4

typedef int size_elem;

typedef struct node
{
    struct node *next;
    size_elem degree;
    size_elem value;
} node, *pnode;

typedef struct
{
    struct node *head;
    int count;
} descriptor_list;

#endif //LAB_12_CONST_H
