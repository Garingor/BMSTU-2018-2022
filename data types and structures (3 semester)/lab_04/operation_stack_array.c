#include <stdio.h>
#include <string.h>
#include "operation_stack_array.h"
#include "const.h"
#include "operation_stack_list.h"

int push_array_menu(double **p_tek, double *p_end, char *sign_array, int *len_sign_array)
{
    int count_tek = 0;
    int value = 0;
    char sign;

    printf("\nВведите арифметическое выражение типа: числознак ... числознак число");
    printf("\nВводятся целые и действительные числа");
    printf("\nВведите выражение:");

    if (p_end - *p_tek != MAX_SIZE_ARRAY)
    {
        fflush(stdin);
        if (scanf("%c%d", &sign, &value) != 2 && sign != EOF && sign != '\0')
            if (sign != '+' && sign != '-' && sign != '*' && sign != '/')
            {
                printf("\nЗнак введен некоррекно");
                printf("\nВыход в главное меню");
                return INV_INPUT;
            }

        (*len_sign_array)++;
        sign_array[(*len_sign_array) - 1] = sign;

        if (push_array(p_tek, p_end, value) == OVERFLOW)
            return OVERFLOW;

        return SUCCESS;
    }

    while (scanf("%d%c", &value, &sign) == 2 && sign != EOF && sign != '\0' && sign != '\n')
    {
        if (sign != '+' && sign != '-' && sign != '*' && sign != '/')
        {
            printf("\nЗнак введен некоррекно");
            printf("\nВыход в главное меню");
            return INV_INPUT;
        }

        (*len_sign_array)++;
        sign_array[(*len_sign_array) - 1] = sign;

        if (push_array(p_tek, p_end, value) == OVERFLOW)
            return OVERFLOW;

        count_tek++;
    }


    if (count_tek == 0)
    {
        printf("\nCтрока введена некоррекно");
        printf("\nВыход в главное меню");
        return INV_INPUT;
    }

    if (push_array(p_tek, p_end, value) == OVERFLOW)
        return OVERFLOW;

    return SUCCESS;
}

int push_array(double **p_tek, double *p_end, double value)
{
    if (*p_tek == p_end)
    {
        printf("\nПереполнение стека");
        printf("\nВыход в главное меню");
        return OVERFLOW;
    }

    (*p_tek)++;
    **p_tek = value;

    return SUCCESS;
}

int pop_array(double **p_tek, double const *p_end)
{
    if (*p_tek == p_end)
    {
        printf("\nCтек пуст");
        printf("\nВыход в главное меню\n");
        return OVERFLOW;
    }

    (*p_tek)--;

    return SUCCESS;
}

int print_array(double *p_tek, double *p_end, char *sign_array, int len_sign_array)
{
    if (p_tek == p_end)
    {
        printf("\nCтек пуст");
        printf("\nВыход в главное меню\n");
        return SUCCESS;
    }
    else
    {
        printf("\nВывод стека (массив):\n");

        while (p_tek != p_end)
        {
            if (len_sign_array != 0)
            {
                printf("\n%c%f", sign_array[len_sign_array - 1], *p_tek);
                len_sign_array--;
            }
            else
                printf("\n%f", *p_tek);
            pop_array(&p_tek, p_end);
        }
    }

    return SUCCESS;
}
