#include "menu.h"
#include "const.h"

void print_red_menu()
{
    printf("\n1 - Ввести размер матрицы и вектора-строки\n");
    printf("%s2 - Ручной ввод данных%s\n", RED, RESET);
    printf("%s3 - случайная генерация данных%s\n", RED, RESET);
    printf("%s4 - вывод на экран исходных данных%s\n", RED, RESET);
    printf("%s5 - вывод результата умножения\n%s", RED, RESET);
    printf("6 - Сравнение эффективности выполнения алгоритмов обработки матриц по памяти и по времени\n");
    printf("0 - выход из программы\n");
}

void print_red_uninitial_menu()
{
    printf("\n1 - Ввести размер матрицы и вектора-строки\n");
    printf("2 - Ручной ввод данных\n");
    printf("3 - случайная генерация данных\n");
    printf("%s4 - вывод на экран исходных данных%s\n", RED, RESET);
    printf("%s5 - вывод результата умножения\n%s", RED, RESET);
    printf("6 - Сравнение эффективности выполнения алгоритмов обработки матриц по памяти и по времени\n");
    printf("0 - выход из программы\n");
}

void print_green_menu()
{
    printf("\n1 - Ввести размер матрицы и вектора-строки\n");
    printf("2 - Ручной ввод данных\n");
    printf("3 - случайная генерация данных\n");
    printf("4 - вывод на экран исходных данных\n");
    printf("5 - вывод результата умножения\n");
    printf("6 - Сравнение эффективности выполнения алгоритмов обработки матриц по памяти и по времени\n");
    printf("0 - выход из программы\n");
}

void print_matrix_menu()
{
    printf("\nВвод матрицы:\n");
    printf("1 - Ввод вручную\n");
    printf("2 - Ввод в разреженном виде\n");
    printf("0 - выход из подменю\n");
}

void print_vector_menu()
{
    printf("\nВвод вектора-строки:\n");
    printf("1 - Ввод вручную\n");
    printf("2 - Ввод в разреженном виде\n");
    printf("0 - выход из подменю\n");
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