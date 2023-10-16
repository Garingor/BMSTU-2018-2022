CC = gcc
CFLAGS = -std=c99
	
app.exe: main.o input_output_struct.o struct_memory.o utilities.o 
	$(CC) -o $@ main.o input_output_struct.o struct_memory.o utilities.o -l ui


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
