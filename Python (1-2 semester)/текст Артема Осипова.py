'''
Лабораторная работа №9
Осипов Артем
'''
from copy import deepcopy

#Функция занесения нового текста
def input_string():
    l_mat = int(input('Введите количество строк: '))
    mat = []
    print('Введите текст построчно:')
    for i in range(l_mat):
        mat.append(input())
    return mat

#Функция вызова меню
def input_menu():
    print()
    print('****************************\n\
Меню программы: \n\
1 - Выравнивание по ширине \n\
2 - Выравнивание по левому краю \n\
3 - Выравнивание по правому краю \n\
4 - Замена во всем тексте одного слова другим словом \n\
5 - Удаление заданного слова \n\
6 - Замена арифметических операций, состоящих из умножения и деления,\n\
    на их результаты \n\
7 - Замена римских цифр арабскими \n\
\n\
0 - Выход из программы \n\
-1 - Поменять текст \n\
-2 - Показать заданный текст \n\
****************************\n')
    flag = input('Введите команду: ')
    print()
    return flag

#Функция убирания лишних пробелов
def probel(matrix):
    mat = deepcopy(matrix)
    for i in range(len(mat)):
        x_mat = ['*']
        for s in mat[i]:
            if s == ' ':
                if x_mat[len(x_mat)-1] == ' ':
                    continue
            x_mat.append(s)
        s = ''
        for j in range(1,len(x_mat)):
            s += x_mat[j]
        mat[i] = s
    return mat

#Метод "split"
def s_split(matrix):
    mat = deepcopy(matrix)
    mat = probel(mat)
    for i in range(len(mat)):
        x_mat = []
        for s in mat[i]:
            x_mat.append(s)
        j = 0
        y_mat = []
        while j < len(x_mat):
            s = ''
            while True:
                if (j == len(x_mat)) or (x_mat[j] == ' '):
                    break
                s += x_mat[j]
                j += 1
            if s != '':
                y_mat.append(s)
            j += 1
        mat[i] = y_mat
    return mat

#Функция создания матрицы пробелов
def probel_matrix(matrix):
    mat = deepcopy(matrix)
    probel_matrix = []
    for i in range(len(mat)):
        y_mat = []
        if mat[i][0] == ' ':
            s = ''
            k = 0
            while mat[i][k] == ' ':
                s += ' '
                k += 1
            y_mat.append(s)
            j = k
        else:
            j = 0
            y_mat.append('')
        while j <= len(mat[i]) - 1:
            if mat[i][j] == ' ':
                s = ''
                k = j
                while k < len(mat[i]) - 1 and mat[i][k] == ' ':
                    s += ' '
                    k += 1
                    if k == len(mat[i]) - 1:
                        break
                else:
                    if s != '':
                        y_mat.append(s)
                j = k + 1
                continue
            j += 1
        probel_matrix.append(y_mat)
    return(probel_matrix)
    
#Функция выравнивания по ширине
def command_1(matrix):
    mat = deepcopy(matrix)
    mat = s_split(mat)
    for i in range(len(mat)):
        count = 0
        for j in range(len(mat[i])):
            count += len(mat[i][j])
        pr_sr = (79 - count)//(len(mat[i]) - 1)
        pr_ost = (79 - count)%(len(mat[i]) - 1)
        s = ''
        for j in range(len(mat[i]) - 1):
            s += mat[i][j]
            s += ' '*pr_sr
            if pr_ost != 0:
                s += ' '
                pr_ost -= 1
        s += mat[i][len(mat[i]) - 1]
        print(s)


#Функция выравния по левому краю
def command_2(matrix):
    mat = deepcopy(matrix)
    mat = s_split(mat)
    count_max = -1
    for i in range(len(mat)):
        s = ''
        for j in range(len(mat[i]) - 1):
            s += mat[i][j]
            s += ' '
        s += mat[i][len(mat[i]) - 1]
        print(s)    

