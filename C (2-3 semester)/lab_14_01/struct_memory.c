#include "const.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct_memory.h"

int malloc_field_struct(schoolboy ***person, int count)
{
    (*person)[count] = (schoolboy *)malloc(sizeof(schoolboy));

    if ((*person)[count] == NULL)
    {
        return INV_MALLOC;
    }

    return SUCCESS;
}

int malloc_struct(schoolboy ***person, int count)
{
    *person = (schoolboy **)malloc(sizeof(schoolboy *) * count);

    if (*person == NULL)
    {
        return INV_MALLOC;
    }

    return SUCCESS;
}

int realloc_struct(schoolboy ***person, int count)
{
    schoolboy **check_realloc = NULL;

    check_realloc = (schoolboy **)realloc(*person, sizeof(schoolboy *) * count);

    if (check_realloc == NULL)
    {
        return INV_REALLOC;
    }

    *person = check_realloc;

    return SUCCESS;
}

void free_line(schoolboy ***person, int i)
{
    free((*person)[i]->surname);
    free((*person)[i]->sex);
    free((*person)[i]->birth);
    free((*person)[i]->marks);
    free((*person)[i]);
}

void free_struct(schoolboy ***person, int count)
{
    if (person != NULL)
    {
        for (int i = 0; i < count; i++)
        {
            free_line(person, i);
        }

        free(*person);
    }
}

int realloc_dmas_marks(schoolboy **person, int i)
{
    int *check_realloc = NULL;

    person[i]->marks[0]++;

    check_realloc = (int *)realloc(person[i]->marks, sizeof(int) * (person[i]->marks[0] + 1));

    if (check_realloc == NULL)
        return INV_REALLOC;

    person[i]->marks = check_realloc;

    return SUCCESS;
}

int realloc_line(schoolboy **person, int i)
{
    char *check_realloc = NULL;
    int *check_realloc_marks = NULL;

    check_realloc = (char *)realloc(person[i]->surname, sizeof(char) * strlen(person[i + 1]->surname) + 1);

    if (check_realloc == NULL)
        return INV_MALLOC;

    person[i]->surname = check_realloc;

    check_realloc = (char *)realloc(person[i]->sex, sizeof(char) * strlen(person[i + 1]->sex) + 1);

    if (check_realloc == NULL)
        return INV_MALLOC;

    person[i]->sex = check_realloc;

    check_realloc = (char *)realloc(person[i]->birth, sizeof(char) * strlen(person[i + 1]->birth) + 1);

    person[i]->birth = check_realloc;

    if (check_realloc == NULL)
        return INV_MALLOC;

    check_realloc_marks = (int *)realloc(person[i]->marks, sizeof(int) * (person[i + 1]->marks[0] + 1));

    if (check_realloc_marks == NULL)
        return INV_MALLOC;

    person[i]->marks = check_realloc_marks;

    return SUCCESS;
}

