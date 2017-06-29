all: program1

program1: main.c a_functions.c b_functions.c c_functions.c d_functions.c
	@gcc -o program1 main.c a_functions.c b_functions.c c_functions.c d_functions.c

install:
	@sudo install program1 /usr/local/bin

uninstall:
	@sudo rm /usr/local/bin/program1

clean:
	@rm -f *.o
