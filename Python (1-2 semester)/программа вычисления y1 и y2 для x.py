# Программа вычисления Y1 и Y2 для вводимого X

# Савинов Егор ИУ7-14Б

X = float(input('\nВведите X: '))
if X < -3 or X > 3:
        y = 0
elif -3 <= X <= -2:
        y = X + 3
elif -2 < X <= -1:
        y = -X - 1
elif 1 <= X <= 2:
        y = X - 1 
elif 2 < X <= 3:
        y = -X + 3
elif X < -3:
    y = 0
elif -1 < X < 1:
        print('\nДля этих значений функция не определена')
        input('\nPress ENTER to exit')
        exit(0)

print('\nY = ', y)

input('\nPress ENTER to exit')
