CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Wpedantic
FLAGS=-lcunit
SOURCES=main_test.c libpower_test.c libresistance_test.c libcomponent_test.c uppgift6/libpower.c uppgift6/libresistance.c uppgift6/libcomponent.c
EXEC_FILE=test_electro.sh

all: $(EXEC_FILE)

$(EXEC_FILE): $(SOURCES)
	@$(CC) $(CFLAGS) -o $(EXEC_FILE) $(SOURCES) $(FLAGS)
