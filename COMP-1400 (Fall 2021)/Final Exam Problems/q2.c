#include <stdio.h>

int main(void) {
  int digits[10] = {0}; // used to store the amount of times a digit is repeated in the integer
  int n = 0;
  puts("Enter an integer: ");
  scanf("%d", &n);
  while (n > 0)
  {
    digits[n % 10] += 1; // will add one to the corresponding index whixh equals to the digit derived from n % 10
    n /= 10;
  }

  for(n = 0; n < 10; ++n)
    if (digits[n] != 0) // if that particular slot is 0, then it means that that digit isn;t in the integer
      printf("%d is repeated %d times\n", n, digits[n]);
  
}