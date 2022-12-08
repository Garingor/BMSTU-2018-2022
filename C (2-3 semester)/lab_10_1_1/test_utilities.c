#include "const.h"
#include <stdio.h>
#include "test_utilities.h"

void output_struct_test(schoolboy **person, int count_field)
{
    int j = 0;
    for (int i = 0; i < count_field; i++)
    {
        printf("%s\n", person[i]->surname);
        printf("%s\n", person[i]->sex);
        printf("%s\n", person[i]->birth);
        j = 0;
        while (j <= person[i]->marks[0])
        {
            printf("%d ", person[i]->marks[j]);
            j++;
        }
        printf("\n");
    }
}
