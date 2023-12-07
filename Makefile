# Copyright (C) 2023 Ethan Uppal. All rights reserved.

SRCDIR		:= ./src
INCLUDEDIR	:= ./src

CC			:= $(shell which /opt/homebrew/bin/g++-13 || \
					   which g++ || which clang)
CFLAGS		:= -std=c++17 -pedantic -Wall -Wextra -I $(INCLUDEDIR)
CDEBUG		:= -g
CRELEASE	:= -O2
TARGET		:= main

# CFLAGS 		+= $(CRELEASE)
CFLAGS 		+= $(CDEBUG)

# use SDL
CFLAGS		+= $(shell sdl2-config --cflags --libs)

SRC			:= main.cpp $(shell find $(SRCDIR) -name "*.cpp" -type f)
OBJ			:= $(SRC:.cpp=.o)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	@echo 'Compiling $@'
	$(CC) $(CFLAGS) $< -c -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ) $(TARGET) $(shell find . -name "*.dSYM")
