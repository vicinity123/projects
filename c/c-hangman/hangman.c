#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int hangman(char *word, char *state, int *attempt);

int main(void)
{
  FILE *fptr = fopen(WORDLIST_FILE, "r");
  int attempts = 6;
  char *hiddenWord = malloc((MAX_WORDLEN * sizeof(char)) + 1);
  getRandomWord(fptr, hiddenWord);
  printf("\nWord is %s\n", hiddenWord);
  int wordLen = strlen(hiddenWord) - 2; // Due to newline char
  char *currState = malloc(wordLen * sizeof(char));

  // Initialize the current state to hyphens at the beginning of the game.
  for (int i = 0, n = strlen(currState); i < n; i++)
  {
    currState[i] = '-';
  }

  printf("This is a game of hangman. You have 6 attempts to guess a hidden word of length %i. Type '!' to end the game early.\n", wordLen);
  printf("All of your following inputs must be from 'a' to 'z' and lowercase characters as the hidden word is in lowercase.\n");

  int running = 1;
  // Game loop
  while (attempts > 0 && running)
  {
    running = hangman(hiddenWord, currState, &attempts);
  }
  printf("Unfortunately, you lost the game. :(\nWord: %s", hiddenWord);
  free(currState);
  return 0;
}

int hangman(char *word, char *state, int *attempt)
{
  // Return values
  // 0 -> Early end by '!'
  // 1 -> Word is found
  // 2 -> Correct letter found in word
  printf("\nAttempt %i\n", *attempt);
  char guess = getInput("Guess: ");
  if (guess == '!')
  {
    return 0;
  }
  int pos = getPosition(word, guess);
  printf("getPosition() -> Index: %i\n", pos);
  updateState(word, guess, pos, state);
  if (strchr(state, '-') == NULL)
  {
    return 1;
  }
  printf("%s\n", state);
  (*attempt)--;
  return 2;
}
