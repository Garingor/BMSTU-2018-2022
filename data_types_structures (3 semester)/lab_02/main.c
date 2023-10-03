#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

#define QUANTITY 60   // кол - во строк таблицы
#define MAX_CHECK 100 // максимальная длина строки для проверки введенных данных

enum success_codes // функции успешно выполнены
{
    SUCCESS,
    SUCCESS_READ
};

enum error_operations // коды ошибок операций
{
    INV_INPUT,
    INV_FILE,
    INV_NAME,
    INV_SURNAME,
    INV_TEL,
    INV_ADD,
    INV_STATUS,
    INV_DAY,
    INV_MONTH,
    INV_YEAR,
    INV_POST,
    INV_ORGANIZ
};

typedef struct { // структура общих полей

    char name[25];          // имя
    char surname[25];       // фамилия
    char phone_number[25];  // номер телефона
    char address[70];       // адресс
    int status;             // статус
    union {
        struct //структура личных полей
        {
            int day;            // день
            int month;          // месяц
            int year;           // год
        } personal;

        struct //структура служебных полей
        {
            char post[80];          // должность
            char organization[80];  // организация
        } official;

    } status_person;
} subscriber;

typedef struct //структура ключей
{
    int index;              // ключи
    char surname[25];       // поля, по которым сортируем
} key_for_table;

void print_menu();  // печать меню

void print_sub_menu();  // печать менб сортировки

void get_choise(int, int *);  // выбор команды

void print_tabl_line(subscriber *, key_for_table *, int); // печать таблицы по полям

void print_tabl_key(subscriber *, key_for_table *, int); // печать таблицы по ключам

int fill_structure(char *, subscriber *, int *); // первичное считывание данных из файла в структуру

int input_line(subscriber *, key_for_table *, int *); // вставить в конец структуры новую строку

int delete_line(subscriber *, key_for_table *, int *); // удалить выбранную строку

void bubble_sort_key(key_for_table *, int); // сортировка пузырьком ключей

void bubble_sort_line(subscriber *, int); // сортировка пузырьком таблицы

void print_key(key_for_table *, int); // печать таблицы ключей

void find_friend(subscriber *, key_for_table *, int); // найти друзей, которых нужно поздравить

int time_sort(int); // замер времени сортировки

void quick_sort_key(key_for_table *, int, int); // быстрая сортировка ключей

void quick_sort_line(subscriber *, key_for_table *, int, int); // быстрая сортировка полей

int main()
{
    int choice_sort;
    int choice;
    int count = 0;
    int count_sourse = 0;
    char file[] = "../tabliza.txt";
    int flag_sort_key = 0;

    subscriber fields[QUANTITY];
    key_for_table key[QUANTITY];

    subscriber fields_sourse[QUANTITY];
    key_for_table key_sourse[QUANTITY];

    if (fill_structure(file, fields, &count) != SUCCESS)
        return INV_FILE;

    if (fill_structure(file, fields_sourse, &count_sourse) != SUCCESS)
        return INV_FILE;

    for (int i = 0; i < count; i++)
    {
        key[i].index = i + 1;
        strcpy(key[i].surname, fields[i].surname);
    }

    for (int i = 0; i < count_sourse; i++)
    {
        key_sourse[i].index = i + 1;
        strcpy(key_sourse[i].surname, fields_sourse[i].surname);
    }

    do
    {
        print_menu();

        get_choise(9, &choice);

        if (count <= 0)
        {
            choice = 0;
            printf("в таблице нет полей\n");
            printf("Завершение работы программы...\n");
            break;
        }

        if (count > QUANTITY)
        {
            choice = 0;
            printf("Таблица переполнена\n");
            printf("Завершение работы программы...\n");
            break;
        }

        switch (choice)
        {
            case 1:
                if (flag_sort_key == 1)
                    bubble_sort_key(key, count);
                print_tabl_line(fields_sourse, key_sourse, count_sourse);
                break;
            case 2:
                if (flag_sort_key == 1)
                    bubble_sort_key(key, count);
                print_tabl_line(fields, key, count);
                break;

            case 3:
                if (flag_sort_key == 1)
                    bubble_sort_key(key, count);
                print_tabl_key(fields, key, count);
                break;

            case 4:
                input_line(fields, key, &count);
                for (int i = 0; i < count; i++)
                {
                    key[i].index = i + 1;
                    memset(&key[i].surname[0], 0, sizeof(key[i].surname));
                    strcpy(key[i].surname, fields[i].surname);
                }
                if (flag_sort_key == 1)
                    bubble_sort_key(key, count);
                break;

            case 5:
                delete_line(fields, key, &count);
                for (int i = 0; i < count; i++)
                {
                    key[i].index = i + 1;
                    memset(&key[i].surname[0], 0, sizeof(key[i].surname));
                    strcpy(key[i].surname, fields[i].surname);
                }
                if (flag_sort_key == 1)
                    bubble_sort_key(key, count);
                break;

            case 6:
            {
                do
                {
                    print_sub_menu();

                    get_choise(3, &choice_sort);

                    switch (choice_sort)
                    {
                        case 1:
                            bubble_sort_key(key, count);
                            flag_sort_key = 1;
                            break;

                        case 2:
                            bubble_sort_line(fields, count);
                            for (int i = 0; i < count; i++)
                            {
                                key[i].index = i + 1;
                                memset(&key[i].surname[0], 0, sizeof(key[i].surname));
                                strcpy(key[i].surname, fields[i].surname);
                            }
                            break;

                        case 3:
                            print_key(key, count);
                            break;

                    }
                } while (choice_sort != 0);
                break;
            }

            case 7:
                time_sort(count_sourse);
                break;

            case 8:
                find_friend(fields, key, count);
                break;
        }


    } while (choice != 0);

    return SUCCESS;
}

