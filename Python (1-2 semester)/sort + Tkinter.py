from tkinter import *
from tkinter import messagebox
import random
import time

window = Tk()
window.title('Sorting methods')
window.geometry("600x650")

scrollbar = Scrollbar(window)
scrollbar.pack(side=RIGHT, fill=Y)

listbox = Listbox(window, yscrollcommand=scrollbar.set)

listbox.pack(side=BOTTOM, fill=BOTH)
scrollbar.config(command=listbox.yview)

# Массив малой размерности
frame01 = Frame(window, bd='3')
label01 = Label(window, text='Поле ввода массива малой размерности')
label01.pack()
entry01 = Entry(frame01)
entry01.pack()
frame01.pack(side=TOP)


# Проверка ввода массива
def checkentry1():
    flagcheck = 1
    global entry01
    text01 = entry01.get()
    text01 = text01.split()
    if (len(text01)) == 0:
        flagcheck = 0
        return flagcheck
    for i in range(len(text01)):
        for j in range(len(text01[i])):
            if text01[i][j] == '-' and j + 1 <= len(text01[i]):
                for k in range(j + 1, len(text01[i])):
                    if text01[i][k] < '0' or text01[i][k] > '9':
                        flagcheck = 0
            else:
                if text01[i][j] < '0' or text01[i][j] > '9':
                    flagcheck = 0
    return flagcheck


# Печать сортировки
def tabl6():
    flagcheck = checkentry1()
    if flagcheck == 1:
        global entry01
        text01 = entry01.get()
        text01 = text01.split()
        for i in range(len(text01)):
            text01[i] = int(text01[i])
        for i in range(len(text01) - 1):
            min_ind = i
            for itr in range(i + 1, len(text01)):
                if text01[itr] < text01[min_ind]:
                    min_ind = itr
            text01[min_ind], text01[i] = text01[i], text01[min_ind]
        listbox.insert(END, text01, '\n')
    else:
        entry01.delete(0, 'end')
        messagebox.showinfo(title='Ошибка', message="""Вы ввели недопустимые значения, попробуйте снова""")


# Кнопка расчета
frame12 = Frame(window)
button12 = Button(frame12, text='расчет', width=25, height=2, font='arial 14', command=tabl6)
button12.pack()
frame12.pack(side=TOP)

# Поле ввода левой границы диапазона
frame0 = Frame(window, bd='3')  # (рамка) предназначен для организации виджетов внутри окна
label0 = Label(window, text='Поле ввода левой границы диапазона:')
label0.pack()  # для отображения какой-либо надписи без возможности редактирования пользователем
entry0 = Entry(frame0)  # позволяющий пользователю ввести одну строку текста
entry0.pack()
frame0.pack(side=TOP)

# Поле ввода правой границы диапазона
frame1 = Frame(window, bd='3')
label1 = Label(window, text='Поле ввода правой границы диапазона:')
label1.pack()
entry1 = Entry(frame1)
entry1.pack()
frame1.pack(side=TOP)

# Поле ввода N1
frame2 = Frame(window, bd='3')
label2 = Label(window, text='Поле ввода N1:')
label2.pack()
entry2 = Entry(frame2)
entry2.pack()
frame2.pack(side=TOP)

# Поле ввода N2
frame3 = Frame(window, bd='3')
label3 = Label(window, text='Поле ввода N2:')
label3.pack()
entry3 = Entry(frame3)
entry3.pack()
frame3.pack(side=TOP)

# Поле ввода N3
frame4 = Frame(window, bd='3')
label4 = Label(window, text='Поле ввода N3:')
label4.pack()
entry4 = Entry(frame4)
entry4.pack()
frame4.pack(side=TOP)


def DEL(event):
    if entry0.get() != '' or entry1.get() != '' or entry2.get() != '' or entry3.get() != '' or entry4.get() != '':
        listbox.delete(0, END)

window.bind("<KeyPress>", DEL)

"""
var1=IntVar()
check1=Checkbutton(window,text='Удалять поле после  любого изменения поля ввода', variable=var1)
check1.pack(side=TOP)
print(var1)
if var1 == 1:
    window.bind("<KeyPress>", DEL)
else:
    pass
"""


def listbox_del():
    listbox.delete(0, END)


# Кнопка очистки
frame13 = Frame(window)
button13 = Button(frame13, text='очистка', width=25, height=2, font='arial 14', command=listbox_del)
button13.pack()
frame13.pack(side=TOP)


