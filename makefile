CC = g++
CFLAGS = -Wall -std=c++17 -O2

# default source file if none provided
SRC ?= templates/boilerplate.cpp
BIN = ./bin

.PHONY: build run clean

build:
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

run: build
	$(BIN)

clean:
	rm -f $(BIN)
