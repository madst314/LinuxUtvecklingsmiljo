CC = gcc
LIBFLAG = -L. -lgdb -Wl,-rpath,.

all:	program

program:	main.c libgdb.so
		$(CC) -g -o program main.c $(LIBFLAG)

libgdb.so:	lib/gdblab.c lib/gdblab.h 
		$(CC) -g -c -fPIC lib/gdblab.c
		$(CC) -g -shared -fPIC -o libgdb.so gdblab.o
		
