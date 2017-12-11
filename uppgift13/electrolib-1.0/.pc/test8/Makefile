CC=gcc
CFLAGS=-I. -std=c99 -Wall -Wextra -Wpedantic
LIBFLAG = -L$(LIB) -Wl,-rpath,$(INSTALL_PATH)/$(LIB) -lpower -lcomponent -lresistance
OBJS=main.o
SOURCES=libresistance.c libcomponent.c libpower.c
HEADERS=libresistance.h libcomponent.h libpower.h
LIB=lib
SOBJS=$(patsubst %.c, $(LIB)/%.so, $(SOURCES))
INSTALL_PATH?=/usr/lib
HEADER_INSTALL_PATH=/usr/include

lib: createdir $(LIB)/$(SOBJS)

.PHONY: createdir
createdir:
	@mkdir -p $(LIB)

$(LIB)/%.so: %.c
	$(CC) $< $(CFLAGS) -shared -fPIC -o $@

.PHONY: clean
clean:
	rm -rf $(LIB)

install: $(EXEC_FILE)
	install -m 0755 $(SOBJS) $(INSTALL_PATH)
	cp $(HEADERS) ${DESTDIR}$(HEADER_INSTALL_PATH)

uninstall:
	rm -f $(addprefix $(INSTALL_PATH)/, $(SOBJS))
