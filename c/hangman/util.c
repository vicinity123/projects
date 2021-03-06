#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "util.h"

char getInput(char *prompt)
{
  char userGuess = '\0';
  while (1)
  {
    printf("%s", prompt);
    scanf(" %c", &userGuess);
    if ((userGuess >= 'a' && userGuess <= 'z') || userGuess == '!')
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
    fgets(tmp, 24, fptr);
    i++;
  }
  if (strlen(tmp) <= MAX_WORDLEN)
  {
    strcpy(word, tmp);
    return;
  }
  getRandomWord(fptr, word);
}

int updateState(char *str, char ch, char *current)
{
  int foundLetter = 0;
  int n = strlen(str) - 2;
  for (int i = 0; i < n; i++)
  {
    if (ch - 32 == str[i])
    {
      current[i] = ch - 32;
      foundLetter = 1;
    }
  }
  printf("%s\n", current);
  // Returns 1 if correct letter is found
  // Otherwise returns 0
  return foundLetter;
}
