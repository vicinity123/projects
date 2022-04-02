# -*- Makefile -*-
#  Apr 01, 2022

CC=gcc

all: clean hangman

hangman: hangman.o util.o
	$(CC) hangman.o util.o -o hangman

hangman.o: hangman.c util.h
	$(CC) -c hangman.c 

util.o: util.c
	$(CC) -c util.c

clean:
	rm -f *.o hangman util

