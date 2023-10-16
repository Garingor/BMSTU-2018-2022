# Написать программу, которая вращает квадратную матрицу F(N,N) из
# целых чисел по часовой и против часовой стрелке (N<=11).
# Дополнительный массивов не создавать
# Савинов Егор ИУ7-14Б

n = int(input('Введите колличество столбцов квадратной матрицы: '))
m = int(input('В какую сторону повернуть матрицу (0 - налево, 1 - направо): '))
if n < 0:
    print('вы ввели неправильные числа')
    exit()

A = [[0] * n for i in range(n)]

d = 0
 
for b in range(n):
    for l in range(n):
        print('Введите элемент',b,' строки', l,' столбца: ')
        A[b][l] = input()
print('\n')

for b in range(n):
    for l in range(n):
        print('{:>6}'.format(A[b][l]), end=' ')
    print()

for b in range(n):
    for l in range(n):
        a = A[b][l]
        z = len(a)
        if ('9' < a[0] or a[0] < '0') and (a[0] != '-'):
            print('данные введены неверно')
            exit()
        fl1 = 0
        fl2 = 0
        fl3 = 0
        i = 1
        for i in range(z):
            if (('9' < a[i] or a[i] < '0') and (a[0] != '-') and (a[i] != '.') and
                    (a[i] != 'e') and (a[i] == '-' and a[i - 1] != 'e') or
                    (a[i] == 'e' and fl1 == 1) or (a[i] == '.' and fl2 == 1) or (
                            a[i] == '-' and fl1 != 1 and fl3 == 1) or (a[i] == 'e' and a[i - 1] == '.')):
                print('данные введены неверно')
                exit()
            elif a[i] == 'e':
                fl1 = 1
            elif a[i] == '.':
                fl2 = 1
            elif a[i] == '-':
                fl3 = 1
            if a[i] == '.' or (a[i] == 'e' and a[i+1] == '-') or(a[i] == '0' and ('9' < a[i-1] or a[i-1] < '0') and
                                             ('9' < a[i+1] or a[i+1] < '0') ):
                print('\nвы ввели нецелые числа')
                exit()
        A[b][l] = float(a)
        

if m == 1:
    m = int(n / 2)
    for i in range(m):
        j = i
        for j in range(n - 1 - i):
            b = A[i][j]
            A[i][j] = A[n - j - 1][i]
            A[n-j-1][i] = A[n - i - 1][n - j - 1]
            A[n - i - 1][n - j - 1] = A[j][n - i - 1]
            A[j][n - i - 1] = b

else:
    m = int(n / 2)
    for i in range(m):
        j = i
        for j in range(n - 1 - i):
            b = A[i][j]
            A[i][j] = A[j][n - 1 - i]
            A[j][n - 1 - i] = A[n - 1 - i][n - 1 - j]
            A[n - 1 - i][n - 1 - j] = A[n - 1 - j][i]
            A[n - j - 1][i] = b
print('\n')

for i in range(n):
    for j in range(n):
        print('{:>6}'.format(int(A[i][j])), end=' ')
    print()
