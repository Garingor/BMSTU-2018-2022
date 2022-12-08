#include <stdio.h>
#include <string.h>

#define N 31
#define M 16
#define K 1
#define QUANTITY 100
#define A_N 256
#define SUCCESS 0
#define INV_FILE -1
#define INV_INPUT -2
#define INV_INPUT_AT -3
#define INV_INPUT_ST -4
#define INV_INPUT_FT -5
#define INV_INPUT_NEW_PRODUCT_AT -6
#define INV_SEARCH_AT -7
#define INV_SEARCH_FT -8
#define INV_SAVE_AT -9
#define INV_SAVE_TO_FILE_ST -10
#define CMD_INV 53

typedef
    struct
{
    char name[N];
    char maker[M];
    unsigned int price;
    unsigned int amount;
} product;

int input_qoods_txt(char *file_name, product goods[QUANTITY], int *n)
{
    FILE *f = fopen(file_name, "r");
    char tek_str[A_N] = { 0 };
    int flag_file = 0;
    int flag_struct = 0;
    (*n) = 0;
    if (f == NULL)
    {
        fclose(f);
        return INV_FILE;
    }
    while (fgets(goods[*n].name, A_N, f))
    {
        flag_struct++;
        if (fgets(goods[*n].maker, A_N, f) == NULL)
            flag_file = 1;
        flag_struct++;
        if (fgets(tek_str, A_N, f) == NULL)
            flag_file = 1;
        else if (sscanf(tek_str, "%u", &goods[*n].price) != 1)
            flag_file = 1;
        flag_struct++;
        if (fgets(tek_str, A_N, f) == NULL)
            flag_file = 1;
        else if (sscanf(tek_str, "%u", &goods[*n].amount) != 1)
            flag_file = 1;
        flag_struct++;
        (*n)++;
    }
    fclose(f);
    if (flag_struct < 4 || (flag_struct) % 4 != 0 || flag_file == 1)
        return INV_INPUT;
    else
        return SUCCESS;
}

int input_new_product(product *new_product, FILE *f)
{
    char tek_str[A_N] = { 0 };
    if (fgets((*new_product).name, A_N, f) == NULL)
        return INV_INPUT;
    if (fgets((*new_product).maker, A_N, f) == NULL)
        return INV_INPUT;
    if (fgets(tek_str, A_N, f) == NULL)
        return INV_INPUT;
    else
        sscanf(tek_str, "%u", &(*new_product).price);
    if (fgets(tek_str, A_N, f) == NULL)
        return INV_INPUT;
    else
        sscanf(tek_str, "%u", &(*new_product).amount);
    return SUCCESS;
}

int search_pos_for_new_product(product *new_product, product goods[QUANTITY], int n, char *file_name_out, int *pos)
{
    FILE *f = fopen(file_name_out, "r");
    *pos = n;
    if (f == NULL)
        return INV_FILE;
    for (int i = 0; i < n; i++)
    {
        if ((*new_product).price > goods[i].price)
        {
            *pos = i;
            break;
        }
        if ((*new_product).price == goods[i].price && (*new_product).amount > goods[i].amount)
        {
            *pos = i;
            break;
        }
    }
    return SUCCESS;
}

void add_new_product_to_product(product *new_product, product goods[QUANTITY], int *n, int pos)
{
    for (int i = *n; i > pos; i--)
        goods[i] = goods[i - 1];
    goods[pos] = (*new_product);
    (*n)++;
}

void change_string_txt(product goods[QUANTITY], int j)
{
    product temp = { "a", "a", 5, 5 };
    temp = goods[j];
    goods[j] = goods[j + 1];
    goods[j + 1] = temp;
}

void sort_by_price_txt(product goods[QUANTITY], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (goods[j].price < goods[j + 1].price)
                change_string_txt(goods, j);
            if (goods[j].price == goods[j + 1].price && goods[j].amount < goods[j + 1].amount)
                change_string_txt(goods, j);
        }
}

int search_print_substr(char substr[N], int n, product goods[QUANTITY])
{
    int flag_found = 0;
    char *pos;
    for (int i = 0; i < n; i++)
        if ((pos = strstr(goods[i].name, substr)) != NULL && pos - goods[i].name + strlen(substr) == strlen(goods[i].name) - 1)
        {
            printf("%s", goods[i].name);
            printf("%s", goods[i].maker);
            printf("%u\n", goods[i].price);
            printf("%u\n", goods[i].amount);
            flag_found = 1;
        }
    if (flag_found == 0)
        return INV_INPUT;
    else
        return SUCCESS;
}

int save_to_new_file_txt(char *filename, product goods[QUANTITY], int n)
{
    FILE *f = fopen(filename, "w");
    if (f == NULL)
        return INV_FILE;
    for (int i = 0; i < n; i++)
    {
        fprintf(f, "%s", goods[i].name);
        fprintf(f, "%s", goods[i].maker);
        fprintf(f, "%u\n", goods[i].price);
        fprintf(f, "%u\n", goods[i].amount);
    }
    fclose(f);
    return SUCCESS;
}

int main(int argc, char *argv[])
{
    product goods[QUANTITY];
    int n = 0;
    if (argc != 4 && argc != 3)
        return CMD_INV;
    if (argc == 4)
    {
        char *key = argv[1];
        char *file_name_in = argv[2];
        char *file_name_out = argv[3];
        char *substr = argv[3];
        if (strcmp(key, "st") == 0)
        {
            if (input_qoods_txt(file_name_in, goods, &n) != SUCCESS)
                return INV_INPUT_ST;
            sort_by_price_txt(goods, n);
            if (save_to_new_file_txt(file_name_out, goods, n) != SUCCESS)
                return INV_SAVE_TO_FILE_ST;
        }
        else if (strcmp(key, "ft") == 0)
        {
            if (input_qoods_txt(file_name_in, goods, &n) != SUCCESS)
                return INV_INPUT_FT;
            if (search_print_substr(substr, n, goods) != SUCCESS)
                return INV_SEARCH_FT;
        }
        else
            return CMD_INV;
    }

    if (argc == 3)
    {
        char *key = argv[1];
        char *file_name_in_out = argv[2];
        product new_product = { "a", "b", 5, 5 };
        FILE *f = stdin;
        int pos = 0;
        if (strcmp(key, "at") == 0)
        {
            if (input_qoods_txt(file_name_in_out, goods, &n) != SUCCESS)
                return INV_INPUT_AT;
            if (input_new_product(&new_product, f) != SUCCESS)
                return INV_INPUT_NEW_PRODUCT_AT;
            if (search_pos_for_new_product(&new_product, goods, n, file_name_in_out, &pos) != SUCCESS)
                return INV_SEARCH_AT;
            add_new_product_to_product(&new_product, goods, &n, pos);
            if (save_to_new_file_txt(file_name_in_out, goods, n) != SUCCESS)
                return INV_SAVE_AT;
        }
        else
            return CMD_INV;
    }
    return SUCCESS;
}
