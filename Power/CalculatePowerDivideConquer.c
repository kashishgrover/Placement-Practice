//Write a program to calculate pow(x,n)

#include <stdio.h>

int power(int x, unsigned int y)
{
  if ( y == 0)
    return 1;
  else if (y % 2 == 0)
    return power(x, y / 2) * power(x, y / 2);
  else
    return x * power(x, y / 2) * power(x, y / 2);
}

// Time Complexity: O(n)
// Space Complexity: O(1)
// Algorithmic Paradigm: Divide and conquer.

// Above function can be optimized to O(logn) by calculating power(x, y/2) only once and storing it.

int powerOptimized(int x, unsigned int y)
{
  int temp;
  if ( y == 0)
    return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return temp * temp;
  else
    return x * temp * temp;
}

int main()
{
  int x = 2;
  unsigned int y = 3;
  printf("Enter number - ");
  scanf("%d", &x);
  printf("Enter power - ");
  scanf("%d", &y);
  printf("Result: %d\n", power(x, y));
  printf("ResultOptimized: %d\n", powerOptimized(x, y));
  getchar();
  return 0;
}