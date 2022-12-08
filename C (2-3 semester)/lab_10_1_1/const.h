#ifndef LAB_10_TEST_CONST_H
#define LAB_10_TEST_CONST_H

#define MAX_LINE 256

#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define RESET   "\033[0m"

#define SUCCESS 0
#define INV_SURNAME 1
#define INV_SEX 2
#define INV_BIRTH 3
#define INV_MARKS 4
#define INV_KEY 5
#define INV_REALLOC 6
#define INV_MALLOC 7
#define NOT_FOUND 8
#define FOUND 9
#define INV_DATA 10
#define INV_ADD_MARK 11

#define FAILED_TEST 0
#define SUCCESS_TEST 1
#define INV_CHECK_FUNC 2

#define SORT 0
#define UNSORT 1

typedef struct
{
    char *surname;
    char *sex;
    char *birth;
    int *marks;
} schoolboy;

#endif //LAB_10_TEST_CONST_H
