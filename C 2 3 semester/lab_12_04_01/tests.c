#include "const.h"
#include "operation_list.h"
#include "main_features.h"
#include "tests_utills.h"
#include "memory_list.h"
#include <stdio.h>
#include <limits.h>

int whole_division()
{
    int int_num_1 = 10, int_num_2 = 2;

    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);

    insert_manually(&expected_res, 1, 5, 1);

    division(int_num_1, int_num_2, &res);

    int result = print_log("whole_division", res, expected_res, compare_res(&res, &expected_res));

    free_list(&res);
    free_list(&expected_res);

    return result;
}

int fractional_division()
{
    int int_num_1 = INT_MAX, int_num_2 = 2;

    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);

    division(int_num_1, int_num_2, &res);

    int result = print_log("fractional_division", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&res);
    free_list(&expected_res);

    return result;
}

int squaring_num_test()
{
    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);

    insert_manually(&res, 1, 13, 1);
    squaring_num(&res);

    insert_manually(&expected_res, 1, 13, 2);

    int result = print_log("squaring_num_test", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&res);
    free_list(&expected_res);

    return result;
}

int squaring_empty_list()
{
    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);

    squaring_num(&res);

    int result = print_log("squaring_empty_list", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&res);
    free_list(&expected_res);

    return result;
}

int multiplication_test()
{
    descriptor_list num_1;
    init_descriptor_list(&num_1);
    insert_manually(&num_1, 3, 13, 2, 14, 2, 15, 3);

    descriptor_list num_2;
    init_descriptor_list(&num_2);
    insert_manually(&num_2, 3, 12, 3, 14, 1, 17, 3);

    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);
    insert_manually(&expected_res, 5, 12, 3, 13, 2, 14, 3, 15, 3, 17, 3);

    multiplication(&num_1, &num_2, &res);

    int result = print_log("multiplication_test", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&num_1);
    free_list(&num_2);
    free_list(&res);
    free_list(&expected_res);

    return result;
}

int multiplication_empty_list()
{
    descriptor_list num_1;
    init_descriptor_list(&num_1);

    descriptor_list num_2;
    init_descriptor_list(&num_2);

    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);

    multiplication(&num_1, &num_2, &res);

    int result = print_log("num_expansion_test", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&num_1);
    free_list(&num_2);
    free_list(&res);
    free_list(&expected_res);

    return result;
}

int num_expansion_test()
{
    descriptor_list res;
    init_descriptor_list(&res);
    num_expansion(1, &res, 121);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);
    insert_manually(&expected_res, 1, 11, 2);

    int result = print_log("num_expansion_test", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&res);
    free_list(&expected_res);

    return result;
}

int division_by_zero()
{
    int int_num_1 = 10, int_num_2 = 0;

    descriptor_list res;
    init_descriptor_list(&res);

    descriptor_list expected_res;
    init_descriptor_list(&expected_res);

    division(int_num_1, int_num_2, &res);

    int result = print_log("division_by_zero", res, expected_res,
    compare_res(&res, &expected_res));

    free_list(&res);
    free_list(&expected_res);

    return result;
}

int main()
{
    int failed_test = 0;

    failed_test = whole_division()
        + fractional_division()
        + squaring_num_test()
        + squaring_empty_list()
        + multiplication_test()
        + multiplication_empty_list()
        + num_expansion_test()
        + division_by_zero();

    printf("\n\n%d FAILED TESTS\n", failed_test);

    if (failed_test != 0)
        return INV_CHECK_FUNC;

    return SUCCESS;
}
