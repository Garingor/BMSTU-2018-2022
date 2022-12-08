#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"
#include "input_output_struct.h"
#include "struct_memory.h"
#include "utilities.h"

int check_surname(char *buffer)
{
    if (strlen(buffer) == 0)
        return INV_SURNAME;

    if (check_trash_symbol(buffer) != SUCCESS)
        return INV_SURNAME;

    return SUCCESS;
}

int check_sex(char *buffer)
{
    char lower_case[MAX_LINE];

    if (strlen(buffer) == 0)
        return INV_SEX;

    lower_case_str(buffer, lower_case);

    if (strcmp(lower_case, "male") != 0 && strcmp(lower_case, "female") != 0)
        return INV_SEX;

    return SUCCESS;
}

int check_format_data(char *buffer)
{
    char *ptr_end = NULL;

    long int year, month, day;

    if (strlen(buffer) > 10 || strlen(buffer) < 8)
        return INV_DATA;
    
    year = strtol(buffer, &ptr_end, 10);
    if (year < 1996 || year > 2013)
        return INV_BIRTH;

    month = strtol(ptr_end + 1, &ptr_end, 10);
    if (month < 1 || month > 12)
        return INV_BIRTH;

    day = strtol(ptr_end + 1, &ptr_end, 10);
    if (day < 1 || day > 31)
        return INV_BIRTH;

    return SUCCESS;
}

int check_birth(char *buffer)
{
    if (strlen(buffer) == 0)
        return INV_BIRTH;

    if (check_format_data(buffer) != SUCCESS)
        return INV_BIRTH;

    return SUCCESS;
}

int check_marks(char *buffer)
{
    int mark = 0;
    int j = 0;
    char *ptr_end = NULL;

    mark = strtol(buffer, &ptr_end, 10);

    while (mark != 0)
    {
        if (mark < 1 || mark > 5)
            return INV_MARKS;

        mark = strtol(ptr_end, &ptr_end, 10);

        j++;
    }

    if (j > 1)
        return INV_MARKS;

    return SUCCESS;
}

int input_surname(schoolboy **person, int i, char *surname_str)
{
    person[i]->surname  = (char *)malloc((strlen(surname_str) + sizeof(char)));

    if (person[i]->surname == NULL)
        return INV_MALLOC;

    strcpy(person[i]->surname , surname_str);

    return SUCCESS;
}

int input_sex(schoolboy **person, int i, char *sex_str)
{
    person[i]->sex  = (char *)malloc((strlen(sex_str) + sizeof(char)));

    if (person[i]->sex == NULL)
        return INV_MALLOC;

    strcpy(person[i]->sex , sex_str);

    return SUCCESS;
}

int input_birth(schoolboy **person, int i, char *bday_str)
{
    person[i]->birth  = (char *)malloc((strlen(bday_str) + sizeof(char)));

    if (person[i]->birth == NULL)
        return INV_MALLOC;

    strcpy(person[i]->birth , bday_str);

    return SUCCESS;
}

int input_marks(schoolboy **person, int i, char *grade_str)
{
    int quantity_marks = 1;
    int mark = 0;
    char *ptr_end = NULL;

    person[i]->marks = (int *)malloc((quantity_marks + 1) * sizeof(int));

    if (person[i]->marks == NULL)
        return INV_MALLOC;

    person[i]->marks[0] = quantity_marks;

    mark = strtol(grade_str, &ptr_end, 10);

    person[i]->marks[1] = mark;

    return SUCCESS;
}

int fill_current_struct(schoolboy **person, int i, char *surname_str, char *sex_str, char *bday_str, char*grade_str)
{
    if (input_surname(person, i, surname_str) != SUCCESS)
        return INV_MALLOC;

    if (input_sex(person, i, sex_str) != SUCCESS)
        return INV_MALLOC;

    if (input_birth(person, i, bday_str) != SUCCESS)
        return INV_MALLOC;

    if (input_marks(person, i, grade_str) != SUCCESS)
        return INV_MALLOC;

    return SUCCESS;
}

int input_struct(schoolboy ***person, int *count, char *surname_str, char *sex_str, char *bday_str, char*grade_str,
        char *str_error)
{
    if (check_surname(surname_str) != SUCCESS)
    {
        input_type_error(str_error, "Invalid username");
        return INV_SURNAME;
    }

    if (check_sex(sex_str) != SUCCESS)
    {
        input_type_error(str_error, "Invalid sex");
        return INV_SEX;
    }

    if (check_birth(bday_str) != SUCCESS)
    {
        input_type_error(str_error, "Invalid birth");
        return INV_BIRTH;
    }

    if (check_marks(grade_str) != SUCCESS)
    {
        input_type_error(str_error, "Invalid marks");
        return INV_MARKS;
    }

    if (realloc_struct(person, *count) != SUCCESS)
    {
        input_type_error(str_error, "Invalid realloc");
        return INV_REALLOC;
    }

    (*count)++;

    if (*count == 1)
    {
        if (malloc_struct(person, *count) != SUCCESS)
        {
            input_type_error(str_error, "Invalid malloc");
            return INV_MALLOC;
        }

    }

    if (malloc_field_struct(person, (*count) - 1) != SUCCESS)
    {
        input_type_error(str_error, "Invalid malloc");
        return INV_MALLOC;
    }

    if (fill_current_struct(*person, (*count) - 1, surname_str, sex_str, bday_str, grade_str) != SUCCESS)
    {
        input_type_error(str_error, "Invalid malloc");
        return INV_MALLOC;
    }

    return SUCCESS;
}

