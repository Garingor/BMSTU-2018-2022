from tkinter import *
from tkinter import ttk
from tkinter import messagebox
from math import sqrt, pi
import matplotlib
'''
import numpy as np
import matplotlib.patches as mpatches
matplotlib.use('TkAgg')
from matplotlib.pyplot import plot, show, subplots, xlabel, ylabel, title, legend, Circle, Polygon, figure
'''
window = Tk()
window.title('Minimum square')
window.geometry("950x950")

canvas = Canvas(window, width=950, height=750, bg='white')

# Поле ввода
label_input = Label(window, text='Введите множество точек через пробел (x1 y1 x2 y2):')
label_input.place(x=10, y=10)
window.entry_input = Entry(window)
window.entry_input.place(x=400, y=10)


# Проверка ввода
def checkentry(entry_input):
    flagcheck = 1
    input = entry_input.get()
    input = input.split()
    if len(input) < 3 or len(input) % 2 == 1:
        flagcheck = 0
        return 0
    for i in range(len(input)):
        try:
            float(input[i])
        except:
            flagcheck = 0
            return 0

    return flagcheck

def pic(x1, y1, x2, y2, x3, y3, r, cx, cy, ab, bc, ca):

    x_min = x1
    y_min = y1

    x_max = x1
    y_max = y1

    #print(ab, bc, ca)
    #print(x1, y1, x2, y2, x3, y3)
    if ab < 30 or bc < 30 or ca < 30:
        while ab < 35 or bc < 35 or ca < 35:
            ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))
            bc = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2))
            ca = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2))
            x1 *= 1.2
            x2 *= 1.2
            x3 *= 1.2
            y1 *= 1.2
            y2 *= 1.2
            y3 *= 1.2
        ao = x2 - x1
        bo = y2 - y1
        co = x3 - x1
        do = y3 - y1
        eo = ao * (x2 + x1) + bo * (y2 + y1)
        fo = co * (x3 + x1) + do * (y3 + y1)
        go = 2 * (ao * (y3 - y2) - bo * (x3 - x2))
        if go != 0:
            cx = (do * eo - bo * fo) / go
            cy = (ao * fo - co * eo) / go
            r = sqrt(pow((x1 - cx), 2) + pow((y1 - cy), 2))
    if ab > 200 or bc > 200 or ca > 200:
        while ab > 50 or bc > 50 or ca > 50:
            ab = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2))
            bc = sqrt(pow((x3 - x1), 2) + pow((y3 - y1), 2))
            ca = sqrt(pow((x3 - x2), 2) + pow((y3 - y2), 2))
            x1 /= 1.2
            x2 /= 1.2
            x3 /= 1.2
            y1 /= 1.2
            y2 /= 1.2
            y3 /= 1.2
        ao = x2 - x1
        bo = y2 - y1
        co = x3 - x1
        do = y3 - y1
        eo = ao * (x2 + x1) + bo * (y2 + y1)
        fo = co * (x3 + x1) + do * (y3 + y1)
        go = 2 * (ao * (y3 - y2) - bo * (x3 - x2))
        if go != 0:
            cx = (do * eo - bo * fo) / go
            cy = (ao * fo - co * eo) / go
            r = sqrt(pow((x1 - cx), 2) + pow((y1 - cy), 2))
    if cx > 475:
        while cx > 475:
            cx -= 10
            x1 -= 10
            x2 -= 10
            x3 -= 10
    if cy > 245:
        while cy > 245:
            cy -= 10
            y1 -= 10
            y2 -= 10
            y3 -= 10
    if cx < 475:
        while cx < 475:
            cx += 10
            x1 += 10
            x2 += 10
            x3 += 10
    if cy < 245:
        while cy < 245:
            cy += 10
            y1 += 10
            y2 += 10
            y3 += 10

    canvas.create_oval(cx - r, cy - r, cx + r, cy + r, fill="green")
    canvas.create_oval(x1 - 5, y1 - 5, x1 + 5, y1 + 5, fill="red")
    canvas.create_oval(x2 - 5, y2 - 5, x2 + 5, y2 + 5, fill="red")
    canvas.create_oval(x3 - 5, y3 - 5, x3 + 5, y3 + 5, fill="red")
    canvas.create_polygon(x1, y1, x2, y2, x3, y3, fill="black")
    canvas.place(x=0, y=200)
    """
    canvas.create_oval(10 * (cx - r), 10 * (cy - r), 10 * (cx + r), 10 * (cy + r), outline="red", fill="green")
    canvas.create_oval(10 * (x1 - 5), 10 * (y1 - 5), 10 * (x1 - 5), 10 * (y1 - 5), outline="red", fill="red")
    canvas.create_oval(10 * (x2 - 5), 10 * (y2 - 5), 10 * (x2 - 5), 10 * (y2 - 5), outline="red", fill="red")
    canvas.create_oval(10 * (x3 - 5), 10 * (y3 - 5), 10 * (x3 - 5), 10 * (y3 - 5), outline="red", fill="red")
    canvas.create_polygon(10 * x1, 10 * y1, 10 * x2, 10 * y2, 10 * x3, 10 * y3)
    """
    #canvas.create_line(0, 0, 900, 600, width=5, fill="red")
    #canvas.create_line(0, 600, 900, 0, width=5, fill="red")
    #canvas.config(scrollregion=(0, 0, 1000, 1000))
    #canvas.config(highlightthickness=0)
    #sbar = Scrollbar(window)
    #sbar.config(command=canvas.yview)
    #canvas.config(yscrollcommand=sbar.set)
    #canvas.create_line(500, 1000, 500, 0, width=2, arrow=LAST)
    #canvas.create_line(0, 500, 1000, 500, width=2, arrow=LAST)

