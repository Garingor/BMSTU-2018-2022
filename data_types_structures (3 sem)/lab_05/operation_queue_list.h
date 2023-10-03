#include "const.h"
#ifndef LAB_04_OPERATION_STACK_LIST_H
#define LAB_04_OPERATION_STACK_LIST_H
int push_list_menu(node **, char *, int *, double **, int *, int *);
int push_list(node **, double, double **, int *);
void free_node(node **);
int pop_list(node **, double **, int *, int *);
void print_list(node *, char *, int, double **, int, int *);
#endif //LAB_04_OPERATION_STACK_LIST_H
