#Савинов Егор ИУ7-14Б
n = int(input('введите кол-во строк: '))
m = int(input('введите кол-во столбцов: '))

if n <= 0 and m <= 0:
       print('вы ввели неверное значение строк/столбцов')
       input()
       
else:       
        x = [[0]*m for i in range(n)]
        amount = 0

        for i in range(n):
                for j in range(m):
                    x[i][j] = float(input('# '))

        print('\n')

##        for i in range(n):
##                for j in range(m):
##                        s = x[i][j]
##                        s.encode('ascii')
##                        print(s,'\n')
##                
##        print('\n')

        for i in range(n): 
                for j in range(m):
                     print(x[i][j], end=' ')
                print()
        print('\n')

        f = x[0][0]
        for i in range(n): 
                for j in range(m):
                        if (x[i][j] < 0 and f > 0) or (x[i][j] > 0 and f < 0) :
                                amount += 1
                        f = x[i][j]
                                  
        if amount == 0:
                print('в массиве нет элементов, удолетворяющих условию')
        else:
                print('amount = ', amount)
                                  