# Очистка
def DEL(event):
    if window.entry_input.get() != '':
        pass

window.bind("<KeyPress>", DEL)


label_fail_1 = Label(window, text='Графическое изображение не может быть построено')

def decision():
    global label_fail_1
    flagcheck = checkentry(window.entry_input)
    if flagcheck == 0:
        window.entry_input.delete(0, 'end')
        messagebox.showinfo(title='Ошибка', message="""Вы ввели недопустимые значения, попробуйте снова""")
    else:
        tabl()
        mas = min_s()
        if mas != -1:
            label_fail_1.place_forget()
            canvas.delete('all')
            pic(mas[0], mas[1], mas[2], mas[3], mas[4], mas[5], mas[9], mas[10], mas[11],mas[12], mas[13], mas[14])
        else:
            canvas.delete('all')
            label_fail_1.place(x=10, y=140)

# Кнопки
button_decision = Button(window, text='Найти', width=25, height=2, command=decision)
button_decision.place(x=10, y=50)

def min_s():
    inp = window.entry_input.get()
    inp = inp.split()
    s_min = -1
    s_crcl = -1
    s_trngl = -1
    for i in range(len(inp)):
        inp[i] = float(inp[i])
    for i in range(len(inp) - 4):
        for j in range(i + 2, len(inp) - 2):
            for k in range(j + 2, len(inp) - 1):
                a = sqrt(pow((inp[j] - inp[i]), 2) + pow((inp[j + 1] - inp[i + 1]), 2))
                b = sqrt(pow((inp[k] - inp[i]), 2) + pow((inp[k + 1] - inp[i + 1]), 2))
                c = sqrt(pow((inp[k] - inp[j]), 2) + pow((inp[k + 1] - inp[j + 1]), 2))
                if a + b > c and a + c > b and b + c > a:
                    s_trngl = (1 / 2) * (((inp[i] - inp[k]) * (inp[j + 1] - inp[k + 1])) -
                                       ((inp[i + 1] - inp[k + 1]) * (inp[j] - inp[k])))
                    if s_trngl < 0:
                        s_trngl = -s_trngl
                    ao = inp[j] - inp[i]
                    bo = inp[j + 1] - inp[i + 1]
                    co = inp[k] - inp[i]
                    do = inp[k + 1] - inp[i + 1]
                    eo = ao * (inp[j] + inp[i]) + bo * (inp[j + 1] + inp[i + 1])
                    fo = co * (inp[k] + inp[i]) + do * (inp[k + 1] + inp[i + 1])
                    go = 2 * (ao * (inp[k + 1] - inp[j + 1]) - bo * (inp[k] - inp[j]))
                    if go != 0:
                        cx = (do * eo - bo * fo) / go
                        cy = (ao * fo - co * eo) / go
                        r = sqrt(pow((inp[i] - cx), 2) + pow((inp[i + 1] - cy), 2))
                        s_crcl = pi * pow(r, 2)
                    if s_trngl != -1 and s_crcl != -1 and s_min == -1:
                        s_min = abs(s_crcl - s_trngl)
                        s_min_crcl = s_crcl
                        s_min_trngl = s_trngl
                        x1 = inp[i]
                        x2 = inp[j]
                        x3 = inp[k]
                        y1 = inp[i + 1]
                        y2 = inp[j + 1]
                        y3 = inp[k + 1]
                        r_min = r
                        cx_min = cx
                        cy_min = cy
                        a_min = sqrt(pow((inp[j] - inp[i]), 2) + pow((inp[j + 1] - inp[i + 1]), 2))
                        b_min = sqrt(pow((inp[k] - inp[i]), 2) + pow((inp[k + 1] - inp[i + 1]), 2))
                        c_min = sqrt(pow((inp[k] - inp[j]), 2) + pow((inp[k + 1] - inp[j + 1]), 2))
                    if abs(s_crcl - s_trngl) < s_min:
                        s_min = abs(s_crcl - s_trngl)
                        s_min_crcl = s_crcl
                        s_min_trngl = s_trngl
                        x1 = inp[i]
                        x2 = inp[j]
                        x3 = inp[k]
                        y1 = inp[i + 1]
                        y2 = inp[j + 1]
                        y3 = inp[k + 1]
                        r_min = r
                        cx_min = cx
                        cy_min = cy
                        a_min = sqrt(pow((inp[j] - inp[i]), 2) + pow((inp[j + 1] - inp[i + 1]), 2))
                        b_min = sqrt(pow((inp[k] - inp[i]), 2) + pow((inp[k + 1] - inp[i + 1]), 2))
                        c_min = sqrt(pow((inp[k] - inp[j]), 2) + pow((inp[k + 1] - inp[j + 1]), 2))
    if s_min == -1:
        return -1
    else:
        return x1, y1, x2, y2, x3, y3, s_min_trngl, s_min_crcl, s_min, r_min, cx_min, cy_min, a_min, b_min, c_min

