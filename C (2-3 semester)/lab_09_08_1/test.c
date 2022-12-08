#include <stdio.h>
#include <stdint.h>
#include "dmatrix.h"
#include "const.h"
#include "input_output_matr.h"
#include "matr_memory.h"

int detect_min_elem_in_matrix()
{
    int64_t **matr = NULL;

    int m = 3, n = 2;

    if (mem_alloc_matr(&matr, n, m) != SUCCESS)
        return 0;
    int i1_expected, j1_expected, i1_func, j1_func;
    matr[0][0] = 33;
    matr[0][1] = 5;
    matr[0][2] = 3;
    matr[1][0] = 11;
    matr[1][1] = 12;
    matr[1][2] = 111;
    i1_expected = 0;
    j1_expected = 2;
    detect_min_matrix(matr, n, m, &i1_func, &j1_func);
    free_matrix(&matr, n);
    if (i1_expected != i1_func && j1_expected != j1_func)
    {
        printf("поиск минимального значения в матрице: FAILED\n");
        printf("ожидалось:     i = 0  j = 2\n");
        printf("фактическое:   i = %d j = %d\n", i1_func, j1_func);
        return 0;
    }
    else
        return 1;
}

int detect_min_2_elem_in_matrix()
{
    int64_t **matr = NULL;

    int m = 3, n = 2;
    if (mem_alloc_matr(&matr, n, m) != SUCCESS)
        return 0;
    int i1_expected, j1_expected, i1_func, j1_func;
    matr[0][0] = 3;
    matr[0][1] = 5;
    matr[0][2] = 3;
    matr[1][0] = 3;
    matr[1][1] = 12;
    matr[1][2] = 3;
    i1_expected = 1;
    j1_expected = 2;
    detect_min_matrix(matr, n, m, &i1_func, &j1_func);
    free_matrix(&matr, n);
    if (i1_expected != i1_func && j1_expected != j1_func)
    {
        printf("поиск минимального значения в матрице: FAILED\n");
        printf("ожидалось:     i = 1  j = 2\n");
        printf("фактическое:   i = %d j = %d\n", i1_func, j1_func);
        return 0;
    }
    else
        return 1;
}

