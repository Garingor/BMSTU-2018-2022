text = ['  Уинстон перестал    писать, отчасти из-за         того, что',
        ' чтобы что что у него свело руку. Он сам не понимал, ',
        '   почему выплеснул на бумагу этот вздор. Но любопытно, что , пока он водил пером, в памяти у него   ',
        '   пап ',
        'другое происшествие, да так,   ',
        '   что хоть сейчас записывай. Ему стало понятно, что из-за этого происшествия он  ',
        '     2 - 3 + 3 + решил вдруг пойти домой 2 - 3 + 3.4 и начать дневник сегодня. 2 +']

choice = None

from copy import deepcopy


# функция убирает лишние пробелы
def normal_text(text):
    text1 = deepcopy(text)
    for i in range(len(text1)):
        mas = ['#']
        for k in range(len(text1[i])):
            if text1[i][k] == ' ' and mas[len(mas) - 1] == ' ':
                continue
            mas.append(text1[i][k])
        k = ''
        for j in range(1, len(mas)):
            k += mas[j]
        text1[i] = k
    return text1


# функция поиска максимальной длины строки
def dlina_max(text):
    stroka_max = 0
    for k in range(len(text)):
        sum = 0
        i = 0
        while text[k][i] == ' ':
            sum += 1
            i += 1
            if i == len(text[k]) - 1:
                break
        j = len(text[k]) - 1
        while text[k][j] == ' ':
            sum += 1
            j -= 1
            if j == 0:
                break
        if len(text[k]) - sum > stroka_max:
            stroka_max = len(text[k]) - sum
    return stroka_max


# функция сохраняет пробелы исходной матрицы
def probel(text):
    text1 = text.copy()
    probel_mas = []
    for i in range(len(text1)):
        mas1 = []
        # пробелы перед первым словом
        k = 0
        if text[i][0] == ' ':
            s = ''
        while text[i][k] == ' ':
            s += ' '
            k += 1
            if k == len(text[i]) - 1:
                break
            
        if k != 0:
            mas1.append(s)
        else:
            mas1.append('')
        j = k
        # пробелы между словами
        while j <= len(text[i]) - 1:
            if text[i][j] == ' ':
                s = ''
                k = j
                while k < len(text[i]) - 1 and text[i][k] == ' ':
                    s += ' '
                    k += 1
                if s != '':
                    mas1.append(s)
                j = k + 1
                continue
            j += 1
        probel_mas.append(mas1)
    return probel_mas




# функция выравнивание по ширине
def shirina(text):
    stroka_max = dlina_max(text)
    mas = []
    mas1 = []
    for i in range(len(text)):
        mas[:] = []
        mas1[:] = []
        mas = [' ']
        fl121 = 0
        fl122 = 0
        for k in range(len(text[i])):
            if text[i][k] == ' ' and mas[len(mas) - 1] == ' ':
                continue
            mas.append(text[i][k])
        if mas == [' ']:
            print(text[i])
            fl121 = 1
        if mas[len(mas) - 1] == ' ':
            del mas[len(mas) - 1]
        #print(mas)
        g = ''
        mas1 = mas
        for j in range(len(mas1)):
            g += mas1[j]
        g = g.split()
        if len(g) == 1:
            fl122 = 1
        if fl121 == 0:
            if text[len(text) - 1] != text[i]:
                fl1 = 0
                while len(mas) - 1 < stroka_max:
                    l = 1
                    if fl122 == 1:
                        l = 0
                    while l != len(mas) - 1:
                        if fl1 == 1:
                            fl1 = 0
                            l += 1
                        if mas[l] == ' ':
                            fl1 = 1
                            mas.append('')
                            for m in range(len(mas) - 1, l, -1):
                                mas[m] = mas[m - 1]
                            mas[l] = ' '
                            if fl122 == 1:
                                mas.append(' ')
                            #print(mas)
                        if len(mas) - 1 >= stroka_max:
                            break
                        l += 1
                        
                f = ''
                for s in range(1,len(mas),1):
                    f += mas[s]
                text[i] = f
                print(text[i])
        if text[len(text) - 1] == text[i]:
            g = ''
            for s in range(1, len(mas), 1):
                g += mas[s]
            text[i] = g
            print(text[i])

