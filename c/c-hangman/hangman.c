#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int hangman(char *word, char *current);

int main(void)
{
  FILE *fptr = fopen(WORDLIST_FILE, "r");
  int attempts = 6;
  char *hiddenWord = malloc((19 * sizeof(char)) + 1);
  getRandomWord(fptr, hiddenWord);
  int wordLen = strlen(hiddenWord);
  char *currState = malloc(wordLen * sizeof(char));

  // Initialize the current state to hyphens at the beginning of the game.
  for (int i = 0, n = strlen(currState); i < n; i++)
  {
    currState[i] = '-';
  }

  printf("This is a game of hangman. You have 6 attempts to guess what letters of a %i hidden word. Type '!' to end the game early.\n", wordLen);
  printf("All of your following inputs must be from 'a' to 'z' and lowercase characters as the hidden word is in lowercase.\n");

  int running = 1;
  // Game loop
  while (attempts > 0 && running)
  {
    running = hangman(hiddenWord, currState);
  }
  free(currState);
  return 0;
}

int hangman(char *word, char *state)
{
  // Return values
  // 0 -> Early end by '!'
  // 1 -> Word is found
  // 2 -> Correct letter found in word
  char guess = getChar("Guess: ");
  if (guess == '!')
  {
    return 0;
  }
  int pos = getPosition(word, guess);
  getState(word, guess, pos, state);
  printf("%s\n", state);
  return 2;
}
