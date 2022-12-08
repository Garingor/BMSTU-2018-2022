#include <stdio.h>
#include <string.h>

#define K 100
#define N 257
#define N_MAX 260
#define M 16
#define L 8
#define INV_INP -1
#define INV_LEX 0
#define SUCCESS 0

int input_string(char str_input[N])
{
    int i = 0;
    if (fgets(str_input, N_MAX, stdin) == NULL)
        return INV_INP;
    else if (strcmp(str_input, "") == 0)
        return INV_INP;
    while (str_input[i] != '\0')
        i++;
    if (i > N)
        return INV_INP;
    return SUCCESS;
}

int detect_lexema(char str)
{
    char str_lexeme[9] = " ?!.-:;,";
    int j = 0;
    while (j < L)
    {
        if (str_lexeme[j] == str)
            return 1;
        j++;
    }
    return 0;
}

int split_string(char str_input[N], char str[K][M])
{
    int i = 0;
    int h = 0, m = 0;
    int flag_word = 0;
    int flag_space = 0;
    while (str_input[i] != '\0')
    {
        m = 0;
        while (detect_lexema(str_input[i]) && str_input[i] != '\0' && str_input[i] != '\n')
        {
            i++;
            flag_space = 1;
        }
        while (!detect_lexema(str_input[i]) && str_input[i] != '\0' && str_input[i] != '\n')
        {
            str[h][m] = str_input[i];
            i++;
            m++;
            if (m > M)
                return INV_INP;
            flag_word = 1;
            flag_space = 0;
        }
        h++;
        i++;
    }
    if (flag_space == 1)
        h--;
    if (flag_word == 0)
        return INV_INP;
    else
        return h - 1;
}

void change_words(char str[N][M], int j)
{
    char temp[M] = { 0 };
    strcpy(temp, str[j]);
    strcpy(str[j], str[j + 1]);
    strcpy(str[j + 1], temp);
}

int remove_duplicate_words(char str[N][M], int n)
{
    char tek[M] = { 0 };
    int i = 0;
    int j = 0;
    while (i < n)
    {
        strcpy(tek, str[i]);

        j = i + 1;
        while (j <= n)
        {
            if (strcmp(tek, str[j]) == 0)
            {
                for (int k = j; k < n; k++)
                    strcpy(str[k], str[k + 1]);
                j--;
                n--;
            }
            j++;
        }
        i++;
    }
    return n;
}

int sort_string(char str[N][M], int n)
{
    int j = 0;
    int i = 0;
    n = remove_duplicate_words(str, n);
    while (i < n)
    {
        j = 0;
        while (j < n - i)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
                change_words(str, j);
            j++;
        }
        i++;
    }
    return n;
}

void output_string(char str[N][M], int n)
{
    printf("Result: ");
    for (int i = 0; i <= n; i++)
        printf("%s ", str[i]);
}


int main()
{
    char str[K][M] = { { 0 } };
    char str_input[N] = { 0 };
    int quantity = 0;

    if (input_string(str_input) == -1)
        return INV_INP;
    quantity = split_string(str_input, str);
    if (quantity < 0)
        return INV_INP;

    quantity = sort_string(str, quantity);

    output_string(str, quantity);

    return SUCCESS;
}
