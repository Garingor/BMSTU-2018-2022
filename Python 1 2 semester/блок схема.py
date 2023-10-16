# Решение квадратного уравнения

# a, b, c - коэффициенты в квадратном уравнении
# x - корень полного квадратного уравнения
# x_1,x_2 - корни квадратного уравнения

# Савинов Егор ИУ7-14Б

from math import sqrt

a, b, c = map(float, input("Введите числа a, b, c = ").split())

if a == 0:
    if b == 0:
        if c == 0:
           print('X - любое число')
           input('\nPress ENTER to exit')
        else:
            print('Нет решений')
            input('\nPress ENTER to exit') 
    else:
         x = -c / b
         if c == 0:
             x = 0
             print('\nX = {:.5g}'.format(x))
             input('\nPress ENTER to exit')

else:
    D = b * b - 4 * a * c
    if D > 0:
        x_1 = (-b + sqrt(D)) / (2 * a)
        x_2 = (-b - sqrt(D)) / (2 * a)
        print('\nX_1 = {:.5g}'.format(x_1), '\nX_2 = {:.5g}'.format(x_2))
        input('\nPress ENTER to exit')
    else:
        if D == 0:
            x = -b / (2 * a)
            if b == 0:
                x = 0
            print('\nX = {:.5g}'.format(x))
            input('\nPress ENTER to exit')
        else:
              print('Нет корней')
              input('\nPress ENTER to exit')
            
    
