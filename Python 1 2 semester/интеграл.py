
# Метод парабол (метод Симпсона)
# Метод прямоугольников

# func - подынтегральная функция
# a, b - пределы интегрирования
# n - количество отрезков (число разбиений)

# Савинов Егор ИУ7-14Б


from scipy import integrate


a, b = map(int, input('Введите границы вычисления интеграла a и b: ').split())
n1, n2 = map(int,input('Введите число разбиений (n1 и n2): ').split())
k = 0


def func(x):
    return 4*x*x+1


def simpson(a, b, n):
    h = (b - a) / (n * 2)  # шаг
    integral_S_0 = func(b) + func(a)
    integral_S_1 = 0
    integral_S_2 = 0
    for i in range(1, n):
        integral_S_1 += func(a + (2 * i * h))
    integral_S_1 *= 2
    for i in range(1, n + 1):
        integral_S_2 += func(a + ((2 * i) - 1) * h)
    integral_S_2 *= 4
    integral_S = integral_S_0 + integral_S_1 + integral_S_2
    integral_S *= h / 3
    return integral_S


def rectangles_center(a, b, n):
    h = (b - a) / n
    integral_r = 0
    for i in range(1, n + 1):
        integral_r += func((a + ((i - 1) * h)) + (h / 2))
    integral_r *= h
    return integral_r


int1_s = simpson(a, b, n1)
int2_s = simpson(a, b, n2)
int1_r = rectangles_center(a, b, n1)
int2_r = rectangles_center(a, b, n2)


print('\nМетод                   |n1 = {:7g}'.format(n1), '|n2 = {:7g}'.format(n2), '|')
if n1 % 2 != 0 and n2 % 2 == 0:
    print('Парабол                 |','{:<8.7}'.format('-'), '|', '{:<8.7}'.format(int2_s), '|')
    k = 1
if n2 % 2 != 0 and n1 % 2 == 0:
    print('Парабол                 |', '{:<8.7}'.format(int1_s), '|', '{:<8.7}'.format('-'), '|')
    k = 2
if n1 % 2 != 0 and n2 % 2 != 0:
    print('Парабол                 |', '{:<8.7}'.format('-'), '|', '{:<8.7}'.format('-'), '|')
    k = 3
if n1 % 2 == 0 and n2 % 2 == 0:
    print('Парабол                 |', '{:<8.7}'.format(int1_s), '|', '{:<8.7}'.format(int2_s), '|')
print('Средних прямоугольников |','{:<8.7}'.format(int1_r), '|', '{:<8.7}'.format(int2_r), '|')


# интеграл с самой высокой точностью


best_integral = integrate.quad(func, a, b)[0]


# абсолютная ошибка


abs_r_1 = abs(best_integral - rectangles_center(a, b, n1))
abs_r_2 = abs(best_integral - rectangles_center(a, b, n2))
abs_s_1 = abs(best_integral - simpson(a, b, n1))
abs_s_2 = abs(best_integral - simpson(a, b, n2))


# относительная ошибка


relative_r_1 = ((best_integral - rectangles_center(a, b, n1)) / best_integral )
relative_r_2 = ((best_integral - rectangles_center(a, b, n2)) / best_integral )
relative_s_1 = ((best_integral - simpson(a, b, n1)) / best_integral )
relative_s_2 = ((best_integral - simpson(a, b, n2)) / best_integral )


print('\nАбсолютная ошибка\n\nabs_r_1 = ', '{:<8.7g}'.format(abs_r_1),
      '\nabs_r_2 = ', '{:<8.7g}'.format(abs_r_2))
if k != 1 and k != 2 and k != 3:
    print('abs_s_1 = ', '{:<8.7}'.format(abs_s_1))
    print('abs_s_2 = ', '{:<8.7}'.format(abs_s_2))
if k == 1:
    print('abs_s_1 = ', '{:<8.7}'.format('-'))
    print('abs_s_2 = ', '{:<8.7}'.format(abs_s_2))
if k == 2:
    print('abs_s_1 = ', '{:<8.7}'.format(abs_s_1))
    print('abs_s_2 = ', '{:<8.7}'.format('-'))
if k == 3:
    print('abs_s_1 = ', '{:<8.7}'.format('-'))
    print('abs_s_2 = ', '{:<8.7}'.format('-'))

print('\nОтносительная ошибка\n\nrelative_r_1 = ', '{:<8.7}'.format(relative_r_1),
      '\nrelative_r_2 = ', '{:<8.7}'.format(relative_r_2))
if k != 1 and k != 2 and k != 3:
    print('relative_s_1 = ', '{:<8.7}'.format(relative_s_1))
    print('relative_s_2 = ', '{:<8.7}'.format(relative_s_2))
if k == 1:
    print('relative_s_1 = ', '{:<8.7}'.format('-'))
    print('relative_s_2 = ', '{:<8.7}'.format(relative_s_2))
if k == 2:
    print('relative_s_1 = ', '{:<8.7}'.format(relative_s_1))
    print('relative_s_2 = ', '{:<8.7}'.format('-'))
if k == 3:
    print('relative_s_1 = ', '{:<8.7}'.format('-'))
    print('relative_s_2 = ', '{:<8.7}'.format('-'))


e = float(input('\nВведите точность вычисления: '))


# интеграл с заданной степенью точности


n0 = 1
while abs(rectangles_center(a, b, (n0*2)) - rectangles_center(a, b, n0)) > e:
    n0 *= 2
inte_r = rectangles_center(a, b, n0)

n0_0 = 1
while abs(simpson(a, b, (n0_0*2)) - simpson(a, b, n0_0)) > e:
    n0_0 *= 2
inte_s = simpson(a, b, n0_0)


print('\nИнтеграл с заданной степенью точности\n\nДля прямоугольников: ', '\nn = {:<8}'.format(n0),
      '\nintegral = {:<8.7}'.format(inte_r), '\n\nДля параболы:', '\nn = {:<8}'.format(n0_0),
      '\nintegral = {:<8.7}'.format(inte_s))


# Вывод т0 до
какого момента сохр точность 

