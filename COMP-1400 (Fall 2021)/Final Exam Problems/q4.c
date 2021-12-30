#include <stdio.h>

int sumPositive(int n);
int sumOdd(int n);
float aveEven(int n);

int main(void) {
  int i = 0;
  do
  {
    puts("How many numbers you want to enter: ");
    scanf("%d", &i);
    if (i <= 0)
      puts("Your input is invalid. Please try again.");
  } while (i <= 0);

  int counter = 1;
  while (counter <= i)
  {
    int n = 0;
    printf("Enter value %d: ", counter);
    scanf("%d", &n);
    if (n <= 0)
    {
      puts("Your input in invalid. Please try again.");
      continue;
    }
    printf("The sum of the first (%d) positive integers is: %d\n", n, sumPositive(n));
    printf("The sum of the first (%d) odd positive integers greater than or equal to %d is: %d\n", n, n, sumOdd(n));
    printf("The avg of the first (%d) even numbers strictly greater than %d is: %.2f\n", n, n, aveEven(n));
    counter++; 
  }
}

int sumPositive(int n)
{
  int sum = 0;
  int i = 1;
  while (i <= n)
  {
    sum += i;
    i++;
  }
  return sum;
}

int sumOdd(int n)
{
  int sum = 0;
  int i = n;
  int counter = 0;
  while (counter != n)
  {
    if (i%2 == 0)
    {
      i++;
      continue;
    }   
    else
      sum += i;
    i++;
    counter++;
  }
  return sum;
}

float aveEven(int n)
{
  int sum = 0;
  float avg = 0;
  int counter = 0;
  int i = n+1;
  while (counter != n)
  {
    if (i%2 != 0)
    {
      i++;
      continue;
    }
    else;
      sum += i;
    i++;
    counter++;
  }
  avg = sum/n;
  return avg;
}