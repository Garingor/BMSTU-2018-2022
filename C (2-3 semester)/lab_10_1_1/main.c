#include "const.h"
#include <string.h>
#include <ctype.h>
#include "input_output_struct.h"
#include "struct_memory.h"
#include "utilities.h"

int main()
{
    int count_line = 10;
    int count_field = 10;
    char key[MAX_LINE];
    char *filename = "kids.txt";
    schoolboy **person = NULL;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return INV_MALLOC;

    if (input_struct(&person, &count_line, &count_field) != SUCCESS)
    {
        free_struct(&person, count_line, count_field);
        return INV_DATA;
    }

    if (delete_old_girls(&person, &count_line, &count_field) != SUCCESS)
    {
        free_struct(&person, count_line, count_field);
        return INV_MALLOC;
    }

    if (insert_mark(person, count_line) != SUCCESS)
    {
        free_struct(&person, count_line, count_field);
        return INV_ADD_MARK;
    }

    if (input_key(key) != SUCCESS)
    {
        free_struct(&person, count_line, count_field);
        return INV_DATA;
    }

    choice_key(person, key, count_line);

    output_struct(filename, person, count_line);

    free_struct(&person, count_line, count_field);

    return SUCCESS;
}
