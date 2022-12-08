#include <stdio.h>

#define OK 0
#define INV_INPUT -1
#define NOT_FOUND -2

int min_max(FILE *f, float *min_num, float *max_num)
{
    float tek;
    int flag_quantity = 0;
    if (fscanf(f, "%f", min_num) == 1)
    {
        *max_num = *min_num;
        while (fscanf(f, "%f", &tek) == 1)
        {
            flag_quantity = 1;
            if (tek > *max_num)
                *max_num = tek;
            if (tek < *min_num)
                *min_num = tek;
        }
        if (flag_quantity == 0)
            return INV_INPUT;
    }
    else
        return INV_INPUT;
    return OK;
}

int search(FILE *f, float average, int *quantity)
{
    rewind(f);
    float tek;
    while (fscanf(f, "%f", &tek) == 1)
    {
        if (tek > average)
            (*quantity)++;
    }
    if (quantity == 0)
        return NOT_FOUND;
    return OK;
}

int main(int argc, char *argv[])
{
    float min_num, max_num;
    int quantity = 0;
    int check;
    FILE *f;
    if (argc != 2)
        return INV_INPUT;
    f = fopen(argv[1], "r");
    if (f == NULL)
        return INV_INPUT;
    check = min_max(f, &min_num, &max_num);
    if (check != 0)
    {
        fclose(f);
        return INV_INPUT;
    }
    else
    {
        float average = (min_num + max_num) / 2;
        check = search(f, average, &quantity);
        if (check != 0)
            return NOT_FOUND;
        else
            printf("%d ", quantity);
        fclose(f);
    }
}
