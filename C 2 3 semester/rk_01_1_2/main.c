#include "stdio.h"
#define N 100
#define OK 0
#define ERROR -1

int input(int *a)
{
    int n;
    int rm;
    rm = scanf("%d", &n);
    if (rm != 1)
        return ERROR;
    if (rm == 1)
        for (int i = 0; i < n; i++)
            if(scanf("%d", &a[i]) != 1)
                return ERROR;
    return n;
}
int mas(int *a, int kr, int n)
{
    int i = 0;
    while (i < n)
    {
        if (a[i] % kr == 0)
        {
            int j = i;
            while (j < n)
            {
                a[j] = a[j + 1];
                j++;
            }
            n--;
        }
        i++;
    }
    return n;
}
void output1(int *a, int n)
{
    for (int k = 0; k < n; k++)
        printf("%d ", a[k]);
}
int main()
{
    int a[N], kr, n1, rm;
    n1 = input(a);
    rm = scanf("%d", &kr);
    if (rm != 1 || n1 == -1)
        return ERROR;
    else
    {
        n1 = mas(a, kr, n1);
        output1(a,n1);
        return OK;
    }
}
