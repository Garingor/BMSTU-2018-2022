#include "operation_stack_list.h"
#include "const.h"
#include <stdio.h>
#include <string.h>
#include "stdlib.h"

int push_list_menu(node **stack_list, char *sign_list, int *len_sign_list, double **free_array, int *len_free_array,
        int *count_overflow)
{
    int count_tek = 0;
    double value = 0.0;
    char sign;

    printf("\nВведите арифметическое выражение типа: числознак ... числознак число");
    printf("\nВводятся целые и действительные числа");
    printf("\nВведите выражение:");

    if (*count_overflow != 0)
    {
        fflush(stdin);
        if (scanf("%c%lf", &sign, &value) != 2 && sign != EOF && sign != '\0')
            if (sign != '+' && sign != '-' && sign != '*' && sign != '/')
            {
                printf("\nЗнак введен некоррекно");
                printf("\nВыход в главное меню");
                return INV_INPUT;
            }

        (*len_sign_list)++;
        sign_list[(*len_sign_list) - 1] = sign;

        if (push_list(stack_list, value, free_array, len_free_array) == INV_MALLOC)
            return INV_MALLOC;

        (*count_overflow)++;
        /*
        if (scanf("%c", &sign) != 1 && sign != EOF && sign != '\0')
        {
            (*len_sign_list)++;
            sign_list[(*len_sign_list) - 1] = sign;
        }
        */
        return SUCCESS;
    }

    while (scanf("%lf%c", &value, &sign) == 2 && sign != EOF && sign != '\0' && sign != '\n')
    {
        if (sign != '+' && sign != '-' && sign != '*' && sign != '/')
        {
            printf("\nЗнак введен некоррекно");
            printf("\nВыход в главное меню");
            return INV_INPUT;
        }

        (*len_sign_list)++;
        sign_list[(*len_sign_list) - 1] = sign;

        if (push_list(stack_list, value, free_array, len_free_array) == INV_MALLOC)
            return INV_MALLOC;

        (*count_overflow)++;
        count_tek++;
    }


    if (count_tek == 0)
    {
        printf("\nCтрока введена некоррекно");
        printf("\nВыход в главное меню");
        return INV_INPUT;
    }

    if (push_list(stack_list, value, free_array, len_free_array) == INV_MALLOC)
        return INV_MALLOC;

    (*count_overflow)++;

    return SUCCESS;
}

int push_list(node **head, double value, double **free_array, int *len_free_array)
{
    node *new = NULL;
    new = malloc(sizeof(node));

    for (int i = 0; i < *len_free_array; i++)
        if ((double *)&value == free_array[i])
        {
            for (int j = i; j < (*len_free_array) - 1; j++)
                free_array[j] = free_array[j + 1];
            (*len_free_array)--;
        }

    if (new == NULL)
    {
        printf("\nНе удалось выделить память под блок");
        printf("\nВыход в главное меню");
        return INV_MALLOC;
    }

    new->value = value;
    new->next = *head;
    *head = new;

    return SUCCESS;
}

int pop_list(node **head, double **free_array, int *len_free_array, int *count_overflow)
{
    if (*head == NULL)
    {
        printf("\nCтек пуст");
        printf("\nВыход в главное меню\n");
        return OVERFLOW;
    }
    (*len_free_array)++;
    free_array[(*len_free_array) - 1] = &((*head)->value);
    node *p = (*head)->next;
    free(*head);
    *head = p;
    (*count_overflow)--;

    return SUCCESS;
}

void print_list(node *head, char *sign_list, int len_sign_list, double **free_array, int len_free_array, int *count_overflow)
{
    if (len_free_array != 0)
    {
        printf("\nОсвобожденные адреса:\n");
        for (int i = 0; i < len_free_array; i++)
            printf("%p\n", free_array[i]);
    }

    int i = 0;

    if (head == NULL)
    {
        printf("\nCтек пуст");
        printf("\nВыход в главное меню\n");
    }
    else
    {
        printf("\nВывод стека (список):\n");
        printf("|Значение |адрес");
        while (head != NULL)
        {
            if (len_sign_list != 0)
            {
                printf("\n|%c%-7lf|%14p", sign_list[len_sign_list - 1], (head)->value, &((head)->value));
                len_sign_list--;
                i++;
            }
            else
                printf("\n|%-9lf|%14p", (head)->value, &((head)->value));

            node *p = (head)->next;
            head = p;
            (*count_overflow)--;
        }
    }

}

void free_node(node **head)
{
    node *prev = NULL;

    while ((*head) != NULL)
    {
        prev = *head;
        *head = (*head)->next;
        free(prev);
    }

    free(*head);
}
