# переписать все отрицательные элементы матрицы А(8,10) в массив Р без пропусков
# и упорядочить их в массиве по возрастанию. Если в матрице нет ни одного отрицательного
# элемента, то напечатать соответствующий текст.

# Савинов Егор ИУ7-14Б

m = int(input('Введите количество строк: '))
n = int(input('Введите количество столбцов: '))

if n <= 0 or m <= 0:
    print('вы ввели неправильные числа')
    exit()

A = [[0] * m for i in range(n)]

d = 0
j = 0

for b in range(n):
    for l in range(m):
        A[b][l] = input('# ')

print('\n')

for b in range(n):
    for l in range(m):
        print('{:>6}'.format(A[b][l]), end=' ')
    print()

for b in range(n):
    for l in range(m):
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
        A[b][l] = float(a)
        if A[b][l] < 0:
            d += 1
        j += 1

if d == 0:
    print('В массиве нет отрицательных элементов')
    exit()

P = list()

for i in range(n):
    for j in range(m):
        if A[i][j] < 0:
            P.append(A[i][j])

print('\n')
for i in range(d):
    for j in range(d - i - 1):
        if P[j] > P[j + 1]:
            P[j], P[j + 1] = P[j + 1], P[j]
print(P)
