CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Wpedantic
FLAGS=-lcunit
SOURCES=libpower_test.c libresistance_test.c uppgift6/libpower.c uppgift6/libresistance.c
EXEC_FILE=testprogram

all: $(EXEC_FILE)

$(EXEC_FILE): $(SOURCES)
	@$(CC) $(CFLAGS) -o $(EXEC_FILE) $(SOURCES) $(FLAGS)
