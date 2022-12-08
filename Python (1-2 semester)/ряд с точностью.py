x, eps = map(float,input('x, eps : ').split())
#d, N_max = map(int,input('d, N_max : ').split())

t = x
s = 1
#n = 0
z = 1
t_0 = 1
f = 1

#print('|','{:>15}'.format(n),'|','{:>15}'.format(t),'|','{:>15}'.format(s),'|')
#n += 1

while abs(t) > eps:#0 and n <= N_max:
##    if n > 100:
##        print('превышение кол-во итераций')
##        n = N_max
##    else:
        t = t_0 * x / f
        t_0 = t
        z += 1
        s += t
        #print('|','{:>15}'.format(n),'|','{:>15.5}'.format(t),'|','{:>15.5}'.format(s),'|')
        #n += d
        f += 1
    
#if abs(t) < eps:
print('\ns = {:>15.5}'.format(s))
##else:
##    print('точность не достигнута')