# функция выравнивания по левому краю
def left_kray(text):
    mas = []
    mas1 = []
    for i in range(len(text)):
        mas[:] = []
        mas = [' ']
        fl121 = 0
        for k in range(len(text[i])):
            if text[i][k] == ' ' and mas[len(mas) - 1] == ' ':
                continue
            mas.append(text[i][k])
        if mas == [' ']:
            print(text[i])
            fl121 = 1
        if fl121 == 0:
            if mas[len(mas) - 1] == ' ':
                del mas[len(mas) - 1]
            a = ''
            for s in range(1, len(mas), 1):
                a += mas[s]
            text[i] = a
            for s in range(1, len(mas), 1):
                print(mas[s], end='')
            print()




# функция выравнивания по правому краю
def right_kray(text):
    stroka_max = dlina_max(text)
    mas = []
    mas1 = []
    for i in range(len(text)):
        mas[:] = []
        mas = [' ']
        mas1[:] = []
        fl121 = 0
        fl122 = 0
        for k in range(len(text[i])):
            if text[i][k] == ' ' and mas[len(mas) - 1] == ' ':
                continue
            mas.append(text[i][k])
        fl1 = 0
        if mas[len(mas) - 1] == ' ':
            del mas[len(mas) - 1]
        if mas == [' ']:
            print(text[i])
            fl121 = 1
        g = ''
        mas1 = mas
        for j in range(len(mas1)):
            g += mas1[j]
        g = g.split()
        if len(g) == 1:
            fl122 = 1
        if fl121 == 0:
            while len(mas) - 1 < stroka_max:
                l = 1
                if fl122 == 1:
                        l = 0
                while l != len(mas) - 1:
                    if fl1 == 1:
                        fl1 = 0
                        l += 1
                    if len(mas) - 1 <= stroka_max:
                        fl1 = 1
                        mas.append('')
                        for m in range(len(mas) - 1, 0, -1):
                            mas[m] = mas[m - 1]
                        mas[0] = ' '
                    if len(mas) - 1 == stroka_max:
                        break
                    l += 1
        if fl121 == 0:
            a = ''
            for s in range(len(mas)):
                a += mas[s]
            text[i] = a
            print(text[i])


# функция замены одного слова другим
def two_zamena(text):
    word1 = (input('введите слово, которое хотите заменить: '))
    word2 = (input('введите замену слова: '))
    mas = probel(text)
    k = 0
    for i in range(len(text)):
        text[i] = text[i].split()
    for i in range(len(text)):
        for j in range(len(text[i])):
            if word1 == text[i][j]:
                text[i][j] = word2
        a = ''
        for v in range(len(text[i])):
            a += mas[i][v]
            a += text[i][v]
        text[i] = a
    for k in text:
        print(k)


#Удаление заданного слова
def del_slovo(text):
    mas1 = probel(text)
    word3 = input('Введите слово для удаления: ')
    for i in range(len(text)):
        text[i] = text[i].split()
    for i in range(len(text)):
        for j in range(len(text[i])-1, -1, -1):
            if word3 == text[i][j]:
                del text[i][j]
        s = ''
        for j in range(len(mas1[i])):
            s += mas1[i][j]
            if j <= len(text[i]) - 1:
                s += text[i][j]
        text[i] = s
        print(text[i])


