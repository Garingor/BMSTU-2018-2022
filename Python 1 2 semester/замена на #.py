# Дана символьная матрица, состояшая из латинских букв и цифр.
# Заменить символами # символы, стоящие в строках или столбцах,
# где имеются цифры. Можно использовать рабочий одномерный массив
# не больше изначальной матрицы, но нельзя вводить рабочий двумерный
# массив.

# Савинов Егор ИУ7-14Б


n = int(input('\nВведите кол-во строк: '))
m = int(input('\nВведите кол-во столбцов: '))


a = [[0] * m for i in range(n)]
x = []


for i in range(n):
    for j in range(m):
        print('Введите элемент ',(i+1),' строки, ',(j+1),'столбца: ')
        a[i][j] = input()


for i in range(n):
    for j in range(m):
        print(a[i][j], end=' ')
    print()


for i in range(n):
    x[:] = []
    for j in range(m):
        x.append(a[i][j])
    for k in range(len(x)):
        if '0' <= x[k] <= '9':
            for v in range(len(x)):
                if '0' <= x[v] <= '9':
                    x[v] = '0'
                else:
                    x[v] = '#'
    for c in range(m):
        a[i][c] = x[c]


for j in range(m):
    x[:] = []
    for i in range(n):
        x.append(a[i][j])
    for k in range(len(x)):
        if '0' <= x[k] <= '9':
            for v in range(len(x)):
                    x[v] = '#'
    for c in range(n):
        a[c][j] = x[c]

print('\n')
for i in range(n):
    for j in range(m):
        print(a[i][j], end=' ')
    print()



                
                
            


