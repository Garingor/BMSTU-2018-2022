#include "memory.h"

int malloc_struct_matrix(matrix **mat, int count)
{
    if (count == 0)
        return SUCCESS;
    matrix *check_malloc_str = NULL;
    int * check_realloc_a = NULL;
    int * check_realloc_ia = NULL;

    check_malloc_str = malloc(sizeof(matrix));
    if (check_malloc_str == NULL)
    {
        printf("Не удалось выделить память под структуру разреженной матрицы\nВозврат в главное меню...\n");
        return INV_MALLOC_STRUCT;
    }
    else
        *mat = check_malloc_str;

    check_realloc_a = NULL;
    check_realloc_a = malloc(count * sizeof(int));
    if (check_realloc_a == NULL)
    {
        printf("Не удалось выделить память под вектор A\nВозврат в главное меню...\n");
        return INV_MALLOC_MATR;
    }
    else
        (*mat)->a = check_realloc_a;

    check_realloc_ia = NULL;
    check_realloc_ia = malloc(count * sizeof(int));
    if (check_realloc_ia == NULL)
    {
        printf("Не удалось выделить память под вектор IA\nВозврат в главное меню...\n");
        return INV_MALLOC_MATR;
    }
    else
        (*mat)->ia = check_realloc_ia;

    return SUCCESS;
} //

void free_struct_matrix(matrix **mat)
{
    free((*mat)->a);
    free((*mat)->ia);
    free(*mat);
    *mat = NULL;
} //

int malloc_struct_vector(vector **vec, int count)
{
    if (count == 0)
        return SUCCESS;
    vector *check_malloc_str;
    int * check_realloc_a = NULL;
    int * check_realloc_ja = NULL;

    check_malloc_str = malloc(sizeof(vector));
    if (check_malloc_str == NULL)
    {
        printf("Не удалось выделить память под структуру вектора-строки\nВозврат в главное меню...\n");
        return INV_MALLOC_STRUCT;
    }
    else
        *vec = check_malloc_str;

    check_realloc_ja = NULL;
    check_realloc_ja = malloc(count * sizeof(int));
    if (check_realloc_ja == NULL)
    {
        printf("Не удалось выделить память под вектор JA\nВозврат в главное меню...\n");
        return INV_MALLOC_MATR;
    }
    else
        (*vec)->ja = check_realloc_ja;

    check_realloc_a = NULL;
    check_realloc_a = malloc(count * sizeof(int));
    if (check_realloc_a == NULL)
    {
        printf("Не удалось выделить память под вектор AN\nВозврат в главное меню...\n");
        return INV_MALLOC_MATR;
    }
    else
        (*vec)->a = check_realloc_a;

    return SUCCESS;
} //

void free_struct_vector(vector **vec)
{
    free((*vec)->ja);
    free((*vec)->a);
    free(*vec);
    *vec = NULL;
} //

int add_elem(tja **head, int value)
{
    if (*head == NULL)
    {
        *head = malloc(sizeof(tja));

        if (*head == NULL)
        {
            printf("Не удалось выделить память под список JA\nВозврат в главное меню...\n");
            return INV_MALLOC_MATR;
        }

        (*head)->value = value;
        (*head)->next = NULL;

        return SUCCESS;
    }

    tja *tmp = *head; // идем с головы пока не встретим конечный элемент

    while(tmp->next != NULL)
    {
        tmp = tmp->next;
    }


    tja *ja; // создаем новый блок
    ja = malloc(sizeof(tja));
    if (ja == NULL)
    {
        printf("Не удалось выделить память под блок JA\nВозврат в главное меню...\n");
        return INV_MALLOC_MATR;
    }

    ja->value = value; // заполняем
    ja->next = NULL;
    tmp->next = ja; // уже в предпоследний помещаем указатель на последний

    return SUCCESS;
} //

void free_head(tja **ja_mas) //
{
    tja *prev = NULL;
    while ((*ja_mas)->next)
    {
        prev = *ja_mas;
        *ja_mas = (*ja_mas)->next;
        free(prev);
    }
    free(*ja_mas);
    *ja_mas = NULL;
}

void read_head(tja *ja_mas, int max)
{
    int i = 0;
    tja *head = ja_mas;
    while (i < max)
    {
        head = head->next;
        i++;
    }
    printf("%d ", head->value);

}

int mem_alloc_matrix_classic(int ***mat, int n, int m)
{
    *mat = malloc(sizeof(int *) * n);

    if (*mat == NULL)
        return INV_MALLOC_MATR_C;

    for (int i = 0; i < n; i++)
    {
        (*mat)[i] = malloc(sizeof(int) * m);

        if ((*mat)[i] == NULL)
            return INV_INPUT_MATR_C;
    }

    return SUCCESS;
}

void free_matrix_classic(int ***matrix, int n)
{
    for (int i = 0; i < n; i++)
        free((*matrix)[i]);
    free(*matrix);
}

int mem_alloc_vector_classic(int ***vector, int m)
{
    (*vector) = malloc(sizeof(int *));

    if ((*vector) == NULL)
        return INV_INPUT_VECTOR_C;


    (*vector)[0] = (int *)malloc(sizeof(int) * m);

    if ((*vector)[0] == NULL)
        return INV_INPUT_VECTOR_C;



    return SUCCESS;
}

void free_vector_classic(int ***vector, int m)
{
    free((*vector)[0]);
    free(*vector);
}
