#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

// char *testFunc(FILE *fptr, char *out);
void testFunc(FILE *fptr, char *out);

int main(void)
{
  FILE *fptr = fopen("wordList.txt", "r");
  // char currline[20];
  char *currline = malloc((19 * sizeof(char)) + 1);
  getRandomWord(fptr, currline);
  getRandomWord(fptr, currline);
  getRandomWord(fptr, currline);
  getRandomWord(fptr, currline);
  free(currline);
  return 0;
}

void testFunc(FILE *fptr, char *out)
{
  char tmp[20];
  int i = 0;
  while (i < 20)
  {
    fgets(tmp, 24, fptr);
    printf("Word: %s\tLevel %i of operation...\n", out, i);
    i++;
  }
  printf("Tmp is %s", tmp);
  strcpy(out, tmp);
}