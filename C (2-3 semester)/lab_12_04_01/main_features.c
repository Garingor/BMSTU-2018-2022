#include "main_features.h"
#include "const.h"
#include "operation_list.h"
#include "utills.h"
#include <stdio.h>
#include <stdarg.h>

int multiplication(descriptor_list *num_1, descriptor_list *num_2, descriptor_list *res)
{
    int compare = 0;

    while (num_1->count > 0 && num_2->count > 0)
    {
        compare = compare_value(num_1->head->value, num_2->head->value);

        if (write_to_res(compare, res, num_1, num_2) != SUCCESS)
            return INV_MALLOC;
    }

    if (last_write_to_res(num_1, num_2, res) != SUCCESS)
        return INV_WRITE;

    if (res->head == NULL)
    {
        return EMPTY_LIST;
    }

    return SUCCESS;
}

int squaring_num(descriptor_list *num)
{
    pnode cpy_head = num->head;

    if (cpy_head == NULL)
    {
        return EMPTY_LIST;
    }

    for (int i = 0; i < num->count; i++)
    {
        cpy_head->degree *= 2;
        cpy_head = cpy_head->next;
    }

    return SUCCESS;
}

int division(int int_num_1, int int_num_2, descriptor_list *res)
{
    if (int_num_2 == 0)
    {
        return INV_INPUT;
    }

    int division_res = int_num_1 / int_num_2;

    if (int_num_1 % int_num_2 == 0)
        num_expansion(1, res, division_res);
    else
    {
        return INV_INPUT;
    }

    return SUCCESS;
}

int num_expansion_to_node(int num, descriptor_list *d_l)
{
    int d = 2;
    int count = 0;

    while (d * d <= num)
    {
        while (num % d == 0)
        {
            count++;
            num /= d;
        }
        if (count != 0)
            if (push_list(d_l, d, count) != SUCCESS)
                return INV_MALLOC;

        count = 0;
        d += 1;
    }

    if (num != 1)
        if (push_list(d_l, num, 1) != SUCCESS)
            return INV_MALLOC;

    return SUCCESS;
}

int num_expansion(int amount, ...)
{
    int num;
    descriptor_list *d_l;

    va_list ap;
    va_start(ap, amount);

    for (; amount > 0; amount--)
    {
        d_l = va_arg(ap, descriptor_list *);
        num = va_arg(ap, int);

        num_expansion_to_node(num, d_l);
    }

    return SUCCESS;
}
