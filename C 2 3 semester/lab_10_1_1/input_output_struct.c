#include "const.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "input_output_struct.h"
#include "struct_memory.h"
#include "utilities.h"

int input_surname(schoolboy **person, char *buffer, int i)
{
    if (strlen(buffer) == 0)
        return INV_SURNAME;

    person[i]->surname = (char *)malloc((strlen(buffer) + sizeof(char)));

    if (person[i]->surname == NULL)
        return INV_MALLOC;

    if (check_trash_symbol(buffer) != SUCCESS)
        return INV_SURNAME;

    strcpy(person[i]->surname, buffer);

    return SUCCESS;
}

int input_sex(schoolboy **person, int i)
{
    char lower_case[MAX_LINE];
    char buffer[MAX_LINE];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (buffer[strlen(buffer) - 1] != '\n')
            return INV_SEX;
        else
            buffer[strlen(buffer) - 1] = '\0';

        if (strlen(buffer) == 0)
            return INV_SEX;

        lower_case_str(buffer, lower_case);

        if (strcmp(lower_case, "male") != 0 && strcmp(lower_case, "female") != 0)
            return INV_SEX;

        person[i]->sex = (char *)malloc((strlen(buffer) + sizeof(char)));

        if (person[i]->sex == NULL)
            return INV_MALLOC;

        strcpy(person[i]->sex, buffer);
    }
    else
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

int input_birth(schoolboy **person, int i)
{
    char buffer[MAX_LINE];

    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        if (buffer[strlen(buffer) - 1] != '\n')
            return INV_BIRTH;
        else
            buffer[strlen(buffer) - 1] = '\0';

        if (strlen(buffer) == 0)
            return INV_BIRTH;

        if (check_format_data(buffer) != SUCCESS)
            return INV_BIRTH;

        person[i]->birth = (char *)malloc((strlen(buffer) + sizeof(char)));

        if (person[i]->birth == NULL)
            return INV_MALLOC;

        strcpy(person[i]->birth, buffer);
    }
    else
        return INV_BIRTH;

    return SUCCESS;
}

int input_marks(schoolboy **person, int i)
{
    int quantity_marks = 0;
    int mark;
    int j = 1;

    if (scanf("%d", &quantity_marks) == 1)
    {
        if (quantity_marks < 1)
            return INV_MARKS;

        person[i]->marks = (int *)malloc((quantity_marks + 1) * sizeof(int));

        if (person[i]->marks == NULL)
            return INV_MALLOC;

        person[i]->marks[0] = quantity_marks;
    }
    else
        return INV_MARKS;

    while (scanf("%d", &mark) == 1 && j != quantity_marks + 1)
    {
        person[i]->marks[j] = mark;
        j++;

        if (mark < 1 || mark > 5)
            return INV_MARKS;
    }

    if (j != quantity_marks + 1)
        return INV_MARKS;

    return SUCCESS;
}

int input_struct(schoolboy ***person, int *count_line, int *count_field)
{
    char buffer[MAX_LINE];
    int i = 0;

    if (fgets(buffer, sizeof(buffer), stdin) == NULL)
    {
        *count_field = i + 1;
        return INV_SURNAME;
    }

    if (buffer[strlen(buffer) - 1] != '\n')
    {
        *count_field = i + 1;
        return INV_SURNAME;
    }
    else
        buffer[strlen(buffer) - 1] = '\0';

    while (strcmp(buffer, "nobody") != 0)
    {
        (*person)[i]->surname = NULL;
        (*person)[i]->sex = NULL;
        (*person)[i]->birth = NULL;
        (*person)[i]->marks = NULL;

        if (input_surname(*person, buffer, i) != SUCCESS)
        {
            *count_field = i + 1;
            return INV_SURNAME;
        }

        if (input_sex(*person, i) != SUCCESS)
        {
            *count_field = i + 1;
            return INV_SEX;
        }

        if (input_birth(*person, i) != SUCCESS)
        {
            *count_field = i + 1;
            return INV_BIRTH;
        }

        if (input_marks(*person, i) != SUCCESS)
        {
            *count_field = i + 1;
            return INV_MARKS;
        }

        i++;

        if (expansion_struct(person, i, count_field, count_line) != SUCCESS)
        {
            *count_field = i;
            return INV_REALLOC;
        }

        if (fgets(buffer, MAX_LINE, stdin) == NULL)
        {
            *count_field = i;
            return INV_SURNAME;
        }

        if (buffer[strlen(buffer) - 1] != '\n')
        {
            *count_field = i;
            return INV_SURNAME;
        }
        else
            buffer[strlen(buffer) - 1] = '\0';
    }

    *count_field = i;

    if (realloc_struct(person, count_line, *count_field) != SUCCESS)
        return INV_REALLOC;

    *count_line = i;

    return SUCCESS;
}

int input_key(char *key)
{
    if (scanf("%s", key) != 1)
        return INV_KEY;

    if (strcmp(key, "SURNAME") != 0 && strcmp(key, "SEX") != 0
        && strcmp(key, "BIRTHDATE") != 0 && strcmp(key, "GRADE") != 0)
        return INV_KEY;

    return SUCCESS;
}

void output_struct(char *filename, schoolboy **person, int count_field)
{
    FILE *f = fopen(filename, "w");
    int j = 0;
    for (int i = 0; i < count_field; i++)
    {
        fprintf(f, "%s\n", person[i]->surname);
        fprintf(f, "%s\n", person[i]->sex);
        fprintf(f, "%s\n", person[i]->birth);
        j = 0;
        while (j <= person[i]->marks[0])
        {
            fprintf(f, "%d ", person[i]->marks[j]);
            j++;
        }
        fprintf(f, "\n");
    }

    fclose(f);
}
