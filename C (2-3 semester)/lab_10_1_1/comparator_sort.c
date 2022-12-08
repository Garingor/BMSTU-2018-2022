#include <string.h>
#include "utilities.h"
#include "const.h"
#include "comparator_sort.h"

void bubble_sort(schoolboy **person, int end, int (*compare)(schoolboy **, int))
{
    int flag_break = 0;
    for (int i = 0; i < end - 1; i++)
    {
        flag_break = 0;
        for (int j = 0; j < end - 1 - i; j++)
            if (compare(person, j) == SORT)
            {
                flag_break = 1;
                change_fields(person, j);
            }
        if (flag_break == 0)
            break;
    }
}

int compare_surname(schoolboy **person, int i)
{
    if (strcmp(person[i]->surname, person[i + 1]->surname) > 0)
        return SORT;

    return UNSORT;
}

int compare_sex(schoolboy **person, int i)
{
    if (strcmp(person[i]->sex, person[i + 1]->sex) > 0)
        return SORT;

    return UNSORT;
}

int compare_birth(schoolboy **person, int i)
{
    if (strcmp(person[i]->birth, person[i + 1]->birth) > 0)
        return SORT;

    return UNSORT;
}

int compare_grade(schoolboy **person, int i)
{
    double average_1 = 0;
    double average_2 = 0;
    int j = 1;

    while (j <= person[i]->marks[0])
    {
        average_1 += person[i]->marks[j];
        j++;
    }

    average_1 /= person[i]->marks[0];

    j = 1;
    while (j <= person[i + 1]->marks[0])
    {
        average_2 += person[i + 1]->marks[j];
        j++;
    }

    average_2 /= person[i + 1]->marks[0];

    if (average_1 > average_2)
        return SORT;

    return UNSORT;
}
