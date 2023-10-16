#include "utills.h"
#include "memory_list.h"
#include "operation_list.h"
#include "main_features.h"
#include "const.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

int compare_value(int value_1, int value_2)
{
    if (value_1 > value_2)
        return 1;
    else if (value_1 < value_2)
        return -1;
    else
        return 0;
}

int write_to_res(int compare, descriptor_list *res, descriptor_list *num_1, descriptor_list *num_2)
{
    int sum_degree = 0;

    if (compare > 0)
    {
        if (push_list(res, num_2->head->value, num_2->head->degree) != SUCCESS)
            return INV_MALLOC;

        pop_node(num_2);
    }
    else if (compare < 0)
    {
        if (push_list(res, num_1->head->value, num_1->head->degree) != SUCCESS)
            return INV_MALLOC;

        pop_node(num_1);
    }
    else
    {
        sum_degree = num_1->head->degree + num_2->head->degree;

        if (push_list(res, num_1->head->value, sum_degree) != SUCCESS)
            return INV_MALLOC;

        pop_node(num_1);
        pop_node(num_2);
    }

    return SUCCESS;
}

int last_write_to_res(descriptor_list *num_1, descriptor_list *num_2, descriptor_list *res)
{
    while (num_1->count > 0)
    {
        if (push_list(res, num_1->head->value, num_1->head->degree) != SUCCESS)
            return INV_MALLOC;

        pop_node(num_1);
    }

    while (num_2->count > 0)
    {
        if (push_list(res, num_2->head->value, num_2->head->degree) != SUCCESS)
            return INV_MALLOC;

        pop_node(num_2);
    }

    return SUCCESS;
}

int scanf_num(int *num, va_list ap)
{
    char c;

    if (scanf("%d%c", num, &c) != 2 || *num <= 0 || (c != ' ' && c != '\r' && c != '\0' && c != '\n'))
    {
        va_end(ap);
        return INV_INPUT;
    }

    return SUCCESS;
}

int input_num(int amount, ...)
{
    va_list ap;
    int *num;

    va_start(ap, amount);

    for (;amount > 0;amount--)
    {
        num = va_arg(ap, int *);

        if (scanf_num(num, ap) != SUCCESS)
            return INV_INPUT;
    }

    va_end(ap);

    return SUCCESS;
}

int scanf_key(char *key)
{
    scanf("%s", key);

    if (strcmp(key, "out") != 0 && strcmp(key, "mul") != 0 && strcmp(key, "sqr") != 0 && strcmp(key, "div") != 0)
        return INV_KEY;

    return SUCCESS;
}

int choice_case(char *key)
{
    if (strcmp(key, "out") == 0)
        return OUT;
    else if (strcmp(key, "mul") == 0)
        return MUL;
    else if (strcmp(key, "sqr") == 0)
        return SQR;
    else if (strcmp(key, "div") == 0)
        return DIV;
    else
        return INV_KEY;
}

int choice_key(char *key, descriptor_list *num_1, descriptor_list *num_2, descriptor_list *res)
{
    int int_num_1, int_num_2;

    int choice = choice_case(key);

    int code_error = SUCCESS;

    switch (choice)
    {
        case OUT:
            {
                code_error = input_num(1, &int_num_1);
                if (code_error != SUCCESS)
                    return code_error;
                code_error = num_expansion(1, num_1, int_num_1);
                if (code_error != SUCCESS)
                    return code_error;
                output_list(num_1);
                break;
            }
        case MUL:
            {
                code_error = input_num(2, &int_num_1, &int_num_2);
                if (code_error != SUCCESS)
                    return code_error;
                code_error = num_expansion(2, num_1, int_num_1, num_2, int_num_2);
                if (code_error != SUCCESS)
                    return code_error;
                code_error = multiplication(num_1, num_2, res);
                if (code_error != SUCCESS)
                    return code_error;
                output_list(res);
                break;
            }
        case SQR:
            {
                code_error = input_num(1, &int_num_1);
                if (code_error != SUCCESS)
                    return code_error;
                code_error = num_expansion(1, num_1, int_num_1);
                if (code_error != SUCCESS)
                    return code_error;
                code_error = squaring_num(num_1);
                if (code_error != SUCCESS)
                    return code_error;
                output_list(num_1);
                break;
            }
        case DIV:
            {
                code_error = input_num(2, &int_num_1, &int_num_2);
                if (code_error != SUCCESS)
                    return code_error;
                code_error = division(int_num_1, int_num_2, res);
                if (code_error != SUCCESS)
                    return code_error;
                output_list(res);
                break;
            }
    }
    return SUCCESS;
}
