CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -g
INCLUDES = -Iinclude
TARGET = build/bit-tools
SOURCES = src/main.c src/bit_tools.c
HEADERS = include/bit_tools.h

$(TARGET): $(SOURCES) $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) $(SOURCES) -o $(TARGET)

.PHONY: clean

clean:
	rm -f $(TARGET)
