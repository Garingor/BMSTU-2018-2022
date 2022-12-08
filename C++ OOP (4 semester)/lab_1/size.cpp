#include "size.h"
#include "errors_processing.h"
#include "check_size.h"

int input_size(int &size, t_stream stream)
{
    int error = check_open_stream(stream);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        int copy_size, right_size_read = 1;

        int size_read = fscanf(stream, "%d", &copy_size);

        error = check_scanf(size_read, right_size_read, copy_size);

        if (error == SUCCESS)
        {
            move_size(size, copy_size);
        }
    }

    return error;
}

void move_size(int &size, int &copy_size)
{
    size = copy_size;
}