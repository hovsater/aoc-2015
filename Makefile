CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

SOURCES = $(wildcard src/*.c)
OBJECTS = $(addprefix out/,$(notdir $(SOURCES:.c=)))

.PHONY: all
all: $(OBJECTS)

out/%: src/%.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(OBJECTS)
