#include "input.h"
#include "memory.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
int input_size(int *n, int *m, int *m_vect)
{
    char buffer[255];
    printf("\nВведите количество строк для матрицы:\n");

    if (scanf("%d", n) != SUCCESS_READ)
    {
        printf("\nНекоректный ввод числа\nВозврат в главное меню\n");
        return INV_N;
    }

    if (*n < 1)
    {
        printf("\nНеправильно введено количество строк в матрице\nВозврат в главное меню...\n");
        return INV_N;
    }

    printf("\nВведите количество cтолбцов для матрицы:\n");

    if (scanf("%d", m) != SUCCESS_READ)
    {
        printf("\nНекоректный ввод числа\nВозврат в главное меню\n");
        return INV_N;
    }

    if (*m < 1)
    {
        printf("\nНеправильно введено количество строк в матрице\nВозврат в главное меню...\n");
        return INV_N;
    }

    printf("\nВведите длину вектора-строки:\n");
    if (scanf("%d", m_vect) != SUCCESS_READ)
    {
        printf("\nНекоректный ввод числа\nВозврат в главное меню\n");
        return INV_M_VECTOR;
    }

    if (*m_vect < 1)
    {
        printf("\nНеправильно введена длина вектора-строки\nВозврат в главное меню...\n");
        return INV_M_VECTOR;
    }

    if(*m_vect != *n)
    {
        printf("\nКоличество столбцов не совпадает с длиной вектора-строки\nВозврат в главное меню...\n");
        return INV_COMPARE_M_VECTOR_M;
    }

    return SUCCESS;
}

int input_matrix_classic(matrix **matrix, tja **head, int **matr_classic, int n, int m, int *count, int *count_ja)
{
    int tek_value;
    int k = 0;
    int ja = 0;
    *count = 0;
    *count_ja = 0;

    printf("\nКоличество строк %d, количество столбцов %d\n", n, m);
    printf("Могут вводиться только целочисленных значения\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            printf("\nВведите элемент %d строки, %d столбца: ", i, j);
            if (scanf("%d", &tek_value) != SUCCESS_READ)
            {
                printf("\nДанные введены неверно\nПеревод в меню выбора способа заполнения матрицы...\n");
                return INV_INPUT_MATR_C;
            }
            matr_classic[i][j] = tek_value;
        }

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (matr_classic[i][j] != 0)
                (*count)++;

    malloc_struct_matrix(matrix, *count);

    for (int j = 0; j < m; j++)
    {
        ja = 0;
        for (int i = 0; i < n; i++)
            if (matr_classic[i][j] != 0)
            {
                (*matrix)->a[k] = matr_classic[i][j];
                (*matrix)->ia[k] = i + 1;
                ja = k + 1;
                k++;
            }
        if (ja != 0)
        {
            (*count_ja)++;
            add_elem(head, ja);
        }
    }
    add_elem(head, k + 1);

    return SUCCESS;
}