# Таблица
window.tree = ttk.Treeview(window, column=('x1', 'y1', 'x2', 'y2', 'x3', 'y3', 's_triangle', 's_circle', 's_min'),
                           height=1, show='headings')

window.tree.column('x1', width=100, anchor=CENTER)
window.tree.column('y1', width=100, anchor=CENTER)
window.tree.column('x2', width=100, anchor=CENTER)
window.tree.column('y2', width=100, anchor=CENTER)
window.tree.column('x3', width=100, anchor=CENTER)
window.tree.column('y3', width=100, anchor=CENTER)
window.tree.column('s_triangle', width=100, anchor=CENTER)
window.tree.column('s_circle', width=100, anchor=CENTER)
window.tree.column('s_min', width=100, anchor=CENTER)

window.tree.heading('x1', text='x1')
window.tree.heading('y1', text='y1')
window.tree.heading('x2', text='x2')
window.tree.heading('y2', text='y2')
window.tree.heading('x3', text='x3')
window.tree.heading('y3', text='y3')
window.tree.heading('s_triangle', text='s_triangle')
window.tree.heading('s_circle', text='s_circle')
window.tree.heading('s_min', text='s_min')

window.tree.place(x=10, y=100)

# Данные в таблице
def tabl():
    for i in window.tree.get_children():
        window.tree.delete(i)

    if min_s() == -1:
        window.tree.insert("", index=0,
                           values=['-', '-', '-', '-', '-', '-', '-', '-', '-'])
    else:
        window.tree.insert("", index=0, values=['{:.4g}'.format(min_s()[0]), '{:.4g}'.format(min_s()[1]),
                                                '{:.4g}'.format(min_s()[2]), '{:.4g}'.format(min_s()[3]),
                                                '{:.4g}'.format(min_s()[4]), '{:.4g}'.format(min_s()[5]),
                                                '{:.4g}'.format(min_s()[6]), '{:.4g}'.format(min_s()[7]),
                                                '{:.4g}'.format(min_s()[8])])

