#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define MAX_WORDLEN 8
#define WORDLIST_LEN 3001
#define WORDLIST_FILE "wordList.txt"

char getInput(char *prompt);
void getRandomWord(FILE *fptr, char *word);
void updateState(char *str, char ch, int posOfC, char *current);

#endif
