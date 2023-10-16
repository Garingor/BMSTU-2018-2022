#include <stdio.h>
#include "memory.h"
#include "utills.h"
#include "in_out.h"
#include "const.h"

int main()
{
    int **matr = NULL;
    int **matr_n = NULL;
    int n = 0;

    if (input_size(&n) != SUCCESS)
        return INV_INPUT;

    if (malloc_matr(&matr, n) != SUCCESS)
        return INV_MALLOC;

    if (input_matr(matr, n) != SUCCESS)
    {
        free_matr(&matr, n);
        return INV_INPUT;
    }

    if (malloc_matr_n(&matr_n, n) != SUCCESS)
    {
        free_matr(&matr, n);
        free_matr(&matr_n, n + n - 1);
        return INV_MALLOC;
    }

    alloc_matr(matr_n, n);

    reverse_matr(matr, matr_n, n);

    free_matr(&matr, n);

    output_matr(matr_n, n);

    free_matr(&matr_n, n + n - 1);

    return SUCCESS;
}
