#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char *getRandomWord()
{
  // TODO: read from a csv file and choose a random word
  // TODO: also check if the chosen word doesn't have a symbol, space, or number.
  return "happy";
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

char *currentState(char *str, char ch, int posOfC, char *current)
{
  for (int i = 0, n = strlen(str); i < n; i++)
  {
    if (i == posOfC && str[posOfC] == ch)
    {
      current[i] = ch;
      continue;
    }
    current[i] = '-';
  }
  return "abc";
}