void print_menu()
{
    printf("\n1 - вывод исходной таблицы\n");
    printf("2 - вывод таблицы\n");
    printf("3 - вывод таблицы по ключам\n");
    printf("4 - добавить запись\n");
    printf("5 - удалить запись\n");
    printf("6 - сортировка записи\n");
    printf("7 - замер времени на сортировку\n");
    printf("8 - вывод друзей, которых нужно поздравить\n");
    printf("0 - выход\n");
}

void print_sub_menu()
{
    printf("1 - сортировка таблицы по ключам\n");
    printf("2 - сортировка таблицы по полям\n");
    printf("3 - вывод таблицы ключей\n");
    printf("0 - выход из подменю\n");
}

void get_choise(int max, int *choice)
{
    char stroka[100];

    printf("Введите команду: ");
    scanf("%s", stroka);

    while (sscanf(stroka, "%d", choice) != SUCCESS_READ || (*choice) > max || (*choice) < 0)
    {
        printf("Неверный ввод, попробуйте еще раз\n");
        printf("Введите команду: ");
        scanf("%s", stroka);
    }

}

void print_tabl_line(subscriber *fields , key_for_table *key, int count)
{
    printf("статус: личный = 1, служебный = 0\n");
    printf("|   №  |     Имя    |     Фамилия   |  Номер телефона  |          Адрес               |Статус| Дата рождения |        Должность        |       Организация                      |\n");
    for (int i = 0; i < count; i++)
    {
        printf("|%6d|", i);
        printf("%12s|", fields[i].name);
        printf("%15s|", fields[i].surname);
        printf("%18s|", fields[i].phone_number);
        printf("%30s|", fields[i].address);
        printf("%6d", fields[i].status);

        if (fields[i].status == 1)
        {
            printf("|%2d.", fields[i].status_person.personal.day);
            printf("%2d.", fields[i].status_person.personal.month);
            printf("%4d     |", fields[i].status_person.personal.year);
            printf("-------------------------|----------------------------------------|\n");
        }

        if (fields[i].status == 0)
        {
            printf("|---------------");
            printf("|%25s|", fields[i].status_person.official.post);
            printf("%40s|\n", fields[i].status_person.official.organization);
        }
    }

}

void print_tabl_key(subscriber *fields , key_for_table *key, int count)
{
    printf("статус: личный = 1, служебный = 0\n");
    printf("|   №  |     Имя    |     Фамилия   |  Номер телефона  |          Адрес               |Статус| Дата рождения |        Должность        |       Организация                      |\n");
    for (int i = 0; i < count; i++)
    {
        printf("|%6d|", i);
        printf("%12s|", fields[key[i].index - 1].name);
        printf("%15s|", fields[key[i].index - 1].surname);
        printf("%18s|", fields[key[i].index - 1].phone_number);
        printf("%30s|", fields[key[i].index - 1].address);
        printf("%6d", fields[key[i].index - 1].status);

        if (fields[key[i].index - 1].status == 1)
        {
            printf("|%2d.", fields[key[i].index - 1].status_person.personal.day);
            printf("%2d.", fields[key[i].index - 1].status_person.personal.month);
            printf("%4d     |", fields[key[i].index - 1].status_person.personal.year);
            printf("-------------------------|----------------------------------------|\n");
        }

        if (fields[key[i].index - 1].status == 0)
        {
            printf("|---------------");
            printf("|%25s|", fields[key[i].index - 1].status_person.official.post);
            printf("%40s|\n", fields[key[i].index - 1].status_person.official.organization);
        }
    }

}

