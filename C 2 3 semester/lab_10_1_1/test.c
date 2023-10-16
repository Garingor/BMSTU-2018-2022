#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "const.h"
#include "utilities.h"
#include "test_utilities.h"
#include "struct_memory.h"
#include "comparator_sort.h"
#include "input_output_struct.h"

int delete_two_old_girls()
{
    schoolboy **person = NULL;
    schoolboy **person_expected = NULL;
    int count_line = 3;
    int count_field = 3;
    int count_line_expect = 1;
    int count_field_expect = 1;
    int flag_failed_test = 0;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return FAILED_TEST;

    if (malloc_struct(&person_expected, &count_line_expect, count_field_expect) != SUCCESS)
        return FAILED_TEST;

    person_expected[0]->surname = NULL;
    person_expected[0]->sex = NULL;
    person_expected[0]->birth = NULL;
    person_expected[0]->marks = NULL;

    person[0]->surname = NULL;
    person[0]->sex = NULL;
    person[0]->birth = NULL;
    person[0]->marks = NULL;

    person[1]->surname = NULL;
    person[1]->sex = NULL;
    person[1]->birth = NULL;
    person[1]->marks = NULL;

    person[2]->surname = NULL;
    person[2]->sex = NULL;
    person[2]->birth = NULL;
    person[2]->marks = NULL;

    person_expected[0]->surname = malloc(sizeof("Bender") + sizeof(char));
    strcpy(person_expected[0]->surname, "Bender");

    person_expected[0]->sex = malloc(sizeof("male") + sizeof(char));
    strcpy(person_expected[0]->sex, "male");

    person_expected[0]->birth = malloc(sizeof("2010.5.20"));
    strcpy(person_expected[0]->birth, "2010.5.20");

    person_expected[0]->marks = malloc(sizeof(int) * 4);
    person_expected[0]->marks[0] = 3;
    person_expected[0]->marks[1] = 4;
    person_expected[0]->marks[2] = 5;
    person_expected[0]->marks[3] = 2;

    person[0]->surname = malloc(sizeof("Bender") + sizeof(char));
    strcpy(person[0]->surname, "Bender");

    person[0]->sex = malloc(sizeof("male") + sizeof(char));
    strcpy(person[0]->sex, "male");

    person[0]->birth = malloc(sizeof("2000.5.20"));
    strcpy(person[0]->birth, "2000.5.20");

    person[0]->marks = malloc(sizeof(int) * 4);
    person[0]->marks[0] = 3;
    person[0]->marks[1] = 4;
    person[0]->marks[2] = 5;
    person[0]->marks[3] = 2;

    person[1]->surname = malloc(sizeof("Potts"));
    strcpy(person[1]->surname, "Potts");

    person[1]->sex = malloc(sizeof("female"));
    strcpy(person[1]->sex, "female");

    person[1]->birth = malloc(sizeof("1999.4.4"));
    strcpy(person[1]->birth, "1999.4.4");

    person[1]->marks = malloc(sizeof(int) * 4);
    person[1]->marks[0] = 3;
    person[1]->marks[1] = 5;
    person[1]->marks[2] = 5;
    person[1]->marks[3] = 5;

    person[2]->surname = malloc(sizeof("Diana"));
    strcpy(person[2]->surname, "Diana");

    person[2]->sex = malloc(sizeof("Female"));
    strcpy(person[2]->sex, "Female");

    person[2]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person[2]->birth, "2000.2.12");

    person[2]->marks = malloc(sizeof(int) * 4);
    person[2]->marks[0] = 3;
    person[2]->marks[1] = 3;
    person[2]->marks[2] = 3;
    person[2]->marks[3] = 5;

    if (delete_old_girls(&person, &count_field, &count_line) != SUCCESS)
        flag_failed_test = 1;

    if (count_field != 1)
        flag_failed_test = 1;
    if (count_line != 1)
        flag_failed_test = 1;
    if (strcmp(person[0]->surname, "Bender") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->sex, "male") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->birth, "2000.5.20") != 0)
        flag_failed_test = 1;
    if (person[0]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[1] != 4)
        flag_failed_test = 1;
    if (person[0]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[0]->marks[3] != 2)
        flag_failed_test = 1;

    if (flag_failed_test == 1)
    {
        printf("Удаление структуры, если девочке больше 17 лет:\n");
        printf("фактическая структура = \n");
        output_struct_test(person, count_line);
        printf("ожидаемая структура = \n");
        output_struct_test(person_expected, count_line_expect);
    }

    free_struct(&person, count_line, count_field);
    free_struct(&person_expected, count_line_expect, count_field_expect);

    if (flag_failed_test == 1)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int insert_mark_to_line()
{
    schoolboy **person = NULL;
    schoolboy **person_expected = NULL;
    int count_line = 1;
    int count_field = 1;
    int count_line_expect = 1;
    int count_field_expect = 1;
    int flag_failed_test = 0;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return FAILED_TEST;

    if (malloc_struct(&person_expected, &count_line_expect, count_field_expect) != SUCCESS)
        return FAILED_TEST;

    person_expected[0]->surname = NULL;
    person_expected[0]->sex = NULL;
    person_expected[0]->birth = NULL;
    person_expected[0]->marks = NULL;

    person[0]->surname = NULL;
    person[0]->sex = NULL;
    person[0]->birth = NULL;
    person[0]->marks = NULL;

    person[0]->surname = malloc(sizeof("Bender"));
    strcpy(person[0]->surname, "Bender");

    person[0]->sex = malloc(sizeof("male"));
    strcpy(person[0]->sex, "male");

    person[0]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person[0]->birth, "2003.5.20");

    person[0]->marks = malloc(sizeof(int) * 4);
    person[0]->marks[0] = 3;
    person[0]->marks[1] = 4;
    person[0]->marks[2] = 5;
    person[0]->marks[3] = 2;

    person_expected[0]->surname = malloc(sizeof("Bender"));
    strcpy(person_expected[0]->surname, "Bender");

    person_expected[0]->sex = malloc(sizeof("male"));
    strcpy(person_expected[0]->sex, "male");

    person_expected[0]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person_expected[0]->birth, "2003.5.20");

    person_expected[0]->marks = malloc(sizeof(int) * 4);
    person_expected[0]->marks[0] = 3;
    person_expected[0]->marks[1] = 4;
    person_expected[0]->marks[2] = 5;
    person_expected[0]->marks[3] = 2;

    if (insert_mark(person, count_line) != SUCCESS)
        return FAILED_TEST;

    if (strcmp(person[0]->surname, "Bender") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->sex, "male") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->birth, "2003.5.20") != 0)
        flag_failed_test = 1;
    if (person[0]->marks[0] != 4)
        flag_failed_test = 1;
    if (person[0]->marks[1] != 4)
        flag_failed_test = 1;
    if (person[0]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[0]->marks[3] != 2)
        flag_failed_test = 1;
    if (person[0]->marks[4] != 3)
        flag_failed_test = 1;

    if (flag_failed_test == 1)
    {
        printf("Добавление оценки 3:\n");
        printf("фактическая структура = \n");
        output_struct_test(person, count_line);
        printf("ожидаемая структура = \n");
        output_struct_test(person_expected, count_line_expect);
    }

    free_struct(&person, count_line, count_field);
    free_struct(&person_expected, count_line_expect, count_field_expect);

    if (flag_failed_test == 1)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int sort_key_sex()
{
    schoolboy **person = NULL;
    schoolboy **person_expected = NULL;
    int count_line = 3;
    int count_field = 3;
    int count_line_expect = 3;
    int count_field_expect = 3;
    int flag_failed_test = 0;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return FAILED_TEST;

    if (malloc_struct(&person_expected, &count_line_expect, count_field_expect) != SUCCESS)
        return FAILED_TEST;

    person_expected[0]->surname = NULL;
    person_expected[0]->sex = NULL;
    person_expected[0]->birth = NULL;
    person_expected[0]->marks = NULL;

    person_expected[1]->surname = NULL;
    person_expected[1]->sex = NULL;
    person_expected[1]->birth = NULL;
    person_expected[1]->marks = NULL;

    person_expected[2]->surname = NULL;
    person_expected[2]->sex = NULL;
    person_expected[2]->birth = NULL;
    person_expected[2]->marks = NULL;

    person[0]->surname = NULL;
    person[0]->sex = NULL;
    person[0]->birth = NULL;
    person[0]->marks = NULL;

    person[1]->surname = NULL;
    person[1]->sex = NULL;
    person[1]->birth = NULL;
    person[1]->marks = NULL;

    person[2]->surname = NULL;
    person[2]->sex = NULL;
    person[2]->birth = NULL;
    person[2]->marks = NULL;

    person[0]->surname = malloc(sizeof("Potts"));
    strcpy(person[0]->surname, "Potts");

    person[0]->sex = malloc(sizeof("female"));
    strcpy(person[0]->sex, "female");

    person[0]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person[0]->birth, "2001.4.4");

    person[0]->marks = malloc(sizeof(int) * 4);
    person[0]->marks[0] = 3;
    person[0]->marks[1] = 5;
    person[0]->marks[2] = 5;
    person[0]->marks[3] = 5;

    person[1]->surname = malloc(sizeof("Bender"));
    strcpy(person[1]->surname, "Bender");

    person[1]->sex = malloc(sizeof("male"));
    strcpy(person[1]->sex, "male");

    person[1]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person[1]->birth, "2003.5.20");

    person[1]->marks = malloc(sizeof(int) * 4);
    person[1]->marks[0] = 3;
    person[1]->marks[1] = 4;
    person[1]->marks[2] = 5;
    person[1]->marks[3] = 2;

    person[2]->surname = malloc(sizeof("Diana"));
    strcpy(person[2]->surname, "Diana");

    person[2]->sex = malloc(sizeof("Female"));
    strcpy(person[2]->sex, "Female");

    person[2]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person[2]->birth, "2000.2.12");

    person[2]->marks = malloc(sizeof(int) * 4);
    person[2]->marks[0] = 3;
    person[2]->marks[1] = 3;
    person[2]->marks[2] = 3;
    person[2]->marks[3] = 5;

    person_expected[0]->surname = malloc(sizeof("Diana"));
    strcpy(person_expected[0]->surname, "Diana");

    person_expected[0]->sex = malloc(sizeof("Female"));
    strcpy(person_expected[0]->sex, "Female");

    person_expected[0]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person_expected[0]->birth, "2000.2.12");

    person_expected[0]->marks = malloc(sizeof(int) * 4);
    person_expected[0]->marks[0] = 3;
    person_expected[0]->marks[1] = 3;
    person_expected[0]->marks[2] = 3;
    person_expected[0]->marks[3] = 5;

    person_expected[1]->surname = malloc(sizeof("Potts"));
    strcpy(person_expected[1]->surname, "Potts");

    person_expected[1]->sex = malloc(sizeof("female"));
    strcpy(person_expected[1]->sex, "female");

    person_expected[1]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person_expected[1]->birth, "2001.4.4");

    person_expected[1]->marks = malloc(sizeof(int) * 4);
    person_expected[1]->marks[0] = 3;
    person_expected[1]->marks[1] = 5;
    person_expected[1]->marks[2] = 5;
    person_expected[1]->marks[3] = 5;

    person_expected[2]->surname = malloc(sizeof("Bender"));
    strcpy(person_expected[2]->surname, "Bender");

    person_expected[2]->sex = malloc(sizeof("male"));
    strcpy(person_expected[2]->sex, "male");

    person_expected[2]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person_expected[2]->birth, "2003.5.20");

    person_expected[2]->marks = malloc(sizeof(int) * 4);
    person_expected[2]->marks[0] = 3;
    person_expected[2]->marks[1] = 4;
    person_expected[2]->marks[2] = 5;
    person_expected[2]->marks[3] = 2;

    choice_key(person, "SEX", count_line);

    if (strcmp(person[0]->surname, "Diana") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->sex, "Female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->birth, "2000.2.12") != 0)
        flag_failed_test = 1;
    if (person[0]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[1] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[2] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[3] != 5)
        flag_failed_test = 1;

    if (strcmp(person[1]->surname, "Potts") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->sex, "female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->birth, "2001.4.4") != 0)
        flag_failed_test = 1;
    if (person[1]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[1] != 5)
        flag_failed_test = 1;
    if (person[1]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[1]->marks[3] != 5)
        flag_failed_test = 1;

    if (strcmp(person[2]->surname, "Bender") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->sex, "male") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->birth, "2003.5.20") != 0)
        flag_failed_test = 1;
    if (person[2]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[2]->marks[1] != 4)
        flag_failed_test = 1;
    if (person[2]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[2]->marks[3] != 2)
        flag_failed_test = 1;

    if (flag_failed_test == 1)
    {
        printf("Сортировка по ключу SEX: \n");
        printf("фактическая структура = \n");
        output_struct_test(person, count_line);
        printf("ожидаемая структура = \n");
        output_struct_test(person_expected, count_line_expect);
    }

    free_struct(&person, count_line, count_field);
    free_struct(&person_expected, count_line_expect, count_field_expect);

    if (flag_failed_test == 1)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int sort_key_surname()
{
    schoolboy **person = NULL;
    schoolboy **person_expected = NULL;
    int count_line = 3;
    int count_field = 3;
    int count_line_expect = 3;
    int count_field_expect = 3;
    int flag_failed_test = 0;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return FAILED_TEST;

    if (malloc_struct(&person_expected, &count_line_expect, count_field_expect) != SUCCESS)
        return FAILED_TEST;

    person_expected[0]->surname = NULL;
    person_expected[0]->sex = NULL;
    person_expected[0]->birth = NULL;
    person_expected[0]->marks = NULL;

    person_expected[1]->surname = NULL;
    person_expected[1]->sex = NULL;
    person_expected[1]->birth = NULL;
    person_expected[1]->marks = NULL;

    person_expected[2]->surname = NULL;
    person_expected[2]->sex = NULL;
    person_expected[2]->birth = NULL;
    person_expected[2]->marks = NULL;

    person[0]->surname = NULL;
    person[0]->sex = NULL;
    person[0]->birth = NULL;
    person[0]->marks = NULL;

    person[1]->surname = NULL;
    person[1]->sex = NULL;
    person[1]->birth = NULL;
    person[1]->marks = NULL;

    person[2]->surname = NULL;
    person[2]->sex = NULL;
    person[2]->birth = NULL;
    person[2]->marks = NULL;

    person[0]->surname = malloc(sizeof("Bender"));
    strcpy(person[0]->surname, "Bender");

    person[0]->sex = malloc(sizeof("male"));
    strcpy(person[0]->sex, "male");

    person[0]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person[0]->birth, "2003.5.20");

    person[0]->marks = malloc(sizeof(int) * 4);
    person[0]->marks[0] = 3;
    person[0]->marks[1] = 4;
    person[0]->marks[2] = 5;
    person[0]->marks[3] = 2;

    person[1]->surname = malloc(sizeof("Potts"));
    strcpy(person[1]->surname, "Potts");

    person[1]->sex = malloc(sizeof("female"));
    strcpy(person[1]->sex, "female");

    person[1]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person[1]->birth, "2001.4.4");

    person[1]->marks = malloc(sizeof(int) * 4);
    person[1]->marks[0] = 3;
    person[1]->marks[1] = 5;
    person[1]->marks[2] = 5;
    person[1]->marks[3] = 5;

    person[2]->surname = malloc(sizeof("Diana"));
    strcpy(person[2]->surname, "Diana");

    person[2]->sex = malloc(sizeof("Female"));
    strcpy(person[2]->sex, "Female");

    person[2]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person[2]->birth, "2000.2.12");

    person[2]->marks = malloc(sizeof(int) * 4);
    person[2]->marks[0] = 3;
    person[2]->marks[1] = 3;
    person[2]->marks[2] = 3;
    person[2]->marks[3] = 5;

    person_expected[0]->surname = malloc(sizeof("Bender"));
    strcpy(person_expected[0]->surname, "Bender");

    person_expected[0]->sex = malloc(sizeof("male"));
    strcpy(person_expected[0]->sex, "male");

    person_expected[0]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person_expected[0]->birth, "2003.5.20");

    person_expected[0]->marks = malloc(sizeof(int) * 4);
    person_expected[0]->marks[0] = 3;
    person_expected[0]->marks[1] = 4;
    person_expected[0]->marks[2] = 5;
    person_expected[0]->marks[3] = 2;

    person_expected[1]->surname = malloc(sizeof("Diana"));
    strcpy(person_expected[1]->surname, "Diana");

    person_expected[1]->sex = malloc(sizeof("Female"));
    strcpy(person_expected[1]->sex, "Female");

    person_expected[1]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person_expected[1]->birth, "2000.2.12");

    person_expected[1]->marks = malloc(sizeof(int) * 4);
    person_expected[1]->marks[0] = 3;
    person_expected[1]->marks[1] = 3;
    person_expected[1]->marks[2] = 3;
    person_expected[1]->marks[3] = 5;

    person_expected[2]->surname = malloc(sizeof("Potts"));
    strcpy(person_expected[2]->surname, "Potts");

    person_expected[2]->sex = malloc(sizeof("female"));
    strcpy(person_expected[2]->sex, "female");

    person_expected[2]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person_expected[2]->birth, "2001.4.4");

    person_expected[2]->marks = malloc(sizeof(int) * 4);
    person_expected[2]->marks[0] = 3;
    person_expected[2]->marks[1] = 5;
    person_expected[2]->marks[2] = 5;
    person_expected[2]->marks[3] = 5;

    choice_key(person, "SURNAME", count_line);

    if (strcmp(person[0]->surname, "Bender") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->sex, "male") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->birth, "2003.5.20") != 0)
        flag_failed_test = 1;
    if (person[0]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[1] != 4)
        flag_failed_test = 1;
    if (person[0]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[0]->marks[3] != 2)
        flag_failed_test = 1;

    if (strcmp(person[1]->surname, "Diana") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->sex, "Female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->birth, "2000.2.12") != 0)
        flag_failed_test = 1;
    if (person[1]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[1] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[2] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[3] != 5)
        flag_failed_test = 1;

    if (strcmp(person[2]->surname, "Potts") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->sex, "female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->birth, "2001.4.4") != 0)
        flag_failed_test = 1;
    if (person[2]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[2]->marks[1] != 5)
        flag_failed_test = 1;
    if (person[2]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[2]->marks[3] != 5)
        flag_failed_test = 1;

    if (flag_failed_test == 1)
    {
        printf("Сортировка по ключу SURNAME: \n");
        printf("фактическая структура = \n");
        output_struct_test(person, count_line);
        printf("ожидаемая структура = \n");
        output_struct_test(person_expected, count_line_expect);
    }

    free_struct(&person, count_line, count_field);
    free_struct(&person_expected, count_line_expect, count_field_expect);

    if (flag_failed_test == 1)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int sort_key_grade()
{
    schoolboy **person = NULL;
    schoolboy **person_expected = NULL;
    int count_line = 3;
    int count_field = 3;
    int count_line_expect = 3;
    int count_field_expect = 3;
    int flag_failed_test = 0;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return FAILED_TEST;

    if (malloc_struct(&person_expected, &count_line_expect, count_field_expect) != SUCCESS)
        return FAILED_TEST;

    person_expected[0]->surname = NULL;
    person_expected[0]->sex = NULL;
    person_expected[0]->birth = NULL;
    person_expected[0]->marks = NULL;

    person_expected[1]->surname = NULL;
    person_expected[1]->sex = NULL;
    person_expected[1]->birth = NULL;
    person_expected[1]->marks = NULL;

    person_expected[2]->surname = NULL;
    person_expected[2]->sex = NULL;
    person_expected[2]->birth = NULL;
    person_expected[2]->marks = NULL;

    person[0]->surname = NULL;
    person[0]->sex = NULL;
    person[0]->birth = NULL;
    person[0]->marks = NULL;

    person[1]->surname = NULL;
    person[1]->sex = NULL;
    person[1]->birth = NULL;
    person[1]->marks = NULL;

    person[2]->surname = NULL;
    person[2]->sex = NULL;
    person[2]->birth = NULL;
    person[2]->marks = NULL;

    person[0]->surname = malloc(sizeof("Bender"));
    strcpy(person[0]->surname, "Bender");

    person[0]->sex = malloc(sizeof("male"));
    strcpy(person[0]->sex, "male");

    person[0]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person[0]->birth, "2003.5.20");

    person[0]->marks = malloc(sizeof(int) * 4);
    person[0]->marks[0] = 3;
    person[0]->marks[1] = 2;
    person[0]->marks[2] = 2;
    person[0]->marks[3] = 2;

    person[1]->surname = malloc(sizeof("Potts"));
    strcpy(person[1]->surname, "Potts");

    person[1]->sex = malloc(sizeof("female"));
    strcpy(person[1]->sex, "female");

    person[1]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person[1]->birth, "2001.4.4");

    person[1]->marks = malloc(sizeof(int) * 4);
    person[1]->marks[0] = 3;
    person[1]->marks[1] = 5;
    person[1]->marks[2] = 3;
    person[1]->marks[3] = 5;

    person[2]->surname = malloc(sizeof("Diana"));
    strcpy(person[2]->surname, "Diana");

    person[2]->sex = malloc(sizeof("Female"));
    strcpy(person[2]->sex, "Female");

    person[2]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person[2]->birth, "2000.2.12");

    person[2]->marks = malloc(sizeof(int) * 4);
    person[2]->marks[0] = 3;
    person[2]->marks[1] = 3;
    person[2]->marks[2] = 3;
    person[2]->marks[3] = 5;

    person_expected[0]->surname = malloc(sizeof("Bender"));
    strcpy(person_expected[0]->surname, "Bender");

    person_expected[0]->sex = malloc(sizeof("male"));
    strcpy(person_expected[0]->sex, "male");

    person_expected[0]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person_expected[0]->birth, "2003.5.20");

    person_expected[0]->marks = malloc(sizeof(int) * 4);
    person_expected[0]->marks[0] = 3;
    person_expected[0]->marks[1] = 2;
    person_expected[0]->marks[2] = 2;
    person_expected[0]->marks[3] = 2;

    person_expected[1]->surname = malloc(sizeof("Diana"));
    strcpy(person_expected[1]->surname, "Diana");

    person_expected[1]->sex = malloc(sizeof("Female"));
    strcpy(person_expected[1]->sex, "Female");

    person_expected[1]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person_expected[1]->birth, "2000.2.12");

    person_expected[1]->marks = malloc(sizeof(int) * 4);
    person_expected[1]->marks[0] = 3;
    person_expected[1]->marks[1] = 3;
    person_expected[1]->marks[2] = 3;
    person_expected[1]->marks[3] = 5;

    person_expected[2]->surname = malloc(sizeof("Potts"));
    strcpy(person_expected[2]->surname, "Potts");

    person_expected[2]->sex = malloc(sizeof("female"));
    strcpy(person_expected[2]->sex, "female");

    person_expected[2]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person_expected[2]->birth, "2001.4.4");

    person_expected[2]->marks = malloc(sizeof(int) * 4);
    person_expected[2]->marks[0] = 3;
    person_expected[2]->marks[1] = 5;
    person_expected[2]->marks[2] = 5;
    person_expected[2]->marks[3] = 5;

    choice_key(person, "GRADE", count_line);

    if (strcmp(person[0]->surname, "Bender") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->sex, "male") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->birth, "2003.5.20") != 0)
        flag_failed_test = 1;
    if (person[0]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[1] != 2)
        flag_failed_test = 1;
    if (person[0]->marks[2] != 2)
        flag_failed_test = 1;
    if (person[0]->marks[3] != 2)
        flag_failed_test = 1;

    if (strcmp(person[1]->surname, "Diana") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->sex, "Female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->birth, "2000.2.12") != 0)
        flag_failed_test = 1;
    if (person[1]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[1] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[2] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[3] != 5)
        flag_failed_test = 1;

    if (strcmp(person[2]->surname, "Potts") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->sex, "female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->birth, "2001.4.4") != 0)
        flag_failed_test = 1;
    if (person[2]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[2]->marks[1] != 5)
        flag_failed_test = 1;
    if (person[2]->marks[2] != 3)
        flag_failed_test = 1;
    if (person[2]->marks[3] != 5)
        flag_failed_test = 1;

    if (flag_failed_test == 1)
    {
        printf("Сортировка по ключу GRADE: \n");
        printf("фактическая структура = \n");
        output_struct_test(person, count_line);
        printf("ожидаемая структура = \n");
        output_struct_test(person_expected, count_line_expect);
    }

    free_struct(&person, count_line, count_field);
    free_struct(&person_expected, count_line_expect, count_field_expect);

    if (flag_failed_test == 1)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int sort_key_birthday()
{
    schoolboy **person = NULL;
    schoolboy **person_expected = NULL;
    int count_line = 3;
    int count_field = 3;
    int count_line_expect = 3;
    int count_field_expect = 3;
    int flag_failed_test = 0;

    if (malloc_struct(&person, &count_line, count_field) != SUCCESS)
        return FAILED_TEST;

    if (malloc_struct(&person_expected, &count_line_expect, count_field_expect) != SUCCESS)
        return FAILED_TEST;

    person_expected[0]->surname = NULL;
    person_expected[0]->sex = NULL;
    person_expected[0]->birth = NULL;
    person_expected[0]->marks = NULL;

    person_expected[1]->surname = NULL;
    person_expected[1]->sex = NULL;
    person_expected[1]->birth = NULL;
    person_expected[1]->marks = NULL;

    person_expected[2]->surname = NULL;
    person_expected[2]->sex = NULL;
    person_expected[2]->birth = NULL;
    person_expected[2]->marks = NULL;

    person[0]->surname = NULL;
    person[0]->sex = NULL;
    person[0]->birth = NULL;
    person[0]->marks = NULL;

    person[1]->surname = NULL;
    person[1]->sex = NULL;
    person[1]->birth = NULL;
    person[1]->marks = NULL;

    person[2]->surname = NULL;
    person[2]->sex = NULL;
    person[2]->birth = NULL;
    person[2]->marks = NULL;

    person[0]->surname = malloc(sizeof("Potts"));
    strcpy(person[0]->surname, "Potts");

    person[0]->sex = malloc(sizeof("female"));
    strcpy(person[0]->sex, "female");

    person[0]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person[0]->birth, "2001.4.4");

    person[0]->marks = malloc(sizeof(int) * 4);
    person[0]->marks[0] = 3;
    person[0]->marks[1] = 5;
    person[0]->marks[2] = 5;
    person[0]->marks[3] = 5;

    person[1]->surname = malloc(sizeof("Diana"));
    strcpy(person[1]->surname, "Diana");

    person[1]->sex = malloc(sizeof("Female"));
    strcpy(person[1]->sex, "Female");

    person[1]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person[1]->birth, "2000.2.12");

    person[1]->marks = malloc(sizeof(int) * 4);
    person[1]->marks[0] = 3;
    person[1]->marks[1] = 3;
    person[1]->marks[2] = 3;
    person[1]->marks[3] = 5;

    person[2]->surname = malloc(sizeof("Bender"));
    strcpy(person[2]->surname, "Bender");

    person[2]->sex = malloc(sizeof("male"));
    strcpy(person[2]->sex, "male");

    person[2]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person[2]->birth, "2003.5.20");

    person[2]->marks = malloc(sizeof(int) * 4);
    person[2]->marks[0] = 3;
    person[2]->marks[1] = 4;
    person[2]->marks[2] = 5;
    person[2]->marks[3] = 2;

    person_expected[0]->surname = malloc(sizeof("Diana"));
    strcpy(person_expected[0]->surname, "Diana");

    person_expected[0]->sex = malloc(sizeof("Female"));
    strcpy(person_expected[0]->sex, "Female");

    person_expected[0]->birth = malloc(sizeof("2000.2.12"));
    strcpy(person_expected[0]->birth, "2000.2.12");

    person_expected[0]->marks = malloc(sizeof(int) * 4);
    person_expected[0]->marks[0] = 3;
    person_expected[0]->marks[1] = 3;
    person_expected[0]->marks[2] = 3;
    person_expected[0]->marks[3] = 5;

    person_expected[1]->surname = malloc(sizeof("Potts"));
    strcpy(person_expected[1]->surname, "Potts");

    person_expected[1]->sex = malloc(sizeof("female"));
    strcpy(person_expected[1]->sex, "female");

    person_expected[1]->birth = malloc(sizeof("2001.4.4"));
    strcpy(person_expected[1]->birth, "2001.4.4");

    person_expected[1]->marks = malloc(sizeof(int) * 4);
    person_expected[1]->marks[0] = 3;
    person_expected[1]->marks[1] = 5;
    person_expected[1]->marks[2] = 5;
    person_expected[1]->marks[3] = 5;

    person_expected[2]->surname = malloc(sizeof("Bender"));
    strcpy(person_expected[2]->surname, "Bender");

    person_expected[2]->sex = malloc(sizeof("male"));
    strcpy(person_expected[2]->sex, "male");

    person_expected[2]->birth = malloc(sizeof("2003.5.20"));
    strcpy(person_expected[2]->birth, "2003.5.20");

    person_expected[2]->marks = malloc(sizeof(int) * 4);
    person_expected[2]->marks[0] = 3;
    person_expected[2]->marks[1] = 4;
    person_expected[2]->marks[2] = 5;
    person_expected[2]->marks[3] = 2;

    choice_key(person, "BIRTHDATE", count_line);

    if (strcmp(person[0]->surname, "Diana") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->sex, "Female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[0]->birth, "2000.2.12") != 0)
        flag_failed_test = 1;
    if (person[0]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[1] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[2] != 3)
        flag_failed_test = 1;
    if (person[0]->marks[3] != 5)
        flag_failed_test = 1;

    if (strcmp(person[1]->surname, "Potts") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->sex, "female") != 0)
        flag_failed_test = 1;
    if (strcmp(person[1]->birth, "2001.4.4") != 0)
        flag_failed_test = 1;
    if (person[1]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[1]->marks[1] != 5)
        flag_failed_test = 1;
    if (person[1]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[1]->marks[3] != 5)
        flag_failed_test = 1;

    if (strcmp(person[2]->surname, "Bender") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->sex, "male") != 0)
        flag_failed_test = 1;
    if (strcmp(person[2]->birth, "2003.5.20") != 0)
        flag_failed_test = 1;
    if (person[2]->marks[0] != 3)
        flag_failed_test = 1;
    if (person[2]->marks[1] != 4)
        flag_failed_test = 1;
    if (person[2]->marks[2] != 5)
        flag_failed_test = 1;
    if (person[2]->marks[3] != 2)
        flag_failed_test = 1;

    if (flag_failed_test == 1)
    {
        printf("Сортировка по ключу BIRTHDAY: \n");
        printf("фактическая структура = \n");
        output_struct_test(person, count_line);
        printf("ожидаемая структура = \n");
        output_struct_test(person_expected, count_line_expect);
    }

    free_struct(&person, count_line, count_field);
    free_struct(&person_expected, count_line_expect, count_field_expect);

    if (flag_failed_test == 1)
        return FAILED_TEST;

    return SUCCESS_TEST;
}

int main()
{
    int test = 0;

    test = delete_two_old_girls() +
        insert_mark_to_line() +
        sort_key_sex() +
        sort_key_surname() +
        sort_key_grade() +
        sort_key_birthday();

    printf("\n");
    if (test != 6)
    {
        printf("lab_09_08_1: FUNC_TESTING %s(FAILED)%s", RED, RESET);
        printf("\nRESULT: correct %d of 6", test);
        return INV_CHECK_FUNC;
    }
    else
        printf("lab_09_08_1: FUNC_TESTING %s(PASSED)%s", GREEN, RESET);
    printf("\nRESULT: correct %d of 6", test);
    printf("\n\n");

    return SUCCESS;
}
