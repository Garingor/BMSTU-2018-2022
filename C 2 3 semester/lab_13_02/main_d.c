#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

#include "mylib.h"
#include "const.h"

int main()
{
    double *d_arr = NULL;
    double *end = NULL;
    int n = 0;
    int p = 0;
    double aver_val = 0.0;
    double max_val = 0.0;

    void *handle = dlopen("./libdyn.so", RTLD_LAZY);
    if (!handle )
    {
        printf("Cannot open library (%s).\n", dlerror());
        return INV_INPUT;
    }

    int(*input_arr)(int *n, double **d_arr, double **end, int *p) = dlsym(handle, "input_arr");

    if (input_arr(&n, &d_arr, &end, &p) != SUCCESS)
    {
        free(d_arr);
        dlclose(handle);
        return INV_INPUT;
    }

    double(*average_value)(double *d_arr, double *end) = dlsym(handle, "average_value");

    aver_val = average_value(d_arr, end);

    int(*detect_delete_elem)(double **d_arr, double **end, double aver_val) = dlsym(handle, "detect_delete_elem");

    if (detect_delete_elem(&d_arr, &end, aver_val) != SUCCESS)
    {
        free(d_arr);
        dlclose(handle);
        return INV_DEL;
    }

    double(*max_value)(double *d_arr, double *end) = dlsym(handle, "max_value");

    max_val = max_value(d_arr, end);

    int(*insert_max)(double **d_arr, double **end, double aver_val, int p) = dlsym(handle, "insert_max");

    if (insert_max(&d_arr, &end, max_val, p) != SUCCESS)
    {
        free(d_arr);
        dlclose(handle);
        return INV_INPUT;
    }

    void(*print_arr)(double *d_arr, double *end) = dlsym(handle, "print_arr");

    print_arr(d_arr, end);

    free(d_arr);

    dlclose(handle);

    return 0;
}
