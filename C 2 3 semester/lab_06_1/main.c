#include <stdio.h>
#include "string.h"

#define N 100
#define SUCCESS 0
#define FAIL -1
char *my_strpbrk(char str1[N], char str2[N])
{
    int i = 0, j;
    while (str1[i] != '\0')
    {
        j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
                return str1 + i;
            j++;
        }
        i++;
    }
    return NULL;
}

unsigned long my_strspn(char str1[N], char str2[N])
{
    int i = 0, j = 0;
    unsigned long quantity = 0;
    unsigned long tek = 0;
    while (str1[i] != '\0')
    {
        j = 0;
        tek = 0;
        while (str2[j] != '\0')
        {
            if (str2[j] == str1[i])
                tek++;
            j++;
        }
        if (tek == 0 && quantity == 0)
            return 0;
        else if (tek == 0 && quantity != 0)
            break;
        else
            quantity++;
        i++;
    }
    return quantity;
}

unsigned long my_strcspn(char str1[N], char str2[N])
{
    unsigned long i = 0;
    int j = 0;
    unsigned long quantity = 0;
    while (str1[i] != '\0')
    {
        j = 0;
        while (str2[j] != '\0')
        {
            if (str1[i] == str2[j])
                return quantity;
            j++;
        }
        quantity++;
        i++;
    }
    return i;
}

char *my_strchr(char str1[N], int digit)
{
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == digit)
            return str1 + i;
        i++;
    }
    if (digit == '\0')
        return str1 + i;
    return NULL;
}
char *my_strrchr(char str1[N], int digit)
{
    char *index = NULL;
    int i = 0;
    while (str1[i] != '\0')
    {
        if (str1[i] == digit)
            index = str1 + i;
        i++;
    }
    if (digit == '\0')
        return str1 + i;
    return index;
}

int main()
{
    char str1[] = "debug";
    char str2[] = "abc";
    if (strcmp(my_strpbrk(str1, str2), strpbrk(str1, str2)) != 0)
        return FAIL;

    char str3[] = "debug";
    char str4[] = "yuz";
    if (strcmp(my_strpbrk(str3, str4), strpbrk(str3, str4)) != 0)
        return FAIL;

    char str32[] = "wallwall";
    char str42[] = "aw";
    if (strcmp(my_strpbrk(str32, str42), strpbrk(str32, str42)) != 0)
        return FAIL;

    char str31[] = "book";
    char str41[] = "abco";
    if (strcmp(my_strpbrk(str31, str41), strpbrk(str31, str41)) != 0)
        return FAIL;

    char str5[] = "creator";
    char str6[] = "qtcreat";
    if (my_strspn(str5, str6) != strspn(str5, str6))
        return FAIL;

    char str7[] = "qtcreator";
    char str8[] = "main";
    if (my_strspn(str7, str8) != strspn(str7, str8))
        return FAIL;

    char str71[] = "qtcreator";
    char str81[] = "qtcreator";
    if (my_strspn(str71, str81) != strspn(str71, str81))
        return FAIL;

    char str72[] = "";
    char str82[] = "qtcreator";
    if (my_strspn(str72, str82) != strspn(str72, str82))
        return FAIL;

    char str9[] = "refrigerator";
    char str10[] = "ger";
    if (my_strcspn(str9, str10) != strcspn(str9, str10))
        return FAIL;

    char str11[] = "refrigerator";
    char str12[] = "yuzqw";
    if (my_strcspn(str11, str12) != strcspn(str11, str12))
        return FAIL;

    char str13[] = "book";
    int symbol1 = 'o';
    if (strcmp(my_strchr(str13, symbol1), strchr(str13, symbol1)) != 0)
        return FAIL;

    char str14[] = "star wars";
    int symbol2 = '1';
    if (my_strchr(str14, symbol2) != strchr(str14, symbol2))
        return FAIL;

    char str15[] = "This is a sample string";
    int symbol3 = 's';
    if (strcmp(my_strrchr(str15, symbol3), strrchr(str15, symbol3)) != 0)
        return FAIL;

    char str17[] = "b0ok";
    int symbol5 = '0';
    if (strcmp(my_strrchr(str17, symbol5), strrchr(str17, symbol5)) != 0)
        return FAIL;

    char str16[] = "IU7";
    int symbol4 = '8';
    if (my_strrchr(str16, symbol4) != strrchr(str16, symbol4))
        return FAIL;

    return SUCCESS;
}
