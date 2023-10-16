#include <stdio.h>
#include <string.h>

#define N 100
#define INV_INPUT -1
#define OK 0

typedef
struct
{
    char name[N];
    int year;
    int quantity;
} town;

int file_to_struct(FILE *f, town t[N])
{
    char tek_str[N] = {0};
    int flag_file = 0;
    int i = 0;
    while (flag_file == 0)
    {
        if(fgets(t[i].name, N, f) == NULL)
            flag_file = 1;
        if (fgets(tek_str, N, f) == NULL)
            flag_file = 1;
        if (sscanf(tek_str, "%d", &t[i].year) != 1)
            flag_file = 1;
        if (fgets(tek_str, N, f) == NULL)
            flag_file = 1;
        if (sscanf(tek_str, "%d", &t[i].year) != 1)
            flag_file = 2;
        i++;
    }
    if (flag_file != 2)
        return INV_INPUT;
    else
        return i;
}

void old_city(FILE *f, town t[N], int n, char *old_city_name, int *old_city)
{
    int flag_space = 0;
    for (int i = 0; i < n; i++)
    {
        flag_space = 0;
        if (t[i].year <= *old_city)
        {
            int m = strlen(t[i].name);
            char *tek = t[i].name;
            for (int j = 0; j < m; j++)
            {
                if (tek[j] == ' ')
                    flag_space = 1;
            }
            if (flag_space == 1)
            {
                *old_city = t[i].year;
                strcpy(old_city_name, t[i].name);
            }
        }
    }
}
void from_struct_to_file(FILE *f, char *old_city_name, int old_city)
{
    fprintf(f,"%s\n%d", old_city_name, old_city);
}

int main()
{
    FILE *f_in;
    f_in = fopen("in.txt", "r");
    if (f_in == NULL)
        return INV_INPUT;

    town t[100];
    int n = file_to_struct(f_in, t);

    int old_city1 = t[0].year;
    char old_city_name;

    old_city(f_in, t, n, &old_city_name, &old_city1);
    fclose(f_in);

    FILE *f_out;
    f_out = fopen("out.txt", "w");
    from_struct_to_file(f_out, &old_city_name, old_city1);
    fclose(f_out);
    return OK;
}