# арифметических операции
def plus(text):
    mas = probel(text)
    for i in range(len(text)):
        text[i] = text[i].split()
    for i in range(len(text)):
        for j in range(len(text[i])):
            try:
                text[i][j] = float(text[i][j])
            except:
                continue
    for i in range(len(text)):
        for j in range(len(text[i])):
            if text[i][j] == '+' and (j != len(text[i]) - 1):
                try:
                    if text[i][j - 1] == float(text[i][j - 1]) and \
                            text[i][j + 1] == float(text[i][j + 1]):
                        text[i][j + 1] = text[i][j + 1] + text[i][j - 1]
                    text[i][j - 1] = '#'
                    text[i][j] = '#'
                except:
                    continue

            if text[i][j] == '-' and (j != len(text[i]) - 1):
                try:
                    if text[i][j - 1] == float(text[i][j - 1]) and \
                        text[i][j + 1] == float(text[i][j + 1]) and (j + 1 <= len(text[i]) - 1):
                        text[i][j + 1] = text[i][j - 1] - text[i][j + 1]

                    text[i][j - 1] = '#'
                    text[i][j] = '#'
                except:
                    continue


            if j == len(text[i]) - 1:
                for j in range(len(text[i]) - 1, -1, -1):
                    if text[i][j] == '#':
                        del text[i][j]
                b = ''
                for j in range(len(text[i])):
                    b += mas[i][j]
                    if j < len(text[i]):
                        b += str(text[i][j])
                text[i] = b
                print(text[i])

# Найти k-ое вхождение подстроки в каждое предложение
def koe(text):
    mas = probel(text)
    try:
        k = int(input('Введите k-ое вхождение: '))
    except:
        print('Введите число')
    text5 = input('Введите искомую подстроку: ')
    text6 = '[' + text5 + ']'
    n = 0
    fl1 = 0
    for i in range(len(text)):
        text[i] = text[i].split()
    for i in range(len(text)):
        for j in range(len(text[i])):
            if text5 == text[i][j]:
                n += 1
            if n == k and fl1 == 0:
                fl1 = 1
                text[i][j] = text6
        a = ''
        for v in range(len(text[i])):
            a += mas[i][v]
            a += text[i][v]
        text[i] = a
        print(text[i])

while choice != '0':
    print('\nМеню программы:')
    print('(0) Выход ')
    print('(1) Выравнивание по ширине')
    print('(2) Выравнивание по левому краю')
    print('(3) Выравнивание по правому краю')
    print('(4) Замена во всем тексте одного слова другим')
    print('(5) Удаление заданного слова из текста')
    print('(6) Замена арифметических выражений, на результат их вычисления')
    print('(7) Найти k-ое вхождение подстроки в каждое предложение')
    choice = input('Выбор: ')
    if choice == '0':
        print('\nВыход\n')

    elif choice == '1':
        shirina(text)
        continue
    elif choice == '2':
        left_kray(text)
        continue
    elif choice == '3':
        right_kray(text)
        continue
    elif choice == '4':
        two_zamena(text)
        continue
    elif choice == '5':
        del_slovo(text)
        continue
    elif choice == '6':
        plus(text)
        continue
    elif choice == '7':
        koe(text)
        continue
    else:
        print('Введенного номера нет ', choice)
        input('Нажмите Enter')

