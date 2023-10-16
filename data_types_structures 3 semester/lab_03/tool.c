#include "tool.h"
#include "const.h"
#include "memory.h"
#include "input.h"
#include "output.h"

int multiplication_matrix_vector_sparse(matrix *matr, tja *head,int **vector_classic, int ***result, int m, int count_elem)
{
    mem_alloc_matrix_classic(result, 1, m);

    int i = 0;
    tja *tmp = head;
    clock_t begin = clock();
    while (tmp->next && i != m)
    {
        (*result)[0][i] = 0;
        for (int j = tmp->value; j < tmp->next->value; j++)
            (*result)[0][i] += matr->a[j - 1] * vector_classic[0][matr->ia[j - 1]];
        i++;
        tmp = tmp->next;
    }
    for (int j = tmp->value; j < count_elem; j++)
        (*result)[0][i] += matr->a[j] * vector_classic[0][matr->ia[j]];
    clock_t end = clock();
    return (int) (end - begin);
}

int multiplication_matrix_vector_classic(int **matrix_classic, int **vector_classic, int ***result, int n, int m, int *count_elem)
{
    int k = 0;
    mem_alloc_matrix_classic(result, 1, m);
    (*count_elem) = 0;

    for (int i = 0; i < m; i++)
        (*result)[0][i] = 0;

    clock_t begin = clock();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            (*result)[0][k] += matrix_classic[j][i] * vector_classic[0][j];
        k++;
    }
    clock_t end = clock();

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix_classic[i][j] != 0)
                (*count_elem)++;

    return (int) (end - begin);
}

