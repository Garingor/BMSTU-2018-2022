#include "test_utills.h"
#include "const.h"
#include <stdio.h>
#include <string.h>

int print_log(char *test, char *buffer, char *my_buffer, int res, int my_res, int choice)
{
    if (choice == FAILED)
    {
        printf("\n%s[   FAILED   ]%s %s", RED, RESET, test);
        printf("\nОжидаемый результат:");
        printf("\nВозвращаемое значение - %d", res);
        printf("\nВозвращаемая строка - %s", buffer);
        printf("\nФактический результат:");
        printf("\nВозвращаемое значение - %d", my_res);
        printf("\nВозвращаемая строка - %s\n", my_buffer);
        return FAILED;
    }
    else
    {
        printf("\n%s[   PASSED   ]%s %s", GREEN, RESET, test);
        return PASSED;
    }
}

int compare_result(char *buffer, char *my_buffer, int res, int my_res)
{
    if (res != my_res || (my_buffer != NULL && strcmp(buffer, my_buffer) != 0))
        return FAILED;
    return PASSED;
}
