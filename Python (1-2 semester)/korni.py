from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import matplotlib
from numpy import linspace, sin, cos
matplotlib.use('TkAgg')
from matplotlib.pyplot import plot, show, subplots, xlabel, ylabel, title, legend, figure


def f(x):
    try:
        y = sin(x)
    except:
        return None
    return y


def f_1(x):
    try:
        y = cos(x)
    except:
        return None
    return y

def f_2(x):
    try:
        y = -sin(x)
    except:
        return None
    return y


def graph(x_tek, y_tek):
    a = float(window.entry_segment_a.get())
    b = float(window.entry_segment_b.get())
    x = linspace(a, b, 10000)
    y = f(x)
    #fig = figure()
    fig, ax = subplots()
    max_x = []
    min_x = []
    max_y = []
    min_y = []
    eps = 0.001
    for i in range(len(x)):
        if f_1(x[i] + eps) > 0 and f_1(x[i] - eps) < 0 and (((f_2(x[i] + eps)) * (f_2(x[i] - eps)) > 0)
                                                            or f_2(x[i]) == None):
            min_x.append(x[i])
            min_y.append(f(x[i]))
        if f_1(x[i] + eps) < 0 and f_1(x[i] - eps) > 0 and (((f_2(x[i] + eps)) * (f_2(x[i] + eps)) > 0)
                                                            or f_2(x[i]) == None):
            max_x.append(x[i])
            max_y.append(f(x[i]))
    if len(max_y) != 0 and len(min_y) == 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(max_x, max_y, 'v', label="максимум")
        legend(loc='best')
        show()
        return 0
    if len(max_y) == 0 and len(min_y) != 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(min_x, min_y, '^', label="минимум")
        legend(loc='best')
        show()
        return 0
    if len(min_y) != 0 and len(max_y) != 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(min_x, min_y, '^', label="минимум")
        ax.plot(max_x, max_y, 'v', label="максимум")
        legend(loc='best')
        show()
        return 0
    if len(min_y) == 0 and len(max_y) == 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        legend(loc='best')
        show()
        return 0
    return 0

window = Tk()
window.title('Roots of equation')
window.geometry("950x800")

# Поле ввода
label_segment_a = Label(window, text='Введите левую границу:')
label_segment_a.place(x=10, y=10)
window.entry_segment_a = Entry(window)
window.entry_segment_a.place(x=200, y=10)

label_segment_b = Label(window, text='Введите правую границу:')
label_segment_b.place(x=10, y=50)
window.entry_segment_b = Entry(window)
window.entry_segment_b.place(x=200, y=50)

label_iter = Label(window, text='Введите шаг:')
label_iter.place(x=10, y=90)
window.entry_iter = Entry(window)
window.entry_iter.place(x=200, y=90)

label_eps = Label(window, text='Введите точность:')
label_eps.place(x=10, y=130)
window.entry_eps = Entry(window)
window.entry_eps.place(x=200, y=130)

label_max = Label(window, text='Введите max итераций:')
label_max.place(x=10, y=170)
window.entry_max = Entry(window)
window.entry_max.place(x=200, y=170)

label_fail_0 = Label(window, text='Нет корня - 2 (знаки функций на отрезке одинаковые)')
label_fail_0.place(x=10, y=540)
label_fail_1 = Label(window, text='Невозможно подсчитать функцию / производную - 3')
label_fail_1.place(x=10, y=580)
label_fail_2 = Label(window, text='Превышено максимальное кол-во итераций - 4')
label_fail_2.place(x=10, y=620)
label_fail_3 = Label(window, text='Вышли за пределы отрезка - 5')
label_fail_3.place(x=10, y=660)
label_fail_4 = Label(window, text='один и тот же корень на концах отрезка - 6')
label_fail_4.place(x=10, y=700)
label_fail_5 = Label(window, text='результат с учетом правой границы поиска - 7')
label_fail_5.place(x=10, y=740)

