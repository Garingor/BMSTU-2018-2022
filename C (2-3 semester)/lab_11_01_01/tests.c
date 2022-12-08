#include "const.h"
#include "my_snprintf.h"
#include "test_utills.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int test_spec_d()
{
    char *buffer = calloc(LEN_STR, sizeof(char));
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int res = snprintf(buffer, LEN_STR, "/%d-%d-%d/", INT_MAX, INT_MIN, 0);
    int my_res = my_snprintf(my_buffer, LEN_STR, "/%d-%d-%d/", INT_MAX, INT_MIN, 0);

    int result = print_log("test_spec_d", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(buffer);
    free(my_buffer);

    return result;
}

int test_spec_s()
{
    char *buffer = calloc(LEN_STR, sizeof(char));
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int res = snprintf(buffer, LEN_STR, "/%s-%s/", "10", "10");
    int my_res = my_snprintf(my_buffer, LEN_STR, "/%s-%s/", "10", "10");

    int result = print_log("test_spec_s", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(buffer);
    free(my_buffer);

    return result;
}

int test_spec_lo()
{
    char *buffer = calloc(LEN_STR, sizeof(char));
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    unsigned long int a = 0;
    int res = snprintf(buffer, LEN_STR, "/%lo-%lo-%lo/", ULONG_MAX, ULONG_MAX, a);
    int my_res = my_snprintf(my_buffer, LEN_STR, "/%lo-%lo-%lo/", ULONG_MAX, ULONG_MAX, a);

    int result = print_log("test_spec_lo", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(buffer);
    free(my_buffer);

    return result;
}

int fill_uncorrect_buf_size_spec_d()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int a = 1234;

    int res = 4;
    char buffer[2] = "1";

    int my_res = my_snprintf(my_buffer, 2, "%d", a);

    int result = print_log("fill_uncorrect_buf_size_spec_d", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int fill_uncorrect_buf_size_spec_s()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    char a[5] = "1234";

    int res = 4;
    char buffer[2] = "1";

    int my_res = my_snprintf(my_buffer, 2, "%s", a);

    int result = print_log("fill_uncorrect_buf_size_spec_s", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int fill_uncorr_buf_size_spec_lo()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int res = 22;
    char buffer[2] = "1";

    int my_res = my_snprintf(my_buffer, 2, "%lo", ULONG_MAX);

    int result = print_log("fill_uncorrect_buf_size_spec_lo", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int fill_uncorr_buf_size()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int a = 1234;
    char b[5] = "1234";

    char buffer[2] = "1";
    int res = 16;

    int my_res = my_snprintf(my_buffer, 2, "1234%lo%d%s", a, a, b);

    int result = print_log("fill_uncorr_buf_size", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int invalid_spec_lo()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    char buffer[2] = "a";
    int res = 1;

    int my_res = my_snprintf(my_buffer, 3, "%la");

    int result = print_log("invalid_spec_lo", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int inv_buf_pointer()
{
    char *my_buffer = NULL;

    int a = 1234;
    char b[5] = "1234";

    int res = 16;
    char buffer[1] = "";

    int my_res = my_snprintf(my_buffer, 2, "1234%lo%d%s", a, a, b);

    int result = print_log("inv_buf_pointer", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int inv_size_buffer()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int a = 1234;

    int res = 4;
    char buffer[2] = "1";

    int my_res = my_snprintf(my_buffer, 2, "%d", a);

    int result = print_log("inv_size_buffer", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int zero_size_buffer()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    int a = 1234;

    int res = 4;
    char buffer[1] = "";

    int my_res = my_snprintf(my_buffer, 0, "%d", a);

    int result = print_log("zero_size_buffer", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int inv_spec_lo_inv_buffer()
{
    char *my_buffer = NULL;

    char buffer[2] = "";
    int res = 1;

    int my_res = my_snprintf(my_buffer, 3, "%la");

    int result = print_log("inv_spec_lo_inv_buffer", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    return result;
}

int spec_not_variant()
{
    char *my_buffer = calloc(LEN_STR, sizeof(char));

    char buffer[2] = "X";
    int res = 1;

    int my_res = my_snprintf(my_buffer, 3, "%X");

    int result = print_log("spec_not_variant", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    free(my_buffer);

    return result;
}

int spec_not_variant_inv_buffer()
{
    char *my_buffer = NULL;

    char buffer[2] = "X";
    int res = 1;

    int my_res = my_snprintf(my_buffer, 3, "%X");

    int result = print_log("spec_not_variant_inv_buffer", buffer, my_buffer, res, my_res,
    compare_result(buffer, my_buffer, res, my_res));

    return result;
}

int main()
{
    int failed_test = 0;

    failed_test = test_spec_d()
        + test_spec_s()
        + test_spec_lo()
        + fill_uncorrect_buf_size_spec_d()
        + fill_uncorrect_buf_size_spec_s()
        + fill_uncorr_buf_size_spec_lo()
        + fill_uncorr_buf_size()
        + invalid_spec_lo()
        + inv_buf_pointer()
        + inv_size_buffer()
        + zero_size_buffer()
        + inv_spec_lo_inv_buffer()
        + spec_not_variant()
        + spec_not_variant_inv_buffer();

    printf("\n\n%d FAILED TESTS\n", failed_test);

    return SUCCESS;
}