int fill_structure(char *name, subscriber *fields , int *count)
{
    int i = 0;
    int len;
    char tek_str[MAX_CHECK];

    FILE *f = fopen(name, "r");

    if (f == NULL)
    {
        fclose(f);
        printf("\nФайл не найден\nзавершение работы программы...\n");
        return INV_FILE;
    }

    while (fgets(tek_str, MAX_CHECK, f) != NULL)
    {
        len = strcspn(tek_str,"\n");
        if (strncmp(tek_str, "...", len) == 0)
        {
            continue;
        }

        memset(&fields[i].name[0], 0, sizeof(fields[i].name));
        strncpy(fields[i].name, tek_str, len);

        if (fgets(tek_str, MAX_CHECK, f) != NULL)
        {
            len = strcspn(tek_str,"\n");
            memset(&fields[i].surname[0], 0, sizeof(fields[i].surname));
            strncpy(fields[i].surname, tek_str, len);
        }


        if (fgets(tek_str, MAX_CHECK, f) != NULL)
        {
            len = strcspn(tek_str,"\n");
            memset(&fields[i].phone_number[0], 0, sizeof(fields[i].phone_number));
            strncpy(fields[i].phone_number, tek_str, len);
        }

        if (fgets(tek_str, MAX_CHECK, f) != NULL)
        {
            len = strcspn(tek_str,"\n");
            memset(&fields[i].address[0], 0, sizeof(fields[i].address));
            strncpy(fields[i].address, tek_str, len);
        }

        if (fgets(tek_str, MAX_CHECK, f) != NULL)
        {
            sscanf(tek_str, "%d", &fields[i].status);
            if (fields[i].status == 1)
            {

                if (fgets(tek_str, MAX_CHECK, f) != NULL)
                    sscanf(tek_str, "%d", &fields[i].status_person.personal.day);

                if (fgets(tek_str, MAX_CHECK, f) != NULL)
                    sscanf(tek_str, "%d", &fields[i].status_person.personal.month);
                if (fgets(tek_str, MAX_CHECK, f) != NULL)
                    sscanf(tek_str, "%d", &fields[i].status_person.personal.year);
            }
            else if (fields[i].status == 0)
            {
                if (fgets(tek_str, MAX_CHECK, f) != NULL)
                {
                    len = strcspn(tek_str, "\n");
                    memset(&fields[i].status_person.official.post[0], 0, sizeof(fields[i].status_person.official.post));
                    strncpy(fields[i].status_person.official.post, tek_str, len);
                }

                if (fgets(tek_str, MAX_CHECK, f) != NULL)
                {
                    len = strcspn(tek_str, "\n");
                    memset(&fields[i].status_person.official.organization[0], 0, sizeof(fields[i].status_person.official.organization));
                    strncpy(fields[i].status_person.official.organization, tek_str, len);
                }
            }
        }

        i++;
    }

    *count = i;

    fclose(f);
    return SUCCESS;
}

