#include "check_size.h"
#include "errors_processing.h"

int check_size_read(int size_read, int right_size)
{
    int error = SUCCESS;

    if (size_read != right_size)
    {
        error = INV_SIZE_READ;
    }

    return error;
}

int check_size(int size)
{
    int error = SUCCESS;

    if (size < 1)
    {
        error = INV_SIZE;
    }

    return error;
}

int check_scanf(int size_read, int right_size_read, int size)
{
    int error = check_size_read(size_read, right_size_read);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        error = check_size(size);
    }

    return error;
}
