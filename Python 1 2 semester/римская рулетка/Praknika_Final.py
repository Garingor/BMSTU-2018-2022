text = [['5', '1'],
        ['1', '5'],
        ['0', '0']]
for k in range(len(text)):
    n = int(text[k][0])
    k = int(text[k][1])
    l = 3
    win_number = 0
    for i in range(1, n + 1):
        p = i
        j = n
        people = ['0'] * n
        num1 = 0                                        # счет k
        fl1 = 0                                         # флаг для корректной работы в цикле
        fl3 = 0                                         # флаг для корректной работы цикла по кругу
        if fl1 == 1:
            break
        while j != 1:                                   # цикл, пока не останется один человек в живых
            while num1 != k:                            # цикл отсчитывает k людей
                if fl1 == 0 and people[p-1] == '0':     # один раз не включает первого человека, с которого начинась игра
                    if p == n:
                        p = 1 + p - n
                    else:
                        p += 1
                    fl1 = 1
                if people[p-1] == '0':                  # счет k
                    num1 += 1
                if num1 == k:                           # остановиться на k-ом человеке
                    break
                if p == n:                              # циклит хождение по массиву
                    p = 1 + p - n
                    fl3 = 1
                if p != n and fl3 == 0:                 # переходит на следующего человека
                    p += 1
                fl3 = 0
            fl3 = 0
            num1 = 0
            people[p-1] = '1'                           # убивают человека
            j -= 1
            num = 0
            for v in range(len(people)):                # проверка на последнего выжившего
                if people[v] == '0':
                    num += 1
            if num == 1:
                for v in range(len(people)):
                    if people[v] == '0':
                        if people[l - 1] != '1':        # если человек на месте l не умер, то задача решена
                            win_number = i
                            fl1 = 1
                            break
    if win_number != 0:
        print('\nЕсли игра начнется с места', win_number, 'вы выживите на месте', l, '.')
    if n == 1:
        print('1')

