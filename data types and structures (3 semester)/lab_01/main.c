#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_INT_N 30
#define MAX_MANTISSA_N 100 // 52
#define OVERFLOW_INT_N 32
#define OVERFLOW_FLOAT_N 37
#define SUCCESS 0
#define INV_INPUT -1

int input_int(char*);
int input_float(char*, int*, int*);
int multiplication_of_numbers(int, int, char*, char*, int, int);

int main()
{
    char int_num[OVERFLOW_INT_N];
    char float_num[OVERFLOW_FLOAT_N];
    int n_int;
    int n_float;
    int flag_e = 0;
    int flag_pointer = 0;

    if ((n_int = input_int(int_num)) == INV_INPUT)
        return INV_INPUT;
    if ((n_float = input_float(float_num, &flag_e, &flag_pointer)) == INV_INPUT)
        return INV_INPUT;

    multiplication_of_numbers(n_int, n_float, int_num, float_num, flag_e, flag_pointer);

    return SUCCESS;
}

int input_int(char *int_num)
{
    printf("Программа: умножение целого числа на вещественное число (3 вариант)\n");
    printf("Условия ввода целого числа:\n");
    printf("1. максимальная длина целого числа 30 символов\n");
    printf("2. Сначала обязательно вводится знак числа, за ним без пробела вводится само целое число\n");
    printf("3. целое число вводится в виде ±m \n");
    printf("Введите целое число:\n±");

    for (int i = 0; i < MAX_INT_N; i++)
        printf("|");
    printf(" 30\n");

    int i = 0;
    while (scanf("%c",&int_num[i]) && int_num[i] != '\n' && i != OVERFLOW_INT_N)
    {
        if (int_num[0] != '+' && int_num[0] != '-')
        {
            printf("ERROR: Неккоректный ввод знака целого числа\n");
            return INV_INPUT;
        }
        else if ((int_num[i] > '9' || int_num[i] < '0') && i != 0)
        {
            printf("ERROR: Неккоректный ввод цифр целого числа\n");
            return INV_INPUT;
        }
        i++;
    }

    if (i == OVERFLOW_INT_N)
    {
        printf("ERROR: Длина числа превышает 30 десятичных цифр\n");
        return INV_INPUT;
    }
    else if (i == 0 || i == 1)
    {
        printf("ERROR: Длина числа должна быть больше нуля\n");
        return INV_INPUT;
    }

    return i;
}

int input_float(char *float_num, int *flag_e, int *flag_pointer)
{
    printf("Условия ввода вещественного числа:\n");
    printf("1. максимальная длина мантиссы вещественного числа 30 символов\n");
    printf("2. Сначала обязательно вводится знак числа, за ним без пробела вводится само вещественное число\n");
    printf("3. вещественное число вводится в виде ±m, ±m E±K, ±m.n, ±m.n E±K \n");
    printf("4. после ввода Е необходимо ввести знак порядка \n");
    printf("Введите вещественное число:\n±");

    for (int i = 0; i < 30; i++)
        printf("|");
    printf("E±|||||\n");

    int i = 0;
    while(scanf("%c", &float_num[i]) && float_num[i] != '\n')
        i++;

    int flag_trash = 0;

    if (float_num[0] == 'E')
        (*flag_e)++;
    else if (float_num[0] == '.') ///обработка первой точки, + или -
        (*flag_pointer)++;
    else if (float_num[0] != '+' && float_num[0] != '-' && (float_num[0] < '0' || float_num[0] > '9'))
        flag_trash = 1;

    int j = 1;
    while (j < i)
    {
        if (float_num[j] == 'E' && j + 1 < i && j - 1 >= 0 && (float_num[j + 1] == '+' ||
                                                               float_num[j + 1] == '-' ||
                                                               float_num[j + 1] < '0'  ||
                                                               float_num[j + 1] > '9'))
        {
            (*flag_e)++;
            j++;
        }
        else if (float_num[j] == '.')
            (*flag_pointer)++;
        else if ((float_num[j] == '+' || float_num[j] == '-') && j - 1 >= 0 && float_num[j - 1] != 'E')
            flag_trash = 1;
        else if (float_num[j] < '0' || float_num[j] > '9')
            flag_trash = 1;
        j++;  //нахождение неккоректного ввода вещественного числа

    }

    if (flag_trash == 1 || *flag_e > 1 || *flag_pointer > 1)
    {
        printf("ERROR: Неккоректный ввод вещественного числа\n");
        return INV_INPUT;
    }

    int check_mantissa = 0;
    int check_poradok = 0;
    j = 1;
    while(j < i) // проверка длины мантиссы и порядка
    {
        if (float_num[j] == 'E')
        {
            j += 2;
            while(j < i)
            {
                check_poradok++;
                j++;
            }
            break;
        }
        if (float_num[j] == '.')
            check_mantissa--;
        check_mantissa++;
        j++;
    }

    if (check_mantissa > 30)
    {
        printf("ERROR: Длина мантиссы вещественного числа превышает 30 символов\n");
        return INV_INPUT;
    }

    if (check_poradok > 5)
    {
        printf("ERROR: Длина порядка вещественного числа превышает 5 символов\n");
        return INV_INPUT;
    }

    if (i == 0 || i == 1)
    {
        printf("ERROR: Длина числа должна быть больше нуля\n");
        return INV_INPUT;
    }
    return i;
}