int delete_line_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int n = 3, m = 2;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n - 1, m) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[1][0] = 8;
    matr_func[1][1] = 3;
    matr_func[2][0] = 12;
    matr_func[2][1] = 3;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = 5;
    matr_expected[1][0] = 8;
    matr_expected[1][1] = 3;

    delete_min_matrix(&matr_func, &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Удаление строки матрицы:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int delete_column_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 2;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, (m - 1)) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[0][2] = 12;
    matr_func[1][0] = 1;
    matr_func[1][1] = 123;
    matr_func[1][2] = 6;

    matr_expected[0][0] = 5;
    matr_expected[0][1] = 12;
    matr_expected[1][0] = 123;
    matr_expected[1][1] = 6;

    delete_min_matrix(&matr_func, &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Удаление столбца матрицы:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }


    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int insert_new_line_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, (n + 1), m) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[0][2] = 8;
    matr_func[1][0] = 3;
    matr_func[1][1] = 12;
    matr_func[1][2] = 3;
    matr_func[2][0] = 31;
    matr_func[2][1] = 121;
    matr_func[2][2] = 31;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = 5;
    matr_expected[0][2] = 8;
    matr_expected[1][0] = 3;
    matr_expected[1][1] = 12;
    matr_expected[1][2] = 3;
    matr_expected[2][0] = 31;
    matr_expected[2][1] = 121;
    matr_expected[2][2] = 31;
    matr_expected[3][0] = 6;
    matr_expected[3][1] = 19;
    matr_expected[3][2] = 9;

    insert_new_line(&matr_func, &n, m, m + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Вставка строки матрицы:\n");
                printf("(Среднее геометрическое, огругленное к нижнему целому)\n");
                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int insert_new_line_neg_num()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, (n + 1), m) != SUCCESS)
        return 0;

    matr_func[0][0] = -3;
    matr_func[0][1] = -5;
    matr_func[0][2] = 8;
    matr_func[1][0] = 3;
    matr_func[1][1] = -12;
    matr_func[1][2] = -3;
    matr_func[2][0] = -31;
    matr_func[2][1] = -121;
    matr_func[2][2] = 31;

    matr_expected[0][0] = -3;
    matr_expected[0][1] = -5;
    matr_expected[0][2] = 8;
    matr_expected[1][0] = 3;
    matr_expected[1][1] = -12;
    matr_expected[1][2] = -3;
    matr_expected[2][0] = -31;
    matr_expected[2][1] = -121;
    matr_expected[2][2] = 31;
    matr_expected[3][0] = 6;
    matr_expected[3][1] = 19;
    matr_expected[3][2] = 9;

    insert_new_line(&matr_func, &n, m, m + 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Вставка строки матрицы:\n");
                printf("(Среднее геометрическое, огругленное к нижнему целому)\n");
                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int insert_new_column_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, (m + 1)) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[0][2] = 8;
    matr_func[1][0] = 3;
    matr_func[1][1] = 12;
    matr_func[1][2] = 3;
    matr_func[2][0] = 31;
    matr_func[2][1] = 121;
    matr_func[2][2] = 31;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = 5;
    matr_expected[0][2] = 8;
    matr_expected[0][3] = 3;
    matr_expected[1][0] = 3;
    matr_expected[1][1] = 12;
    matr_expected[1][2] = 3;
    matr_expected[1][3] = 3;
    matr_expected[2][0] = 31;
    matr_expected[2][1] = 121;
    matr_expected[2][2] = 31;
    matr_expected[2][3] = 31;

    insert_new_column(&matr_func, n, &m, 4);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Вставка минимального элемента в конец строки матрицы:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int insert_new_col_matr_negat_num()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, (m + 1)) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = -5;
    matr_func[0][2] = 8;
    matr_func[1][0] = 3;
    matr_func[1][1] = -12;
    matr_func[1][2] = -3;
    matr_func[2][0] = -31;
    matr_func[2][1] = 121;
    matr_func[2][2] = -31;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = -5;
    matr_expected[0][2] = 8;
    matr_expected[0][3] = -5;
    matr_expected[1][0] = 3;
    matr_expected[1][1] = -12;
    matr_expected[1][2] = -3;
    matr_expected[1][3] = -12;
    matr_expected[2][0] = -31;
    matr_expected[2][1] = 121;
    matr_expected[2][2] = -31;
    matr_expected[2][3] = -31;

    insert_new_column(&matr_func, n, &m, 4);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Вставка минимального элемента (отрицательного) в конец строки матрицы:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int transpose_this_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[0][2] = 8;
    matr_func[1][0] = 3;
    matr_func[1][1] = 12;
    matr_func[1][2] = 3;
    matr_func[2][0] = 31;
    matr_func[2][1] = 121;
    matr_func[2][2] = 31;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = 3;
    matr_expected[0][2] = 31;
    matr_expected[1][0] = 5;
    matr_expected[1][1] = 12;
    matr_expected[1][2] = 121;
    matr_expected[2][0] = 8;
    matr_expected[2][1] = 3;
    matr_expected[2][2] = 31;

    transpose_matr(matr_func, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Вставка минимального элемента в конец строки матрицы:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int multiplication_two_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int64_t **matr_1 = NULL;

    int64_t **matr_2 = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_1, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_2, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    matr_1[0][0] = 3;
    matr_1[0][1] = 5;
    matr_1[0][2] = 8;
    matr_1[1][0] = 3;
    matr_1[1][1] = 1;
    matr_1[1][2] = 3;
    matr_1[2][0] = 3;
    matr_1[2][1] = 1;
    matr_1[2][2] = 3;

    matr_2[0][0] = 1;
    matr_2[0][1] = 3;
    matr_2[0][2] = 8;
    matr_2[1][0] = 3;
    matr_2[1][1] = 1;
    matr_2[1][2] = 3;
    matr_2[2][0] = 9;
    matr_2[2][1] = 1;
    matr_2[2][2] = 1;

    matr_expected[0][0] = 90;
    matr_expected[0][1] = 22;
    matr_expected[0][2] = 47;
    matr_expected[1][0] = 33;
    matr_expected[1][1] = 13;
    matr_expected[1][2] = 30;
    matr_expected[2][0] = 33;
    matr_expected[2][1] = 13;
    matr_expected[2][2] = 30;

    transpose_matr(matr_2, n);
    memset_matrix(matr_func, n);

    multiplication_matr(matr_1, matr_2, matr_func, n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Умножение двух матриц:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);
                free_matrix(&matr_1, n);
                free_matrix(&matr_2, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);
    free_matrix(&matr_1, n);
    free_matrix(&matr_2, n);

    return 1;
}

