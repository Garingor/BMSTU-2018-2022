#include "utills.h"
#include "operation_list.h"
#include "memory_list.h"
#include "const.h"

int main()
{
    char key[3];
    int code_error = 0;

    descriptor_list num_1;
    descriptor_list num_2;
    descriptor_list res;

    init_descriptor_list(&num_1);
    init_descriptor_list(&num_2);
    init_descriptor_list(&res);

    if (scanf_key(key) == INV_KEY)
        return INV_KEY;

    code_error = choice_key(key, &num_1, &num_2, &res);

    free_list(&num_1);
    free_list(&num_2);
    free_list(&res);

    return code_error;
}