'''
# функция сохраняет пробелы исходной матрицы
def probel(text):
    text1 = text.copy()
    mas = normal_text(text1)
    mas_probel = ['#']
    for a in mas:
        s = 0
        while a[s] == ' ' and s != len(a) - 1:
            mas_probel.append(a[s])
            s += 1
        mas_probel.append('#')
        s += 1
    return mas_probel
print(probel(text))

while choice != '0':
    print('\nМеню программы:')
    print('(0) Выход ')
    print('(1) Выравнивание по ширине')
    print('(2) Выравнивание по левому краю')
    print('(3) Выравнивание по правому краю')
    print('(4) Замена во всем тексте одного слова другим')
    print('(5) Удаление заданного слова из текста')
    print('(6) Замена арифметических выражений, на результат их вычисления')
    print('(7) Найти k-ое вхождение подстроки в каждое предложение')

    choice = input('Выбор: ')
    if choice == '0':
        print('\nВыход\n')
        
    elif choice == '1':
        stroka_max = 0
        fl11 = 1
        fl22 = 0
        fl33 = 0
        mas1 = ['#']
        for a in text:
            sum = 0
            i = 0
            while a[i] == ' ':
                sum += 1
                i += 1
            j = len(a) - 1
            while a[j] == ' ':
                sum += 1
                j -= 1
            if len(a) - sum > stroka_max:
                stroka_max = len(a) - sum
                
        mas = []
        for a in text:
            mas[:] = []
            mas = [' ']
            for k in range(len(a)):
                if a[k] == ' ' and mas[len(mas) - 1] == ' ':
                    continue
                mas.append(a[k])
            if mas[len(mas) - 1] == ' ':
                del mas[len(mas) - 1]
            if text[len(text) - 1] != a:
                fl1 = 0
                while len(mas) - 1 < stroka_max:
                    l = 1
                    while l != len(mas) - 1:
                        if fl1 == 1:
                            fl1 = 0
                            l += 1
                        if mas[l] == ' ':
                            fl1 = 1
                            mas.append('')
                            for m in range(len(mas) - 1, l, -1):
                                mas[m] = mas[m - 1]
                            mas[l] = ' '
                        if len(mas) - 1 == stroka_max:
                            break
                        l += 1
                s = 1
                while s != len(mas) - 1:
                    if mas[s] == ' ':
                        while mas[s] == ' ':
                            mas1.append(mas[s])
                            s += 1
                        mas1.append('#')
                    else:
                        s += 1
                for s in range(1, len(mas), 1):
                    print(mas[s], end='')
                print()
            else:
                s = 1
                while s != len(mas) - 1:
                    if mas[s] == ' ':
                        while mas[s] == ' ':
                            mas1.append(mas[s])
                            s += 1
                        mas1.append('#')
                    else:
                        s += 1
                for s in range(1, len(mas), 1):
                    print(mas[s], end='')
                print()
    elif choice == '2':
        mas = []
        fl11 = 0
        fl22 = 1
        fl33 = 0
        for a in text:
            mas[:] = []
            mas = [' ']
            for k in range(len(a)):
                if a[k] == ' ' and mas[len(mas) - 1] == ' ':
                    continue
                mas.append(a[k])
            if mas[len(mas) - 1] == ' ':
                del mas[len(mas) - 1]
            for s in range(1, len(mas), 1):
                print(mas[s], end='')
            print()
    elif choice == '3':
        fl11 = 0
        fl22 = 0
        fl33 = 1
        mas2 = []
        stroka_max = 0
        for a in text:
            sum = 0
            i = 0
            while a[i] == ' ':
                sum += 1
                i += 1
            j = len(a) - 1
            while a[j] == ' ':
                sum += 1
                j -= 1
            if len(a) - sum > stroka_max:
                stroka_max = len(a) - sum
        mas = []
        for a in text:
            mas[:] = []
            fl123 = 0
            mas = [' ']
            for k in range(len(a)):
                if a[k] == ' ' and mas[len(mas) - 1] == ' ':
                    continue
                mas.append(a[k])
            if mas[len(mas) - 1] == ' ':
                del mas[len(mas) - 1]
            fl1 = 0
            while len(mas) - 1 < stroka_max:
                l = 1
                while l != len(mas) - 1:
                    if fl1 == 1:
                        fl1 = 0
                        l += 1
                    if len(mas) - 1 <= stroka_max:
                        fl1 = 1
                        mas.append('')
                        for m in range(len(mas) - 1, 0, -1):
                            mas[m] = mas[m - 1]
                        mas[0] = ' '
                    if len(mas) - 1 == stroka_max:
                        break
                    l += 1
            s = 0
            while s != len(mas) - 1:
                if mas[s] == ' ' and fl123 != 1:
                    while mas[s] == ' ':
                        mas2.append(mas[s])
                        s += 1
                        fl123 = 1
                    mas2.append('#')
                else:
                    s += 1

            for s in range(1, len(mas), 1):
                print(mas[s], end='')
            print()

    elif choice == '4':
        word1 = (input('введите слово, которое хотите заменить: '))
        word2 = (input('введите замену слова: '))
        num = -2
        s = 0
        text1 = text.copy()
        for a in text1:
            num = a.find(word1)
            fl1 = 0
            while num != -1:
                fl1 += 1
                if num + len(word1) <= len(a) - 1:
                    if a[num - 1] == ' ' and a[num + len(word1)] == ' ':
                        a = a[:num] + word2 + a[num + len(word1):]
                    if ((a[num - 1] == ' ' and (a[num + len(word1)] == ',' or a[num + len(word1)] == '.'
                                                or a[num + len(word1)] == ':' or a[num + len(word1)] == '!' or a[
                                                    num + len(word1)] == '?'))):
                        a = a[:num] + word2 + a[num + len(word1):]
                if num + len(word1) - 1 == len(a) - 1:
                    if (a[num - 1] == ' ' or a[num - 1] == '.' or a[num - 1] == ',' or a[num - 1] == ':' or
                            a[num - 1] == '?' or a[num - 1] == '!'):
                        a = a[:num] + word2 + a[num + len(word1):]
                if fl1 > len(a):
                    a = a[:num] + ('*' * len(word1)) + a[num + len(word1):]
                    fl1 = 0
                if fl1 > len(a):
                    break
                num = a.find(word1)
            num = -2
            fl1 = 0
            num = a.find('*' * len(word1))
            while num != -1:
                fl1 += 1
                a = a[:num] + word1 + a[num + len(word1):]
                if fl1 > len(a):
                    break
                num = a.find('*' * len(word1))
            if fl22 == 1:
                a = a.split()
                for i in a:
                    print(i,end=' ')
                print()
            if fl11 == 1:
                a = a.split()
                for i in range(len(a)):
                    if i == len(a) - 1:
                        continue
                    while mas1[s] == ' ':
                        a[i] += mas1[s]
                        s += 1
                    s += 1
                for i in a:
                    print(i, end='')
                print()
            if fl33 == 1:
                a = a.split()
                a += ['']
                for m in range(len(a) - 1, 0, -1):
                    a[m] = a[m - 1]
                a[0] = ''
                while mas2[s] == ' ':
                    a[0] += mas2[s]
                    s += 1
                s += 1
                for i in a:
                    print(i, end=' ')
                print()
            if fl11 == 0 and fl22 == 0 and fl33 == 0:
                print(a)
    elif choice == '5':
        text2 = text.copy()
        word3 = input('Введите слово для удаления: ')
        num = -2
        for a in text2:
            num = a.find(word3)
            fl1 = 0
            while num != -1:
                fl1 += 1
                if num + len(word3) <= len(a) - 1:
                    if a[num - 1] == ' ' and a[num + len(word3)] == ' ':
                        a = a[:num] + '' + a[num + len(word3):]
                    if ((a[num - 1] == ' ' and (a[num + len(word3)] == ',' or a[num + len(word3)] == '.'
                                                or a[num + len(word3)] == ':' or a[num + len(word3)] == '!' or a[
                                                    num + len(word3)] == '?'))):
                        a = a[:num] + '' + a[num + len(word3):]
                if num + len(word3) - 1 == len(a) - 1:
                    if (a[num - 1] == ' ' or a[num - 1] == '.' or a[num - 1] == ',' or a[num - 1] == ':' or
                            a[num - 1] == '?' or a[num - 1] == '!'):
                        a = a[:num] + '' + a[num + len(word3):]
                if fl1 > len(a):
                    a = a[:num] + ('*' * len(word3)) + a[num + len(word3):]
                    fl1 = 0
                if fl1 > len(a):
                    break
                num = a.find(word3)
            num = -2
            fl1 = 0
            num = a.find('*' * len(word3))
            while num != -1:
                fl1 += 1
                a = a[:num] + word3 + a[num + len(word3):]
                if fl1 > len(a):
                    break
                num = a.find('*' * len(word3))

            if fl22 == 1:
                a = a.split()
                for i in a:
                    print(i, end=' ')
                print()
            if fl11 == 1:
                a = a.split()
                for i in range(len(a)):
                    if i == len(a) - 1:
                        continue
                    while mas1[s] == ' ':
                        a[i] += mas1[s]
                        s += 1
                    s += 1
                for i in a:
                    print(i, end='')
                print()
            if fl33 == 1:
                a = a.split()
                print(a)
                a += ['']
                for m in range(len(a) - 1, 0, -1):
                    a[m] = a[m - 1]
                a[0] = ''
                while mas2[s] == ' ':
                    a[0] += mas2[s]
                    s += 1
                s += 1
                for i in a:
                    print(i, end=' ')
                print()
            if fl11 == 0 and fl22 == 0 and fl33 == 0:
                print(a)

    elif choice == '6':
        text3 = text.copy()
        for i in range(len(text3)):
            text3[i] = text3[i].split()
            fl1 = 0
            fl2 = 0
        for i in range(len(text3)):
            for j in range(len(text3[i])):
                try:
                    text3[i][j] = float(text3[i][j])
                except:
                    continue
        for i in range(len(text3)):
            for j in range(len(text3[i])):
                if text3[i][j] == '+' and (j != len(text3[i]) - 1):
                    try:
                        if text3[i][j - 1] == float(text3[i][j - 1]) and \
                                text3[i][j + 1] == float(text3[i][j + 1]):
                            text3[i][j + 1] = text3[i][j + 1] + text3[i][j - 1]
                            if int(text3[i][j + 1]) == float(text3[i][j + 1]):
                                text3[i][j + 1] = int(text3[i][j + 1])
                            else:
                                text3[i][j + 1] = float(text3[i][j + 1])
                        text3[i][j - 1] = '#'
                        text3[i][j] = '#'
                    except:
                        continue

                if text3[i][j] == '-' and (j != len(text3[i]) - 1):
                    try:
                        if text3[i][j - 1] == float(text3[i][j - 1]) and \
                                text3[i][j + 1] == float(text3[i][j + 1]) and (j + 1 <= len(text3[i]) - 1):
                            text3[i][j + 1] = text3[i][j - 1] - text3[i][j + 1]
                            if int(text3[i][j + 1]) == float(text3[i][j + 1]):
                                text3[i][j + 1] = int(text3[i][j + 1])
                            else:
                                text3[i][j + 1] = float(text3[i][j + 1])
                        text3[i][j - 1] = '#'
                        text3[i][j] = '#'
                    except:
                        continue

        for i in range(len(text3)):
            for j in range(len(text3[i])):
                if text3[i][j] == '#':
                    continue
                print(text3[i][j], end=' ')
            print()

    elif choice == '7':
        try:
            k = int(input('Введите k-ое вхождение: '))
        except:
            print('Введите число')
            continue
        text4 = text.copy()
        text5 = input('Введите искомую подстроку: ')
        num = -2
        n = 0
        a_correct = -2
        for a in range(len(text4)):
            num = text4[a].find(text5)
            fl3 = num
            fl2 = 0
            fl1 = 0
            while num != -1:
                if fl3 == num and fl1 > 0:
                    break
                fl1 += 1
                if num + len(text5) <= len(text4[a]) - 1:
                    if text4[a][num - 1] == ' ' and text4[a][num + len(text5)] == ' ':
                        n += 1
                        text4[a] = text4[a][:num] + ('#' * len(text5)) + text4[a][num + len(text5):]
                    if ((text4[a][num - 1] == ' ' and (text4[a][num + len(text5)] == ',' or text4[a][num + len(text5)] == '.'
                                                or text4[a][num + len(text5)] == ':' or text4[a][num + len(text5)] == '!' or
                                                       text4[a][num + len(text5)] == '?'))):
                        n += 1
                        text4[a] = text4[a][:num] + ('#' * len(text5)) + text4[a][num + len(text5):]
                if num + len(text5) - 1 == len(text4[a]) - 1:
                    if (text4[a][num - 1] == ' ' or text4[a][num - 1] == '.' or text4[a][num - 1] == ',' or text4[a][num - 1] == ':' or
                            text4[a][num - 1] == '?' or text4[a][num - 1] == '!'):
                        n += 1
                        text4[a] = text4[a][:num] + ('#' * len(text5)) + text4[a][num + len(text5):]
                if n == k and fl2 == 0:
                    text4[a] = text4[a][:num] + ('#' * len(text5)) + text4[a][num + len(text5):]
                    fl2 = 1
                    num_correct = num
                    a_correct = a
                if fl1 > len(text4):
                    break
                num = text4[a].find(text5)
        text4 = text.copy()
        for a in range(len(text4)):
            if a == a_correct:
                text4[a] = text4[a][:num_correct] + '[' + text5 + ']' + text4[a][num_correct + len(text5):]
            print(text4[a])

    else:
        print('Введенного номера нет ', choice)
        input('Нажмите Enter')
'''
