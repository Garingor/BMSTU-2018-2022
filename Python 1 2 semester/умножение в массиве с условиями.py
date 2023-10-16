n = int(input())
A = [[0]*n for i in range(n)]
s = 1
m = int(n / 2)
k = int(n / 2)
for i in range(n):
    for j in range(n):
        A[i][j] = input('# ')
        A[i][j] = float(A[i][j])
for i in range(n):
    for j in range(n):
        if i <= j and j < m and i < k:
            s *= A[i][j]
        elif i >= j and j >= m and i >= k:
            s *= A[i][j]
        elif i >= k and i + j <= n - 1 and j <= m:
            s *= A[i][j]
        elif j >= m and i + j >= n - 1 and i < k:
            s *= A[i][j]
for i in range(n):
    for j in range(n):
        print(A[i][j],end = ' ')
    print()
print('\n s = ', s)
