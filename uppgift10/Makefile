CC=gcc
CFLAGS=-I. -std=c99 -Wall -Wextra -Wpedantic
FLAGS=-lcunit
SOURCES=script_test.c uppgift6/libpower.c uppgift6/libcomponent.c uppgift6/libresistance.c
EXEC_FILE=testprogram

all: $(EXEC_FILE)

$(EXEC_FILE):
	@$(CC) $(CFLAGS) -o $(SOURCES) $(FLAGS)
