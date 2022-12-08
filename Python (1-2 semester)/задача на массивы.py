x = list(map(int,input('').split()))
N = len(x)
s = 0
ind = 0
d = 0
max_1 = x[0]
for i in range(N):
        s += x[i]
        d += 1
        print(x)
        if x[i] > max_1:
            max_1 == x[i]
        if d % 3 == 0:
            x += [s]
            ind = i
            d = 0
            s = 0
            print(x)
            break
        else:
           for i in range(N - 1,ind,-1):
               x[i] = x[i-1]
           x[ind] = s
           print(x)
