from tkinter import *
from tkinter import ttk
from tkinter import messagebox
from math import sqrt, pi

window = Tk()
window.geometry("950x950")

canvas = Canvas(window, width=950, height=750, bg='white')

label_input = Label(window, text='Введите множество точек через пробел (x y r):')
label_input.place(x=10, y=10)
window.entry_input = Entry(window)
window.entry_input.place(x=400, y=10)


def pic(x, y, r):
    inp = window.entry_input.get()
    inp = inp.split()
    for i in range(len(inp)):
        inp[i] = float(inp[i])
    for i in range(0, len(inp), 3):
        canvas.create_oval(inp[i] - inp[i + 2], inp[i + 1] - inp[i + 2], inp[i] + inp[i + 2], inp[i + 1] + inp[i + 2])
        canvas.create_oval(x - r, y - r, x + r, y + r, outline="green")
    canvas.place(x=0, y=200)


def decision():
    mas = max_c()
    #print(mas)
    canvas.delete('all')
    pic(mas[1], mas[2], mas[3])


# Кнопки
button_decision = Button(window, text='Найти', width=25, height=2, command=decision)
button_decision.place(x=10, y=50)

def max_c():
    inp = window.entry_input.get()
    inp = inp.split()
    max_curcle = 0
    max_curcle_tek = 0
    tek_x_max = 0
    tek_y_max = 0
    tek_r_max = 0
    for i in range(len(inp)):
        inp[i] = float(inp[i])
    for i in range(0, len(inp), 3):
        max_curcle_tek = 0
        tek_x = inp[i]
        tek_y = inp[i + 1]
        tek_r = inp[i + 2]
        for j in range(0, len(inp), 3):
            tek_x1 = inp[j]
            tek_y1 = inp[j + 1]
            tek_r1 = inp[j + 2]
            a = sqrt(pow(tek_x - tek_x1, 2) + pow(tek_y - tek_y1, 2))
            if a < tek_r:
                if a + tek_r1 < tek_r:
                    max_curcle_tek += 1
        if max_curcle_tek > max_curcle:
            max_curcle = max_curcle_tek
            tek_x_max = tek_x
            tek_y_max = tek_y
            tek_r_max = tek_r
    return max_curcle, tek_x_max, tek_y_max, tek_r_max
# 100 100 100 100 100 50 100 100 20 100 150 30 100 120 30 100 80 20 80 100 100 100 100 200



window.mainloop()

