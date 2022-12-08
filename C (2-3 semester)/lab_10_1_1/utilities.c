#include <string.h>
#include <ctype.h>
#include "const.h"
#include "input_output_struct.h"
#include "struct_memory.h"
#include "utilities.h"
#include "comparator_sort.h"

int detect_old_girls(schoolboy **person, int i)
{
    char *data_compare = "2002.11.01";

    if (strcmp(person[i]->birth, data_compare) < 0)
        return FOUND;

    return NOT_FOUND;
}

int move_fields(schoolboy ***person, int i, int count)
{
    for (int j = i; j < count - 1; j++)
    {
        if (realloc_line(*person, j) != SUCCESS)
            return INV_MALLOC;

        strcpy((*person)[j]->surname, (*person)[j + 1]->surname);
        strcpy((*person)[j]->sex, (*person)[j + 1]->sex);
        strcpy((*person)[j]->birth, (*person)[j + 1]->birth);

        for (int k = 0; k < (*person)[j + 1]->marks[0] + 1; k++)
            (*person)[j]->marks[k] = (*person)[j + 1]->marks[k];
    }

    free_line(person, count - 1);

    return SUCCESS;
}

int delete_old_girls(schoolboy ***person, int *count_fieds, int *count_line)
{
    char lower_case[MAX_LINE];
    int i = 0;

    while (i < *count_fieds)
    {
        lower_case_str((*person)[i]->sex, lower_case);

        if (detect_old_girls((*person), i) == FOUND && strcmp(lower_case, "female") == 0)
        {
            if (move_fields(person, i, *count_fieds) != SUCCESS)
                return INV_MALLOC;
            i--;
            (*count_fieds)--;
            (*count_line)--;
        }

        if (*count_fieds == 0 || *count_line == 0)
            return INV_DATA;

        i++;
    }

    if (realloc_struct(person, count_line, *count_fieds) != SUCCESS)
        return INV_REALLOC;

    return SUCCESS;
}

int insert_mark(schoolboy **person, int count)
{
    for (int i = 0; i < count; i++)
    {
        if (realloc_dmas_marks(person, i) != SUCCESS)
            return INV_REALLOC;

        person[i]->marks[person[i]->marks[0]] = 3;
    }
    return SUCCESS;
}

void change_fields(schoolboy **person, int i)
{
    schoolboy *temp;

    temp = person[i];
    person[i] = person[i + 1];
    person[i + 1] = temp;
}

void choice_key(schoolboy **person, char *key, int count_line)
{
    if (strcmp(key, "SURNAME") == 0)
        bubble_sort(person, count_line, compare_surname);

    if (strcmp(key, "SEX") == 0)
        bubble_sort(person, count_line, compare_sex);

    if (strcmp(key, "BIRTHDATE") == 0)
        bubble_sort(person, count_line, compare_birth);

    if (strcmp(key, "GRADE") == 0)
        bubble_sort(person, count_line, compare_grade);
}

void lower_case_str(char *buffer, char *lower_case)
{
    unsigned long j = 0;

    for (; j < strlen(buffer); j++)
        lower_case[j] = (char) tolower(buffer[j]);

    lower_case[j] = '\0';
}

int check_trash_symbol(char *buffer)
{
    int flag_lower_char = 0;
    int flag_upper_char = 0;

    for (unsigned long j = 0; j < strlen(buffer); j++)
    {
        if (buffer[j] > 'z' || buffer[j] < 'a')
            flag_lower_char = 1;
        if (buffer[j] > 'Z' || buffer[j] < 'A')
            flag_upper_char = 1;

        if (flag_lower_char == 1 && flag_upper_char == 1)
            return INV_SURNAME;

        if (buffer[j] == ' ')
            return INV_SURNAME;

        flag_upper_char = 0;
        flag_lower_char = 0;
    }

    return SUCCESS;
}
