#include <string.h>
#include <ctype.h>

#include "const.h"
#include "input_output_struct.h"
#include "struct_memory.h"
#include "utilities.h"

#include "./libui/ui.h"

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

int delete_old_girls(schoolboy ***person, int *count, char *str_error)
{
    char lower_case[MAX_LINE];
    int i = 0;

    if (person == NULL)
    {
        input_type_error(str_error, "Invalid input");
        return INV_INPUT;
    }

    while (i < *count)
    {
        lower_case_str((*person)[i]->sex, lower_case);

        if (detect_old_girls((*person), i) == FOUND && strcmp(lower_case, "female") == 0)
        {
            if (move_fields(person, i, *count) != SUCCESS)
            {
                input_type_error(str_error, "Invalid malloc");
                return INV_MALLOC;
            }
            i--;
            (*count)--;
        }

        if (*count == 0)
        {
            input_type_error(str_error, "Invalid data");
            return INV_DATA;
        }

        i++;
    }

    if (realloc_struct(person, *count) != SUCCESS)
    {
        input_type_error(str_error, "Invalid realloc");
        return INV_REALLOC;
    }

    return SUCCESS;
}

int insert_mark(schoolboy **person, int count, char *str_error)
{
    if (person == NULL)
    {
        input_type_error(str_error, "Invalid input");
        return INV_INPUT;
    }

    for (int i = 0; i < count; i++)
    {
        if (realloc_dmas_marks(person, i) != SUCCESS)
        {
            input_type_error(str_error, "Invalid realloc");
            return INV_REALLOC;
        }

        person[i]->marks[person[i]->marks[0]] = 3;
    }

    return SUCCESS;
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

void from_int_to_str(int value, char *str)
{
    int pos = 0;
    int cur_num;

    for (int i = value ; i != 0; i /= 10)
        pos++;

    str[pos] = '\0';
    pos--;

    for (; pos >= 0; pos--)
    {
        cur_num = value % 10;

        if (cur_num < 0)
            cur_num = -cur_num;

        str[pos] = cur_num + '0';
        value /= 10;
    }
}



void clean_entry(uiEntry *surname, uiEntry *sex, uiEntry *bday,uiEntry *grade)
{
    uiEntrySetText(surname, "");
    uiEntrySetText(sex, "");
    uiEntrySetText(bday, "");
    uiEntrySetText(grade, "");
}

void input_type_error(char *str_error, char *text)
{
    strcpy(str_error, "");
    strcpy(str_error, text);
}