# Всплывающее окно
def showinfo():
    messagebox.showinfo(title='О программе', message="""
  Карточка программы
 |название                = Minimum square
 |подпись                 = Версия 0.1.1
 |автор                   = Савинов Егор
 |языки интерфейса        = русский """)



# Выпадающее меню

menu = Menu(window)
window.config(menu=menu)

submenu = Menu(menu)
menu.add_cascade(label='Действия', menu=submenu)
submenu.add_command(label='Найти', command=decision)
submenu.add_command(label='Выход', command=exit)

submenu2 = Menu(menu)
menu.add_cascade(label='Помощь', menu=submenu2)
submenu2.add_command(label='О программе', command=showinfo)

window.mainloop()



"""
    fig, ax = subplots()
    xlabel('x')
    ylabel('y')
    title('picture')
    ax.set_xlim((-50, 50))
    ax.set_ylim((-50, 50))

    x_tek = np.array([x1, x2, x3])
    y_tek = np.array([y1, y2, y3])
    triangle = mpatches.Polygon(np.array([[x1, y1], [x2, y2], [x3, y3]]), color='black', zorder=10,
                                 label='площадь треугольника')
    circle = Circle((cx, cy), r, color='blue', zorder=1, label='разность площадей')
    ax.add_artist(triangle)
    ax.add_artist(circle)
    line, = ax.plot(x_tek, y_tek, 'o', color='red', label='Найденные точки')
    ax.legend(loc='best', handles=[circle, triangle, line])
    show()
    """

