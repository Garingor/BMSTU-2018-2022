CC = gcc
CFLAG = -std=c99 -Wall -Werror

app.exe: main.o in_out.o memory.o utills.o
	$(CC) -o $@ main.o in_out.o memory.o utills.o
	./app.exe
%o: %c %h
	$(CC) $(CFLAG) -c $<
clean:
	rm *.o *.exe
