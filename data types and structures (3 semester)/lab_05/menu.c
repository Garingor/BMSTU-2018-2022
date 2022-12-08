#include "menu.h"
#include "const.h"
#include <stdio.h>

void print_main_menu()
{
    printf("\n1 - Настройка программы\n");
    printf("2 - Реализация очереди в виде массива\n");
    printf("3 - Реализация очереди в виде линейного списка\n");
    printf("0 - выход из программы\n");
}

void print_preferences_menu()
{
    printf("\n1 - Изменить время прихода \n");
    printf("0 - выход из подменю\n");
}

void print_array_menu()
{
    printf("\n1 - Обработка заявок\n");
    printf("0 - выход из подменю\n");
}

void print_list_menu()
{
    printf("\n1 - to do\n");
    printf("0 - выход из подменю\n");
}
void print_menu()
{
    printf("\n1 - Обработка 100 заявок\n");
    printf("2 - Обработка 1000 заявок\n");
    printf("5 - Просмотр первого элемента в очереди \n");
    printf("6 - Просмотр последнего элемента в очереди \n");
    printf("7 - Просмотр всей очереди (список)\n");
    printf("8 - Просмотр первого элемента в очереди (список)\n");
    printf("9 - Просмотр последнего элемента в очереди (список)\n");
    printf("10 - Просмотр всей очереди (список)\n");
    printf("11 - Сравнение эффективности\n");
    printf("0 - выход из программы\n");
}

void get_choice(int min, int max, int *choice)
{
    char stroka[100];

    printf("Введите команду: ");
    scanf("%s", stroka);

    while (sscanf(stroka, "%d", choice) != SUCCESS_READ || (*choice) > max || (*choice) < min)
    {
        printf("Неверный ввод, попробуйте еще раз\n");
        printf("Введите команду: ");
        scanf("%s", stroka);
    }
}
