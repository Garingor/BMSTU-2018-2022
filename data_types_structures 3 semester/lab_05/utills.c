#include "utills.h"
#include "const.h"
#include "operation_stack_list.h"
#include "operation_stack_array.h"
#include <stdio.h>
#include <time.h>

int calculation(node **stack_list, double **free_array, int *len_free_array, int *count_overflow, char *sign_list, int len_sign_list)
{
    double answer = 0;
    int flag_answer = 0;

    int cur_sign = 1;

    double cur_multiplication_division = 1;

    double cur_num_1 = 0;
    double cur_num_2 = 0;

    int flag_division = 0;
    int flag_multiplication = 0;

    int flag_answer_cur = 0;

    while (*stack_list != NULL && len_sign_list - cur_sign >= 0)
    {
        if (sign_list[len_sign_list - cur_sign] == '*')
        {
            while (sign_list[len_sign_list - cur_sign] == '*' && *stack_list != NULL)
            {
                cur_num_1 = (*stack_list)->value;
                cur_multiplication_division *= cur_num_1;
                pop_list(stack_list, free_array, len_free_array, count_overflow);
                cur_sign++;
                flag_multiplication = 1;
            }

            if (*stack_list != NULL)
            {
                cur_num_2 = (*stack_list)->value;
                if (*stack_list != NULL)
                    pop_list(stack_list, free_array, len_free_array, count_overflow);
                if (*stack_list != NULL)
                    cur_multiplication_division *= cur_num_2;
            }

            if (len_sign_list - cur_sign <= len_sign_list && sign_list[len_sign_list - cur_sign] != '/')
            {
                flag_answer = 1;
                continue;
            }

        }
        if (sign_list[len_sign_list - cur_sign] == '/')
        {
            while (sign_list[len_sign_list - cur_sign] == '/' && *stack_list != NULL)
            {
                cur_num_1 = (*stack_list)->value;
                if (cur_num_1 == 0)
                    return INV_INPUT;
                cur_multiplication_division /= cur_num_1;
                pop_list(stack_list, free_array, len_free_array, count_overflow);
                cur_sign++;
                flag_division = 1;
            }
            if (cur_num_1 == 0)
                return INV_INPUT;

            if (*stack_list != NULL)
            {
                cur_num_2 = (*stack_list)->value;
                if (*stack_list != NULL)
                    pop_list(stack_list, free_array, len_free_array, count_overflow);
                if (*stack_list != NULL)
                {
                    if (cur_num_2 == 0)
                        return INV_INPUT;
                    cur_multiplication_division *= cur_num_2;
                }

            }

            if (len_sign_list - cur_sign <= len_sign_list)
            {
                flag_answer = 1;
                continue;
            }
        }
        if (sign_list[len_sign_list - cur_sign] == '+')
        {
            if (flag_division == 1 || flag_multiplication == 1)
            {
                answer += cur_multiplication_division;
                flag_division = 0;
                cur_sign++;
                flag_multiplication = 0;
                cur_multiplication_division = 1;
                flag_answer_cur = 1;
            }

            if (len_sign_list - cur_sign - 1 >= 0 && (sign_list[len_sign_list - cur_sign - 1] == '*' || sign_list[len_sign_list - cur_sign - 1] == '/')
            && flag_answer_cur == 1)
            {
                flag_answer = 1;
                flag_answer_cur = 1;
                continue;
            }

            while (sign_list[len_sign_list - cur_sign] == '+' && *stack_list != NULL)
            {
                cur_num_1 = (*stack_list)->value;
                answer += cur_num_1;
                pop_list(stack_list, free_array, len_free_array, count_overflow);
                cur_sign++;
            }
            if (*stack_list != NULL && len_sign_list - cur_sign < 0)
                answer += (*stack_list)->value;
        }
        if (sign_list[len_sign_list - cur_sign] == '-')
        {
            if (flag_division == 1 || flag_multiplication == 1)
            {
                answer += cur_multiplication_division;
                flag_division = 0;
                cur_sign++;
                flag_multiplication = 0;
                cur_multiplication_division = 1;
                flag_answer_cur = 1;
            }

            if (len_sign_list - cur_sign - 1 >= 0 && (sign_list[len_sign_list - cur_sign - 1] == '*' || sign_list[len_sign_list - cur_sign - 1] == '/')
            && flag_answer_cur == 1)
            {
                flag_answer = 1;
                flag_answer_cur = 1;
                continue;
            }

            while (sign_list[len_sign_list - cur_sign] == '-' && *stack_list != NULL)
            {
                cur_num_1 = (*stack_list)->value;
                answer -= cur_num_1;
                pop_list(stack_list, free_array, len_free_array, count_overflow);
                cur_sign++;
            }
            if (*stack_list != NULL && len_sign_list - cur_sign < 0)
                answer += (*stack_list)->value;
        }
        flag_answer = 1;
    }
    if (flag_division == 1 || flag_multiplication == 1)
        answer += cur_multiplication_division;

    if (flag_answer != 0)
        printf("\nЗначение выражения = %f\n", answer);
    else
    {
        printf("\nСтек пуст");
        printf("\nВыход в главное меню\n");
    }
    return SUCCESS;
}

