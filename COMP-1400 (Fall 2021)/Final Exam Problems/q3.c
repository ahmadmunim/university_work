#include <stdio.h>
#include <math.h>

int isSymmetric(int myArray[], int size);

int main(void) {
  int arr[27];
  char space = 32;
  puts("Enter 9 integers (separated by space): ");

  for (int i = 0; i < 9; i++)
  {
    scanf("%d%c", &arr[i], &space);
  }

  if (isSymmetric(arr, 9) == 1)
    puts("Symmetric");
  else
    puts("Not symmetric");
}

int isSymmetric(int myArray[], int size)
{
   double midpoint = ceil(size/2) - 1;
   for (int i = 1; i <= midpoint; i++)
   {
     if (myArray[i-1] != myArray[size - i])
      return 0;
   }
   return 1;
}