int input_line(subscriber *fields , key_for_table *key, int *count)
{
    char tek_str[50];

    printf("\nВведите следующие данные:\n\n");

    printf("Имя не должно превышать 15 символов\n");
    printf("Имя вводится с большой буквы\n");
    printf("Введите имя: ");
    if (scanf("%s", tek_str) != 1)
    {
        printf("\nИмя введено неверно\n");
        printf("Выход в главное меню...\n");
        return INV_NAME;
    }
    if (strlen(tek_str) > 15 || strlen(tek_str) < 1)
    {
        printf("\nДлина имени больше 15 символов или меньше 1 символа\n");
        printf("Выход в главное меню...\n");
        return INV_NAME;
    }
    if (tek_str[0] < 'A' || tek_str[0] > 'Z')
    {
        printf("\nИмя введено не с большой буквы\n");
        printf("Выход в главное меню...\n");
        return INV_NAME;
    }
    for (int i = 1; i < strlen(tek_str); i++)
    {
        if (tek_str[i] < 'a' || tek_str[i] > 'z')
        {
            printf("\nИмя введено некорректно\n");
            printf("Выход в главное меню...\n");
            return INV_NAME;
        }
    }
    memset(&fields[*count].name[0], 0, sizeof(fields[*count].name));
    strcpy(fields[*count].name, tek_str);
    memset(&tek_str[0], 0, sizeof(tek_str));

    printf("\nФамилия не должна превышать 20 символов\n");
    printf("Фамилия вводится с большой буквы\n");
    printf("Введите фамилию: ");
    if (scanf("%s", tek_str) != 1)
    {
        printf("\nФамилия введена неверно\n");
        printf("Выход в главное меню...\n");
        return INV_SURNAME;
    }
    if (strlen(tek_str) > 20 || strlen(tek_str) < 1)
    {
        printf("\nДлина фамилии больше 20 символов или меньше 1 символа\n");
        printf("Выход в главное меню...\n");
        return INV_SURNAME;
    }
    if (tek_str[0] < 'A' || tek_str[0] > 'Z')
    {
        printf("\nФамилия введено не с большой буквы\n");
        printf("Выход в главное меню...\n");
        return INV_NAME;
    }
    for (int i = 1; i < strlen(tek_str); i++)
    {
        if (tek_str[i] < 'a' || tek_str[i] > 'z')
        {
            printf("\nФамилия введена некорректно\n");
            printf("Выход в главное меню...\n");
            return INV_NAME;
        }
    }
    memset(&fields[*count].surname[0], 0, sizeof(fields[*count].surname));
    strcpy(fields[*count].surname, tek_str);
    memset(&tek_str[0], 0, sizeof(tek_str));

    printf("\nНомер телефона должен иметь не меньше 10 цифр\n");
    printf("Введите номер телефона: ");
    if (scanf("%s", tek_str) != 1)
    {
        printf("\nНомер телефона введен неверно\n");
        printf("Выход в главное меню...\n");
        return INV_TEL;
    }

    if (strlen(tek_str) < 10)
    {
        printf("Длина номера телефона меньше 10 символов\n");
        printf("Выход в главное меню...\n");
        return INV_TEL;
    }
    for (int i = 0; i < strlen(tek_str); i++)
    {
        if ((tek_str[i] < '0' || tek_str[i] > '9') && tek_str[i] != '(' && tek_str[i] != ')' && tek_str[i] != '-' && tek_str[i] != '+')
        {
            printf("\nВ номере телефона присутствуют недопустимые символы\n");
            printf("Выход в главное меню...\n");
            return INV_TEL;
        }
    }
    memset(&fields[*count].phone_number[0], 0, sizeof(fields[*count].phone_number));
    strcpy(fields[*count].phone_number, tek_str);
    memset(&tek_str[0], 0, sizeof(tek_str));

    printf("\nАдрес не должен превышать 40 символов\n");
    printf("Введите адрес: ");


    char buffer[MAX_CHECK];
    fgets(buffer, sizeof(buffer), stdin);

    if (fgets(tek_str, sizeof(tek_str), stdin) != NULL)
    {
        if (strlen(tek_str) > 40 || strlen(tek_str) < 1)
        {
            printf("\nДлина адреса больше 40 символов или меньше 1 симвовола\n");
            printf("Выход в главное меню...\n");
            return INV_ADD;
        }
        int len = strcspn(tek_str, "\n");
        memset(&fields[*count].address[0], 0, sizeof(fields[*count].address));
        strncpy(fields[*count].address, tek_str, len);
    }
    else
    {
        printf("\nАдрес введен неверно\n");
        printf("Выход в главное меню...\n");
        return INV_ADD;
    }

    printf("Статус должен быть цифрой (личный == 1, служебный == 0)\n");
    printf("Введите статус: ");
    if (scanf("%d", &fields[*count].status) != 1)
    {
        printf("\nСтатус введен неверно\n");
        printf("Выход в главное меню...\n");
        return INV_STATUS;
    }
    if (fields[*count].status != 0 && fields[*count].status != 1)
    {
        printf("\nСтатус введен неккоректно\n");
        printf("Выход в главное меню...\n");
        return INV_STATUS;
    }

    if (fields[*count].status == 1)
    {
        printf("\nДень не должен меньше 1 и больше 31\n");
        printf("Введите день: ");
        if (scanf("%d", &fields[*count].status_person.personal.day) != 1)
        {
            printf("\nДень введен неверно\n");
            printf("Выход в главное меню...\n");
            return INV_DAY;
        }

        if (fields[*count].status_person.personal.day < 1 || fields[*count].status_person.personal.day > 31)
        {
            printf("\nВведенный день меньше 1 или больше 31\n");
            printf("Выход в главное меню...\n");
            return INV_DAY;
        }

        printf("\nМесяц не должен меньше 1 и больше 12\n");
        printf("Введите месяц: ");
        if (scanf("%d", &fields[*count].status_person.personal.month) != 1)
        {
            printf("\nМесяц введен неверно\n");
            printf("Выход в главное меню...\n");
            return INV_MONTH;
        }
        if (fields[*count].status_person.personal.month < 1 || fields[*count].status_person.personal.month > 12)
        {
            printf("\nВведенный месяц меньше 1 или больше 12\n");
            printf("Выход в главное меню...\n");
            return INV_DAY;
        }

        printf("\nГод не должен больше 2019\n");
        printf("Введите год: ");
        if (scanf("%d", &fields[*count].status_person.personal.year) != 1)
        {
            printf("\nГод введен неверно\n");
            printf("Выход в главное меню...\n");
            return INV_YEAR;
        }
        if (fields[*count].status_person.personal.year > 2019)
        {
            printf("\nВведенный год больше 2019\n");
            printf("Выход в главное меню...\n");
            return INV_YEAR;
        }

    }

    if (fields[*count].status == 0)
    {
        printf("\nДолжность не должна превышать 30 символов\n");
        printf("Введите должность: ");

        fgets(buffer, sizeof(buffer), stdin);

        if (fgets(tek_str, sizeof(tek_str), stdin) != NULL)
        {
            if (strlen(tek_str) > 30 || strlen(tek_str) < 1)
            {
                printf("\nДлина должности больше 30 символов или меньше 1 символа\n");
                printf("Выход в главное меню...\n");
                return INV_POST;
            }
            int len = strcspn(tek_str, "\n");
            memset(&fields[*count].status_person.official.post[0], 0, sizeof(fields[*count].status_person.official.post));
            strncpy(fields[*count].status_person.official.post, tek_str, len);
            memset(&tek_str[0], 0, sizeof(tek_str));
        }
        else
        {
            printf("\nДолжность введена неверно\n");
            printf("Выход в главное меню...\n");
            return INV_POST;
        }

        printf("\nОрганизация не должна превышать 30 символов\n");
        printf("Введите организацию: ");

        if (fgets(tek_str, sizeof(tek_str), stdin) != NULL)
        {
            if (strlen(tek_str) > 30 || strlen(tek_str) < 1)
            {
                printf("\nДлина организации больше 30 символов или меньше 1 символа\n");
                printf("Выход в главное меню...\n");
                return INV_ORGANIZ;
            }
            int len = strcspn(tek_str, "\n");
            memset(&fields[*count].status_person.official.organization[0], 0, sizeof(fields[*count].status_person.official.organization));
            strncpy(fields[*count].status_person.official.organization, tek_str, len);
            memset(&tek_str[0], 0, sizeof(tek_str));
        }
        else
        {
            printf("\nОрганизация введена неверно\n");
            printf("Выход в главное меню...\n");
            return INV_ORGANIZ;
        }
    }

    (*count)++;

    key[(*count) - 1].index = *count;
    strcpy(key[(*count) - 1].surname, fields[(*count) - 1].surname);

    return SUCCESS;
}

