#include "file.h"
#include "errors_processing.h"

int open_stream(t_stream &stream, t_filename filename)
{
    int error = SUCCESS;

    stream = fopen(filename, "r");

    if (stream == NULL)
    {
        error = INV_FILE;
    }

    return error;
}

void close_stream(t_stream &stream)
{
    fclose(stream);
}

int check_open_stream(t_stream stream)
{
    int error = SUCCESS;

    if (stream == NULL)
    {
        error = INV_FILE;
    }

    return error;
}