fl1 = 0
def method(a_tek, b_tek):
    a = float(window.entry_segment_a.get())
    b = float(window.entry_segment_b.get())
    h = float(window.entry_iter.get())
    global fl1
    eps = float(window.entry_eps.get())
    iter_max = int(window.entry_max.get())
    n_tek = 0
    iter_tek = 0
    if b_tek > b:
        return -1
    tek = f(a_tek) * f(b_tek)
    if tek > 0.0:
        return -2
    else:
        if f(a_tek) * f_2(a_tek) > 0:
            x_n = a_tek
            if abs(f(a_tek)) < eps:
                return a_tek, f(a_tek), 1
        elif f(b_tek) * f_2(b_tek) > 0:
            if abs(f(b_tek)) < eps:
                return b_tek, f(b_tek), 1
            x_n = b_tek
        else:
            x_n = a_tek
        if f_1(x_n) != None and f(x_n) != None:
            try:
                x_n_1 = x_n - (f(x_n) / f_1(x_n))
            except:
                return -3
            """
            if abs(x_n - x_n_1) <= eps:
                check = x_n_1
                return x_n_1, f(x_n_1), 1
            """
            if abs(x_n - x_n_1) <= eps:
                n_tek = 1
            print(a_tek, b_tek)
            print('--------')
            while abs(x_n - x_n_1) > eps:
                print(x_n_1)
                x_n = x_n_1
                x_n_1 = x_n - (f(x_n) / f_1(x_n))
                n_tek += 1
                iter_tek += 1
                if iter_tek == iter_max:
                    return -4
            if x_n_1 < a_tek or x_n_1 > b_tek:
                #print(x_n_1, ' < ', a_tek, '  ', x_n_1, ' > ', b_tek)
                return -5
        else:
            return -3
    return x_n_1, f(x_n_1), n_tek

# Проверка ввода
def checkentry(entry_segment_a, entry_segment_b, entry_iter, entry_eps, entry_max):
    flagcheck = 1
    segment_a = entry_segment_a.get()
    segment_a = segment_a.split()
    if (len(segment_a)) != 1:
        flagcheck = 0
        return 0
    try:
        float(segment_a[0])
    except:
        flagcheck = 0

    segment_b = entry_segment_b.get()
    segment_b = segment_b.split()
    if (len(segment_b)) != 1:
        flagcheck = 0
        return 0
    try:
        float(segment_b[0])
    except:
        flagcheck = 0

    if flagcheck == 1 and (float(segment_b[0]) - float(segment_a[0]) < 0) and float(segment_a[0]) > 0 and \
            float(segment_b[0]) > 0:
        flagcheck = 0
    if flagcheck == 1 and (abs(float(segment_b[0])) - abs(float(segment_a[0])) > 0) and \
            float(segment_a[0]) < 0 and float(segment_b[0]) < 0:
        flagcheck = 0
    if flagcheck == 1 and float(segment_a[0]) > 0 and float(segment_b[0]) < 0:
        flagcheck = 0
    if float(segment_a[0]) == float(segment_b[0]):
        flagcheck = 0

    iter = entry_iter.get()
    iter = iter.split()
    if (len(iter)) != 1:
        flagcheck = 0
        return flagcheck
    if float(iter[0]) <= 0:
        flagcheck = 0
    try:
        float(iter[0])
    except:
        flagcheck = 0
        return 0
    eps = entry_eps.get()
    eps = eps.split()
    if (len(eps)) != 1:
        flagcheck = 0
        return 0
    if float(eps[0]) <= 0.0 or float(eps[0]) >= 1.0:
        flagcheck = 0
    try:
        float(eps[0])
    except:
        flagcheck = 0
        return 0

    iter_max = entry_max.get()
    iter_max = iter_max.split()
    if (len(iter_max)) != 1:
        flagcheck = 0
        return 0
    try:
        int(iter_max[0])
    except:
        flagcheck = 0
        return 0
    if (int(iter_max[0]) <= 0):
        flagcheck = 0
        return 0
    try:
        int(iter_max[0])
    except:
        flagcheck = 0

    return flagcheck


# Очистка
def DEL(event):
    if window.entry_segment_a.get() != '' or window.entry_segment_b.get() != '' or window.entry_iter.get() != '' \
            or window.entry_eps.get() != '' or window.entry_max.get() != '':
        pass


window.bind("<KeyPress>", DEL)


def decision():
    flagcheck = checkentry(window.entry_segment_a, window.entry_segment_b, window.entry_iter, window.entry_eps,
                           window.entry_max)
    if flagcheck == 0:
        window.entry_segment_a.delete(0, 'end')
        window.entry_segment_b.delete(0, 'end')
        window.entry_iter.delete(0, 'end')
        window.entry_eps.delete(0, 'end')
        window.entry_max.delete(0, 'end')
        messagebox.showinfo(title='Ошибка', message="""Вы ввели недопустимые значения, попробуйте снова""")
    else:
        mas = tabl()
        graph(mas[0], mas[1])