int delete_line(subscriber *fields, key_for_table *key, int *count)
{
    int del_str;

    printf("Какую строчку удалить в таблице: ");
    if (scanf("%d", &del_str) != 1)
        return INV_INPUT;
    if (del_str < 0 || del_str > *count - 1)
    {
        printf("строчка не найдена, выход в главное меню...\n");
        return SUCCESS;
    }

    for (int i = del_str; i < (*count) - 1; i++)
    {
        memset(&fields[i].name, 0, sizeof(fields[i].name));
        memset(&fields[i].surname, 0, sizeof(fields[i].surname));
        memset(&fields[i].phone_number, 0, sizeof(fields[i].phone_number));
        memset(&fields[i].address, 0, sizeof(fields[i].address));
        if (fields[i].status == 1)
        {
            memset(&fields[i].status, 0, sizeof(fields[i].status));
            memset(&fields[i].status_person.personal.day, 0, sizeof(fields[i].status_person.personal.day));
            memset(&fields[i].status_person.personal.month, 0, sizeof(fields[i].status_person.personal.month));
            memset(&fields[i].status_person.personal.year, 0, sizeof(fields[i].status_person.personal.year));
        }

        if (fields[i].status == 0)
        {
            memset(&fields[i].status, 0, sizeof(fields[i].status));
            memset(&fields[i].status_person.official.post, 0, sizeof(fields[i].status_person.official.post));
            memset(&fields[i].status_person.official.organization, 0, sizeof(fields[i].status_person.official.organization));
        }

        strcpy(fields[i].name,fields[i + 1].name);
        strcpy(fields[i].surname,fields[i + 1].surname);
        strcpy(fields[i].phone_number, fields[i + 1].phone_number);
        strcpy(fields[i].address, fields[i + 1].address);
        fields[i].status = fields[i + 1].status;

        if (fields[i].status == 1)
        {
            fields[i].status_person.personal.day = fields[i + 1].status_person.personal.day;
            fields[i].status_person.personal.month = fields[i + 1].status_person.personal.month;
            fields[i].status_person.personal.year = fields[i + 1].status_person.personal.year;
        }

        if (fields[i].status == 0)
        {
            strcpy(fields[i].status_person.official.post, fields[i + 1].status_person.official.post);
            strcpy(fields[i].status_person.official.organization, fields[i + 1].status_person.official.organization);
        }

    }

    (*count)--;

    return SUCCESS;
}

