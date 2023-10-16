#include "my_snprintf.h"
#include "const.h"
#include <stdarg.h>

void from_int_to_str(int value, char *value_str);

void convert_to_octal(unsigned long int value, char *value_str);

void insert_into_str(char *buffer, char *string, int *len_buffer, size_t n);

int my_snprintf(char *buffer, size_t n, const char *format, ...)
{
    int len_buffer = 0;
    char value_str[30];

    va_list ap;
    va_start(ap, format);

    const char *p = format;

    for (; *p; p++)
    {
        if (*p == '%')
        {
            switch (*(++p))
            {
                case 's':
                    {
                        insert_into_str(buffer, va_arg(ap, char *), &len_buffer, n);
                        break;
                    }
                case 'd':
                    {
                        from_int_to_str(va_arg(ap, int), value_str);
                        insert_into_str(buffer, value_str, &len_buffer, n);
                        break;
                    }
                case 'l':
                    {
                        if (*(++p) == 'o')
                        {
                            convert_to_octal(va_arg(ap, unsigned long int), value_str);
                            insert_into_str(buffer, value_str, &len_buffer, n);
                        }
                        else if (len_buffer < n - 1 && buffer != NULL)
                        {
                            buffer[len_buffer] = *p;
                            len_buffer++;
                        }
                        else
                            len_buffer++;
                        break;
                    }
                default:
                    {
                        if (len_buffer < n - 1 && buffer != NULL)
                            buffer[len_buffer] = *p;
                        len_buffer++;
                        break;
                    }
            }
        }
        else
        {
            if (len_buffer < n - 1 && buffer != NULL)
                buffer[len_buffer] = *p;
            len_buffer++;
        }
    }

    if (n > len_buffer && buffer != NULL)
        buffer[len_buffer] = '\0';
    else if (buffer != NULL && n != 0)
        buffer[n - 1] = '\0';
    else if (buffer != NULL)
        buffer[0] = '\0';

    va_end(ap);

    return len_buffer;
}

void from_int_to_str(int value, char *value_str)
{
    int pos = 0;
    int cur_num;
    int end;

    if (value != 0)
    {
        for (int i = value ; i != 0; i /= 10)
            pos++;

        if (value < 0)
        {
            value_str[0] = '-';
            value_str[pos + 1] = '\0';
            end = 1;
        }
        else
        {
            end = 0;
            value_str[pos] = '\0';
            pos--;
        }

        for (; pos >= end; pos--)
        {
            cur_num = value % 10;

            if (cur_num < 0)
                cur_num = -cur_num;

            value_str[pos] = cur_num + '0';
            value /= 10;
        }
    }
    else
    {
        value_str[0] = '0';
        value_str[1] = '\0';
    }
}

void convert_to_octal(unsigned long int value, char *value_str)
{
    int pos = 0;

    if (value != 0)
    {
        for (unsigned long int i = value ; i != 0; i /= 8)
            pos++;

        value_str[pos] = '\0';

        for (int i = pos - 1; i >= 0; i--)
        {
            value_str[i] = value % 8 + '0';
            value /= 8;
        }
    }
    else
    {
        value_str[0] = '0';
        value_str[1] = '\0';
    }
}

void insert_into_str(char *buffer, char *string, int *len_buffer, size_t n)
{
    int i = 0;

    if (buffer != NULL && n != 0)
        for (i = 0; *len_buffer < n - 1 && string[i] != '\0'; i++)
        {
            buffer[*len_buffer] = string[i];
            (*len_buffer)++;
        }

    for (; string[i] != '\0'; i++)
        (*len_buffer)++;
}
