#ifndef LAB_12_OPERATION_LIST_H
#define LAB_12_OPERATION_LIST_H

#include "const.h"

int push_list(descriptor_list *, int, int);
void output_list(descriptor_list *);
void init_descriptor_list(descriptor_list *);
pnode find_node(descriptor_list, int);
void pop_list(descriptor_list *);
void pop_node(descriptor_list *);
#endif //LAB_12_OPERATION_LIST_H
