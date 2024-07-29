CC          =
CFLAGS      = -Ofast -DDEBUG -static

ifeq ($(CC),)
CC          = gcc
endif

CSOURCES    = src/main.c src/utils/cd.c src/utils/export.c src/utils/echo.c src/execute.c src/parse_input.c
BIN         = microsh

COBJ        = $(CSOURCES:.c=.o)
all: $(COBJ)
	@echo "  CCLD  $(BIN)"
	@$(CC) $(CFLAGS) -o $(BIN) $^

%.o: %.c
	@echo "  CC    $@"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning up..."
	@rm -f $(COBJ) $(BIN)

install: all
	install -d ${DESTDIR}/usr/bin
	install -m 755 $(BIN) ${DESTDIR}/usr/bin
	install -m 755 scripts/pako-builder ${DESTDIR}/usr/bin
