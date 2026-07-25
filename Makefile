# Simple Makefile for the Mini Kernel Hello demo
# Inspired by the real Linux kernel build system (Kbuild)

CC = gcc
CFLAGS = -Wall -Wextra -O2 -std=c11
TARGET = mini-kdb
SRC = kdb_hello.c

all: $(TARGET)

$(TARGET): $(SRC)
	@echo "Building mini kernel debugger..."
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)
	@echo "Done! Run it with: ./$(TARGET)"

clean:
	rm -f $(TARGET)

.PHONY: all clean
