#include "util.h"
#include "input_output.h"
#include "memory_darr.h"
#include "const.h"
void reverse_arr(int **matr_new, int **matr, int n, int m)
{
    int k = 0;
    int h = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = m - 1 - i; j < m; j++)
        {
            matr[h][k] = matr_new[k][j];
            k++;
        }
        k = 0;
        h++;
    }
}

void find_change_del(int **matr_new, int n, int m, int *i_check)
{
    int min = n;
    int max = 1;

    int min_i = -1;
    int max_i = -1;

    int k = 1;
    int count = m - n;
    if (count < 0)
        count = -count;
    count++;

    int flag_n = 0;
    for (int i = 0; i < n + m - 1; i++)
    {
        if (k < min)
        {
            min = k;
            min_i = i;
        }
        if (k > max)
        {
            max = k;
            max_i = i;
        }

        if (k < n && flag_n == 0)
            k++;
        if (k == n && count > 0)
        {
            count--;
            flag_n = 1
        }
        else
            k--;
    }

    if (max_i == min_i)
    {
        free(matr_new[min_i]);
        for (int i = min_i; i < n + m - 2; i++)
            matr_new[i] = matr_new[i + 1];
    }

    if (max_i != min_i)
    {
        *i_check = min_i;

        int *temp_m = NULL;

        temp_m = realloc(matr_new[min], sizeof(int) * max - min);
        if (temp_m == NULL)
            return INV_REALLOC;

        for (int i = 0; i < max - min; i++)
           matr_new[min_i][min_i + i] = 0;

        temp_m = matr_new[min_i];
        matr_new[min_i] = matr_new[max_i];
        matr_new[max_i] = matr_new[min_i];
    }
}
