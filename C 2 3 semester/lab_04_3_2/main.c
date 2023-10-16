#include <stdio.h>
#include <math.h>

#define N 10
#define SUCCESS 0
#define INV_INPUT -1

int input_arr(int *a, int *n)
{
    if (scanf("%d", n) != 1)
        return INV_INPUT;

    if (*n <= 0 || *n > N)
        return INV_INPUT;

    for (int i = 0;i < *n;i++)
    {
        if (scanf("%d", &a[i]) != 1)
            return INV_INPUT;
    }

    return *n;
}

int solution(int *a, int *b, int *n)
{
    int j = 0, rs, st, sum, tek;
    for (int i = 0;i < *n;i++)
    {
        if (a[i] > 0)
        {
            sum = 0;
            st = 0;
            rs = a[i];
            while (rs > 0)
            {
                rs /= 10;
                st++;
            }

            rs = a[i];
            while (rs > 0)
            {
                tek = rs % 10;
                sum += pow(tek, st);
                rs /= 10;
            }
            if (sum == a[i])
            {
                b[j] = sum;
                j++;
            }
        }
    }
    if (j == 0 || j == *n)
        return -1;
    return j;
}

void output_arr(int *b, int *n)
{
    for (int i = 0; i < *n; i++)
        printf("%d ", b[i]);
}

int main()
{
    int a[N], b[N], n;

    n = input_arr(a, &n);

    if (n == INV_INPUT)
        return INV_INPUT;
    else
    {
        n = solution(a, b, &n);
        if (n == INV_INPUT)
            return INV_INPUT;
        else
            output_arr(b, &n);
    }
    return SUCCESS;
}