int input_matrix_sparse(matrix **matrix, tja **head, int **matr_classic, int n, int m, int *count, int *count_ja) 
{
    int i_tek, j_tek, tek_value;
    int k = 0;
    int ja = 0;
    int continue_input = -1;
    int flag_end = 0;
    *count = 0;

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            matr_classic[i][j] = 0;

    printf("\nКоличество строк %d, количество столбцов %d\n", n, m);
    printf("\nВведите элементы по образцу: номер строки, номер столбца, значение\nНапример: 2 0 100\n");
    printf("\nНомер строки и столбца нумеруются с нуля\n");
    printf("\nМогут вводиться только целочисленных значения\n");
    while (continue_input != 0 && flag_end != n)
    {
        printf("\nВведите элемент: ");

        printf("\nНомер строки: ");
        if (scanf("%d", &i_tek) != 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_MATR_S;
        }
        if (i_tek < 0 || i_tek > n - 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_MATR_S;
        }
        printf("\nНомер столбца: ");
        if (scanf("%d", &j_tek) != 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_MATR_S;
        }
        if (j_tek < 0 || j_tek > m - 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_MATR_S;
        }
        printf("\nЗначение: ");
        if (scanf("%d", &tek_value) != 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_MATR_S;
        }

        matr_classic[i_tek][j_tek] = tek_value;

        printf("\nПродолжить ввод?\nДа - 1, нет - 0\n");
        if (scanf("%d", &continue_input) != 1)
        {
            printf("Некоректный ввод числа\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_MATR_S;
        }
        if (continue_input != 1 && continue_input != 0)
        {
            printf("Некоректный ввод числа\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_VECTOR_S;
        }
        flag_end++;
    }

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (matr_classic[i][j] != 0)
                (*count)++;

    malloc_struct_matrix(matrix, *count);

    for (int j = 0; j < m; j++)
    {
        ja = 0;
        for (int i = 0; i < n; i++)
        {
            if (matr_classic[i][j] != 0)
            {
                (*matrix)->a[k] = matr_classic[i][j];
                (*matrix)->ia[k] = i + 1;
                ja = k + 1;
                k++;
            }
        }
        if (ja != 0)
        {
            (*count_ja)++;
            add_elem(head, ja);
        }
    }
    add_elem(head, k + 1);

    return SUCCESS;
} 

int input_vector_classic(vector **vector, int **vector_classic, int m, int *count)
{
    int tek;
    int k = 0;
    *count = 0;

    printf("\nВведите вектор-строку из %d элементов: \n", m);
    printf("Могут вводиться только целочисленных значения\n");
    for (int j = 0; j < m; j++)
    {
        if (scanf("%d", &tek) != SUCCESS_READ)
        {
            printf("\nДанные введены неверно\nПеревод в меню выбора способа заполнения матрицы...\n");
            return INV_INPUT_VECTOR_C;
        }

        vector_classic[0][j] = tek;
        if (tek != 0)
            (*count)++;
    }

    malloc_struct_vector(vector, *count);

    for (int j = 0; j < m; j++)
    {
        if (vector_classic[0][j] != 0)
        {
            (*vector)->ja[k] = j + 1;
            (*vector)->a[k] = vector_classic[0][j];
            k++;
        }
    }

    return SUCCESS;
}

int input_vector_sparse(vector **vector, int **vector_classic, int m, int *count)
{
    int k = 0;
    int j_tek, tek_value;
    int continue_input = -1;
    *count = 0;

    for (int j = 0; j < m; j++)
        vector_classic[0][j] = 0;

    printf("\nВведите вектор-строку из %d элементов: \n", m);
    printf("\nВведите элементы по образцу: номер столбца, значение\nНапример: 0 100\n");
    printf("\nНомер столбца нумеруется с нуля\n");
    printf("\nМогут вводиться только целочисленных значения\n");
    while (continue_input != 0)
    {
        printf("\nВведите элемент: ");

        printf("\nНомер столбца: ");
        if (scanf("%d", &j_tek) != 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_VECTOR_S;
        }

        if (j_tek > m - 1 || j_tek < 0)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_VECTOR_S;
        }

        printf("\nЗначение: ");
        if (scanf("%d", &tek_value) != 1)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_VECTOR_S;
        }

        vector_classic[0][j_tek] = tek_value;

        printf("\nПродолжить ввод?\nДа - 1, нет - 0");
        if (scanf("%d", &continue_input) != 1 )
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_VECTOR_S;
        }
        if (continue_input != 1 && continue_input != 0)
        {
            printf("Некоректный ввод чисел\nПеревод в меню выбора способа заполнения матрицы...\n\n");
            return INV_INPUT_VECTOR_S;
        }
    }

    for (int j = 0; j < m; j++)
        if (vector_classic[0][j] != 0)
            (*count)++;

    malloc_struct_vector(vector, *count);

    for (int j = 0; j < m; j++)
    {
        if (vector_classic[0][j] != 0)
        {
            (*vector)->ja[k] = j + 1;
            (*vector)->a[k] = vector_classic[0][j];
            k++;
        }
    }

    return SUCCESS;
}

