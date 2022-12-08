#include <stdio.h>
#include "const.h"
#include "menu.h"
#include "operation_stack_array.h"
#include "operation_stack_list.h"
#include "utills.h"

int main()
{
    int choice = -1;

    double stack_array[MAX_SIZE_ARRAY];
    double *p_tek = stack_array - 1;
    char sign_array[MAX_SIZE_ARRAY];
    int len_sign_array = 0;

    node *stack_list = NULL;
    double *free_array[MAX_SIZE_LIST];
    char sign_list[MAX_SIZE_LIST];
    int len_free_array = 0;
    int len_sign_list = 0;
    int count_overflow = 0;

    do
    {
        print_menu();

        get_choice(0, 8, &choice);

        switch (choice)
        {
            case 1:
                if (calculation(&stack_list, free_array, &len_free_array, &count_overflow, sign_list, len_sign_list) == INV_INPUT)
                {
                    printf("\nДеление на ноль запрещено");
                    printf("\nВыход в главное меню\n");
                }
                len_sign_list = 0;
                break;
            case 2:
                push_array_menu(&p_tek, stack_array + MAX_SIZE_ARRAY - 1, sign_array, &len_sign_array);
                break;
            case 3:
                pop_array(&p_tek, stack_array - 1);
                len_sign_array--;
                break;
            case 4:
                print_array(p_tek, stack_array - 1, sign_array, len_sign_array);
                break;
            case 5:
                if (count_overflow > MAX_SIZE_LIST)
                {
                    printf("\nСтек переполнен");
                    printf("\nВыход в главное меню\n");
                }
                else
                    push_list_menu(&stack_list, sign_list, &len_sign_list, free_array, &len_free_array, &count_overflow);
                break;
            case 6:
                pop_list(&stack_list, free_array, &len_free_array, &count_overflow);
                len_sign_list--;
                break;
            case 7:
                print_list(stack_list, sign_list, len_sign_list, free_array, len_free_array, &count_overflow);
                break;
            case 8:
                time_calc();
                break;
        }
    } while (choice != 0);

    free_node(&stack_list);

    return SUCCESS;
}
