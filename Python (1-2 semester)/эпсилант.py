x, eps  = map(float,input('Введите x, '
                                  'точность: ').split())
d, N_max = map(int,input('Введите шаг печати, max кол-во итераций : ').split())

n = 1
s = x
z = 3.0
t = x
t_1 = x

print('  n              t                  s')

while n <= N_max and abs(t) > eps:
    if n > 100:
        print('превышение кол-во итераций')
        n = N_max
    else:
        t = t_1 * x * x * (z-2) * (z - 2) / z / (z - 1)
        t_1 = t
        s += t
        print('|','{:>8}'.format(n),'|', '{:>15.5}'.format(t),'|', '{:>15.5}'.format(s),'|')
        n += d
        z += 2

##if abs(t) > eps and N_max < 100:
##    while abs(t) > eps and n <= 100:
##        t = t_1 * x * x * (z-2) * (z - 2) / z / (z - 1)
##        t_1 = t
##        s += t
##        print('|','{:>8}'.format(int(n)),'|', '{:>15.5}'.format(t),'|', '{:>15.5}'.format(s),'|')
##        n += d
##        z += 2
        
if  abs(t) < eps:       
    print('\ns = {:>15.5}'.format(s), '\nn = {:>15}'.format(n-d))
else:
    print('точность не достигнута')

# 1 1e-5 1 100