"""def pic(x1, y1, x2, y2, x3, y3, r, cx, cy, ab, bc, ca):

    x_min = x1
    y_min = y1

    x_max = x1
    y_max = y1

    print(ab, bc, ca)
    print(x1, y1, x2, y2, x3, y3)
    if ab < 30 or bc < 30 or ca < 30:
        x1 *= 2
        x2 *= 2
        x3 *= 2
        y1 *= 2
        y2 *= 2
        y3 *= 2
        ao = x2 - x1
        bo = y2 - y1
        co = x3 - x1
        do = y3 - y1
        eo = ao * (x2 + x1) + bo * (y2 + y1)
        fo = co * (x3 + x1) + do * (y3 + y1)
        go = 2 * (ao * (y3 - y2) - bo * (x3 - x2))
        if go != 0:
            cx = (do * eo - bo * fo) / go
            cy = (ao * fo - co * eo) / go
            r = sqrt(pow((x1 - cx), 2) + pow((y1 - cy), 2))
    if ab > 200 or bc < 200 or ca < 200:
        x1 /= 2
        x2 /= 2
        x3 /= 2
        y1 /= 2
        y2 /= 2
        y3 /= 2
        ao = x2 - x1
        bo = y2 - y1
        co = x3 - x1
        do = y3 - y1
        eo = ao * (x2 + x1) + bo * (y2 + y1)
        fo = co * (x3 + x1) + do * (y3 + y1)
        go = 2 * (ao * (y3 - y2) - bo * (x3 - x2))
        if go != 0:
            cx = (do * eo - bo * fo) / go
            cy = (ao * fo - co * eo) / go
            r = sqrt(pow((x1 - cx), 2) + pow((y1 - cy), 2))
    if x1 < 0 or y1 < 0 or x2 < 0 or y2 < 0 or x3 < 0 or y3 < 0:
            if x2 < x_min:
                x_min = x2
            if x3 < x_min:
                x_min = x3
            if y2 < x_min:
                x_min = y2
            if y3 < x_min:
                x_min = y3
            print('min ', x_min, y_min)
            if x_min < 0 and y_min >=0:
                canvas.create_oval(cx + abs(x_min) - r, cy - r, cx + abs(x_min) + r, cy + r, fill="green")
                canvas.create_oval(x1 + abs(x_min) - 5, y1 - 5, x1 + abs(x_min) + 5, y1 + 5, fill="red")
                canvas.create_oval(x2 + abs(x_min) - 5, y2 - 5, x2 + abs(x_min) + 5, y2 + 5, fill="red")
                canvas.create_oval(x3 + abs(x_min) - 5, y3 - 5, x3 + abs(x_min) + 5, y3 + 5, fill="red")
                canvas.create_polygon(x1 + abs(x_min), y1, x2 + abs(x_min), y2, x3 + abs(x_min), y3, fill="black")
            if y_min < 0 and x_min >= 0:
                canvas.create_oval(cx - r, cy + abs(y_min) - r, cx + r, cy + abs(y_min) + r, fill="green")
                canvas.create_oval(x1 - 5, y1 + abs(y_min) - 5, x1 + 5, y1 + abs(y_min) + 5, fill="red")
                canvas.create_oval(x2 - 5, y2 + abs(y_min) - 5, x2 + 5, y2 + abs(y_min) + 5, fill="red")
                canvas.create_oval(x3 - 5, y3 + abs(y_min) - 5, x3 + 5, y3 + abs(y_min) + 5, fill="red")
                canvas.create_polygon(x1, y1 + abs(y_min), x2, y2 + abs(y_min), x3, y3 + abs(y_min), fill="black")
            if y_min < 0 and x_min < 0:
                canvas.create_oval(cx + abs(x_min) - r, cy + abs(y_min) - r, cx + abs(x_min) + r,
                                   cy + abs(y_min) + r, fill="green")
                canvas.create_oval(x1 + abs(x_min) - 5, y1 + abs(y_min) - 5, x1 + abs(x_min) + 5, y1 + abs(y_min) + 5, fill="red")
                canvas.create_oval(x2 + abs(x_min) - 5, y2 + abs(y_min) - 5, x2 + abs(x_min) + 5, y2 + abs(y_min) + 5, fill="red")
                canvas.create_oval(x3 + abs(x_min) - 5, y3 + abs(y_min) - 5, x3 + abs(x_min) + 5, y3 + abs(y_min) + 5, fill="red")
                canvas.create_polygon(x1 + abs(x_min), y1 + abs(y_min), x2 + abs(x_min), y2 + abs(y_min),
                                      x3 + abs(x_min), y3 + abs(y_min), fill="black")

    elif x1 > 100 or y1 > 100 or x2 > 100 or y2 > 100 or x3 > 100 or y3 > 100:
            if x2 > x_max:
                x_max = x2
            if x3 > x_max:
                x_max = x3
            if y2 > x_max:
                x_max = y2
            if y3 > x_max:
                x_max = y3
            print('max ', x_max, y_max)
            if x_max > 100 and y_min <= 100:
                canvas.create_oval(cx - abs(x_min) - r, cy - r, cx - abs(x_min) + r, cy + r, fill="green")
                canvas.create_oval(x1 - abs(x_min) - 5, y1 - 5, x1 - abs(x_min) + 5, y1 + 5, fill="red")
                canvas.create_oval(x2 - abs(x_min) - 5, y2 - 5, x2 - abs(x_min) + 5, y2 + 5, fill="red")
                canvas.create_oval(x3 - abs(x_min) - 5, y3 - 5, x3 - abs(x_min) + 5, y3 + 5, fill="red")
                canvas.create_polygon(x1 - abs(x_max), y1, x2 - abs(x_max), y2, x3 - abs(x_max), y3, fill="black")
            if y_max > 100 and x_max <= 100:
                canvas.create_oval(cx - r, cy - abs(y_min) - r, cx + r, cy - abs(y_min) + r, fill="green")
                canvas.create_oval(x1 - 5, y1 - abs(y_min) - 5, x1 + 5, y1 - abs(y_min) + 5, fill="red")
                canvas.create_oval(x2 - 5, y2 - abs(y_min) - 5, x2 + 5, y2 - abs(y_min) + 5, fill="red")
                canvas.create_oval(x3 - 5, y3 - abs(y_min) - 5, x3 + 5, y3 - abs(y_min) + 5, fill="red")
                canvas.create_polygon(x1, y1 - abs(y_max), x2, y2 - abs(y_max), x3, y3 - abs(y_max), fill="black")
            if y_max > 100 and x_max > 100:
                canvas.create_oval(cx - abs(x_min) - r, cy - abs(y_min) - r, cx - abs(x_min) + r,
                                   cy - abs(y_min) + r, fill="green")
                canvas.create_oval(x1 - abs(x_min) - 5, y1 - abs(y_min) - 5, x1 - abs(x_min) + 5, y1 - abs(y_min) + 5, fill="red")
                canvas.create_oval(x2 - abs(x_min) - 5, y2 - abs(y_min) - 5, x2 - abs(x_min) + 5, y2 - abs(y_min) + 5, fill="red")
                canvas.create_oval(x3 - abs(x_min) - 5, y3 - abs(y_min) - 5, x3 - abs(x_min) + 5, y3 - abs(y_min) + 5, fill="red")
                canvas.create_polygon(x1 - abs(x_max), y1 - abs(y_max), x2 - abs(x_max), y2 - abs(y_max),
                                      x3 - abs(x_max), y3 - abs(y_max), fill="black")
    elif x1 == 0 or y1 == 0 or x2 == 0 or y2 == 0 or x3 == 0 or y3 == 0:
        x_min = 50
        y_min = 50
        canvas.create_oval(cx + abs(x_min) - r, cy + abs(y_min) - r, cx + abs(x_min) + r,
                           cy + abs(y_min) + r, fill="green")
        canvas.create_oval(x1 + abs(x_min) - 5, y1 + abs(y_min) - 5, x1 + abs(x_min) + 5, y1 + abs(y_min) + 5,
                           fill="red")
        canvas.create_oval(x2 + abs(x_min) - 5, y2 + abs(y_min) - 5, x2 + abs(x_min) + 5, y2 + abs(y_min) + 5,
                           fill="red")
        canvas.create_oval(x3 + abs(x_min) - 5, y3 + abs(y_min) - 5, x3 + abs(x_min) + 5, y3 + abs(y_min) + 5,
                           fill="red")
        canvas.create_polygon(x1 + abs(x_min), y1 + abs(y_min), x2 + abs(x_min), y2 + abs(y_min),
                              x3 + abs(x_min), y3 + abs(y_min), fill="black")
    else:
        canvas.create_oval(cx - r, cy - r, cx + r, cy + r, fill="green")
        canvas.create_oval(x1 - 5, y1 - 5, x1 + 5, y1 + 5, fill="red")
        canvas.create_oval(x2 - 5, y2 - 5, x2 + 5, y2 + 5, fill="red")
        canvas.create_oval(x3 - 5, y3 - 5, x3 + 5, y3 + 5, fill="red")
        canvas.create_polygon(x1, y1, x2, y2, x3, y3, fill="black")
    canvas.create_oval(5 - 5, 5 - 5, 5 + 5, 5 + 5, fill="red")
    canvas.place(x=0, y=200)"""