#include <stdio.h>

#define OK 0
#define ERROR -1

int input()
{
    int n;
    int rm;
    rm = scanf("%d", &n);
    if (rm != 1)
        return ERROR;
    else
        return n;
}

void min_max(int a, int *min_a, int *max_a)
{
    *min_a = a % 10;
    *max_a = a % 10;
    int copy_a = a;
    while (copy_a > 0)
    {
        if (copy_a % 10 < *min_a)
            *min_a = copy_a % 10;
        if (copy_a % 10 > *max_a)
            *max_a = copy_a % 10;
        copy_a /= 10;
    }
}
void print_min_max(int *min_a, int *max_a)
{
    printf("%d %d", *min_a, *max_a);
}

int main()
{
    int min_a = 0, max_a = 0;
    int a1 = input();
    if (a1 == ERROR)
        return ERROR;
    else
    {
      min_max(a1, &min_a, &max_a);
      print_min_max(&min_a, &max_a);
      return OK;
    }
    return OK;
}