int multipl_two_matr_neg_num()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int64_t **matr_1 = NULL;

    int64_t **matr_2 = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_1, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_2, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    matr_1[0][0] = -3;
    matr_1[0][1] = 5;
    matr_1[0][2] = -8;
    matr_1[1][0] = -3;
    matr_1[1][1] = -12;
    matr_1[1][2] = 3;
    matr_1[2][0] = 31;
    matr_1[2][1] = -121;
    matr_1[2][2] = 31;

    matr_2[0][0] = 1;
    matr_2[0][1] = 3;
    matr_2[0][2] = -84;
    matr_2[1][0] = 31;
    matr_2[1][1] = -17;
    matr_2[1][2] = 38;
    matr_2[2][0] = -99;
    matr_2[2][1] = 11;
    matr_2[2][2] = 10;

    matr_expected[0][0] = 944;
    matr_expected[0][1] = -182;
    matr_expected[0][2] = 362;
    matr_expected[1][0] = -672;
    matr_expected[1][1] = 228;
    matr_expected[1][2] = -174;
    matr_expected[2][0] = -6789;
    matr_expected[2][1] = 2491;
    matr_expected[2][2] = -6892;

    transpose_matr(matr_2, n);
    memset_matrix(matr_func, n);

    multiplication_matr(matr_1, matr_2, matr_func, n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Умножение двух матриц (c отрицательными элементами):\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);
                free_matrix(&matr_1, n);
                free_matrix(&matr_2, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);
    free_matrix(&matr_1, n);
    free_matrix(&matr_2, n);

    return 1;
}

int multipl_two_small_matr_big_num()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int64_t **matr_1 = NULL;

    int64_t **matr_2 = NULL;

    int m = 2, n = 2;

    if (mem_alloc_matr(&matr_1, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_2, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    matr_1[0][0] = 331;
    matr_1[0][1] = 512;
    matr_1[1][0] = 812;
    matr_1[1][1] = 312;

    matr_2[0][0] = 123;
    matr_2[0][1] = -133;
    matr_2[1][0] = 841;
    matr_2[1][1] = 812;

    matr_expected[0][0] = 471305;
    matr_expected[0][1] = 371721;
    matr_expected[1][0] = 362268;
    matr_expected[1][1] = 145348;

    transpose_matr(matr_2, n);
    memset_matrix(matr_func, n);

    multiplication_matr(matr_1, matr_2, matr_func, n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Умножение двух маленьких матриц с большими числами:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);
                free_matrix(&matr_1, n);
                free_matrix(&matr_2, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);
    free_matrix(&matr_1, n);
    free_matrix(&matr_2, n);

    return 1;
}

int multipl_cyclically_even_num()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int64_t **matr_1 = NULL;

    int64_t **matr_2 = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_1, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_2, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    matr_1[0][0] = 3;
    matr_1[0][1] = 5;
    matr_1[0][2] = 8;
    matr_1[1][0] = 3;
    matr_1[1][1] = 12;
    matr_1[1][2] = 3;
    matr_1[2][0] = 31;
    matr_1[2][1] = 121;
    matr_1[2][2] = 31;

    matr_2[0][0] = 3;
    matr_2[0][1] = 5;
    matr_2[0][2] = 8;
    matr_2[1][0] = 3;
    matr_2[1][1] = 12;
    matr_2[1][2] = 3;
    matr_2[2][0] = 31;
    matr_2[2][1] = 121;
    matr_2[2][2] = 31;

    matr_expected[0][0] = 12842;
    matr_expected[0][1] = 48603;
    matr_expected[0][2] = 14202;
    matr_expected[1][0] = 6723;
    matr_expected[1][1] = 25467;
    matr_expected[1][2] = 7413;
    matr_expected[2][0] = 69057;
    matr_expected[2][1] = 261593;
    matr_expected[2][2] = 76142;

    transpose_matr(matr_2, n);
    memset_matrix(matr_func, n);

    multiplication_matr(matr_1, matr_2, matr_func, n, 2);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Умножение матрицы циклично (2 раза):\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);
                free_matrix(&matr_1, n);
                free_matrix(&matr_2, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);
    free_matrix(&matr_1, n);
    free_matrix(&matr_2, n);

    return 1;
}

