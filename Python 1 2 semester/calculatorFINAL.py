from tkinter import *
from tkinter import messagebox

window = Tk()
window.title('calculator')
window.resizable(False, False)
 
# Поле ввода
frame0 = Frame(window, bd='3')
label0 = Label(window, text='Поле ввода:')
label0.pack()
entry0 = Entry(frame0)
entry0.pack()
frame0.pack(side=TOP)


# Поле вывода
frame1 = Frame(window, bd='3')
label1 = Label(window, text='Поле вывода:')
label1.pack()
entry1 = Entry(frame1)
entry1.pack()
frame1.pack(side=TOP)


#постоянный опрос ввода
def timeconst():
    try:
        lentext1 = answer_cal()
        lentext2 = len(sorttext0())
        if lentext2 < lentext1:
            a = answer_cal()
    except:
        qwerty = 0   
timeconst()


# Считывание текста в поле ввода
def sorttext0():
    global entry0
    text = entry0.get()
    return text


# Считывание текста в поле вывода
def sorttext1():
    global entry1
    text = entry1.get()
    return text


# Удаление одного символа в поле ввода
def delete0():
    text = sorttext0()
    entry0.delete(len(text) - 1, 'end')
    timeconst()


# Удаление всех символов в поле ввода
def clear_text0():
    entry0.delete(0, 'end')
    timeconst()

# Удаление одного символа в поле вывода
def delete1():
    text = sorttext1()
    entry1.delete(len(text) - 1, 'end')


# Удаление всех символов в поле вывода
def clear_text1():
    entry1.delete(0, 'end')


# Окно "О программе"
def showinfo():
    messagebox.showinfo(title='О программе', message="""
  Карточка программы
 |название                = Calculator
 |автор                   = Савинов Егор
 |разработчики            = Индивидуально
 |написана на             = [[Python]]
 |интерфейс               = [[PyCharm]]
 |языки интерфейса        = русский 
 |операционные системы    = [[Linux]], [[OS X]] и др. [[UNIX-подобная операционная система|UNIX-подобные]], [[Windows]]
 |первый выпуск           = 15 февраля 2019
 |дата последней версии   = 17 февраля 2019
 |состояние               = активное""")


# Знак "+"
def plus_sign():
    text = sorttext0()
    global entry0
    entry0.insert(len(text), '+')
    timeconst()


# Знак "-"
def minus_sign():
    text = sorttext0()
    global entry0
    entry0.insert(len(text), '-')
    timeconst()

# Знак "0"
def zero_sign():
    text = sorttext0()
    global entry0
    entry0.insert(len(text), '0')
    timeconst()

# Сложение
def sum_cal():
    text = sorttext0()
    global entry0

    entry0.insert(len(text), ' |+| ')
    

# Вычитание
def subst_cal():
    text = sorttext0()
    global entry0
    entry0.insert(len(text), ' |-| ')


# Проверка ввода
def checkentry():
    global entry0
    text = entry0.get()
    text = text.split()
    flagcheck = 1
    for k in range(len(text)):
        if (text[k] == '|+|' or text[k] == '|-|') and (k == 0 or k == len(text) - 1):
            flagcheck = 0
    for i in range(len(text)):
        for j in range(len(text[i])):
            if text[i][j] != '0' and text[i][j] != '-' and text[i][j] != '+' and text[i][j] != '|':
                flagcheck = 0
                break
            if text[i][j] == '|' and (text[i] != '|+|' and text[i] != '|-|'):
                flagcheck = 0
                break
    return flagcheck