void bubble_sort_key(key_for_table *key, int count)
{
    int temp;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(key[key[j].index - 1].surname, key[key[j + 1].index - 1].surname) > 0)
            {
                temp = key[j].index;
                key[j].index = key[j + 1].index;
                key[j + 1].index = temp;
            }
        }
    }
}

void bubble_sort_line(subscriber *fields ,int count)
{
    subscriber temp_char_sub;
    subscriber temp_char_per;
    subscriber temp_char_work;

    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - i - 1; j++)
        {
            if (strcmp(fields[j].surname, fields[j + 1].surname) > 0)
            {
                temp_char_sub = fields[j];
                fields[j] = fields[j + 1];
                fields[j + 1] = temp_char_sub;

                temp_char_per.status_person.personal = fields[j].status_person.personal;
                fields[j].status_person.personal = fields[j + 1].status_person.personal;
                fields[j + 1].status_person.personal = temp_char_per.status_person.personal;

                temp_char_work.status_person.official = fields[j].status_person.official;
                fields[j].status_person.official = fields[j + 1].status_person.official;
                fields[j + 1].status_person.official = temp_char_work.status_person.official;
            }
        }
    }
}

void print_key(key_for_table *key, int count)
{
    printf("|   №  | ключ |   Фамилия     |\n");
    for (int i = 0; i < count; i++)
    {
        printf("|%6d|%6d|%15s|\n", i, key[i].index, key[key[i].index - 1].surname);
    }
}

void find_friend(subscriber *fields , key_for_table *key, int count)
{
    struct tm *tim;
    time_t tt = time(NULL);
    tim = localtime(&tt);

    int flag_search = 0;

    for (int i = 0; i < count; i++)
    {
        if (fields[i].status == 1)
        {
            if (fields[i].status_person.personal.month - 1 == tim->tm_mon && tim->tm_mday <= fields[i].status_person.personal.day && tim->tm_mday + 7 >= fields[i].status_person.personal.day)
            {
                if (flag_search == 0)
                {
                    printf("статус: личный = 1, служебный = 0\n");
                    printf("Друзей, которых нужно поздравить:\n");
                    printf("|   №  |     Имя    |     Фамилия   |  Номер телефона  |          Адрес                    |Статус| Дата рождения |\n");
                }
                flag_search = 1;

                printf("|%6d|", i);
                printf("%12s|", fields[i].name);
                printf("%15s|", fields[i].surname);
                printf("%18s|", fields[i].phone_number);
                printf("%35s|", fields[i].address);
                printf("%6d", fields[i].status);
                printf("|%2d.", fields[i].status_person.personal.day);
                printf("%2d.", fields[i].status_person.personal.month);
                printf("%4d     |\n", fields[i].status_person.personal.year);
            }
        }
    }

    if (flag_search == 0)
        printf("Нет друзей, которых нужно поздравить.\n");
}

