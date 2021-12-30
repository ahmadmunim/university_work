#include <stdio.h>

int main(void) {
  float n = 0;
  float sum = 0;
  float avg = 0;
  int count = 0;
  puts("Enter a number greater than 1: ");
  scanf("%f", &n);

  if (n <= 1)
    puts("Invalid number");

  else
  {
    printf("The positive factors of %.0f are: ", n);
    for (int i = 1; i < n; i++)
    {
      if ((int)n % i == 0) // Gets the factor of the inputted number
      {
        printf("%d ", i); // prints that said factor
        sum += i; // adds that said fector
        count++; // adds one to counter to indicate that there's 1 more factor
      } 
    }
    puts("");
    avg = sum / count;
    printf("The avg is %.2f", avg);
  }
}