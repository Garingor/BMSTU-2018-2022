month = str(input('Месяц '))
day = str(input('День недели '))
a = ['январь', 'февраль','март', 'апрель','май','июнь', 'июль', 'август', 'сентябрь', 'октябрь','ноябрь', 'декабрь',
     'понедельник','вторник', 'среда', 'четверг','пятница','суббота','воскресенье']
for i in range(12):
    if a[i] == month.lower():
        month = i + 1
        break
for j in range(12,19,1):
    if a[j] == day.lower():
        day = j - 11
        break

a = [31,28,31,30,31,30,31,31,30,31,30,31]
count = a[month - 1]
if month != 1:
    n = 0
    for i in range(month - 1):
        n += a[i]
    day_correct = int(((n + day) % 7))
else:
    day_correct = 0 + day

b = [['  ' for j in range(7)] for i in range(6)]
k = 1
for j in range(day_correct,8,1):
    b[0][j-1] = k
    k += 1

for i in range(1,6,1):
    for j in range(0,7):
        if k <= count:
            b[i][j] = k
            k += 1

for i in range(6):
    print(*b[i])