# Окно "О программе"
def showinfo():
    messagebox.showinfo(title='О программе', message="""
  Карточка программы
 |название                = Sorting methods
 |подпись                 = Версия 0.1.1
 |автор                   = Савинов Егор
 |языки интерфейса        = русский """)


# Проверка ввода для таблицы
def checkentry():
    flagcheck = 1
    global entry0
    text0 = entry0.get()
    text0 = text0.split()
    if (len(text0)) != 1:
        flagcheck = 0
        return flagcheck
    if text0[0][0] <= '0' or text0[0][0] > '9':
        flagcheck = 0
    if text0[0][0] == '0' and len(text0[0]) == 1:
        flagcheck = 1
    if text0[0][0] == '-' or text0[0][0] == '+':
        flagcheck = 1
    for i in range(1, len(text0[0])):
        if text0[0][i] < '0' or text0[0][i] > '9':
            flagcheck = 0

    global entry1
    text1 = entry1.get()
    text1 = text1.split()
    if (len(text1)) != 1:
        flagcheck = 0
        return flagcheck
    if text1[0][0] <= '0' or text1[0][0] > '9':
        flagcheck = 0
    if text1[0][0] == '0' and len(text1[0]) == 1:
        flagcheck = 1
    if text1[0][0] == '-' or '+' == text1[0][0]:
        flagcheck = 1
    for i in range(1, len(text1[0])):
        if text1[0][i] < '0' or text1[0][i] > '9':
            flagcheck = 0

    if flagcheck == 1 and (float(text1[0]) - float(text0[0]) < 0) and float(text0[0]) > 0 and float(text1[0]) > 0:
        flagcheck = 0
    if flagcheck == 1 and (abs(float(text1[0])) - abs(float(text0[0])) > 0) and \
            float(text0[0]) < 0 and float(text1[0]) < 0:
        flagcheck = 0
    if flagcheck == 1 and float(text0[0]) > 0 and float(text1[0]) < 0:
        flagcheck = 0

    global entry2
    text2 = entry2.get()
    text2 = text2.split()
    if (len(text2)) != 1:
        flagcheck = 0
        return flagcheck
    if text2[0][0] <= '0' or text2[0][0] > '9':
        flagcheck = 0
    for i in range(1, len(text2[0])):
        if (text2[0][i] < '0' or text2[0][i]) > '9':
            flagcheck = 0
    if text2[0] == '0':
        flagcheck = 0

    global entry3
    text3 = entry3.get()
    text3 = text3.split()
    if (len(text3)) != 1:
        flagcheck = 0
        return flagcheck
    if text3[0][0] < '0' or text3[0][0] > '9':
        flagcheck = 0
    for i in range(1, len(text3[0])):
        if (text3[0][i] < '0' or text3[0][i]) > '9':
            flagcheck = 0
    if text3[0] == '0':
        flagcheck = 0

    global entry4
    text4 = entry4.get()
    text4 = text4.split()
    if (len(text4)) != 1:
        flagcheck = 0
        return flagcheck
    if text4[0][0] <= '0' or text4[0][0] > '9':
        flagcheck = 0
    for i in range(1, len(text4[0])):
        if (text4[0][i] < '0' or text4[0][i]) > '9':
            flagcheck = 0
    if text4[0] == '0':
        flagcheck = 0

    return flagcheck


# Сортировки + время

# Неупорядоченный массив
def sort_1(entry1, entry2, entry3):
    text1 = int(entry1.get())
    text2 = int(entry2.get())
    text3 = int(entry3.get())

    mas = []
    for i in range(text3):
        mas.append(random.randrange(text1, text2))

    start = time.process_time()
    for i in range(len(mas) - 1):
        min_ind = i
        for itr in range(i + 1, len(mas)):
            if mas[itr] < mas[min_ind]:
                min_ind = itr
        mas[min_ind], mas[i] = mas[i], mas[min_ind]
    elapsed = (time.process_time() - start)

    return elapsed, mas


# Упорядоченный массив
def sort_2(entry1, entry2, entry3):
    mas = sort_1(entry1, entry2, entry3)[1]

    start = time.process_time()
    for i in range(len(mas) - 1):
        min_ind = i
        for itr in range(i + 1, len(mas)):
            if mas[itr] < mas[min_ind]:
                min_ind = itr
        mas[min_ind], mas[i] = mas[i], mas[min_ind]
    elapsed = (time.process_time() - start)

    return elapsed