void time_calc()
{
    int count = 10000;
    double stack_array[count];
    double *p_tek = stack_array - 1;

    node *stack_list = NULL;
    double *free_array[count];
    int len_free_array = 0;
    int count_overflow = 0;

    double value = 1.0;

    clock_t begin;
    clock_t end;

    int time1 = 0, time2 = 0, time3 = 0, time4 = 0, time5 = 0, time6 = 0,
           time11 = 0, time22 = 0, time33 = 0, time44 = 0, time55 = 0, time66 = 0;

    int memory_1 = 0, memory_2 = 0, memory_3 = 0, memory_4 = 0, memory_5 = 0, memory_6 = 0;


    int stack_array_c[1];

    for (int i = 0; i < 100; i++)
    {
        begin = clock();
        push_array(&p_tek, stack_array + 100 - 1, value);
        end = clock();
        time1 += end - begin;
    }

    for (int i = 0; i < 100; i++)
    {
        begin = clock();
        pop_array(&p_tek, stack_array - 1);
        end = clock();
        time11 += end - begin;
    }

    memory_1 = sizeof(stack_array_c) * 100;

    p_tek = stack_array - 1;
    stack_array[count];
    for (int i = 0; i < 1000; i++)
    {
        begin = clock();
        push_array(&p_tek, stack_array + 1000 - 1, value);
        end = clock();
        time2 += end - begin;
    }

    for (int i = 0; i < 1000; i++)
    {
        begin = clock();
        pop_array(&p_tek, stack_array - 1);
        end = clock();
        time22 += end - begin;
    }

    memory_2 = sizeof(stack_array_c) * 1000;

    p_tek = stack_array - 1;
    stack_array[count];
    for (int i = 0; i < 1000; i++)
    {
        begin = clock();
        push_array(&p_tek, stack_array + 1000 - 1, value);
        end = clock();
        time3 += end - begin;
    }

    for (int i = 0; i < 1000; i++)
    {
        begin = clock();
        pop_array(&p_tek, stack_array - 1);
        end = clock();
        time33 += end - begin;
    }

    memory_3 = sizeof(stack_array_c) * 10000;


    len_free_array = 0;
    count_overflow = 0;
    for (int i = 0; i < 100; i++)
    {
        begin = clock();
        push_list(&stack_list, value, free_array, &len_free_array);
        end = clock();
        time4 += end - begin;
    }


    for (int i = 0; i < 100; i++)
    {
        begin = clock();
        pop_list(&stack_list, free_array, &len_free_array, &count_overflow);
        end = clock();
        time44 += end - begin;
    }

    memory_4 = sizeof(node) * 100;

    free_node(&stack_list);
    stack_list = NULL;
    len_free_array = 0;
    count_overflow = 0;
    for (int i = 0; i < 1000; i++)
    {
        begin = clock();
        push_list(&stack_list, value, free_array, &len_free_array);
        end = clock();
        time5 += end - begin;
    }

    for (int i = 0; i < 1000; i++)
    {
        begin = clock();
        pop_list(&stack_list, free_array, &len_free_array, &count_overflow);
        end = clock();
        time55 += end - begin;
    }
    memory_5 = sizeof(node) * 1000;

    free_node(&stack_list);
    stack_list = NULL;
    len_free_array = 0;
    count_overflow = 0;
    for (int i = 0; i < 10000; i++)
    {
        begin = clock();
        push_list(&stack_list, value, free_array, &len_free_array);
        end = clock();
        time6 += end - begin;
    }


    for (int i = 0; i < 10000; i++)
    {
        begin = clock();
        pop_list(&stack_list, free_array, &len_free_array, &count_overflow);
        end = clock();
        time66 += end - begin;
    }
    memory_6 = sizeof(node) * 10000;

    free_node(&stack_list);
    stack_list = NULL;

    printf("------------------------------------------------------------------------\n");
    printf("|Функция       |Время(clock signal)   |Время(clock signal)   |Память   |\n");
    printf("|Стек массивом |PUSH                  |POP                   |         |\n");
    printf("|100           |%22d|%22d|%9d|\n", time1, time11, memory_1);
    printf("|1000          |%22d|%22d|%9d|\n", time2, time22, memory_2);
    printf("|10000         |%22d|%22d|%9d|\n", time3, time33, memory_3);
    printf("------------------------------------------------------------------------\n");
    printf("|Стек списком  |PUSH                  |POP                   |Память   |\n");
    printf("|100           |%22d|%22d|%9d|\n", time4, time44, memory_4);
    printf("|1000          |%22d|%22d|%9d|\n", time5, time55, memory_5);
    printf("|10000         |%22d|%22d|%9d|\n", time6, time66, memory_6);
    printf("------------------------------------------------------------------------\n");
}
