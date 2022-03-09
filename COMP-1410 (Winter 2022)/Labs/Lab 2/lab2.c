/* ===========================================================================
COMP-1410 Week of Jan. 31 Lab
=========================================================================== */

#include <stdio.h>
#include <assert.h>

// gcd(n,m) returns the greatest common divisor of n and m
// requires: 0 <= m and 0 <= n
int gcd(int n, int m)
{
    if (m == 0)
        return n;

    else if (n == 0)
        return m;

    else if (m > n)
        return gcd(m, n);

    else
        return gcd(m, n - m);
}

// num_nice_up_to_n(n) returns how many nice numbers are in the range between
//   1 and n (i.e., in the set [1, n])
// requires: 1 <= n
int num_nice_up_to_n(int n)
{
    if (n == 1)
        return 0;

    else
        if (n % 10 == 7 || n % 10 == 3)
            return 1 + num_nice_up_to_n(n - 1);
            
        else
            return 0 + num_nice_up_to_n(n - 1);
}

int main(void) {
  // Implement your test code here
  printf("%d\n", gcd(20, 12));
  printf("%d\n", num_nice_up_to_n(50));
  printf("All tests passed successfully.\n");
}