int generate(matrix **matrix, vector **vector, tja **head, int **matr_classic, int **vector_classic,  int n,
        int m, int m_vec, int *count_m, int *count_v, double per_matr, double per_vect, int *count_ja)
{
    double fill_percent;
    double count_value_matr = 0.0;
    double count_value_vect = 0.0;
    *count_ja = 0;

    int i1, j1, value;
    int k = 0;
    int ja = 0;
    *count_m = 0;
    *count_v = 0;

    srand(time(NULL));

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            matr_classic[i][j] = 0;

    fill_percent = 100.0 - per_matr;


        while (fabs((((double)count_value_matr / (double)(n * m)) * 100.0) - fill_percent) >= 5)
        {
            //printf("%f \n", fabs((((double)count_value_matr / (double)(n * m)) * 100.0) - fill_percent));
            i1 = rand() % n;
            j1 = rand() % m;
            value = -100 + rand() % 100;
            if (value != 0 && matr_classic[i1][j1] == 0)
            {
                matr_classic[i1][j1] = value;
                count_value_matr++;
            }
            if (count_value_matr >= (n * m))
                break;
        }


    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matr_classic[i][j] != 0)
                (*count_m)++;

    malloc_struct_matrix(matrix, *count_m);

    for (int j = 0; j < m; j++)
    {
        ja = 0;
        for (int i = 0; i < n; i++)
        {
            if (matr_classic[i][j] != 0)
            {
                (*matrix)->a[k] = matr_classic[i][j];
                (*matrix)->ia[k] = i + 1;
                ja = k + 1;
                k++;
            }
        }
        (*count_ja)++;
        add_elem(head, ja);
    }
    add_elem(head, k + 1);

    fill_percent = 100.0 - per_vect;

    for (int j = 0; j < m_vec; j++)
        vector_classic[0][j] = 0;

    srand(time(NULL));


        while (fabs((((double) count_value_vect / (double) m_vec) * 100.0) - fill_percent ) >= 5)
        {
            j1 = 0 + rand() % m_vec;
            value = -100 + rand() % 100;
            if (value != 0 && vector_classic[0][j1] == 0)
            {
                vector_classic[0][j1] = value;
                count_value_vect++;
            }
            if (count_value_vect >= m_vec)
                break;
        }


    for (int j = 0; j < m_vec; j++)
        if (vector_classic[0][j] != 0)
            (*count_v)++;

    k = 0;

    malloc_struct_vector(vector, *count_v);


    for (int j = 0; j < m_vec; j++)
    {
        if (vector_classic[0][j] != 0)
        {
            (*vector)->ja[k] = j + 1;
            (*vector)->a[k] = vector_classic[0][j];
            k++;
        }
    }
    return SUCCESS;
}

int fill_percent(double *percent_m, double *percent_v)
{
    printf("\nВведите процент разреженности для матрицы: ");

    if (scanf("%lf", percent_m) != SUCCESS_READ)
    {
        printf("\nНекоректный ввод числа\nВозврат в главное меню\n");
        return INV_PERCENT;
    }

    if (*percent_m < 0.0 || *percent_m > 100.0)
    {
        printf("\nПроцент меньше 0%% или больше 100%%\nВозврат в главное меню\n");
        return INV_PERCENT;
    }

    printf("\nВведите процент разреженности для вектора-строки: ");

    if (scanf("%lf", percent_v) != SUCCESS_READ)
    {
        printf("\nНекоректный ввод числа\nВозврат в главное меню\n");
        return INV_PERCENT;
    }

    if (*percent_v < 0.0 || *percent_v > 100.0)
    {
        printf("\nПроцент меньше 0%% или больше 100%%\nВозврат в главное меню\n");
        return INV_PERCENT;
    }

    return SUCCESS;
}