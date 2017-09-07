CC=gcc
CFLAGS=-std=c99 -Wall -Wextra -Wpedantic
GTKFLAGS=-export-dynamic `pkg-config --cflags --libs gtk+-2.0`
SOURCES=main.c
EXEC_FILE=main

all: $(EXEC_FILE)

$(EXEC_FILE): $(SOURCES)
	@$(CC) $(CFLAGS) -o $(EXEC_FILE) $(SOURCES) $(GTKFLAGS)
