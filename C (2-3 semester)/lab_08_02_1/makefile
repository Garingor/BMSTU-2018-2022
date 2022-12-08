app.exe: main.o darray.o test.exe
	gcc -std=c99 -Wall -Werror -o app.exe main.o darray.o
test.exe: func.o test.o
	gcc -std=c99 -Wall -Werror -o test.exe func.o test.o
func.o: func.c
	gcc -std=c99 -Wall -Werror -c func.c -o func.o
test.o: test.c 
	gcc -std=c99 -Wall -Werror -c test.c -o test.o
main.o: main.c
	gcc -std=c99 -Wall -Werror -c main.c -o main.o
darray.o: darray.c
	gcc -std=c99 -Wall -Werror -c darray.c -o darray.o

