#ifndef LAB_08_02_1_DARRAY_H
#define LAB_08_02_1_DARRAY_H
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"
#define INV_INPUT -1
#define INV_MEMORY -2
#define INV_DEL -3
#define INV_CHECK -4
#define SUCCESS 0
int input_arr(int*, double**, double**, int*);
void delete_elem_arr(double**, double*);
double average_value(double*, double*);
int detect_delete_elem(double**, double**, double);
double max_value(double*, double*);
void print_arr(double*, double*);
void sort_arr(double*, double*);
int insert_max(double**, double**, double, int);
#endif
