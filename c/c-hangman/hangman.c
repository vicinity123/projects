#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "util.h"

#define ATTEMPTS_TOT 6

int hangman(int *attemptNum);

int main(void)
{
  int attempts = ATTEMPTS_TOT; // Line 6 in util.h
  printf("This is a game of hangman. You have 6 attempts to guess what letters of the hidden word. Type '!' to end the game early.\n");
  printf("All of your following inputs must be from 'a' to 'z' and lowercase characters as the hidden word is in lowercase.\n");
  printState("Hello", 'o', getPosition("Hello", 'r'));
  
  int running = 1;
  // Game loop
  while (attempts > 0 && running)
  {
    running = hangman(&attempts);
  }
  return 0;
}

int hangman(int *attemptNum)
{
  // Return values
  // 0 -> Early end by '!'
  // 1 -> Word is found
  // 2 -> Correct letter found in word
  char *hiddenWord = getRandomWord();
  char guess = getChar("Guess: ");
  if (guess == '!')
  {
    return 0;
  }
  int pos = getPosition(hiddenWord, guess);
  currentState(hiddenWord, guess, pos);
  printf("Word: %s\n", hiddenWord);
  return 2;
}
