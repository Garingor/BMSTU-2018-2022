#include <stdio.h>
#include "const.h"
#include "input_output.h"
#include "memory_darr.h"

int main()
{
    int **matr = NULL;
    int **matr_new = NULL;
    int n = 0, m = 0;
    int i_check = 0;

    if (input_size(&n, &m) != SUCCESS)
        return INV_INPUT;

    if (malloc_darr(&matr, n, m) != SUCCESS)
       return INV_MALLOC;

    if (input_elem(matr, n, m) != SUCCESS)
    {
        free_darr(&matr, n);
        return INV_INPUT;
    }

    if (malloc_darr_new(&matr_new, n, m) != SUCCESS)
       return INV_MALLOC;

    reverse_arr(matr_new, matr, n, m);

    output_darr_new(matr_new, n, m);

    find_change_del(matr_new, n, m, &i_check);

    output_darr_fix(matr_new, n, m, i_check);

    free_darr(&matr, n);

    free_darr(&matr_new, n + m - 1);

    return SUCCESS;
}