#Функция выравния по правому краю
def command_3(matrix):
    mat = deepcopy(matrix)
    mat = s_split(mat)
    for i in range(len(mat)):
        s = ''
        for j in range(len(mat[i]) - 1):
            s += mat[i][j]
            s += ' '
        s += mat[i][len(mat[i]) - 1]
        mat[i] = s
    count_max = -1
    for i in range(len(mat)):
        count = len(mat[i])
        if count > count_max:
            count_max = count
    for i in range(len(mat)):
        s = ''
        if len(mat[i]) != count_max:
            s += ' '*(count_max - len(mat[i]))
        s += mat[i]
        print(s)

#Замена одного слова другим словом
def command_4(matrix):
    mat = deepcopy(matrix)
    y_mat = deepcopy(probel_matrix(mat))
    mat = s_split(mat)
    old_word = input('Введите слово, которое надо заменить: ')
    new_word = input('Введите новое слово: ')
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            if old_word == mat[i][j]:
                mat[i][j] = new_word
        s = ''
        for j in range(len(y_mat[i])):
            s += y_mat[i][j]
            s += mat[i][j]
        print(s)

#Удаление заданного слова
def command_5(matrix):
    mat = deepcopy(matrix)
    y_mat = deepcopy(probel_matrix(mat))
    mat = s_split(mat)
    del_word = input('Введите слово, которое надо удалить: ')
    for i in range(len(mat)):
        for j in range(len(mat[i])-1, -1, -1):
            if del_word == mat[i][j]:
                del mat[i][j]
        s = ''
        for j in range(len(y_mat[i])):
            s += y_mat[i][j]
            if j <= len(mat[i]) - 1:  
                s += mat[i][j]
        print(s)

#Замена арифметических операций умножения и деления
def command_6(matrix):
    mat = deepcopy(matrix)
    y_mat = deepcopy(probel_matrix(mat))
    mat = s_split(mat)
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            flag = True
            for s in mat[i][j]:
                if not('0' <= s <= '9' or s == '*'):
                    flag = False
            if not('*' in mat[i][j] and mat[i][j][0] != '*' and mat[i][j][len(mat[i][j]) - 1] != '*'):
                flag = False                
            if flag == True:
                print()
            
# Проверка на римское слово
def rim_number(slovo):
    rim = ('I', 'V', 'X', 'L', 'C', 'D', 'M',)
    mat = []
    for s in slovo:
        mat.append(s)
    flag = True
    if len(mat) > 4:
        for i in range(3,len(mat)):
            if mat[i-2] == mat[i-1] == mat[i] == mat[i-3]:
                flag = False
                break
    if flag == True:
        for i in range(1, len(mat)):
            index = rim.index(mat[i]) - rim.index(mat[i-1])
            if index >= 3:
                flag = False
                break
            elif index >= 1:
                if i >= 2:
                    if mat[i-2] == mat[i-1]:
                        flag = False
                        break
    return flag
            
                

# Замена римских цифр арабскими
def command_7(matrix):
    mat = deepcopy(matrix)
    mat = s_split(mat)
    rim = ('I', 'V', 'X', 'L', 'C', 'D', 'M',)
    for i in range(len(mat)):
        for j in range(len(mat[i])):
            flag = True
            for s in mat[i][j]:
                if s not in rim:
                    flag = False
                    break
            if flag == rim_number(mat[i][j]) == True:
                arab = (1, 5, 10, 50, 100, 500, 1000,)
                




print('Добрый день')
text = input_string()
flag = 1
while int(flag) != 0:
    flag = input_menu()
    if int(flag) == 0:
        continue
    elif int(flag) == -1:
        text = input_string()
        continue
    elif int(flag) == -2:
        for i in range(len(text)):
            print(text[i])
        continue
    elif int(flag) == 1:
        command_1(text)
        continue
    elif int(flag) == 2:
        command_2(text)
        continue
    elif int(flag) == 3:
        command_3(text)
        continue
    elif int(flag) == 4:
        command_4(text)
        continue
    elif int(flag) == 5:
        command_5(text)
        continue
    elif int(flag) == 6:
        command_6(text)
        continue
    elif int(flag) == 7:
        print(command_7(text))
        continue
    else:
        print('Неверная команда')
        flag = 1
        continue


