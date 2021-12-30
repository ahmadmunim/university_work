#include <stdio.h>

int main(void) {
  puts("Enter the first number (a): ");
  int a;
  scanf("%d", &a);
  puts("Enter the second number (b): ");
  int b;
  scanf("%d", &b);
  puts("Enter the third number (c): ");
  int c;
  scanf("%d", &c);
  puts("Enter the fourth number (x): ");
  int x;
  scanf("%d", &x);

  if (x > 40000)
    puts("Possible overflow");

  else {
    int formula = a*b*x*x+b*b*x+c;
    printf("Q(%d) = %d * %d * %d^2 + %d^2 * %d + %d = %d", x, a, b, x, b, x, c, formula);
  }

}