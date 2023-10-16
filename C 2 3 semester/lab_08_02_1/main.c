#include <stdio.h>
#include <stdlib.h>
#include "darray.h"

int main()
{
    double *d_arr = NULL;
    double *end = NULL;
    int n = 0;
    int p = 0;
    double aver_val = 0.0;
    double max_val = 0.0;

    if (input_arr(&n, &d_arr, &end, &p) != SUCCESS)
    {
        free(d_arr);
        return INV_INPUT;
    }

    aver_val = average_value(d_arr, end);

    if (detect_delete_elem(&d_arr, &end, aver_val) != SUCCESS)
    {
        free(d_arr);
        return INV_DEL;
    }

    max_val = max_value(d_arr, end);

    if (insert_max(&d_arr, &end, max_val, p) != SUCCESS)
    {
        free(d_arr);
        return INV_INPUT;
    }

    print_arr(d_arr, end);

    free(d_arr);

    return 0;
}
