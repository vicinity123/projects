#include "math_util.h"

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

void divisors(int num, int *divList)
{
  // Returns -1 because 0 has infinite divisors
  if (num == 0)
    return;

  int divInd = 0;
  divList[divInd] = 1;

  for (int i = 2; i <= num; i++)
  {
    if (num % i == 0)
    {
      divInd++;
      divList[divInd] = i;
    }
  }
}