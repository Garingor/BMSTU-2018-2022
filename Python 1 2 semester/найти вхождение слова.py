spicok = ['mousec', 'cat', 'mo', 'mouse', 'mousecat']

mx = 0
for i in range(len(spicok)):
    if len(spicok[i]) > mx:
        word = ''
        for j in range(len(spicok[i])):
            word += spicok[i][j]
            if word in spicok:
                word = '1'
        if word == '1':
            print(mx)
            if len(spicok[i]) > mx:
                mx = len(spicok[i])
                print(mx)
                answer = spicok[i]
print(answer)