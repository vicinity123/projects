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
  int *output = malloc(2 * sizeof(int));
  simplify(num, output);
  printf("%i√%i\n", output[0], output[1]);
  free(output);
  return 0;
}