x, x_n, d = map(float, input('введите начальное и конечное x, шаг = ').split())

e = 1e-8
x_0 = x
x_n_0 = x_n
g = 0

y_min = x ** 8 - 5 * x ** 7 + 3 * x ** 6 + 8 * x ** 5 - 35 * x ** 4 + 73 * x ** 3 \
        - 6 * x ** 2 + 23 * x + 7
y_max = x ** 8 - 5 * x ** 7 + 3 * x ** 6 + 8 * x ** 5 - 35 * x ** 4 + 73 * x ** 3 \
        - 6 * x ** 2 + 23 * x + 7

print('         x                  y')

while x <= x_n + d/2:
    y = x ** 8 - 5 * x ** 7 + 3 * x ** 6 + 8 * x ** 5 - 35 * x ** 4 + 73 * x ** 3 \
        - 6 * x ** 2 + 23 * x + 7
    if (abs(x) < e):
        x = 0.0
    if y_min > y:
        y_min = y
    if y_max < y:
        y_max = y
    print('| {:>15.5}'.format(x), ' | {:>15.5}'.format(y), '|')
    g+=1
    x += d
    
print('\n')

if y_min < 0 and y_max > 0:
    while x_0 <= x_n_0 + d/2:
        if (abs(x_0) < e):
            x_0 = 0.0
        y = x_0 ** 8 - 5 * x_0 ** 7 + 3 * x_0 ** 6 + 8 * x_0 ** 5 - 35 * x_0 ** 4 + 73 * x_0 ** 3 - 6 * x_0 ** 2 + 23 * x_0 + 7
        dep = round(((y - y_min) / (y_max - y_min)) * 80)
        m = round(((0 - y_min) / (y_max - y_min)) * 80)
        if dep > m:
            s_1 = ' ' * (m-1) + '|' + ' '* (dep-m-1) + '*'
        if dep < m:
            s_1 = ' ' * (dep-1) + '*' + ' '* (m-dep-1) + '|'
        if dep == m:
            s_1 = ' ' * (dep-1) + '*'
        print('{:>8.5}'.format(x_0),s_1)
        x_0 += d 
else:
    while x_0 <= x_n_0 + d/2:
        if (abs(x_0) < e):
            x_0 = 0.0
        y = x_0 ** 8 - 5 * x_0 ** 7 + 3 * x_0 ** 6 + 8 * x_0 ** 5 - 35 * x_0 ** 4 + 73 * x_0 ** 3 - 6 * x_0 ** 2 + 23 * x_0 + 7
        dep = round(((y - y_min) / (y_max - y_min)) * 80)
        s_1 = ' ' * (dep-1) + '*'
        print('{:>8.5}'.format(x_0),s_1)
        x_0 += d 


