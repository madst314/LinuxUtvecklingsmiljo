CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Wpedantic
FLAGS=-lcunit
SOURCES=uppgift6_test.c uppgift6/libpower.c
EXEC_FILE=testprogram

all: $(EXEC_FILE)

$(EXEC_FILE): $(SOURCES)
	@$(CC) -o $(EXEC_FILE) $(SOURCES) $(FLAGS)
