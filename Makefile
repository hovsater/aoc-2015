CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic

SOURCES = $(wildcard src/*.c)
EXECUTABLES = $(addprefix out/,$(notdir $(SOURCES:.c=)))

.PHONY: all
all: $(EXECUTABLES)

out/%: src/%.c
	$(CC) $(CFLAGS) -o $@ $<

.PHONY: clean
clean:
	rm -f $(EXECUTABLES)

.PHONY: format
format:
	clang-format --style=WebKit -i $(SOURCES)
