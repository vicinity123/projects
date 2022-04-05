#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

int hangman(char *word, char *state, int *attempt);

int main(void)
{
  FILE *fptr = fopen(WORDLIST_FILE, "r");
  int attempts = 6;
  // char *hiddenWord = malloc((MAX_WORDLEN * sizeof(char)) + 1);
  char *hiddenWord = calloc(MAX_WORDLEN + 1, sizeof(char));
  getRandomWord(fptr, hiddenWord);
  int wordLen = strlen(hiddenWord) - 2; // Due to newline char
  // char *currState = malloc(wordLen * sizeof(char));
  char *currState = calloc(wordLen, sizeof(char));

  if (hiddenWord == NULL || currState == NULL)
  {
    printf("Couldn't get enough memory.");
    return 1;
  }

  // Initialize the state to hyphens at the beginning of the game.
  for (int i = 0; i < wordLen; i++)
  {
    currState[i] = '-';
  }

  printf("This is a game of hangman. You have 6 attempts to guess a hidden word of length %i. Type '!' to end the game early.\n", wordLen);
  printf("All of your following inputs must be from 'a' to 'z' and lowercase characters as the hidden word is in lowercase.\n");

  int run = 1;
  // Game loop
  while (attempts > 0 && run == 1)
  {
    run = hangman(hiddenWord, currState, &attempts);
    if (run == 2)
      break;
  }

  if (run == 0)
  {
    printf("Rerun the command to play again.\n");
  }
  else if (run == 2)
  {
    printf("Well done on find the word. :)\n");
  }
  else if (attempts == 0)
  {
    printf("Unfortunately, you lost the game. :(\nWord: %s\n", hiddenWord);
  }
  free(hiddenWord);
  free(currState);
  return 0;
}

int hangman(char *word, char *state, int *attempt)
{
  // Return values
  // 0 -> Early end by '!'
  // 1 -> Correct letter found, not complete
  // 2 -> All letter found
  printf("\nAttempt %i\n", *attempt);
  printf("%s\n", state);
  char guess = getInput("Guess: ");
  if (guess == '!')
    return 0;

  int found = updateState(word, guess, state);
  if (strchr(state, '-') == NULL)
    return 2;

  if (!found)
    (*attempt)--;

  return 1;
}
