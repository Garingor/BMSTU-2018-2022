CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
	
app.exe: main.o main_features.o memory_list.o operation_list.o utills.o test.exe
	$(CC) -o $@ main.o main_features.o memory_list.o operation_list.o utills.o
test.exe: tests.o main_features.o memory_list.o operation_list.o utills.o tests_utills.o 
	$(CC) -o $@ $^

%o: %c %h 
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o *.exe out.txt *.exe.dSYM	

utest:
	make 
	./test.exe
ftest:
	make
	bash ./test.sh