# Кнопки
button_decision = Button(window, text='Вычислить', width=25, height=2, command=decision)
button_decision.place(x=10, y=210)

# Таблица
window.tree = ttk.Treeview(window, column=('#', 'segment', 'aver_x', 'f(aver_x)', 'iter', 'code'), height=15,
                           show='headings')

window.tree.column('#', width=100, anchor=CENTER)
window.tree.column('segment', width=300, anchor=CENTER)
window.tree.column('aver_x', width=150, anchor=CENTER)
window.tree.column('f(aver_x)', width=150, anchor=CENTER)
window.tree.column('iter', width=150, anchor=CENTER)
window.tree.column('code', width=50, anchor=CENTER)

window.tree.heading('#', text='#')
window.tree.heading('segment', text='[x(i),x(i+1)]')
window.tree.heading('aver_x', text='aver_x')
window.tree.heading('f(aver_x)', text='f(aver_x)')
window.tree.heading('iter', text='iter')
window.tree.heading('code', text='code')

window.tree.place(x=10, y=250)

# Данные в таблице
def tabl():
    for i in window.tree.get_children():
        window.tree.delete(i)
    a = float(window.entry_segment_a.get())
    b = float(window.entry_segment_b.get())
    h = float(window.entry_iter.get())
    n = 0
    i = b
    j = a
    x = []
    y = []
    while i > a:
        i -= h
        n += 1
        j += h
    n_check = n
    flag_7 = 1
    i = j
    while i > a and n != 0:
        if i != b and n_check == n and flag_7 == 1:
            if method((i - h), b) == -1:
                continue
            elif method((i - h), b) == -2:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']', '-',
                                           '-', '-', '2, 7'])
            elif method((i - h), i) == -3:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']', '-',
                                           '-', '-', '3, 7'])
            elif method((i - h), i) == -4:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']', '-',
                                           '-', '-', '4, 7'])
            elif method((i - h), i) == -5:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']', '-',
                                           '-', '-', '5, 7'])
            else:
                flag_6 = 0
                flag_method = 0
                if i - h - h >= a:
                    try:
                        i_h_h = method((i - h - h), (i - h))[0]
                        i_h = method((i - h), b)[0]
                        if abs(i_h - i_h_h) < 0.001:
                            flag_6 = 1
                    except:
                        flag_6 = 0
                if flag_6 == 0:
                    try:
                        window.tree.insert("", index=0, values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']',
                                                                '{:.5g}'.format(method((i - h), b)[0]),
                                                                '{:1.0e}'.format(method((i - h), b)[1]),
                                                                method((i - h), b)[2], '7'])
                        x.append(method((i - h), b)[0])
                        y.append(method((i - h), b)[1])
                    except:
                        window.tree.insert("", index=0,
                                           values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']',
                                                   '-',
                                                   '-', '-', '2'])
                if flag_6 != 0:
                    window.tree.insert("", index=0,
                                       values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(b) + ']', '-',
                                               '-', '-', '6, 7'])
            flag_7 = 0
        else:
            if method((i - h), i) == -1:
                continue
            elif method((i - h), i) == -2:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(i) + ']', '-',
                                           '-', '-', '2'])
            elif method((i - h), i) == -3:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(i) + ']', '-',
                                           '-', '-', '3'])
            elif method((i - h), i) == -4:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(i) + ']', '-',
                                           '-', '-', '4'])
            elif method((i - h), i) == -5:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(i) + ']', '-',
                                           '-', '-', '5'])
            else:
                flag_6 = 0
                flag_method = 0
                if i - h - h >= a:
                    try:
                        i_h_h = method((i - h - h), (i - h))[0]
                        i_h = method((i - h), i)[0]
                        if abs(i_h - i_h_h) < 0.001:
                            flag_6 = 1
                    except:
                        flag_6 = 0
                if flag_6 == 0:
                    window.tree.insert("", index=0, values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(i) + ']',
                                                            '{:.5g}'.format(method((i - h), i)[0]),
                                                            '{:1.0e}'.format(method((i - h), i)[1]),
                                                            method((i - h), i)[2], '-'])
                    x.append(method((i - h), i)[0])
                    y.append(method((i - h), i)[1])
                if flag_6 != 0:
                    window.tree.insert("", index=0,
                                       values=[n, '[' + '{:.4g}'.format(i - h) + ',' + '{:.4g}'.format(i) + ']', '-',
                                               '-', '-', '6'])
        i -= h
        n -= 1
    return x, y

