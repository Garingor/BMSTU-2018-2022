CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic

test.exe: tests.o my_snprintf.o test_utills.o
	$(CC) -o $@ $^

%o: %c %h
	$(CC) $(CFLAGS) -c $<

clean: 
	rm *.o *.exe

utest:
	make 
	./test.exe