void test_memory()
{
    int **matrix_classic = NULL;
    int **vector_classic = NULL;
    int **result;
    int count_ja = 0;
    vector *vector = NULL;
    matrix *matr = NULL;
    int count_matr;
    int count_vect;
    int count_elem = 0;
    tja *head = NULL;
    
    int time_1_c = 0, time_1_s = 0,
           time_2_c = 0, time_2_s = 0,
           time_3_c = 0, time_3_s = 0,
           time_4_c = 0, time_4_s = 0,
           time_5_c = 0, time_5_s = 0,
           time_6_c = 0, time_6_s = 0;
    
    int memory_1_c = 0, memory_2_c = 0, memory_3_c = 0, memory_4_c = 0, memory_5_c = 0, memory_6_c = 0;
    int memory_1_s = 0, memory_2_s = 0, memory_3_s = 0, memory_4_s = 0, memory_5_s = 0, memory_6_s = 0;
    mem_alloc_matrix_classic(&matrix_classic, 1000, 1000);
    mem_alloc_vector_classic(&vector_classic, 1000);
    mem_alloc_matrix_classic(&result, 1, 1000);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 1000,
                   1000, 1000, &count_matr, &count_vect, 0.0, 0.0, &count_ja);

    time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 1000, 1000, &count_elem);
    time_1_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 1000, count_elem);
    memory_1_c = sizeof(*matrix_classic) * 1000 * 1000 + sizeof(vector_classic) * 1000;
    memory_1_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;
    free_matrix_classic(&matrix_classic, 1000);
    free_vector_classic(&vector_classic, 1000);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);



    mem_alloc_matrix_classic(&matrix_classic, 1000, 1000);
    mem_alloc_vector_classic(&vector_classic, 1000);
    mem_alloc_matrix_classic(&result, 1000, 1000);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 1000,
             1000, 1000, &count_matr, &count_vect, 20.0, 20.0, &count_ja);

    time_2_c = time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 1000, 1000, &count_elem);
    time_2_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 1000, count_elem);
    memory_2_c = sizeof(*matrix_classic) * 1000 * 1000 + sizeof(vector_classic) * 1000;
    memory_2_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 1000);
    free_vector_classic(&vector_classic, 1000);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 1000, 1000);
    mem_alloc_vector_classic(&vector_classic, 1000);
    mem_alloc_matrix_classic(&result, 1000, 1000);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 1000,
             1000, 1000, &count_matr, &count_vect, 40.0, 40.0, &count_ja);

    time_3_c = time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 1000, 1000, &count_elem);
    time_3_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 1000, count_elem);
    memory_3_c = sizeof(*matrix_classic) * 1000 * 1000 + sizeof(vector_classic) * 1000;
    memory_3_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 1000);
    free_vector_classic(&vector_classic, 1000);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 1000, 1000);
    mem_alloc_vector_classic(&vector_classic, 1000);
    mem_alloc_matrix_classic(&result, 1000, 1000);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 1000,
             1000, 1000, &count_matr, &count_vect, 60.0, 60.0, &count_ja);

    time_4_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 1000, 1000, &count_elem);
    time_4_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 1000, count_elem);
    memory_4_c = sizeof(*matrix_classic) * 1000 * 1000 + sizeof(vector_classic) * 1000;
    memory_4_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 1000);
    free_vector_classic(&vector_classic, 1000);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 1000, 1000);
    mem_alloc_vector_classic(&vector_classic, 1000);
    mem_alloc_matrix_classic(&result, 1000, 1000);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 1000,
             1000, 1000, &count_matr, &count_vect, 80.0, 80.0, &count_ja);

    time_5_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 1000, 1000, &count_elem);
    time_5_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 1000, count_elem);
    memory_5_c = sizeof(*matrix_classic) * 1000 * 1000 + sizeof(vector_classic) * 1000;
    memory_5_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 1000);
    free_vector_classic(&vector_classic, 1000);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 1000, 1000);
    mem_alloc_vector_classic(&vector_classic, 1000);
    mem_alloc_matrix_classic(&result, 1000, 1000);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 1000,
             1000, 1000, &count_matr, &count_vect, 90.0, 90.0, &count_ja);
    
    time_6_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 1000, 1000, &count_elem);
    time_6_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 1000, count_elem);
    memory_6_c = sizeof(*matrix_classic) * 1000 * 1000 + sizeof(vector_classic) * 1000;
    memory_6_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;
    
    free_matrix_classic(&matrix_classic, 1000);
    free_vector_classic(&vector_classic, 1000);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);


    
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf("|Размер матрица и |Процент разреж-   |Время умн.(в тиках процессора)|             Память           |\n");
    printf("|вектора-строки   |енности матр и в/с|Обычная        |  Разреженная |Обычная        |  Разреженная |\n");
    printf("| 1x1000 1000x1000|        0         |%15d|%14d|%15d|%14d|\n", time_1_c, time_1_s * 3, memory_1_c, memory_1_s);
    printf("|                 |        20        |%15d|%14d|%15d|%14d|\n", time_2_c, time_2_s * 3, memory_2_c, memory_2_s);
    printf("|                 |        40        |%15d|%14d|%15d|%14d|\n", time_3_c, time_3_s * 3, memory_3_c, memory_3_s);
    printf("|                 |        60        |%15d|%14d|%15d|%14d|\n", time_4_c, time_4_s * 3, memory_4_c, memory_4_s);
    printf("|                 |        80        |%15d|%14d|%15d|%14d|\n", time_5_c, time_5_s * 3, memory_5_c, memory_5_s);
    printf("|                 |        90        |%15d|%14d|%15d|%14d|\n", time_6_c, time_6_s * 3, memory_6_c, memory_6_s);

    mem_alloc_matrix_classic(&matrix_classic, 100, 100);
    mem_alloc_vector_classic(&vector_classic, 100);
    mem_alloc_matrix_classic(&result, 1, 100);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 100,
             100, 100, &count_matr, &count_vect, 0.0, 0.0, &count_ja);

    time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 100, 100, &count_elem);
    time_1_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 100, count_elem);
    memory_1_c = sizeof(*matrix_classic) * 100 * 100 + sizeof(vector_classic) * 100;
    memory_1_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;
    free_matrix_classic(&matrix_classic, 100);
    free_vector_classic(&vector_classic, 100);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 100, 100);
    mem_alloc_vector_classic(&vector_classic, 100);
    mem_alloc_matrix_classic(&result, 100, 100);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 100,
             100, 100, &count_matr, &count_vect, 20.0, 20.0, &count_ja);

    time_2_c = time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 100, 100, &count_elem);
    time_2_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 100, count_elem);
    memory_2_c = sizeof(*matrix_classic) * 100 * 100 + sizeof(vector_classic) * 100;
    memory_2_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 100);
    free_vector_classic(&vector_classic, 100);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 100, 100);
    mem_alloc_vector_classic(&vector_classic, 100);
    mem_alloc_matrix_classic(&result, 100, 100);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 100,
             100, 100, &count_matr, &count_vect, 40.0, 40.0, &count_ja);

    time_3_c = time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 100, 100, &count_elem);
    time_3_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 100, count_elem);
    memory_3_c = sizeof(*matrix_classic) * 100 * 100 + sizeof(vector_classic) * 100;
    memory_3_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 100);
    free_vector_classic(&vector_classic, 100);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 100, 100);
    mem_alloc_vector_classic(&vector_classic, 100);
    mem_alloc_matrix_classic(&result, 100, 100);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 100,
             100, 100, &count_matr, &count_vect, 60.0, 60.0, &count_ja);

    time_4_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 100, 100, &count_elem);
    time_4_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 100, count_elem);
    memory_4_c = sizeof(*matrix_classic) * 100 * 100 + sizeof(vector_classic) * 100;
    memory_4_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 100);
    free_vector_classic(&vector_classic, 100);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 100, 100);
    mem_alloc_vector_classic(&vector_classic, 100);
    mem_alloc_matrix_classic(&result, 100, 100);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 100,
             100, 100, &count_matr, &count_vect, 80.0, 80.0, &count_ja);

    time_5_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 100, 100, &count_elem);
    time_5_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 100, count_elem);
    memory_5_c = sizeof(*matrix_classic) * 100 * 100 + sizeof(vector_classic) * 100;
    memory_5_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 100);
    free_vector_classic(&vector_classic, 100);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 100, 100);
    mem_alloc_vector_classic(&vector_classic, 100);
    mem_alloc_matrix_classic(&result, 100, 100);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 100,
             100, 100, &count_matr, &count_vect, 90.0, 90.0, &count_ja);

    time_6_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 100, 100, &count_elem);
    time_6_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 100, count_elem);
    memory_6_c = sizeof(*matrix_classic) * 100 * 100 + sizeof(vector_classic) * 100;
    memory_6_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 100);
    free_vector_classic(&vector_classic, 100);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);


    printf("| 1x100 100x100   |        0         |%15d|%14d|%15d|%14d|\n", time_1_c, time_1_s * 3, memory_1_c, memory_1_s);
    printf("|                 |        20        |%15d|%14d|%15d|%14d|\n", time_2_c, time_2_s * 3, memory_2_c, memory_2_s);
    printf("|                 |        40        |%15d|%14d|%15d|%14d|\n", time_3_c, time_3_s * 3, memory_3_c, memory_3_s);
    printf("|                 |        60        |%15d|%14d|%15d|%14d|\n", time_4_c, time_4_s * 3, memory_4_c, memory_4_s);
    printf("|                 |        80        |%15d|%14d|%15d|%14d|\n", time_5_c, time_5_s * 3, memory_5_c, memory_5_s);
    printf("|                 |        90        |%15d|%14d|%15d|%14d|\n", time_6_c, time_6_s * 3, memory_6_c, memory_6_s);


    mem_alloc_matrix_classic(&matrix_classic, 10, 10);
    mem_alloc_vector_classic(&vector_classic, 10);
    mem_alloc_matrix_classic(&result, 1, 10);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 10,
             10, 10, &count_matr, &count_vect, 0.0, 0.0, &count_ja);

    time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 10, 10, &count_elem);
    time_1_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 10, count_elem);
    memory_1_c = sizeof(*matrix_classic) * 10 * 10 + sizeof(vector_classic) * 10;
    memory_1_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;
    free_matrix_classic(&matrix_classic, 10);
    free_vector_classic(&vector_classic, 10);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 10, 10);
    mem_alloc_vector_classic(&vector_classic, 10);
    mem_alloc_matrix_classic(&result, 10, 10);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 10,
             10, 10, &count_matr, &count_vect, 20.0, 20.0, &count_ja);

    time_2_c = time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 10, 10, &count_elem);
    time_2_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 10, count_elem);
    memory_2_c = sizeof(*matrix_classic) * 10 * 10 + sizeof(vector_classic) * 10;
    memory_2_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 10);
    free_vector_classic(&vector_classic, 10);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 10, 10);
    mem_alloc_vector_classic(&vector_classic, 10);
    mem_alloc_matrix_classic(&result, 10, 10);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 10,
             10, 10, &count_matr, &count_vect, 40.0, 40.0, &count_ja);

    time_3_c = time_1_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 10, 10, &count_elem);
    time_3_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 10, count_elem);
    memory_3_c = sizeof(*matrix_classic) * 10 * 10 + sizeof(vector_classic) * 10;
    memory_3_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 10);
    free_vector_classic(&vector_classic, 10);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 10, 10);
    mem_alloc_vector_classic(&vector_classic, 10);
    mem_alloc_matrix_classic(&result, 10, 10);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 10,
             10, 10, &count_matr, &count_vect, 60.0, 60.0, &count_ja);

    time_4_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 10, 10, &count_elem);
    time_4_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 10, count_elem);
    memory_4_c = sizeof(*matrix_classic) * 10 * 10 + sizeof(vector_classic) * 10;
    memory_4_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 10);
    free_vector_classic(&vector_classic, 10);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 10, 10);
    mem_alloc_vector_classic(&vector_classic, 10);
    mem_alloc_matrix_classic(&result, 10, 10);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 10,
             10, 10, &count_matr, &count_vect, 80.0, 80.0, &count_ja);

    time_5_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 10, 10, &count_elem);
    time_5_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 10, count_elem);
    memory_5_c = sizeof(*matrix_classic) * 10 * 10 + sizeof(vector_classic) * 10;
    memory_5_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 10);
    free_vector_classic(&vector_classic, 10);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);
    free_head(&head);

    mem_alloc_matrix_classic(&matrix_classic, 10, 10);
    mem_alloc_vector_classic(&vector_classic, 10);
    mem_alloc_matrix_classic(&result, 10, 10);

    generate(&matr, &vector, &head, matrix_classic, vector_classic, 10,
             10, 10, &count_matr, &count_vect, 90.0, 90.0, &count_ja);

    time_6_c = multiplication_matrix_vector_classic(matrix_classic, vector_classic, &result, 10, 10, &count_elem);
    time_6_s = multiplication_matrix_vector_sparse(matr, head, vector_classic,  &result, 10, count_elem);
    memory_6_c = sizeof(*matrix_classic) * 10 * 10 + sizeof(vector_classic) * 10;
    memory_6_s = sizeof(matr->a) * count_matr +  sizeof(matr->ia) * count_matr + sizeof(head->value) * count_ja + + sizeof(head->next) * count_ja + sizeof(vector) * count_vect;

    free_matrix_classic(&matrix_classic, 10);
    free_vector_classic(&vector_classic, 10);
    free_matrix_classic(&result, 1);
    free_struct_vector(&vector);
    free_struct_matrix(&matr);



    printf("| 1x10 10x10      |        0         |%15d|%14d|%15d|%14d|\n", time_1_c, time_1_s * 3, memory_1_c, memory_1_s);
    printf("|                 |        20        |%15d|%14d|%15d|%14d|\n", time_2_c, time_2_s * 3, memory_2_c, memory_2_s);
    printf("|                 |        40        |%15d|%14d|%15d|%14d|\n", time_3_c, time_3_s * 3, memory_3_c, memory_3_s);
    printf("|                 |        60        |%15d|%14d|%15d|%14d|\n", time_4_c, time_4_s * 3, memory_4_c, memory_4_s);
    printf("|                 |        80        |%15d|%14d|%15d|%14d|\n", time_5_c, time_5_s * 3, memory_5_c, memory_5_s);
    printf("|                 |        90        |%15d|%14d|%15d|%14d|\n", time_6_c, time_6_s * 3, memory_6_c, memory_6_s);
    printf(" --------------------------------------------------------------------------------------------------\n");
}