# Всплывающее окно
def showinfo():
    messagebox.showinfo(title='О программе', message="""
  Карточка программы
 |название                = Roots of equation
 |подпись                 = Версия 0.1.1
 |автор                   = Савинов Егор
 |языки интерфейса        = русский """)


# Выпадающее меню

menu = Menu(window)
window.config(menu=menu)

submenu = Menu(menu)
menu.add_cascade(label='Действия', menu=submenu)
submenu.add_command(label='Вычислить', command=decision)
submenu.add_command(label='Выход', command=exit)

submenu2 = Menu(menu)
menu.add_cascade(label='Помощь', menu=submenu2)
submenu2.add_command(label='О программе', command=showinfo)

window.mainloop()
'''
def graph(x_tek, y_tek):
    a = float(window.entry_segment_a.get())
    b = float(window.entry_segment_b.get())
    x = linspace(a, b, 10000)
    y = f(x)
    #fig = figure()
    fig, ax = subplots()
    max_x = []
    min_x = []
    max_y = []
    min_y = []
    eps = 0.1
    for i in range(len(x)):
        if f_1(x[i] + eps) > 0 and f_1(x[i] - eps) < 0 and (((f_2(x[i] + eps)) * (f_2(x[i] - eps)) > 0)
                                                            or f_2(x[i]) == None):
            min_x.append(x[i])
            min_y.append(f(x[i]))
        if f_1(x[i] + eps) < 0 and f_1(x[i] - eps) > 0 and (((f_2(x[i] + eps)) * (f_2(x[i] + eps)) > 0)
                                                            or f_2(x[i]) == None):
            max_x.append(x[i])
            max_y.append(f(x[i]))
    if len(min_y) != 0:
        min_y1 = min_y[0]
        min_x1 = min_x[0]
        for i in range(1, len(min_y)):
            if min_y[i] < min_y1:
                min_y1 = min_y[i]
                min_x1 = min_x[i]
    if len(max_y) != 0:
        max_y1 = max_y[0]
        max_x1 = max_x[0]
        for i in range(1, len(max_y)):
            if max_y[i] > max_y1:
                max_y1 = max_y[i]
                max_x1 = max_x[i]
    if len(max_y) != 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(min_x, min_y, '^', label="минимум")
        ax.plot(max_x1, max_y1, 'v', label="максимум")
        legend(loc='best')
        show()
        return 0
    if len(min_y) != 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(min_x1, min_y1, '^', label="минимум")
        ax.plot(max_x, max_y, 'v', label="максимум")
        legend(loc='best')
        show()
        return 0
    if len(min_y) != 0 and len(max_y) != 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(min_x1, min_y1, '^', label="минимум")
        ax.plot(max_x1, max_y1, 'v', label="максимум")
        legend(loc='best')
        show()
        return 0
    if len(min_y) == 0 and len(max_y) == 0:
        xlabel('x')
        ylabel('y')
        title('function')
        ax.hlines(0, a, b, 'b')
        ax.vlines(0, f(x).min(), f(x).max(), 'b')
        ax.plot(x, y, 'r', label="f(x)")
        ax.plot(x_tek, y_tek, 'o', label="корни")
        ax.plot(min_x, min_y, '^', label="минимум")
        ax.plot(max_x, max_y, 'v', label="максимум")
        legend(loc='best')
        show()
        return 0
    return 0
'''
# -*- coding: utf -*-

"""

==============================================================================

Python. Лабораторная работа №3. Уточнение корней уравнения.
Метод: комбинированный (хорд и касательных)

Данная программа вычисляет приблизительные корни заданого не линейного уравн.
на заданном интервале и с заданным шагом поиска корней. Данные о найденных
корнях выводится в таблицу. Так же, программа показывает график заданной 
функции, найденные корни, точки перегиба.

График функции:

x^6-24x^5+208x^4-768x^3+1024x^2-10x-400

Разработчик: Романов Алексей ИУ7-23Б

==============================================================================


"""

from matplotlib import mlab
import pylab
from math import *
import numpy as np
from tkinter import *
from tkinter import messagebox as msb


# Информация о программе

def about_program():
    msb.showinfo("Информация о программе", "Данная программа вычисляет приближенное \
значение корней уравнения с помощью комбинированного метода (метод хорд и касательных). \
Пользователь может задать интервал поиска, шаг поиска, точность ε и максимальное \
количество итераций. Все данные выводятся в таблицу. Так же показывается \
график функции, найденных решений и точек перегиба.\n\n\
Разработчк: Романов Алексей, группа ИУ7-23Б")