int multipl_cyclically_odd_num()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int64_t **matr_1 = NULL;

    int64_t **matr_2 = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_1, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_2, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    matr_1[0][0] = 3;
    matr_1[0][1] = 5;
    matr_1[0][2] = 8;
    matr_1[1][0] = 3;
    matr_1[1][1] = 12;
    matr_1[1][2] = 3;
    matr_1[2][0] = 31;
    matr_1[2][1] = 121;
    matr_1[2][2] = 31;

    matr_2[0][0] = 3;
    matr_2[0][1] = 5;
    matr_2[0][2] = 8;
    matr_2[1][0] = 3;
    matr_2[1][1] = 12;
    matr_2[1][2] = 3;
    matr_2[2][0] = 31;
    matr_2[2][1] = 121;
    matr_2[2][2] = 31;

    matr_expected[0][0] = 624597;
    matr_expected[0][1] = 2365888;
    matr_expected[0][2] = 688807;
    matr_expected[1][0] = 326373;
    matr_expected[1][1] = 1236192;
    matr_expected[1][2] = 359988;
    matr_expected[2][0] = 3352352;
    matr_expected[2][1] = 12697583;
    matr_expected[2][2] = 3697637;

    transpose_matr(matr_2, n);
    memset_matrix(matr_func, n);

    multiplication_matr(matr_1, matr_2, matr_func, n, 3);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Умножение матрицы циклично (3 раза):\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);
                free_matrix(&matr_1, n);
                free_matrix(&matr_2, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);
    free_matrix(&matr_1, n);
    free_matrix(&matr_2, n);

    return 1;
}

int copy_matr_to_matr()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int64_t **matr_primary = NULL;

    int m = 3, n = 3;
    int alfa = 1;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_primary, n, m) != SUCCESS)
        return 0;

    matr_primary[0][0] = 333;
    matr_primary[0][1] = 15;
    matr_primary[0][2] = 81;
    matr_primary[1][0] = 123;
    matr_primary[1][1] = 12;
    matr_primary[1][2] = 3;
    matr_primary[2][0] = 31;
    matr_primary[2][1] = 111;
    matr_primary[2][2] = 3441;

    memset_matrix(matr_func, n);

    matr_expected[0][0] = 333;
    matr_expected[0][1] = 15;
    matr_expected[0][2] = 81;
    matr_expected[1][0] = 123;
    matr_expected[1][1] = 12;
    matr_expected[1][2] = 3;
    matr_expected[2][0] = 31;
    matr_expected[2][1] = 111;
    matr_expected[2][2] = 3441;

    copy_matr_to_matr_c(matr_primary, matr_func, n, &alfa);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("копирование одной матрицы в другую:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);
                free_matrix(&matr_primary, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);
    free_matrix(&matr_primary, n);

    return 1;
}

