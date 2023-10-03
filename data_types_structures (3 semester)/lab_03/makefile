CC = gcc
CFLAGS = -std=c99 -Wall# -Werror -pedantic
	
app.exe: main.o input.o memory.o output.o tool.o
	$(CC) -o $@ main.o input.o memory.o output.o tool.o

%o: %c %h 
	$(CC) $(CFLAGS) -c $< 

clean:
	rm *.o *.exe	