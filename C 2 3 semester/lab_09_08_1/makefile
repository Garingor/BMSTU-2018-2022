CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
	
app.exe: main.o dmatrix.o input_output_matr.o matr_memory.o buffer_memory_init.o test.exe
	$(CC) -o $@ main.o dmatrix.o input_output_matr.o matr_memory.o buffer_memory_init.o
test.exe: test.o dmatrix.o input_output_matr.o matr_memory.o 
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