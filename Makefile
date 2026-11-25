CC ?= cc
CFLAGS ?= -std=c11 -Wall -Wextra -Wpedantic

temperatures: main.c temperature.c temperature.h
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ main.c temperature.c $(LDLIBS)

.PHONY: clean
clean:
	$(RM) temperatures
