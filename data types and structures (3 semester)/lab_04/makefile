CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic
	
app.exe: main.o menu.o operation_stack_array.o operation_stack_list.o utills.o
	$(CC) -o $@ $< 


%o: %c %h 
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o *.exe kids.txt