# Очищение всех лэйблов

def clear_all_labels():
    list_with_all_labels = [label_number, label_interval, \
                            label_approximate, label_approximate_func, \
                            label_count_iteration, label_code_error]

    for labels_list in list_with_all_labels:
        labels_list["text"] = ""
        labels_list["font"] = "Arial 12"


# Поиск значения второй производной

def second_derivative_f(x):
    function = -sin(x)  # 2
    return function
    # return 30 * (x ** 4) - 480 * (x ** 3) + 2496 * (x ** 2) - 4608 * x + 2048


# Поиск значения первой производной

def derivative_f(x):
    function = cos(x)  # 2 * x
    return function
    # return 6 * (x ** 5) - 120 * (x ** 4) + 832 * (x ** 3) - 2304 * (x ** 2) + 2048 * x - 10


# Поиск значения f(x)

def f(x):
    function = sin(x)  # x * x - 4
    return function
    # return  (x ** 2) * ((x-4) ** 2) * ((x-8) ** 2) - 10 * x - 400


# Создание графика

def create_graph(xmin=-1, xmax=9, list_x_approximate=False):
    dx = 0.001
    fig = pylab.gcf()
    fig.canvas.set_window_title("Fuction graph")
    xlist = np.arange(xmin, xmax, dx)
    ylist = [f(x) for x in xlist]
    x_list_OX = np.arange(xmin, xmax, dx)
    y_list_OX = [0 for x in (x_list_OX)]

    pylab.xlabel("x")
    pylab.ylabel("y")
    pylab.plot(xlist, ylist, label="f(x)")
    pylab.plot(x_list_OX, y_list_OX)

    if list_x_approximate:
        for i in range(len(list_x_approximate)):
            y = f(list_x_approximate[i])
            if i == 0:
                pylab.scatter(list_x_approximate[i], y, color="red", \
                              label="Solutions")
            else:
                pylab.scatter(list_x_approximate[i], y, color="red")

    pylab.legend()
    pylab.title("f(x)")
    pylab.tick_params(labelsize=14)

    pylab.show()


# Обновление лейблов

def update_labels(count_roots, temp_a, temp_b, border, \
                  code_error, count_iterations):
    list_with_all_labels = [label_number, label_interval, \
                            label_approximate, label_approximate_func, \
                            label_count_iteration, label_code_error]

    if count_roots > 16:
        for labels in list_with_all_labels:
            labels["font"] = "Arial 5"
    elif count_roots >= 13:
        for labels in list_with_all_labels:
            labels["font"] = "Arial 6"
    elif count_roots >= 10:
        for labels in list_with_all_labels:
            labels["font"] = "Arial 7"
    elif count_roots > 7:
        for labels in list_with_all_labels:
            labels["font"] = "Arial 10"

    label_number["text"] += str(count_roots) + "\n\n"
    label_interval["text"] += "[{:.2f}, {:.2f}]" \
                                  .format(temp_a, temp_b) + "\n\n"
    if int(code_error) == 0:
        label_approximate["text"] += \
            "{:.6f}".format(border) + "\n\n"
        label_approximate_func["text"] += \
            "{:.0e}".format(f(border)) + "\n\n"
    else:
        label_approximate["text"] += "-\n\n"
        label_approximate_func["text"] += "-\n\n"

    label_count_iteration["text"] += \
        str(count_iterations) + "\n\n"
    label_code_error["text"] += str(code_error) + "\n\n"


# Комбинированный метод

