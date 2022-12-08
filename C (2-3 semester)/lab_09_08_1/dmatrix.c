#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include "const.h"

void change_min_matrix(int64_t *min, int64_t value, int *i1, int *j1, int i, int j)
{
    *min = value;
    *i1 = i;
    *j1 = j;
}

void detect_min_matrix(int64_t **matr, int n, int m, int *i1, int *j1)
{
    int64_t min = matr[0][0];
    *i1 = 0;
    *j1 = 0;

    for (int j = 0; j < m; j++)
        for (int i = 0; i < n; i++)
            if (matr[i][j] <= min)
                change_min_matrix(&min, matr[i][j], i1, j1, i, j);
}

int delete_min_matrix(int64_t ***matr, int *n, int *m)
{
    int i1;
    int j1;

    while ((*n) != (*m))
    {
        detect_min_matrix(*matr, *n, *m, &i1, &j1);
        if ((*n) > (*m))
            if (delete_line_matrix(matr, n, i1) != SUCCESS)
                return INV_ADDRESS;
        if ((*n) < (*m))
            if (delete_column_matrix(*matr, *n, m, j1) != SUCCESS)
                return INV_ADDRESS;
    }

    return SUCCESS;
}

int delete_line_matrix(int64_t ***matr, int *n, int m_i)
{
    int64_t **matr_check = NULL;

    free((*matr)[m_i]);

    for (int i = m_i; i < (*n) - 1; i++)
        (*matr)[i] = (*matr)[i + 1];

    (*n)--;

    matr_check = realloc(*matr, sizeof(int64_t *) * (*n));

    if (matr_check == NULL)
        return INV_ADDRESS;
    else
        *matr = matr_check;

    return SUCCESS;
}

int delete_column_matrix(int64_t **matr, int n, int *m, int m_j)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = m_j; j < (*m) - 1; j++)
            matr[i][j] = matr[i][j + 1];

        matr[i] = realloc(matr[i], sizeof(int64_t) * ((*m) - 1));

        if (matr[i] == NULL)
            return INV_ADDRESS;
    }

    (*m)--;

    return SUCCESS;
}

int insert_new_line(int64_t ***matr, int *n, int m, int n1)
{
    double average_geom;
    int64_t **matr_check = NULL;
    int count;

    while (n1 > *n)
    {
        matr_check = realloc(*matr, ((*n) + 1) * sizeof(int64_t *));

        if (matr_check == NULL)
            return INV_ADDRESS;
        else
            *matr = matr_check;

        (*matr)[*n] = (int64_t *)malloc(m * sizeof(int64_t));

        if ((*matr)[*n] == NULL)
            return INV_ADDRESS;

        for (int j = 0; j < m; j++)
        {
            average_geom = 1.0;
            count = 0;
            for (int i = 0; i < *n; i++)
            {
                average_geom *= llabs((*matr)[i][j]);
                count++;
            }
            average_geom = pow(average_geom, 1.0 / count);
            (*matr)[*n][j] = floor(average_geom);
        }
        (*n)++;
    }

    return SUCCESS;
}

int insert_new_column(int64_t ***matr, int n, int *m, int m1)
{
    int min;

    while (m1 > *m)
    {
        (*m)++;
        for (int i = 0; i < n; i++)
        {
            (*matr)[i] = realloc((*matr)[i], ((*m) * sizeof(int64_t)));
            if ((*matr)[i] == NULL)
                return INV_ADDRESS;
        }

        for (int i = 0; i < n; i++)
        {
            min = (*matr)[i][0];
            for (int j = 0; j < (*m) - 1; j++)
                if ((*matr)[i][j] < min)
                    min = (*matr)[i][j];
            (*matr)[i][(*m) - 1] = min;
        }
    }

    return SUCCESS;
}

void transpose_matr(int64_t **matr, int n)
{
    int64_t temp;

    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            temp = matr[i][j];
            matr[i][j] = matr[j][i];
            matr[j][i] = temp;
        }
}

void multiplication_matr(int64_t **matr, int64_t **matr1, int64_t **matr_c, int n, int count)
{
    int count_multiplication = 0;
    while (count_multiplication < count)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                for (int k = 0; k < n; k++)
                    matr_c[i][j] += matr[i][k] * matr1[j][k];

        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                matr[i][j] = matr_c[i][j];

        memset_matrix(matr_c, n);

        count_multiplication++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr_c[i][j] = matr[i][j];
}

void copy_matr_to_matr_c(int64_t **matr, int64_t **matr_c, int n, int *degree)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr_c[i][j] = matr[i][j];
    (*degree)--;
}

void unit_matrix(int64_t **matr, int n)
{
    memset_matrix(matr, n);

    for (int i = 0; i < n; i++)
        matr[i][i] = 1;
}

void memset_matrix(int64_t **matr, int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matr[i][j] = 0;
}

void exponentiation(int alfa, int beta, int64_t ***mas_buffer, int n, int m, int64_t **matr_a, int64_t **matr_b)
{
    if (alfa != 0)
    {
        copy_matr_to_matr_c(matr_a, mas_buffer[0], n, &alfa);
        transpose_matr(matr_a, n);
        multiplication_matr(mas_buffer[0], matr_a, mas_buffer[2], n, alfa);
    }
    else
        unit_matrix(mas_buffer[2], n);

    if (beta != 0)
    {
        copy_matr_to_matr_c(matr_b, mas_buffer[1], n, &beta);
        transpose_matr(matr_b, n);
        multiplication_matr(mas_buffer[1], matr_b, mas_buffer[3], n, beta);
        transpose_matr(mas_buffer[3], n);
        multiplication_matr(mas_buffer[2], mas_buffer[3], mas_buffer[4], n, 1);
        print_matrix(mas_buffer[4], n, m);
    }
    else
    {
        unit_matrix(matr_b, n);
        transpose_matr(matr_b, n);
        multiplication_matr(mas_buffer[2], matr_b, mas_buffer[4], n, 1);
        print_matrix(mas_buffer[4], n, m);
    }
}