int time_sort(int count_tabl)
{
    subscriber fields_cpy[QUANTITY];
    key_for_table key_cpy[QUANTITY];

    subscriber fields_cpy_2[QUANTITY];
    key_for_table key_cpy_2[QUANTITY];

    char file[] = "../tabliza.txt";

    int count;

    double time_spent_cpy_b = 0.0;
    double time_spent_cpy_b_l = 0.0;
    double time_spent_cpy_q = 0.0;
    double time_spent_cpy_q_l = 0.0;
    double time_spent_cpy_b_1 = 0.0;
    double time_spent_cpy_b_l_1 = 0.0;
    double time_spent_cpy_q_1 = 0.0;
    double time_spent_cpy_q_l_1 = 0.0;

    int j = 0;

    while (j < 100) {
        count = 50;

        for (int i = 0; i < count; i++) {
            key_cpy[i].index = i + 1;
            memset(&key_cpy[i].surname[0], 0, sizeof(key_cpy[i].surname));
            strcpy(key_cpy[i].surname, fields_cpy[i].surname);
        }

        clock_t begin = clock();
        bubble_sort_key(key_cpy, count);
        clock_t end = clock();

        time_spent_cpy_b += (double) (end - begin) / CLOCKS_PER_SEC;

        if (j == 50)
            time_spent_cpy_b_1 = time_spent_cpy_b;
        j++;
    }

    j = 0;
    while (j < 100) {
        if (fill_structure(file, fields_cpy, &count) != SUCCESS)
            return INV_FILE;

        for (int i = 0; i < count; i++) {
            key_cpy[i].index = i + 1;
            memset(&key_cpy[i].surname[0], 0, sizeof(key_cpy[i].surname));
            strcpy(key_cpy[i].surname, fields_cpy[i].surname);
        }

        clock_t begin = clock();
        bubble_sort_line(fields_cpy, count);
        clock_t end = clock();

        time_spent_cpy_b_l += (double) (end - begin) / CLOCKS_PER_SEC;

        if (j == 50)
            time_spent_cpy_b_l_1 = time_spent_cpy_b_l;
        j++;
    }

    j = 0;
    while (j < 100) {
        count = 50;

        for (int i = 0; i < count; i++) {
            key_cpy_2[i].index = i + 1;
            memset(&key_cpy[i].surname[0], 0, sizeof(key_cpy[i].surname));
            strcpy(key_cpy_2[i].surname, fields_cpy_2[i].surname);
        }

        clock_t begin = clock();
        quick_sort_key(key_cpy_2, 0, count - 1);
        clock_t end = clock();

        time_spent_cpy_q += (double) (end - begin) / CLOCKS_PER_SEC;

        if (j == 50)
            time_spent_cpy_q_1 = time_spent_cpy_q;
        j++;
    }

    j = 0;
    while (j < 100) {
        if (fill_structure(file, fields_cpy_2, &count) != SUCCESS)
            return INV_FILE;

        for (int i = 0; i < count; i++) {
            key_cpy_2[i].index = i + 1;
            memset(&key_cpy[i].surname[0], 0, sizeof(key_cpy[i].surname));
            strcpy(key_cpy_2[i].surname, fields_cpy_2[i].surname);
        }

        clock_t begin = clock();
        quick_sort_line(fields_cpy_2, key_cpy_2, 0, count - 1);
        clock_t end = clock();

        time_spent_cpy_q_l += (double) (end - begin) / CLOCKS_PER_SEC;

        if (j == 50)
            time_spent_cpy_q_l_1 = time_spent_cpy_q_l;
        j++;
    }

    printf("|кол-во раз отсортировано | 50      | 100     |\n");
    printf("|сорт. пузырьком по ключам| %5.5lf | %5.5lf |\n", time_spent_cpy_b_1, time_spent_cpy_b);
    printf("|сорт. пузырьком по полям | %5.5lf | %5.5lf |\n", time_spent_cpy_b_l_1, time_spent_cpy_b_l);
    printf("|быстрая сорт. по ключам  | %5.5lf | %5.5lf |\n", time_spent_cpy_q_1, time_spent_cpy_q);
    printf("|быстрая сорт. по полям   | %5.5lf | %5.5lf |\n", time_spent_cpy_q_l_1, time_spent_cpy_q_l);

    printf("\n(50 раз по ключам) на %.2lf %% быстрее быстрая сортировка, чем сортировки пузырьком\n",
           (time_spent_cpy_b_1 - time_spent_cpy_q_1) * 100.0 / time_spent_cpy_b_1);
    printf("(50 раз по полям) на %.2lf %% быстрее сортировка пузырьком, чем быстрая сортировка\n",
           (time_spent_cpy_b_l_1 - time_spent_cpy_q_l_1) * 100.0 / time_spent_cpy_b_l_1);
    printf("(100 раз по ключам) на %.2lf %% быстрее быстрая сортировка, чем сортировка пузырьком\n",
           (time_spent_cpy_b - time_spent_cpy_q) * 100.0 / time_spent_cpy_b);
    printf("(100 раз по полям) на %.2lf %% быстрее сортировка пузырьком, чем быстрая сортировка\n",
           (time_spent_cpy_b_l - time_spent_cpy_q_l) * 100.0 / time_spent_cpy_b_l);
    printf("на %.2lf %% сортировка пузырьком по ключам быстрее сортировки пузырьком по полям\n",
           (time_spent_cpy_b_l_1 - time_spent_cpy_b_1) * 100.0 / time_spent_cpy_b_l_1);
    printf("на %.2lf %% быстрая сортировка по ключам быстрее быстрой сортировки по полям\n",
           (time_spent_cpy_q_l_1 - time_spent_cpy_q_1) * 100.0 / time_spent_cpy_q_l_1);
    printf("При хранении таблицы ключей память увеличивается на %.2f %%\n", (double)(count_tabl * sizeof(key_cpy[0])) * 100 /
                                                                            (double)(count_tabl * sizeof(fields_cpy[0]) +
                                                                            count_tabl * sizeof(fields_cpy[0].status_person.personal) +
                                                                            count_tabl * sizeof(fields_cpy[0].status_person.official)));
}