def combined_method(step, interval_list, epsilon, max_iterations):
    border_a = interval_list[0]
    border_b = interval_list[1]
    list_x_approximate = []
    total_interval = border_b - border_a
    temp_a = border_a
    count_roots = 0

    for i in range(ceil(total_interval / step)):
        temp_b = temp_a + step
        code_error = "0"
        count_iterations = 1
        try_search = 1

        if temp_b > border_b:
            temp_b = border_b

        if (f(temp_b) * f(temp_a)) < 0:
            count_roots += 1

            while try_search < 3:

                if try_search == 1:
                    left_border = temp_a + ((f(temp_a) * \
                                             (temp_a - temp_b)) / (f(temp_a) - f(temp_b)))
                    right_border = temp_b - (f(temp_b) / derivative_f(temp_b))

                    while abs(right_border - left_border) > epsilon \
                            and count_iterations < max_iterations:
                        left_border = left_border + ((f(left_border) * \
                                                      (right_border - left_border)) / \
                                                     (f(left_border) - f(right_border)))
                        right_border = right_border - (f(right_border) / derivative_f(right_border))
                        count_iterations += 1

                    if temp_a < (right_border + left_border) / 2 < temp_b:
                        break

                else:
                    left_border = temp_a - (f(temp_a) / derivative_f(temp_a))
                    right_border = temp_b + ((f(temp_b) * (temp_b - temp_a)) / (f(temp_b) - f(temp_a)))

                    while abs(right_border - left_border) > epsilon and \
                            count_iterations < max_iterations:
                        right_border = right_border + ((f(right_border) * \
                                                        (right_border - left_border)) \
                                                       / (f(left_border) - f(right_border)))
                        left_border = left_border - (f(left_border) / derivative_f(left_border))
                        count_iterations += 1

                try_search += 1

            if not (temp_a < ((right_border + left_border) / 2) < temp_b):
                code_error = "3"
            else:
                list_x_approximate.append((right_border + left_border) / 2)

            if max_iterations <= count_iterations:
                code_error = "2"

            update_labels(count_roots, temp_a, temp_b, (right_border + left_border) / 2, \
                          code_error, count_iterations)

        temp_a = temp_b

    return list_x_approximate, count_roots


# Метод Хорд

def chord_method(step, interval_list, epsilon, max_iterations):
    border_a = interval_list[0]
    border_b = interval_list[1]
    list_x_approximate = []
    total_interval = border_b - border_a
    temp_a = border_a
    count_roots = 0

    for i in range(ceil(total_interval / step)):
        temp_b = temp_a + step
        code_error = "0"
        count_iterations = 1
        try_search = 1

        if temp_b > border_b:
            temp_b = border_b

        if (f(temp_b) * f(temp_a)) < 0:
            count_roots += 1

            while try_search < 3:

                if try_search == 1:
                    root, root_previous = temp_a, temp_a + 2 * epsilon
                else:
                    root, root_previous = temp_b, temp_b - 2 * epsilon

                while abs(root - root_previous) > epsilon and \
                        count_iterations < max_iterations:
                    root, root_previous = root_previous - f(root_previous) \
                                          / (f(root) - f(root_previous)) * (root - root_previous), root
                    count_iterations += 1

                # print(root, try_search)
                if temp_a < (root) < temp_b:
                    break
                try_search += 1

            if not (temp_a < root < temp_b):
                code_error = "3"
            else:
                list_x_approximate.append(root)

            if max_iterations <= count_iterations:
                code_error = "2"

            update_labels(count_roots, temp_a, temp_b, root, code_error, count_iterations)

        temp_a = temp_b

    return list_x_approximate, count_iterations


# Метод Ньютона

def Newton_method(step, interval_list, epsilon, max_iterations):
    border_a = interval_list[0]
    border_b = interval_list[1]
    list_x_approximate = []
    total_interval = border_b - border_a
    temp_a = border_a
    count_roots = 0

    for i in range(ceil(total_interval / step)):
        temp_b = temp_a + step
        code_error = "0"
        count_iterations = 1

        if temp_b > border_b:
            temp_b = border_b

        if (f(temp_b) * f(temp_a)) < 0:
            count_roots += 1
            try_search = 1

            while try_search < 3:
                count_iterations = 1
                if try_search == 1:
                    x_o = temp_a
                else:
                    x_o = temp_b

                root_previous = x_o - (f(x_o) / derivative_f(x_o))
                root = root_previous - (f(root_previous) / \
                                        derivative_f(root_previous))

                while abs(root - root_previous) > epsilon and \
                        count_iterations < max_iterations:
                    root_previous = root
                    root = root_previous - (f(root_previous) / \
                                            derivative_f(root_previous))
                    count_iterations += 1

                if temp_a < root < temp_b:
                    break

                try_search += 1

            if not (temp_a < (root) < temp_b):
                code_error = "3"
            else:
                list_x_approximate.append(root)

            if max_iterations <= count_iterations:
                code_error = "2"

            update_labels(count_roots, temp_a, temp_b, root, code_error, count_iterations)

        temp_a = temp_b

    return list_x_approximate, count_roots


# Поиск корней