int multiplication_of_numbers(int n_int, int n_float, char *int_num, char* float_num, int flag_e, int flag_pointer)
{
    int mantissa[MAX_MANTISSA_N] = {0};
    int smejenie = 0;
    int tek_cislo = 0;
    int k = 0;
    int i;
    int flag_poradok = 0;
    char poradok_char[6];
    int poradok = 0;
    int n_float_poradok = 0;
    if (flag_e == 1) // вычисление порядка (глобально)
    {
        i = 0;
        int h = 0;
        while (float_num[i] != 'E')
            i++;

        int b = 0;
        if (flag_pointer == 1)
            while(float_num[b] != '.')
            {
                if (float_num[b] != '+' && float_num[b] != '-') // вычисление порядка
                    poradok++;
                b++;
            }
        else
        {
            b = 0;
            while(float_num[b] != 'E') // вычисление порядка
            {
                if (float_num[b] != '+' && float_num[b] != '-')
                    poradok++;
                b++;
            }
        }

        b = 0;
        while(float_num[b] != 'E')
        {
            if (float_num[b] != '+' && float_num[b] != '-' && float_num[b] != '.') // вычисление длины мантиссы
                n_float_poradok++;
            b++;
        }
        i = 0;
        while (float_num[i] != 'E')
            i++;
        int check_n_float = i;

        i++;
        if (float_num[i] == '-') // флаг на отрицательное число
            flag_poradok = 1;
        i++;
        for (; i < n_float; i++)
        {
            poradok_char[h] = float_num[i];
            h++;
        }
        if (flag_poradok == 1)
            poradok -= atoi(poradok_char); // порядок из char в int
        else
            poradok += atoi(poradok_char);
        n_float = check_n_float; // кол-во чисел до "E"
    }
    else if (flag_pointer == 1)
    {

        i = 0;
        int b = 0;
        while(b < n_float)
        {
            if (float_num[b] != '+' && float_num[b] != '-' && float_num[b] != '.') // вычисление длины мантиссы
                n_float_poradok++;
            b++;
        }
        while (float_num[i] != '.')
        {
            if (float_num[i] != '+' && float_num[i] != '-') // вычисление порядка
                poradok++;
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < n_float)
        {
            if(float_num[i] != '+' && float_num[i] != '-') // вычисление порядка
                poradok++;
            i++;
        }
        n_float_poradok = poradok;
    }

    int tek_mant;
    for(i = n_float - 1; i >= 0; i--) // алгоритм умножения числа на число
    {
        if (float_num[i] != '.' && float_num[i] != '+' && float_num[i] != '-' && float_num[i] != 'E')
        {
            for (int j = n_int - 1; j >= 0; j--)
            {
                if (int_num[j] != '+' && int_num[j] != '-')
                {
                    tek_cislo = (float_num[i] - '0') * (int_num[j] - '0');
                    if (tek_cislo > 9)
                    {
                        if (mantissa[MAX_MANTISSA_N - k - smejenie - 1] + (tek_cislo % 10) > 9)
                        {
                            tek_mant = mantissa[MAX_MANTISSA_N - k - smejenie - 1] + (tek_cislo % 10);
                            mantissa[MAX_MANTISSA_N - k - smejenie - 1] = tek_mant % 10;
                            mantissa[MAX_MANTISSA_N - k - smejenie - 2] += tek_mant / 10;
                            mantissa[MAX_MANTISSA_N - k - smejenie - 2] += tek_cislo / 10;
                            if (mantissa[MAX_MANTISSA_N - k - smejenie - 2] > 9)
                            {
                                tek_mant = mantissa[MAX_MANTISSA_N - k - smejenie - 2];
                                mantissa[MAX_MANTISSA_N - k - smejenie - 2] = tek_mant % 10;
                                mantissa[MAX_MANTISSA_N - k - smejenie - 3] += tek_mant / 10;
                            }
                        }
                        else
                        {
                            mantissa[MAX_MANTISSA_N - k - smejenie - 1] += (tek_cislo % 10);
                            mantissa[MAX_MANTISSA_N - k - smejenie - 2] += tek_cislo / 10;
                            if (mantissa[MAX_MANTISSA_N - k - smejenie - 2] > 9)
                            {
                                tek_mant = mantissa[MAX_MANTISSA_N - k - smejenie - 2];
                                mantissa[MAX_MANTISSA_N - k - smejenie - 2] = tek_mant % 10;
                                mantissa[MAX_MANTISSA_N - k - smejenie - 3] += tek_mant / 10;
                            }
                        }
                    }
                    else
                    {
                        if (mantissa[MAX_MANTISSA_N - k - smejenie - 1] + tek_cislo > 9)
                        {
                            tek_mant = mantissa[MAX_MANTISSA_N - k - smejenie - 1] + tek_cislo;
                            mantissa[MAX_MANTISSA_N - k - smejenie - 1] = tek_mant % 10;
                            mantissa[MAX_MANTISSA_N - k - smejenie - 2] += tek_mant / 10;
                            if (mantissa[MAX_MANTISSA_N - k - smejenie - 2] > 9)
                            {
                                tek_mant = mantissa[MAX_MANTISSA_N - k - smejenie - 2];
                                mantissa[MAX_MANTISSA_N - k - smejenie - 2] = tek_mant % 10;
                                mantissa[MAX_MANTISSA_N - k - smejenie - 3] += tek_mant / 10;
                            }
                        }
                        else
                            {
                            mantissa[MAX_MANTISSA_N - k - smejenie - 1] += tek_cislo;
                            mantissa[MAX_MANTISSA_N - k - smejenie - 2] += tek_cislo / 10;
                            if (mantissa[MAX_MANTISSA_N - k - smejenie - 2] > 9)
                            {
                                tek_mant = mantissa[MAX_MANTISSA_N - k - smejenie - 2];
                                mantissa[MAX_MANTISSA_N - k - smejenie - 2] = tek_mant % 10;
                                mantissa[MAX_MANTISSA_N - k - smejenie - 3] += tek_mant / 10;
                            }
                        }
                    }
                }
                k++;
            }
            k = 0;
            smejenie++;
        }
    }

    i = 0;
    while (mantissa[i] == 0)
        i++;

    int correct_poradok = 0;
    while (i < MAX_MANTISSA_N) // кол-во цифр в результате (для порядка)
    {
        correct_poradok++;
        i++;
    }

    if (correct_poradok != n_float_poradok) // корректировка порядка в соответствии с результатом
        poradok += correct_poradok - n_float_poradok;

    printf("результат вычислений:\n");
    for (i = 0; i < MAX_MANTISSA_N; i++)
        if (mantissa[i] != 0)
            break;

    if (i == MAX_MANTISSA_N)
    {
        printf("0");
        return SUCCESS;
    }

    int j = 0;
    while (mantissa[j] == 0 && j < MAX_MANTISSA_N)
        j++;

    int max_len_mant = MAX_MANTISSA_N - 1;
    int flag_perepoln = 0;
    if (MAX_MANTISSA_N - j > 30 && mantissa[j + 30] >= 5) // округление по правилам математики
    {
        max_len_mant = j + 30 - 1;
        flag_perepoln = 1;
        i = j + 30;
        while (i >= j)
        {
            if (mantissa[i] == 0)
            {
                mantissa[i]++;
                break;
            }
            else if (mantissa[i] == 9)
                mantissa[i] = 0;
            else
                mantissa[i]++;
            i--;
        }
        mantissa[j + 30] = 0;
    }
    else if (MAX_MANTISSA_N - j > 30)
    {
        max_len_mant = j + 30 - 1;
        flag_perepoln= 1;
    }

    if (poradok > 99999 || poradok < -99999) // переполнение порядка
    {
        printf("переполнение порядка\n");
        return INV_INPUT;
    }

    //вывод в нормализованом виде
    if (int_num[0] == '-' && float_num[0] == '+')
        printf("-0.");
    else if (int_num[0] == '+' && float_num[0] == '-')
        printf("-0.");
    else
        printf("+0.");

    i = MAX_MANTISSA_N - 1; // убирать незначащие нули
    while (mantissa[i] == 0 && i > j)
        i--;
    if (flag_perepoln == 0 || i < MAX_MANTISSA_N - 1)
        max_len_mant = i;

    for (;j <= max_len_mant; j++)
        printf("%d", mantissa[j]);
    if (poradok >= 0)
        printf("E+%d", poradok);
    else
        printf("E%d", poradok);

    return SUCCESS;
}
