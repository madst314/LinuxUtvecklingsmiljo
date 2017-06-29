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

main.o: main.c lib

$(EXEC_FILE): $(OBJS)
	$(CC) $^ -o $@ $(CFLAGS) $(LIBFLAG)

$(OBJS):
	$(CC) -c -o $@ $< $(CFLAGS)

lib: createdir $(LIB)/$(SOBJS)

.PHONY: createdir
createdir:
	@mkdir -p $(LIB)

$(LIB)/%.so: %.c
	$(CC) $< $(CFLAGS) -shared -fPIC -o $@

.PHONY: clean
clean:
	rm -f $(EXEC_FILE) *.o
	rm -rf $(LIB)

install: $(EXEC_FILE)
	install -m 0755 $(EXEC_FILE) $(INSTALL_PATH)/bin
	install -m 0755 $(SOBJS) $(INSTALL_PATH)/lib

uninstall:
	rm -f $(INSTALL_PATH)/bin/$(EXEC_FILE)
	rm -f $(addprefix $(INSTALL_PATH)/, $(SOBJS))