def start_find_roots(step, interval_list, epsilon, max_iterations, method):
    clear_all_labels()

    if method == "Newton":
        list_x_approximate, count_roots = Newton_method(step, \
                                                        interval_list, epsilon, max_iterations)
    elif method == "chord":
        list_x_approximate, count_roots = chord_method(step, \
                                                       interval_list, epsilon, max_iterations)
    else:
        list_x_approximate, count_roots = combined_method(step, \
                                                          interval_list, epsilon, max_iterations)

    if count_roots == 0:
        msb.showerror("Ошибка", "На заданном интервале нет корней.")
    else:
        button_see_graph = Button(root, \
                                  text="Показать график функции\n на заданном интервале", \
                                  command=lambda: create_graph(interval_list[0], \
                                                               interval_list[1], list_x_approximate))
        button_see_graph.place(x=780, y=440, width=160)


# Функция проверки введеных данных в окна ввода

def check_entry(entry_step, entry_interval, entry_epsilon, entry_max_iterations, method):
    # Проверка первого окна (количество шагов)
    try:
        step = float(entry_step.get())
    except:
        msb.showerror("Ошибка", "Некорректный ввод шага разбиения \
на интервалы.")
        return

    if step <= 0:
        msb.showerror("Ошибка", "Шаг должен быть больше нуля.")
        return

    # Проверка второго окна (интервал)

    interval_list = list(map(float, entry_interval.get().split()))
    if len(interval_list) != 2:
        msb.showerror("Ошибка", "Интервал поиска корней \
должен состоять из двух чисел.")
        return

    if interval_list[0] > interval_list[1]:
        msb.showerror("Ошибка", "Левая граница интервала \
должна быть больше правой границы.")
        return

    interval_list[0] -= 0.001
    interval_list[1] += 0.001

    # Проверка третьего окна (точность epsilon)

    try:
        epsilon = float(entry_epsilon.get())
    except:
        msb.showerror("Ошибка", "Некорректный ввод точности ε.")
        return

    if epsilon <= 0:
        msb.showerror("Ошибка", "Точность ε должна быть больше нуля.")
        return

    # Проверка четвертого окна (количество итераций)

    try:
        iterations = int(entry_max_iterations.get())
    except:
        msb.showerror("Ошибка", "Некорректный ввод \
максимального количества итераций.")
        return

    if iterations <= 0:
        msb.showerror("Ошибка", "Максимальное количество \
итераций должно быть нуля. ")
        return

    start_find_roots(step, interval_list, epsilon, iterations, method)


# Настроки корневого окна

root = Tk()
root.geometry("500x100")
root.maxsize(width=1000, height=500)
root.minsize(width=1000, height=500)
root.title("Уточнение корней уравнения смешаным способм")

# Настройка фонового изображения

bg_image = PhotoImage(file="bg_image_lab03.png")
label_bg = Label(image=bg_image)
label_bg.place(x=0, y=0, relwidth=1, relheight=1)

# Создание и настройка меню

mainmenu = Menu(root)
root.config(menu=mainmenu)
mainmenu.add_command(label="О программе", command=about_program)
mainmenu.add_command(label="Показать график функции", command=create_graph)
mainmenu.add_command(label="Выйти", command=exit)

# Лэйблы

label_enter_step = Label(root, text="Введите шаг разбиения на интервалы:")
label_enter_interval = Label(root, text="Введите интервал для поиска корней:")
label_enter_epsilon = Label(root, text="Введите точность ε: ")
label_enter_max_iterations = Label(root, \
                                   text="Введите максимальное количество итераций: ")
label_info_about_codes = Label(root, text="Коды выполнения:\n\n0. Метод сошелся\n\n\
1. Превышено максимальное \nкол-во итераций.\n\n2. Метод не сошелся.\n\
\n3. Из-за особенностей графика \nкасательная в одной из точек \nвышла за \
интервалы разбиения.", justify=CENTER, bg="#4682B4", font="Arial 12")

# Вывод лэйблов

label_enter_step.place(x=255, y=8, width=227)
label_enter_interval.place(x=10, y=8, width=227)
label_enter_epsilon.place(x=500, y=8, width=200)
label_enter_max_iterations.place(x=725, y=8, width=260)
label_info_about_codes.place(x=735, y=200, width=250)

# Кнопки

find_roots_newton = Button(root, text="Найти корни (метод Ньютона)", \
                           command=lambda: check_entry(enter_step, enter_interval, \
                                                       enter_epsilon, enter_max_iterations, "Newton"))
find_roots_chord = Button(root, text="Найти корни (метод Хорд)", \
                          command=lambda: check_entry(enter_step, enter_interval, \
                                                      enter_epsilon, enter_max_iterations, "chord"))
find_roots_combined = Button(root, text="Найти корни (комбинированный метод)", \
                             command=lambda: check_entry(enter_step, enter_interval, \
                                                         enter_epsilon, enter_max_iterations, "combined"))

