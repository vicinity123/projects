#include <math.h>
#include "math_util.h"
#include <stdio.h>
#include <stdlib.h>

int numOfDivs(int num)
{
  // Returns -1 because 0 has infinite divisors
  if (num == 0)
    return -1;
  int count = 1; // Implicit '1' divisor
  for (int i = 2; i <= num; i++)
  {
    if (num % i == 0)
    {
      count++;
    }
  }
  return count;
}

int isPrime(int num)
{
  int divisors = numOfDivs(num);
  if (divisors < 2)
    return 0;
  else if (divisors == 2)
    return 1;
  else
    return 2;
}

void factors(int num, int *factorList)
{
  // Returns -1 because 0 has infinite divisors
  if (num == 0)
    return;

  int divInd = 0;
  factorList[divInd] = 1;

  for (int i = 2; i <= num; i++)
  {
    if (num % i == 0)
    {
      divInd++;
      factorList[divInd] = i;
    }
  }
}

int isPerfectSquare(int num)
{
  // Returns 1 if num is a perfect square
  // Returns 0 otherwise
  double sqrtValue = sqrt((double)num);
  int sqrtIntValue = (int)sqrtValue;
  if (sqrtValue - sqrtIntValue == 0.0)
  {
    return 1;
  }
  return 0;
}

void simplifySqrt(int num, int *out)
{
  int factorNum = numOfDivs(num);
  int *facList = malloc(factorNum * sizeof(int));
  if (facList == NULL)
    return;
  factors(num, facList);
  // Initialized to -1 as a starting value
  int maxPerfSqrt = -1;
  for (int i = 0; i < factorNum; i++)
    if (isPerfectSquare(facList[i]))
      maxPerfSqrt = facList[i];

  if (maxPerfSqrt == -1)
  {
    out[0] = 1;
    out[1] = num;
  }
  else
  {
    out[0] = sqrt(maxPerfSqrt);
    out[1] = num / maxPerfSqrt;
  }
  free(facList);
}