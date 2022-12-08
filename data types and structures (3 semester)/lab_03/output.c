#include "output.h"
#include "memory.h"

void print_initial_data(matrix *matrix, vector *vector, tja **head, int **matr_classic, int **vector_classic,
        int n, int m, int m_vector, int count_matrix, int count_vector, int count_ja)
{
    if (n > 20 && (count_matrix == 0 && count_vector == 0))
    {
        printf("Длина матрицы и вектора-столбца больше 20 цифр и матрица и вектор-строка полностью разрежена\n");
        printf("Возврат в главное меню...\n");
    }
    else
    {
        printf("\nЕсли размеры матрицы меньше 20 * 20, то также будет распечатана в стандартном виде");
        printf("\nЕсли размеры вектор-строки меньше 20, то также будет распечатана в стандартном виде");

        if (n <= 20)
        {
            printf("\nИсходная матрица:");
            printf("\nКлассический вид:\n");
            {
                for (int i = 0; i < n; i++)
                {
                    for(int j = 0; j < m; j++)
                        printf("%d ", matr_classic[i][j]);
                    printf("\n");
                }
            }
        }

        tja *tmp = *head;
        if (tmp != NULL && tmp->value != 0)
        {
            printf("\nИсходная матрица:");
            printf("\nРазреженный вид:\n");
            printf("\nA: ");
            for (int i = 0; i < count_matrix; i++)
                printf("%d ", matrix->a[i]);

            printf("\nIA: ");
            for (int i = 0; i < count_matrix; i++)
                printf("%d ", matrix->ia[i]);

            printf("\nJA: ");
            for (int i = 0; i < count_ja; i++)
                read_head(*head, i);
        }
        else
            printf("\n");

        if (n <= 20)
        {
            printf("\nИсходный вектор-строка:");
            printf("\nКлассический вид:\n");
            for (int i = 0; i < m_vector; i++)
                printf("%d ", vector_classic[0][i]);

        }
        if (count_vector != 0)
        {
            printf("\nИсходный вектор-строка:");
            printf("\nРазреженный вид:\n");
            printf("\nA: ");
            for (int i = 0; i < count_vector; i++)
                printf("%d ", vector->a[i]);

            printf("\nJA: ");
            for (int i = 0; i < count_vector; i++)
                printf("%d ", vector->ja[i]);
        }
        else
            printf("\n");
    }
}

void result_print(int **result, int n, int m, matrix **matrix, tja **head)
{
    int count = 0;
    int k = 0;
    int ja = 0;
    int count_ja = 0;

    printf("\nВывод результата умножения вектора-строки на матрицу: \n");
    if (n <= 20)
    {
        printf("\nСтандартный вид:\n");
        for (int j = 0; j < m; j++)
            printf("%d ", result[0][j]);
    }

    for (int i = 0; i < m; i++)
        if (result[0][i] != 0)
            count++;

    malloc_struct_matrix(matrix, count);

    for (int i = 0; i < m; i++)
        if (result[0][i] != 0)
        {
            (*matrix)->a[k] = result[0][i];
            (*matrix)->ia[k] = i + 1;
            ja = k + 1;
            k++;
        }
    count_ja++;
    add_elem(head, ja);

    tja *tmp = *head;
    if (tmp != NULL)
    {
        printf("\nРазреженный вид:\n");
        printf("\nA: ");
        for (int i = 0; i < count; i++)
            printf("%d ", (*matrix)->a[i]);

        printf("\nIA: ");
        for (int i = 0; i < count; i++)
            printf("%d ", (*matrix)->ia[i]);

        printf("\nJA: ");
        for (int i = 0; i < count_ja; i++)
            read_head(*head, i);
    }
    else
        printf("\n");
}