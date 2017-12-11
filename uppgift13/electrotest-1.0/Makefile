CC=gcc
CFLAGS=-I. -std=c99 -Wall -Wextra -Wpedantic
LIBFLAG = -L$(LIB) -Wl,-rpath,$(INSTALL_PATH)/$(LIB) -lpower -lcomponent -lresistance
OBJS=main.o
SOURCES=libresistance.c libcomponent.c libpower.c
LIB=lib
SOBJS=$(patsubst %.c, $(LIB)/%.so, $(SOURCES))
INSTALL_PATH?=.
EXEC_FILE=electrotest

all: $(EXEC_FILE)

main.o: main.c

$(EXEC_FILE): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBFLAG)

$(OBJS):
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f $(EXEC_FILE) *.o

install: $(EXEC_FILE)
	install -m 0755 $(EXEC_FILE) $(INSTALL_PATH)/bin

uninstall:
	rm -f $(INSTALL_PATH)/bin/$(EXEC_FILE)
