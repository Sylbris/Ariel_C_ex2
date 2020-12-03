CC=gcc
CFLAGS= -Wall -g

mains: main.o libmyBank.a
	$(CC) $(CFLAGS) -o mains main.o libmyBank.a 

libmyBank.a: myBank.o                 
	ar -rcs libmyBank.a myBank.o

myBank.o: myBank.c myBank.h
	$(CC) $(CFLAGS) -c myBank.c

main.o: main.c myBank.h
	$(CC) $(CFLAGS) -c main.c
	
.PHONY: clean 
	
clean:              #clean all .o files.
	rm -f mains *.o *.a
