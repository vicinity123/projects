#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "math_util.h"

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Insufficient arguments, must be exactly 2.");
    return 1;
  }

  int num = atoi(argv[1]);
  int divNum = numOfDivs(num);
  // int *divList = calloc(divNum, sizeof(int));
  int *divList = malloc(divNum * sizeof(int));
  divisors(num, divList);
  for (int i = 0; i < divNum; i++)
  {
    if (i == divNum - 1)
      printf("%i", divList[i]);
    else
      printf("%i, ", divList[i]);
  }
  printf("\n");
  return 0;
}