void quick_sort_key(key_for_table *key, int first, int last)
{
    if (first < last)
    {
        int left = first, right = last, middle = (left + right) / 2;
        do
        {
            while (strcmp(key[left].surname, key[middle].surname) < 0)
                left++;
            while (strcmp(key[right].surname, key[middle].surname) > 0)
                right--;
            if (left <= right)
            {
                int tmp = key[left].index;
                key[left].index = key[right].index;
                key[right].index = tmp;
                left++;
                right--;
            }
        } while (left <= right);
        quick_sort_key(key, first, right);
        quick_sort_key(key, left, last);
    }
}

void quick_sort_line(subscriber *fields , key_for_table *key, int first, int last)
{
    subscriber temp_char_sub;
    subscriber temp_char_per;
    subscriber temp_char_work;

    if (first < last)
    {
        int left = first, right = last, middle = (left + right) / 2;
        do
        {
            while (strcmp(fields[left].surname, fields[middle].surname) < 0)
                left++;
            while (strcmp(fields[right].surname, fields[middle].surname) > 0)
                right--;
            if (left <= right)
            {
                temp_char_sub = fields[left];
                fields[left] = fields[right];
                fields[right] = temp_char_sub;

                temp_char_per.status_person.personal = fields[left].status_person.personal;
                fields[left].status_person.personal = fields[right].status_person.personal;
                fields[right].status_person.personal = temp_char_per.status_person.personal;

                temp_char_work.status_person.official = fields[left].status_person.official;
                fields[left].status_person.official = fields[right].status_person.official;
                fields[right].status_person.official = temp_char_work.status_person.official;

                int tmp = key[left].index;
                key[left].index = key[right].index;
                key[right].index = tmp;
                left++;
                right--;
            }
        } while (left <= right);

        quick_sort_line(fields, key, first, right);
        quick_sort_line(fields, key, left, last);
    }
}

/*
printf("\n(50 раз) быстрая сортировка по ключам быстрее сортировки пузырьком на %.2lf %%\n",
           (time_spent_cpy_b_1 - time_spent_cpy_q_1) * 100.0 / time_spent_cpy_b_1);
    printf("(50 раз) сортировки пузырьком по полям быстрее  быстрой сортировки на %.2lf %%\n",
           (time_spent_cpy_b_l_1 - time_spent_cpy_q_l_1) * 100.0 / time_spent_cpy_b_l_1);
    printf("(100 раз) быстрая сортировка по ключам быстрее сортировки пузырьком на %.2lf %%\n",
           (time_spent_cpy_b - time_spent_cpy_q) * 100.0 / time_spent_cpy_b);
    printf("(100 раз) сортировки пузырьком по полям быстрее быстрой сортировки на %.2lf %%\n",
           (time_spent_cpy_b_l - time_spent_cpy_q_l) * 100.0 / time_spent_cpy_b_l);
    printf("сортировка пузырьком по ключам быстрее сортировки пузырьком по полям на %.2lf %%\n",
           (time_spent_cpy_b_l_1 - time_spent_cpy_b_1) * 100.0 / time_spent_cpy_b_l_1);
    printf("быстрая сортировка по ключам быстрее быстрой сортировки по полям на %.2lf %%\n",
           (time_spent_cpy_q_l_1 - time_spent_cpy_q_1) * 100.0 / time_spent_cpy_q_l_1);
    printf("При хранении таблицы ключей память увеличивается на %.2f %%\n", (double)(count_tabl * sizeof(key_cpy[0])) * 100 /
    (double)(count_tabl * sizeof(fields_cpy[0]) + count_tabl * sizeof(date_of_birth_cpy[0]) + count_tabl * sizeof(work_cpy[0])));
*/