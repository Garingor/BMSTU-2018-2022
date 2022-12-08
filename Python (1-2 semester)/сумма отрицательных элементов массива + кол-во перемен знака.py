# в введенном массиве вычислить сумму отрицательных
# элементов расположенных на позициях с четными индексами
# для введенного массива определить количество перемен знака

# (('9' < a[i] or a[i] < '0') and (a[0] != '-')) # 1, -1
# (a[i] != '.' or (a[i] == '.' and fl2 == 1)) # 1t 1..
# (a[i] != 'e' or (a[i] == 'e' and fl1 == 1)) # 1g 1ee
# (a[i] == '-' and a[i - 1] != 'e')) # 1-5, (1e-5 = correct)
# (a[i] == 'e' and fl1 == 1) or (a[i] == '.' and fl2 == 1) # 1ee, 1..
# Савинов Егор ИУ7-14Б

x = list(map(str, input('введите элементы: ').split()))
print(x)
j = 0
for a in x:  # Для каждого элемента из строки x, т.е. символа
    z = len(a)  # Длина каждого элемента строки
    if ('9' < a[0] or a[0] < '0') and (a[0] != '-'):
        print('данные введены неверно')
        exit()
    i = 1
    fl1 = 0
    fl2 = 0
    fl3 = 0
    for i in range(z):  # Присвоить индекс для кадого элемента из строки a
        if (('9' < a[i] or a[i] < '0') and (a[0] != '-') and (a[i] != '.') and
            (a[i] != 'e') and (a[i] == '-' and a[i - 1] != 'e') or \
                (a[i] == 'e' and fl1 == 1) or (a[i] == '.' and fl2 == 1) or (a[i] == '-' and fl1 != 1 and fl3 == 1 ) or (a[i] == 'e' and a[i - 1] == '.')):
            print('данные введены неверно')
            exit()
        elif a[i] == 'e':
            fl1 = 1
        elif a[i] == '.':
            fl2 = 1
        elif a[i] == '-':
            fl3 = 1
    x[j] = float(a)  # элемент строки, который перебрали записали в float
    j += 1
s = 0
N = len(x)
for i in range(N):
    if x[i] < 0 and i % 2 == 0:
        s += x[i]
print('\ns = ', s)

f = x[0]
amount = 0
for i in range(N):
    if (x[i] < 0 and f > 0) or (x[i] > 0 and f < 0):
        amount += 1
    f = x[i]
print('\namount = ', amount)
