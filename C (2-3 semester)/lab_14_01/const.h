#ifndef LAB_10_TEST_CONST_H
#define LAB_10_TEST_CONST_H

#define MAX_LINE 256

#define SUCCESS 0
#define INV_SURNAME 1
#define INV_SEX 2
#define INV_BIRTH 3
#define INV_MARKS 4
#define INV_REALLOC 6
#define INV_MALLOC 7
#define NOT_FOUND 8
#define FOUND 9
#define INV_DATA 10
#define INV_INPUT 11;
#define INV_EXP 12

typedef struct
{
    char *surname;
    char *sex;
    char *birth;
    int *marks;
} schoolboy;

#endif //LAB_10_TEST_CONST_H
