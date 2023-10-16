/*
 * целочисленный тип - int
 * алгоритм сортировки - пузырьком
 * «направление» упорядочивания - по возрастанию.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define INV_INPUT -1
#define INV_POS -2

void write_file(FILE *f)
{
    int n, tek;
    srand(time(NULL));
    n = rand() % 10 + 1;
    for (int i = 0; i < n; i++)
    {
        tek = rand() % 10 + 1;
        fwrite(&tek, sizeof(int), 1, f);
    }
}

int print_file(FILE *f)
{
    int num;
    if (fread(&num, sizeof(int), 1, f) == 0)
        return INV_INPUT;
    rewind(f);
    while (fread(&num, sizeof(int), 1, f) == 1)
        printf("%d ", num);
    return OK;
}

int get_number_by_pos(FILE *f, int *num, long int tek)
{
    fseek(f, tek, SEEK_SET);
    if (fread(num, sizeof(int), 1, f) == 1)
        return OK;
    else
        return INV_POS;
}

int put_number_by_pos(FILE *f, int num, long tek)
{
    fseek(f, tek, SEEK_SET);
    if (fwrite(&num, sizeof(int), 1, f) == 1)
        return OK;
    else
        return INV_POS;
}

int sort(FILE *f)
{
    int tek1 = 0, tek = 0;
    fseek(f, 0, SEEK_END);
    long int max_len = ftell(f);
    for (int k = 0; k < max_len - 4; k += 4)
    {
        rewind(f);
        for (unsigned int j = 1; j < (max_len - k) / 4; j++)
        {
            if (get_number_by_pos(f, &tek1, ftell(f)) == OK && get_number_by_pos(f, &tek, ftell(f)) == OK)
            {
                if (tek1 > tek)
                {
                    if (put_number_by_pos(f, tek1, j * sizeof(int)) != OK)
                        return INV_POS;
                    if (put_number_by_pos(f, tek, (j - 1) * sizeof(int)) != OK)
                        return INV_POS;
                }
                else
                    fseek(f, j * sizeof(int), SEEK_SET);
            }
        }
    }
    return OK;
}

int main(int argc, char *argv[])
{
    FILE *f;
    if (argc != 3)
        return INV_INPUT;
    if (strcmp(argv[1], "s") == 0)
    {
        f = fopen(argv[2], "r+b");
        if (f == NULL)
            return INV_INPUT;
        fseek(f, 0, SEEK_END);
        if (ftell(f) == 0)
            return INV_INPUT;
        sort(f);
        fclose(f);
    }
    else if (strcmp(argv[1], "p") == 0)
    {
        f = fopen(argv[2], "rb");
        if (f == NULL)
            return INV_INPUT;
        fseek(f, 0, SEEK_END);
        if (ftell(f) == 0)
            return INV_INPUT;
        rewind(f);
        if (print_file(f) == INV_INPUT)
            return INV_INPUT;
        fclose(f);
    }
    else if (strcmp(argv[1], "c") == 0)
    {
        f = fopen(argv[2], "wb");
        if (f == NULL)
            return INV_INPUT;
        write_file(f);
        fclose(f);
    }
    else
        return INV_INPUT;
    return OK;
}
