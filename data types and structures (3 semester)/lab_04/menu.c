#include "menu.h"
#include "const.h"
#include <stdio.h>

void print_menu()
{
    printf("\n1 - Вычислить значение выражения\n");
    printf("2 - Добавление элемента в стек (массив)\n");
    printf("3 - Удаление элемента из стека (массив)\n");
    printf("4 - Просмотр стека (массив)\n");
    printf("5 - Добавление элемента в стек (список)\n");
    printf("6 - Удаление элемента из стека (список)\n");
    printf("7 - Просмотр стека (список)\n");
    printf("8 - Сравнение эффективности\n");
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
