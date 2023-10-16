#include "tests_utills.h"
#include "operation_list.h"
#include "utills.h"
#include "const.h"
#include <stdio.h>
#include <stdarg.h>

int print_log(char *test, descriptor_list res, descriptor_list exp_res, int choice)
{
    if (choice == FAILED)
    {
        printf("\n%s[   FAILED   ]%s %s", RED, RESET, test);
        printf("\nExpected:");
        output_list(&exp_res);
        printf("\nReturn:");
        output_list(&res);
        printf("\n");
        return FAILED;
    }
    else
    {
        printf("\n%s[   PASSED   ]%s %s", GREEN, RESET, test);
        return PASSED;
    }
}

int compare_list(descriptor_list *res, descriptor_list *exp_res)
{
    if (res->head == NULL && exp_res->head == NULL)
        return PASSED;

    if (res->count != exp_res->count)
        return FAILED;

    int compare_val = 0, compare_degree = 0;

    while (res->count > 0)
    {
        compare_val = compare_value(res->head->value, exp_res->head->value);
        compare_degree = compare_value(res->head->degree, exp_res->head->degree);

        pop_node(res);
        pop_node(exp_res);

        if (compare_val != 0 || compare_degree != 0)
            return FAILED;
    }

    return PASSED;
}

int compare_res(descriptor_list *res, descriptor_list *experted_res)
{
    if (compare_list(res, experted_res) != PASSED)
        return FAILED;
    else
        return PASSED;
}

void insert_manually(descriptor_list *d, int amount, ...)
{
    va_list ap;
    int value, degree;
    va_start(ap, amount);

    for (; amount > 0; amount--)
    {
        value = va_arg(ap, int);
        degree = va_arg(ap, int);

        push_list(d, value, degree);
    }
}
