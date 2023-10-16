# Защита

# Программа вставляет после каждого третьего элемента массива сумму предыдущих
# трёх элементов

# Написал: Евсигнеев Т.А. ИУ7-14

a = list(map(int,input().split()))

print('Your list: ', a)

counter = 0
sum1 = 0
nextRound = 0

length = len(a)
#print('len1', len(a))
z = len(a) // 3
a += [0]*z
#print('len2', len(a))

for i in range(length):
    if i == length - 1 and counter == 3:
        a[len(a) - 1] = sum1
    if nextRound > 1 and a[i] == sum1:
        #print('check:', i, nextRound)
        continue
    counter += 1
    #print('counter', counter)
    sum1 += a[i + nextRound]
    #print('adding...', a[i], i)
    #print('sum', sum1)
    if counter == 3:
        x = i
        a[len(a) - 1] = sum1
        for j in range(len(a) - 1, x + 1 + nextRound, -1):
            a[j], a [j - 1] = a[j - 1], a[j]
            #print('cur: ', a)
        #print(sum1)
        sum1 = 0
        counter = 0
        nextRound += 1
print('Result: ', a)

amax = a[0]
ind = 0

for i in range(len(a)):
    if a[i] > amax:
        amax = a[i]
        ind = i
for i in range(ind + 1, len(a)):
    a[i - 1] = a[i]
    
#print('MaxElem found: ', a[ind])
#del(a[ind])
b = a[:-1]
print('MaxElem deleted: ', b )
        
    
