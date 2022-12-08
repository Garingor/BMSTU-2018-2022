x = list(map(int, input('введите элементы: ').split()))

print(x)
N = len(x)
ind = 0
max_1 = x[0]
min_1 = x[0]
fl1 = 1
fl2 = 0
for i in range(N):
    if x[i] > max_1:
        max_1 = x[i]
    if x[i] < min_1:
        min_1 = x[i]
if x[N-1] == min_1:
   fl1 = 1
for i in range(len(x)):
    if x[i] == max_1:
        x += [min_1]
        ind = i
        for i in range(len(x)-1,ind,-1):
            x[i] = x[i-1]
        x[ind+1] = min_1
N = len(x)
if x[N-1] == max_1:
   x += [min_1]
   fl2= 1
for i in range(len(x)-1):
    if x[i] == max_1 and x[i+1] != min_1:
        x += [min_1]
        ind = i
        for i in range(len(x)-1,ind,-1):
            x[i] = x[i-1]
        x[ind + 1] = min_1
if x[N-1] == max_1 and fl1 == 1 and fl2 != 1:
   x += [min_1]
print(x)



