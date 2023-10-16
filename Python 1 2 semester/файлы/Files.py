def choice_file():

    simbol = ['|', '/', '*', '<', '>', '?',]
    fl_final = False
    while fl_final != True:
        filename = input('\nВведите имя файла: ')
        try:
            file = open(filename, 'r')
            fl_final = True
            if filename == '':
                print('\nВы ничего не ввели, попробуйте снова ')
                fl_final = False
        except:
            fl2 = 1
            for i in simbol:
                if i in filename:
                    fl2 = 0
            if fl2 == 1:
                print('\nТакого файла нет, создать? (1 - да, 0 - нет)')
                fl1 = input()
                if fl1 == '1':
                    try:
                        file = open(filename, 'w')
                        fl_final = True
                        if filename == '':
                            print('\nВы ничего не ввели, попробуйте снова ')
                            fl_final = False
                    except:
                        print('\nВведены запрещенные символы, попробуйте снова')
                else:
                    exit('\nВы не захотели создавать файл, завершение работы...')
            if fl2 == 0:
                print('\nВведены запрещенные символы, попробуйте снова')

    return filename


def new_write(filename):

    if fl_file == 0:
        print('\nФайл не выбран, перенаправляю на выбор файла...')
        filename = choice_file()

    file = open(filename, 'w')
    file.close()

    fl_1 = False
    while fl_1 != True:
        try:
            lines_num = int(input('\nВведите кол-во строк в файле: '))
            fl_1 = True
            if lines_num < 0:
                fl_1 = False
        except:
            print('\nВы ввели не цифру, попробуйте снова')


    for j in range(lines_num):
        fl_1 = False
        while fl_1 != True:
            fl_current = 1
            lines = input('\nВведите фамилию: ')
            fl4 = 0
            if lines == '':
                fl_current = 0
            if 'А' <= lines[0] <= 'Я' or 'A' <= lines[0] <= 'Z':
                fl1 = 1
            else:
                fl1 = 0
                fl_current = 0
            if fl1 == 0 and fl4 == 0:
                print('\nВ фамилии присутствуют грубые ошибки')
                fl4 = 1
            for i in range(1, len(lines) - 1, 1):
                if 'а' <= lines[i] <= 'я' or 'a' <= lines[i] <= 'z':
                    fl2 = 1
                else:
                    fl2 = 0
                    fl_current = 0
                if fl2 == 0 and fl4 == 0:
                    print('\nВ фамилии присутствуют грубые ошибки')
            if fl_current == 1:
                fl_1 = True

        with open(filename, 'a') as f:
            f.write(str(lines))

        fl_1 = False
        while fl_1 != True:
            fl_current = 1
            print('\nВведите ученику ', lines, 'две оценки, через запятую: ')
            marks = input()
            marks = marks.split(',')
            fl4 = 0
            if len(marks) != 2:
                fl_current = 0
            for i in range(len(marks)):
                if '2' <= marks[i] <= '5':
                    fl3 = 1
                else:
                    fl3 = 0
                    fl_current = 0
                if len(marks[i]) > 1:
                    fl3 = 0
                    fl_current = 0
                if fl3 == 0 and fl4 == 0:
                    print('\nВ оценках присутствуют грубые ошибки')
                    fl4 = 1
            if fl_current == 1:
                fl_1 = True

        with open(filename, 'a') as f:
            for i in range(len(marks)):
                f.write('|' + str(marks[i]))
        with open(filename, 'a') as f:
            f.write('\n')
    return filename

def add_to_file(filename):

    if fl_file == 0:
        print('\nФайл не выбран, перенаправляю на выбор файла...')
        filename = choice_file()

    fl_1 = False
    while fl_1 != True:
        try:
            lines_num = int(input('\nВведите сколько строк хотите добавить: '))
            fl_1 = True
            if lines_num < 0:
                print('\nКол-во строк всегда больше нуля')
                fl_1 = False
        except:
            print('\nВы ввели не цифру, попробуйте снова')

    for j in range(lines_num):
        fl_1 = False
        while fl_1 != True:
            fl_current = 1
            lines = input('\nВведите фамилию: ')
            fl4 = 0
            if lines == '':
                fl_current = 0
            if 'А' <= lines[0] <= 'Я' or 'A' <= lines[0] <= 'Z':
                fl1 = 1
            else:
                fl1 = 0
                fl_current = 0
            if fl1 == 0 and fl4 == 0:
                print('\nВ фамилии присутствуют грубые ошибки')
                fl4 = 1
            for i in range(1, len(lines) - 1, 1):
                if 'а' <= lines[i] <= 'я' or 'a' <= lines[i] <= 'z':
                    fl2 = 1
                else:
                    fl2 = 0
                    fl_current = 0
                if fl2 == 0 and fl4 == 0:
                    print('\nВ фамилии присутствуют грубые ошибки')
            if fl_current == 1:
                fl_1 = True

        with open(filename, 'a') as f:
            f.write(str(lines))

        fl_1 = False
        while fl_1 != True:
            fl_current = 1
            print('\nВведите ученику ', lines, 'две оценки, через запятую: ')
            marks = input()
            marks = marks.split(',')
            fl4 = 0
            if len(marks) != 2:
                fl_current = 0
            for i in range(len(marks)):
                if '2' <= marks[i] <= '5':
                    fl3 = 1
                else:
                    fl3 = 0
                    fl_current = 0
                if len(marks[i]) > 1:
                    fl3 = 0
                    fl_current = 0
                if fl3 == 0 and fl4 == 0:
                    print('\nВ оценках присутствуют грубые ошибки')
                    fl4 = 1
            if fl_current == 1:
                fl_1 = True
        with open(filename, 'a') as f:
            for i in range(len(marks)):
                f.write('|' + str(marks[i]))
        with open(filename, 'a') as f:
            f.write('\n')
    return filename