# Вывод кнопок

find_roots_newton.place(x=745, y=150, width=235)
find_roots_chord.place(x=745, y=120, width=235)
find_roots_combined.place(x=745, y=90)

# Поля ввода

enter_step = Entry(root)
enter_interval = Entry(root)
enter_epsilon = Entry(root)
enter_max_iterations = Entry(root)

# Вывод окон полей ввода

enter_step.place(x=255, y=30, width=227)
enter_interval.place(x=10, y=30, width=227)
enter_epsilon.place(x=500, y=30, width=200)
enter_max_iterations.place(x=725, y=30, width=260)

# ================= CANVAS ===================

table = Canvas(root)
table.place(x=30, y=120, width=650, height=350)

# Таблица

# Основная рамка

table.create_line(0, 0, 0, 350, width=10)
table.create_line(0, 350, 650, 350, width=10)
table.create_line(0, 0, 650, 0, width=10)
table.create_line(650, 0, 650, 350, width=10)

# Линии внутри

table.create_line(90, 0, 90, 350, width=5)
table.create_line(210, 0, 210, 350, width=5)
table.create_line(320, 0, 320, 350, width=5)
table.create_line(430, 0, 430, 350, width=5)
table.create_line(540, 0, 540, 350, width=5)

table.create_line(0, 40, 650, 40, width=5)

# Лэйблы внутри таблицы

# Заголовки таблицы

label_number = Label(table, text="№", font="Arial 14", bg="#9370DB")
label_interval = Label(table, text="Интервал", font="Arial 14", bg="#9370DB")
label_approximation = Label(table, text="x̅", font="Arial 14", bg="#9370DB")
label_approximation_function = Label(table, text="f(x̅)", font="Arial 14", \
                                     bg="#9370DB")
label_count_iterations = Label(table, text="Количество \nитераций", \
                               font="Arial 12", bg="#9370DB")
label_code_error = Label(table, text="Код \nвыполнения", font="Arial 12", \
                         bg="#9370DB")

# Вывод заголовков

label_number.place(x=5, y=5, width=84, height=33)
label_interval.place(x=93, y=5, width=115, height=33)
label_approximation.place(x=213, y=5, width=105, height=33)
label_approximation_function.place(x=323, y=5, width=105, height=33)
label_count_iterations.place(x=433, y=5, width=105, height=33)
label_code_error.place(x=543, y=5, width=102, height=33)

# == Лэйблы с значениями ==


# Номера поиска

# list_label_number = []
y_coord = 44

"""
for i in range(6):
    label_numbers = Label(table, text="", bg="#008080", font="Arial 14")
    label_numbers.place(x=5, y = y_coord, width=83, height=50)
    list_label_number.append(label_numbers)
    y_coord += 50
"""

label_number = Label(table, text="", bg="#008080", font="Arial 12")
label_number.place(x=5, y=44, width=83, height=300)

# Интервалы поиска

# list_label_intervals = []

# for i in range(6):
label_interval = Label(table, text="", bg="#008080", font="Arial 12")
label_interval.place(x=93, y=43.7, width=115, height=300)
# list_label_intervals.append(label_intervals)
# y_coord += 50

# Приближенное значение

list_label_approximate = []
y_coord = 44

# for i in range(6):
label_approximate = Label(table, text="", bg="#008080", font="Arial 12")
label_approximate.place(x=213, y=44, width=105, height=300)
# list_label_approximate.append(label_approximates)
# y_coord += 50

# Приближенное значение от функции

# list_label_approximate_func = []
# y_coord = 44

# for i in range(6):
label_approximate_func = Label(table, text="", bg="#008080", font="Arial 12")
label_approximate_func.place(x=323, y=44, width=105, height=300)
# list_label_approximate_func.append(label_approximates_func)
# y_coord += 501

# Количество итераций

# list_label_count_iterations = []
# y_coord = 44

# for i in range(6):
label_count_iteration = Label(table, text="", bg="#008080", font="Arial 12")
label_count_iteration.place(x=433, y=44, width=105, height=300)
# list_label_count_iterations.append(label_count_iterations)
# y_coord += 50

# Код ошибки

# list_label_code_error = []
# y_coord = 44

# for i in range(6):
label_code_error = Label(table, text="", bg="#008080", font="Arial 12")
label_code_error.place(x=543, y=y_coord, width=102, height=300)
# list_label_code_error.append(label_code_error)
# y_coord += 50

root.mainloop()