int unit_this_matrix()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int m = 3, n = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m) != SUCCESS)
        return 0;

    memset_matrix(matr_func, n);

    matr_expected[0][0] = 1;
    matr_expected[0][1] = 0;
    matr_expected[0][2] = 0;
    matr_expected[1][0] = 0;
    matr_expected[1][1] = 1;
    matr_expected[1][2] = 0;
    matr_expected[2][0] = 0;
    matr_expected[2][1] = 0;
    matr_expected[2][2] = 1;

    unit_matrix(matr_func, n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Единичная матрица:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int delete_min_matrix_line()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int n = 4, m = 3;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n - 1, m) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[0][2] = 8;
    matr_func[1][0] = 3;
    matr_func[1][1] = 12;
    matr_func[1][2] = 3;
    matr_func[2][0] = 31;
    matr_func[2][1] = 121;
    matr_func[2][2] = 31;
    matr_func[3][0] = 31;
    matr_func[3][1] = 121;
    matr_func[3][2] = 31;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = 5;
    matr_expected[0][2] = 8;
    matr_expected[1][0] = 31;
    matr_expected[1][1] = 121;
    matr_expected[1][2] = 31;
    matr_expected[2][0] = 31;
    matr_expected[2][1] = 121;
    matr_expected[2][2] = 31;

    delete_min_matrix(&matr_func, &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Удаление минимальной строки в общей функции удаления строк/столбцов:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int delete_min_matrix_column()
{
    int64_t **matr_expected = NULL;

    int64_t **matr_func = NULL;

    int n = 3, m = 4;

    if (mem_alloc_matr(&matr_func, n, m) != SUCCESS)
        return 0;
    if (mem_alloc_matr(&matr_expected, n, m - 1) != SUCCESS)
        return 0;

    matr_func[0][0] = 3;
    matr_func[0][1] = 5;
    matr_func[0][2] = 8;
    matr_func[0][3] = 3;
    matr_func[1][0] = 12;
    matr_func[1][1] = 3;
    matr_func[1][2] = 31;
    matr_func[1][3] = 121;
    matr_func[2][0] = 31;
    matr_func[2][1] = 31;
    matr_func[2][2] = 121;
    matr_func[2][3] = 31;

    matr_expected[0][0] = 3;
    matr_expected[0][1] = 5;
    matr_expected[0][2] = 8;
    matr_expected[1][0] = 12;
    matr_expected[1][1] = 3;
    matr_expected[1][2] = 31;
    matr_expected[2][0] = 31;
    matr_expected[2][1] = 31;
    matr_expected[2][2] = 121;

    delete_min_matrix(&matr_func, &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matr_func[i][j] != matr_expected[i][j])
            {
                printf("Удаление минимального столбца в общей функции удаления строк/столбцов:\n");

                printf("фактическая матрица = \n");
                print_matrix(matr_func, n, m);

                printf("ожидаемая матрица = \n");
                print_matrix(matr_expected, n, m);

                free_matrix(&matr_expected, n);
                free_matrix(&matr_func, n);

                return 0;
            }
        }
    }

    free_matrix(&matr_expected, n);
    free_matrix(&matr_func, n);

    return 1;
}

int main()
{
    int test = 0;

    test = detect_min_elem_in_matrix()
        + detect_min_2_elem_in_matrix()
        + delete_line_matr()
        + delete_column_matr()
        + insert_new_line_matr()
        + insert_new_col_matr_negat_num()
        + insert_new_column_matr()
        + insert_new_line_neg_num()
        + transpose_this_matr()
        + multiplication_two_matr()
        + multipl_two_matr_neg_num()
        + multipl_two_small_matr_big_num()
        + multipl_cyclically_even_num()
        + multipl_cyclically_odd_num()
        + copy_matr_to_matr()
        + unit_this_matrix()
        + delete_min_matrix_column()
        + delete_min_matrix_line();

    printf("\n");
    if (test != 18)
    {
        printf("lab_09_08_1: FUNC_TESTING %s(FAILED)%s", RED, RESET);
        printf("\nRESULT: correct %d of 18", test);
        return INV_CHECK_FUNC;
    }
    else
        printf("lab_09_08_1: FUNC_TESTING %s(PASSED)%s", GREEN, RESET);
    printf("\nRESULT: correct %d of 18", test);
    printf("\n\n");
    return SUCCESS;
}