# Обратный массив
def sort_3(entry1, entry2, entry3):
    mas = sort_1(entry1, entry2, entry3)[1]
    mas.reverse()
    start = time.process_time()
    for i in range(len(mas) - 1):
        min_ind = i
        for itr in range(i + 1, len(mas)):
            if mas[itr] < mas[min_ind]:
                min_ind = itr
        mas[min_ind], mas[i] = mas[i], mas[min_ind]
    elapsed = (time.process_time() - start)

    return elapsed


# С помощью sort()
def sort_4(entry1, entry2, entry3):
    text1 = int(entry1.get())
    text2 = int(entry2.get())
    text3 = int(entry3.get())

    mas = []
    for i in range(text3):
        mas.append(random.randrange(text1, text2))

    start = time.process_time()
    mas.sort()
    elapsed = (time.process_time() - start)

    return elapsed


# Проверка ввода для таблицы
def check_flagcheck():
    flagcheck = checkentry()
    if flagcheck == 0:
        entry0.delete(0, 'end')
        entry1.delete(0, 'end')
        entry2.delete(0, 'end')
        entry3.delete(0, 'end')
        entry4.delete(0, 'end')
        messagebox.showinfo(title='Ошибка', message="""Вы ввели недопустимые значения, попробуйте снова""")
    else:

        sort_1(entry0, entry1, entry2)
        sort_1(entry0, entry1, entry3)
        sort_1(entry0, entry1, entry4)

        sort_2(entry0, entry1, entry2)
        sort_2(entry0, entry1, entry3)
        sort_2(entry0, entry1, entry4)

        sort_3(entry0, entry1, entry2)
        sort_3(entry0, entry1, entry3)
        sort_3(entry0, entry1, entry4)

        sort_4(entry0, entry1, entry2)
        sort_4(entry0, entry1, entry3)
        sort_4(entry0, entry1, entry4)

        time2 = sort_1(entry0, entry1, entry2)[0]
        time3 = sort_1(entry0, entry1, entry3)[0]
        time4 = sort_1(entry0, entry1, entry4)[0]
        time5 = sort_2(entry0, entry1, entry2)
        time6 = sort_2(entry0, entry1, entry3)
        time7 = sort_2(entry0, entry1, entry4)
        time8 = sort_3(entry0, entry1, entry2)
        time9 = sort_3(entry0, entry1, entry3)
        time10 = sort_3(entry0, entry1, entry4)
        time11 = sort_4(entry0, entry1, entry2)
        time12 = sort_4(entry0, entry1, entry3)
        time13 = sort_4(entry0, entry1, entry4)

        tabl(time2, time3, time4, time5, time6, time7, time8, time9, time10, time11, time12, time13)


# Кнопка расчета
frame5 = Frame(window)
button1 = Button(frame5, text='расчет', width=25, height=2, font='arial 14', command=check_flagcheck)
button1.pack()
frame5.pack(side=TOP)

# Выпадающее меню

menu = Menu(window)
window.config(menu=menu)

submenu = Menu(menu)
menu.add_cascade(label='Действия', menu=submenu)
submenu.add_command(label='Расчет', command=check_flagcheck)
submenu.add_command(label='Выход', command=exit)

submenu2 = Menu(menu)
menu.add_cascade(label='Помощь', menu=submenu2)
submenu2.add_command(label='О программе', command=showinfo)


# Таблица

def tabl(time2, time3, time4, time5, time6, time7, time8, time9, time10, time11, time12, time13):
    text2 = int(entry2.get())
    text3 = int(entry3.get())
    text4 = int(entry4.get())
    str1 = '                                 |n1={:^18g}|n2={:^18g}|n3={:^18g}|'.format(text2, text3, text4)
    str2 = 'Неупорядоченный  |{:^20.5f}|{:^20.5f}|{:^20.5f}|'.format(time2, time3, time4)
    str3 = 'Упорядоченный      |{:^20.5f}|{:^20.5f}|{:^20.5f}|'.format(time5, time6, time7)
    str4 = 'Обратный                |{:^20.5f}|{:^20.5f}|{:^20.5f}|'.format(time8, time9, time10)
    str5 = 'Sort()                       |{:^20.5f}|{:^20.5f}|{:^20.5f}|'.format(time11, time12, time13)
    listbox.insert(END, str1, str2, str3, str4, str5, '\n')


window.mainloop()
