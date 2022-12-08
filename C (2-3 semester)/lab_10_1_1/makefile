CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
	
app.exe: main.o comparator_sort.o input_output_struct.o struct_memory.o utilities.o test_utilities.o test.exe
	$(CC) -o $@ main.o comparator_sort.o input_output_struct.o struct_memory.o utilities.o

test.exe: test.o comparator_sort.o input_output_struct.o struct_memory.o utilities.o test_utilities.o
	$(CC) -o $@ $^

%o: %c %h 
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o *.exe kids.txt

utest:
	make 
	./test.exe
ftest:
	make
	bash ./test.sh
