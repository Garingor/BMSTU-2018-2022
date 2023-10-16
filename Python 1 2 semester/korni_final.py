from tkinter import *
from tkinter import ttk
from tkinter import messagebox
import matplotlib
from numpy import linspace, sin, cos
from math import ceil
matplotlib.use('TkAgg')
from matplotlib.pyplot import plot, show, subplots, xlabel, ylabel, title, legend, figure

def f(x):
    try:
        y = sin(x)#x * x - 4
    except:
        return None
    return y


def f_1(x):
    try:
        y = cos(x)#2 * x
    except:
        return None
    return y

def f_2(x):
    try:
        y = -sin(x)#x
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

label_fail_0 = Label(window, text='на отрезке есть корень - 0')
label_fail_0.place(x=10, y=540)
label_fail_1 = Label(window, text='Вышли за пределы отрезка - 1')
label_fail_1.place(x=10, y=580)
label_fail_2 = Label(window, text='Превышено максимальное кол-во итераций - 2')
label_fail_2.place(x=10, y=620)
label_fail_3 = Label(window, text='Корень на границе двух отрезков - 3')
label_fail_3.place(x=10, y=660)
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

def method():
    for i in window.tree.get_children():
        window.tree.delete(i)
    a = float(window.entry_segment_a.get())
    b = float(window.entry_segment_b.get())
    h = float(window.entry_iter.get())
    eps = float(window.entry_eps.get())
    iter_max = int(window.entry_max.get())
    a_tek = a
    x_value = []
    y_value = []
    n = 0
    flag = 0
    while a_tek < b:
        error = 0
        b_tek = a_tek + h
        if b_tek > b:
            b_tek = b
        if (f(b_tek) * f(a_tek)) <= 0:
            n += 1
            flag = 1
            while flag < 3:
                iter = 1
                if flag == 1:
                    x_n = a_tek
                else:
                    x_n = b_tek
                try:
                    x_n = x_n - (f(x_n) / f_1(x_n))
                    x_n_1 = x_n - (f(x_n) / f_1(x_n))
                except:
                    x_n = b_tek
                    x_n = x_n - (f(x_n) / f_1(x_n))
                    x_n_1 = x_n - (f(x_n) / f_1(x_n))
                while abs(x_n_1 - x_n) > eps and iter < iter_max:
                    x_n = x_n_1
                    x_n_1 = x_n - (f(x_n) / f_1(x_n))
                    iter += 1
                if a_tek <= x_n_1 <= b_tek:
                    break
                flag += 1
            if not (a_tek <= (x_n_1) <= b_tek):
                error = 1
            else:
                x_value.append(x_n_1)
                y_value.append(f(x_n_1))
            if iter_max <= iter:
                error = 2
            if len(x_value) >= 2 and x_value[len(x_value) - 2] == x_value[len(x_value) - 1]:
                    window.tree.insert("", index=0,
                                       values=[n, '[' + '{:.4g}'.format(a_tek) + ',' + '{:.4g}'.format(b_tek) + ']',
                                               '-', '-', iter, '3'])


            elif error == 1:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(a_tek) + ',' + '{:.4g}'.format(b_tek) + ']',
                                           '-', '-', '-', '1'])
            elif error == 2:
                window.tree.insert("", index=0,
                                   values=[n, '[' + '{:.4g}'.format(a_tek) + ',' + '{:.4g}'.format(b_tek) + ']',
                                           '-', '-', '-', '2'])
            else:
                window.tree.insert("", index=0,values=[n, '[' + '{:.4g}'.format(a_tek) + ',' + '{:.4g}'.format(b_tek) + ']',
                                                    '{:.5g}'.format(x_n_1),
                                                    '{:1.0e}'.format(f(x_n_1)), iter, error])
        a_tek = b_tek
    return x_value, y_value

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
        mas = method()
        graph(mas[0], mas[1])


# Кнопки
button_decision = Button(window, text='Вычислить', width=25, height=2, command=decision)
button_decision.place(x=10, y=210)

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
