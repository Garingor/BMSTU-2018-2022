#include <stdio.h>

#define OK 0
#define INV_INPUT -1
#define NOT_FOUND -2

int process(FILE *f, int *min_len)
{
    int tek, left, right;
    int flag_quantity = 0;
    int start = 0, end = 2;
    if (fscanf(f, "%d%d", &left, &tek) == 2)
    {
        while (fscanf(f, "%d", &right) == 1)
        {
            end++;
            if (tek > left && tek > right)
            {
                flag_quantity++;
                if (start == 0)
                    start = end;
                if (flag_quantity == 2)
                {
                    *min_len = end - start;
                    start = end;
                }
                if (flag_quantity > 2)
                    if ((end - start) < *min_len)
                    {
                        *min_len = end - start;
                        start = end;
                    }
            }
            left = tek;
            tek = right;
        }
        if (flag_quantity < 2)
            return INV_INPUT;
    }
    else
        return INV_INPUT;
    return OK;
}

int main(void)
{
    int min_len;
    FILE *f = stdin;
    if (process(f, &min_len) != 0)
        return NOT_FOUND;
    else
        printf("%d ", min_len);
    return OK;
}
