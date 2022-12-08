#include "test.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int average_value_in_arr()
{
    double *start = (double*)malloc(5 * sizeof(double));
    double *end = start + 5;
    *start = 1.0;
    *(start + 1) = 2.24;
    *(start + 2) = 3.21;
    *(start + 3) = 100.7;
    *(start + 4) = 25.8;
    double e = 0.01;
    double aver = average_value(start, end);
    free(start);
    if (fabs(aver - 26.59) > e)
    {
        printf("подсчет среднего значения в массиве: FAILED\n");
        printf("ожидалось   = 25.59\n");
        printf("фактическое = %lf\n", aver);
        return 0;
    }
    else
        return 1;
}

int aver_value_in_arr_small_mant()
{
    double *start = (double*)malloc(5 * sizeof(double));
    double *end = start + 5;
    *start = 3e-50;
    *(start + 1) = 1e-10;
    *(start + 2) = 3e-20;
    *(start + 3) = 3.21;
    *(start + 4) = 100.7;
    double e = 0.01;
    double aver = average_value(start, end);
    free(start);
    if (fabs(aver - 20.782000) > e)
    {
        printf("подсчет среднего значения в массиве (элементы с маленькой мантиссой): FAILED\n");
        printf("ожидалось   = 25.59\n");
        printf("фактическое = %lf\n", aver);
        return 0;
    }
    else
        return 1;
}

int formatted_arr()
{
    double *start = (double*)malloc(5 * sizeof(*start));
    double *end = start + 5;
    double e = 0.01;
    *start = 1.0;
    *(start + 1) = 7.2;
    *(start + 2) = 3.2;
    *(start + 3) = 1.3;
    *(start + 4) = 20.4;

    double *start2 = (double*)malloc(3 * sizeof(*start2));
    double *end2 = start2 + 3;

    *start2 = 1.000000;
    *(start2 + 1) = 3.200000;
    *(start2 + 2) = 1.300000;

    double aver = 6.62;
    double *p2 = start2;
    detect_delete_elem(&start, &end, aver);

    if (end - start > end2 - start2)
    {
        free(start);
        free(start2);
        printf("длина отформатированного массива меньше положенного\n");
        return 0;
    }

    for (double *p = start; p < end; p++)
    {
        if (fabs(*p - *p2) > e)
        {
            printf("удаление элементов выше среднего значения в массиве: FAILED\n");
            printf("ожидалось   = 1.000000 3.200000 1.300000\n");
            printf("фактическое = ");
            for (double *p = start; p < end; p++)
            {
                printf("%lf ", *p);
            }
            free(start);
            free(start2);
            return 0;
        }
        p2++;
    }
    free(start);
    free(start2);
    return 1;
}

int max_value_in_massive()
{
    double *start = (double*)malloc(5 * sizeof(double));
    double *end = start + 5;
    double e = 0.01;
    *start = 1.0;
    *(start + 1) = 7.2;
    *(start + 2) = 3.2;
    *(start + 3) = 1.3;
    *(start + 4) = 20.4;

    double max_v = max_value(start, end);
    free(start);
    if (fabs(max_v - 20.4) > e)
    {
        printf("подсчет максимального значения в массиве: FAILED\n");
        printf("ожидалось   = 20.4\n");
        printf("фактическое = %lf\n", max_v);
        return 0;
    }
    else
        return 1;
}

int insert_max_elem_to_start_p_end()
{
    double *start = (double*)malloc(5 * sizeof(*start));
    double *end = start + 5;
    double e = 0.01;
    int p = 2;
    double max_v = 220.4;
    *start = 113.1;
    *(start + 1) = 12.0;
    *(start + 2) = 33.22;
    *(start + 3) = 0.3;
    *(start + 4) = 220.4;
    double *start2 = (double*)malloc(8 * sizeof(*start2));

    *start2 = 220.400000;
    *(start2 + 1) = 113.100000;
    *(start2 + 2) = 12.000000;
    *(start2 + 3) = 220.400000;
    *(start2 + 4) = 33.220000;
    *(start2 + 5) = 0.300000;
    *(start2 + 6) = 220.400000;
    *(start2 + 7) = 220.400000;

    double *p2 = start2;
    insert_max(&start, &end, max_v, p);

    for (double *p = start; p < end; p++)
    {
        if (fabs(*p - *p2) > e)
        {
            printf("вставка элемента в массив: FAILED\n");
            printf("ожидалось   = 220.400000 113.100000 12.000000 220.400000 0.300000 220.400000 220.400000\n");
            printf("фактическое = ");
            for (double *p = start; p < end; p++)
            {
                printf("%lf ", *p);
            }
            free(start);
            free(start2);
            return 0;
        }
        p2++;
    }
    free(start);
    free(start2);
    return 1;
}

int main()
{
    int test = 0;
    test = average_value_in_arr()
        + aver_value_in_arr_small_mant()
        + formatted_arr()
        + max_value_in_massive()
        + insert_max_elem_to_start_p_end();
    printf("\n");
    if (test != 5)
    {
        printf("lab_08_02_1: FUNC_TESTING %s(FAILED)%s", RED, RESET);
        return INV_CHECK;
    }
    else
        printf("lab_08_02_1: FUNC_TESTING %s(PASSED)%s", GREEN, RESET);
    printf("\nRESULT: correct %d of 5", test);
    printf("\n\n");
    return SUCCESS;
}
