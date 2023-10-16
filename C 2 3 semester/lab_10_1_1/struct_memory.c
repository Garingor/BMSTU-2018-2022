#include "const.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "struct_memory.h"

int malloc_struct(schoolboy ***person, int *count_line, int count_fields)
{
    *person = (schoolboy **)malloc(sizeof(schoolboy *) * count_fields);

    if (*person == NULL)
        return INV_MALLOC;

    for (int i = 0; i < count_fields; i++)
    {
        (*person)[i] = (schoolboy *)malloc(sizeof(schoolboy));
        if ((*person)[i] == NULL)
        {
            *count_line = i;
            return INV_MALLOC;
        }
    }

    return SUCCESS;
}

int realloc_struct(schoolboy ***person, int *count_line, int count_field)
{
    schoolboy **check_realloc = NULL;

    if (count_field < *count_line)
        for (int i = count_field; i < *count_line; i++)
            free((*person)[i]);

    check_realloc = (schoolboy **)realloc(*person, sizeof(schoolboy *) * count_field);

    if (check_realloc == NULL)
        return INV_REALLOC;

    *person = check_realloc;

    if (count_field > *count_line)
        for (int i = *count_line; i < count_field; i++)
        {
            (*person)[i] = (schoolboy *)malloc(sizeof(schoolboy));
            if ((*person)[i] == NULL)
            {
                *count_line = i;
                return INV_MALLOC;
            }
        }

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

void free_struct(schoolboy ***person, int count_line, int count_field)
{
    for (int i = 0; i < count_field; i++)
    {
        free((*person)[i]->surname);
        free((*person)[i]->sex);
        free((*person)[i]->birth);
        free((*person)[i]->marks);
    }

    for (int i = 0; i < count_line; i++)
        free((*person)[i]);

    free(*person);
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

int expansion_struct(schoolboy ***person, int i, int *count_field, int *count_line)
{
    if (i >= *count_field)
    {
        *count_field += 10;
        if (realloc_struct(person, count_line, *count_field) != SUCCESS)
            return INV_REALLOC;
        *count_line += 10;
    }
    return SUCCESS;
}
