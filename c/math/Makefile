# -*- Makefile -*-
#  Apr 01, 2022

CC=gcc
FLAG=-c

all: clean main

main: main.o math_util.o
	$(CC) main.o math_util.o -o main

main.o: main.c math_util.h
	$(CC) $(FLAG) main.c

math_util.o: math_util.c
	$(CC) $(FLAG) math_util.c

clean:
	rm -f *.o *.out main math_util