# Ответ
def answer_cal():
    text = sorttext0()
    text = text.split()
    textfinal = list()
    flag1 = 0
    flag2 = 0
    flagcheck = checkentry()
    for i in range(len(text)):
        if (text[i] == '|+|' or text[i] == '|-|') and flagcheck == 1:
            if text[i] == '|-|':
                for d in range(len(text[i + 1])):
                    fl1 = 0
                    s = text[i + 1]
                    if text[i + 1][d] == '-':
                        s = s[:d] + '+' + s[d + 1:]
                        fl1 = 1
                    if text[i + 1][d] == '+' and fl1 == 0:
                        s = s[:d] + '-' + s[d + 1:]
                    text[i + 1] = ''
                    for v in range(len(s)):
                        text[i + 1] += s[v]
            k = len(text[i - 1]) - 1
            j = len(text[i + 1]) - 1
            xtext = ''
            while k != -1 or j != -1:
                #print(text[i - 1][k],'  ',text[i + 1][j])
                if k == 0 and j != 0:
                    text[i - 1] = text[i - 1][::-1]
                    text[i - 1] += '0'
                    text[i - 1] = text[i - 1][::-1]
                    k += 1

                if k != 0 and j == 0:
                    text[i + 1] = text[i + 1][::-1]
                    text[i + 1] += '0'
                    text[i + 1] = text[i + 1][::-1]
                    j += 1

                if (flag1 == 1 or flag2 == 1) or (flag1 == 0 or flag2 == 0):
                    if (text[i-1][k] == '+' and text[i+1][j] == '+'):
                        if xtext == '-':
                            textfinal.append('+')
                            xtext = '-'
                        elif xtext == '+':
                            textfinal.append('0')
                            xtext = '+'
                        else:
                            textfinal.append('-')
                            xtext = '+'

                    if (text[i-1][k] == '-' and text[i+1][j] == '-'):
                        if xtext == '-':
                            textfinal.append('0')
                            xtext = '-'
                        elif xtext == '+':
                            textfinal.append('-')
                            xtext = ''
                        else:
                            textfinal.append('+')
                            xtext = '-'

                    if (text[i-1][k] == '+' and text[i+1][j] == '-') or (text[i-1][k] == '-' and text[i+1][j] == '+'):
                        if xtext == '+':
                            textfinal.append('+')
                        elif xtext == '-':
                            textfinal.append('-')
                        else:
                            textfinal.append('0')
                        xtext = ''

                    if (text[i-1][k] == '0' and text[i+1][j] == '-') or (text[i-1][k] == '-' and text[i+1][j] == '0'):
                        if xtext == '+':
                            textfinal.append('0')
                            xtext = ''
                        elif xtext == '-':
                            textfinal.append('+')
                            xtext = '-'
                        else:
                            textfinal.append('-')
                            xtext = ''

                    if (text[i-1][k] == '0' and text[i+1][j] == '+') or (text[i-1][k] == '+' and text[i+1][j] == '0'):
                        if xtext == '+':
                            textfinal.append('-')
                            xtext = '+'
                        elif xtext == '-':
                            textfinal.append('0')
                            xtext = ''
                        else:
                            textfinal.append('+')
                            xtext = ''

                    if (text[i-1][k] == '0' and text[i+1][j] == '0'):
                        if xtext == '+':
                            textfinal.append('+')
                        elif xtext == '-':
                            textfinal.append('-')
                        else:
                            textfinal.append('0')
                        xtext = ''

                    if k == 0 and j == 0 and xtext == '+':
                        textfinal.append('+')
                    if k == 0 and j == 0 and xtext == '-':
                        textfinal.append('-')

                k -= 1
                j -= 1

            textfinal.reverse()
            entry1.delete(0, 'end')
            for l in range(len(textfinal)):
                entry1.insert(l, textfinal[l])
            if (i + 2) < len(text):
                if text[i + 2] == '|+|' or text[i + 2] == '|-|':
                    text[i + 1] = ''
                    for h in range(len(textfinal)):
                        text[i + 1] += textfinal[h]
                    textfinal = list()

        if flagcheck == 0:
            entry0.delete(0, 'end')
            messagebox.showinfo(title='Ошибка',
            message="""Вы ввели недопустимые значения, попробуйте снова""")
            flagcheck = 1
            break
    lentext = len(text)
    return lentext

# Выпадающее меню
menu = Menu(window)
window.config(menu=menu)

submenu = Menu(menu)
menu.add_cascade(label='Действия', menu=submenu)
submenu.add_command(label='Сложение', command=sum_cal)
submenu.add_command(label='Вычитание', command=subst_cal)
submenu.add_separator()
submenu.add_command(label='Вывести результат', command=answer_cal)
submenu.add_separator()
submenu.add_command(label='Выход', command=exit)

submenu1 = Menu(menu)
menu.add_cascade(label='Очистка', menu=submenu1)
submenu1.add_command(label='Один символ из поле ввода', command=delete0)
submenu1.add_command(label='Все символы из поля ввода', command=clear_text0)
submenu1.add_separator()
#submenu1.add_command(label='Один символ из поле вывода', command=delete1)
submenu1.add_command(label='Все символы из поля вывода', command=clear_text1)

submenu2 = Menu(menu)
menu.add_cascade(label='Помощь', menu=submenu2)
submenu2.add_command(label='О программе', command=showinfo)


# Кнопки действий (+ - DEL AC =)
frame2 = Frame(window, bd='3')

label2 = Label(window, text='Действия:')
label2.pack()

button1 = Button(frame2, text='+', width=5, height=3, font='arial 14', command=sum_cal)
button1.pack(side=LEFT)

button2 = Button(frame2, text='-', width=5, height=3, font='arial 14', command=subst_cal)
button2.pack(side=LEFT)

button3 = Button(frame2, text='=', width=5, height=3, font='arial 14', command=answer_cal)
button3.pack(side=LEFT)

frame2.pack(side=TOP)

frame3 = Frame(window, bd='3')

label3 = Label(window, text='Действия для строки ввода:')
label3.pack()

button4 = Button(frame3, text='DEL', width=5, height=3, font='arial 14', command=delete0)
button4.pack(side=LEFT)

button5 = Button(frame3, text='AC', width=5, height=3, font='arial 14', command=clear_text0)
button5.pack(side=LEFT)

frame3.pack(side=TOP)

frame4 = Frame(window, bd='3')

label4 = Label(window, text='Действия для строки вывода:')
label4.pack()

#button6 = Button(frame4, text='DEL', width=5, height=3, font='arial 14', command=delete1)
#button6.pack(side=LEFT)

button7 = Button(frame4, text='AC', width=5, height=3, font='arial 14', command=clear_text1)
button7.pack(side=LEFT)

frame4.pack(side=TOP)


# Кнопки троичной системы (+ 0 -)
frame5 = Frame(window, bd='3')

label4 = Label(window, text='Ввод:')
label4.pack()

button8 = Button(frame5, text='-', width=5, height=3, font='arial 14', command=minus_sign)
button8.pack(side=LEFT)

button9 = Button(frame5, text='0', width=5, height=3, font='arial 14', command=zero_sign)
button9.pack(side=LEFT)

button10 = Button(frame5, text='+', width=5, height=3, font='arial 14', command=plus_sign)
button10.pack(side=LEFT)

frame5.pack(side=TOP)


window.mainloop()
