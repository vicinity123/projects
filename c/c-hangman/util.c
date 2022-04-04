#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

char getChar(char *prompt)
{
  char userGuess = '\0';
  while (1)
  {
    printf("%s", prompt);
    scanf(" %c", &userGuess);
    if ((userGuess >= 97 && userGuess <= 122) || userGuess == 33)
    {
      break;
    }
  }
  return userGuess;
}

void getRandomWord(FILE *fptr, char *word)
{
  srand(time(NULL));
  // Formula to generate a random number between a range(lower, upper)
  // (rand() % (upper - lower + 1)) + lower
  int randNum = (rand() % (WORDLIST_LEN - 1 + 1)) + 1;

  char tmp[20];
  int i = 0;
  while (i <= randNum)
  {
    if (i == randNum)
    {
      fgets(tmp, 24, fptr);
    }
    i++;
  }
  printf("Number: %i\tWord: %s", randNum, tmp);
  strcpy(word, tmp);
}

int getPosition(char *str, char c)
{
  // Returns -1 if character doesn't exist in the string
  for (int i = 0; i < strlen(str); i++)
  {
    if (c == str[i])
    {
      return i;
    }
  }
  return -1;
}

void getState(char *str, char ch, int posOfC, char *state)
{
  for (int i = 0, n = strlen(str); i < n; i++)
  {
    if (i == posOfC && str[posOfC] == ch)
    {
      state[i] = ch;
    }
    state[i] = '-';
  }
}