def see_file(filename):

    if fl_file == 0:
        print('\nФайл не выбран, перенаправляю на выбор файла...')
        filename = choice_file()
    print('\n')
    fl_tabl = 0
    with open(filename, 'r') as f:
        for line in f:
            line = line.strip()
            line_correct = line.split('|')
            if fl_tabl == 0:
                fl_tabl = 1
                print('---------------------------------------')
                print('|   Фамилия   | оценка по | оценка по |')
                print('|             | биологии  | истории   |')
                print('---------------------------------------')
            print('|{:^13}|'.format(line_correct[0]),'{:^10}|'.format(line_correct[1]),'{:^10}|'.format(line_correct[2]))
            print('---------------------------------------')
    return filename

def search_one(filename):

    if fl_file == 0:
        print('\nФайл не выбран, перенаправляю на выбор файла...')
        filename = choice_file()

    fl_1 = False
    while fl_1 != True:
        fl_current = 1
        print('\nС какой оценкой вывести список фамилий? ')
        num = input()
        if len(num) > 1:
            fl_current = 0
            fl1 = 0
        num = num.split()
        if '2' <= num[0] <= '5':
            fl1 = 1
        else:
            fl1 = 0
            fl_current = 0
        if fl1 == 0:
            print('\nВы ввели неправильно, попробуйте снова ввести правильно')
            fl_current = 0
        if fl_current == 1:
            fl_1 = True
    num_correct = ''
    num_correct += num[0]
    fl12 = 1
    with open(filename, 'r') as f:
        for line in f:
            fl1 = 0
            for i in range(len(line)):
                if line[i] == num_correct and fl1 == 0:
                    fl1 = 1
                    fl12 = 0
                    print(line)
            if fl12 == 1:
                print('\nПоиск не дал результатов')
    return filename

def search_two(filename):
    if fl_file == 0:
        print('\nФайл не выбран, перенаправляю на выбор файла...')
        filename = choice_file()

    fl_1 = False
    while fl_1 != True:
        fl_current = 1
        print('\nС какими двумя оценками вывести список фамилий?(введите через запятую) ')
        num = input()
        num = num.split(',')
        fl__num = 1
        if len(num) != 2:
            print('\nВы ввели неправильно, попробуйте снова ввести правильно')
            fl_current = 0
            fl__num = 0
        if fl__num == 1:
            if '2' <= num[0] <= '5' or '2' <= num[1] <= '5':
                fl1 = 1
            else:
                fl1 = 0
                fl_current = 0
            if fl1 == 0:
                print('\nВы ввели неправильно, попробуйте снова ввести правильно')
        if fl_current == 1:
            fl_1 = True

    num_correct1 = ''
    num_correct2 = ''
    num_correct1 += num[0]
    num_correct2 += num[1]
    fl12 = 1
    with open(filename, 'r') as f:
        for line in f:
            fl1 = 0
            fl2 = 0
            for i in range(len(line)-2):
                if line[i] == num_correct1 and line[i+2] == num_correct2:
                    print(line)
                    fl12 = 0
                    break
        if fl12 == 1:
            print('\nПоиск не дал результатов')
    return filename
choice = None
fl_file = 0
mark_num = 0
filename = None

while choice != '0':
    print('\nМеню программы:')
    print('(0) Выход ')
    print('(1) Выбор файла')
    print('(2) Создание нового набора записей')
    print('(3) Добавление записи')
    print('(4) Вывод всех записей')
    print('(5) Поиск по одному полю')
    print('(6) Поиск по двум полям')

    choice = input('Выбор: ')

    if choice == '0':
        print('\nВыход\n')

    elif choice == '1':
        filename = choice_file()
        fl_file = 1
    elif choice == '2':
        filename = new_write(filename)
        fl_file = 1
    elif choice == '3':
        filename = add_to_file(filename)
        fl_file = 1
    elif choice == '4':
        filename = see_file(filename)
        fl_file = 1
    elif choice == '5':
        filename = search_one(filename)
        fl_file = 1
    elif choice == '6':
        filename = search_two(filename)
        fl_file = 1
    else:
        print('\nНекорректные данные ', choice)
        input('\nНажмите Enter')

