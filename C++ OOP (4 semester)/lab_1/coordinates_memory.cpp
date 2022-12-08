#include "coordinates_memory.h"
#include "errors_processing.h"
#include <cstdlib>
#include "check_size.h"

int check_malloc_coord(dot* dots)
{
    int error = SUCCESS;

    if (dots == NULL)
    {
        error = INV_MALLOC_COORD;
    }

    return error;
}

int malloc_coordinates(dot* &dots, int size)
{
    int error = check_size(size);

    if (error != SUCCESS)
    {
        return error;
    }
    else
    {
        dots = (dot*) malloc(size * sizeof(dot));

        error = check_malloc_coord(dots);
    }

    return error;
}

void free_coordinates(dot* &dots)
{
    free(dots);
    dots = NULL;
}