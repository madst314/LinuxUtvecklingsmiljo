CC=gcc
PACKAGES= gtk+-2.0
PKG_CFLAGS= $(shell pkg-config --cflags $(PACKAGES))
CFLAGS=-I. -std=c99 -Wall -Wextra -Wpedantic $(PKG_CFLAGS)
LIBFLAG=$(shell pkg-config --libs $(PACKAGES)) -lresistance -lpower -lcomponent
OBJS=main.o
SOURCES=main.c
EXEC_FILE=electrotestgtk

all: $(EXEC_FILE)

$(EXEC_FILE): $(SOURCES)
	@$(CC) $(CFLAGS) $(SOURCES) -o $(EXEC_FILE) $(LIBFLAG)
