/* ===========================================================================
COMP-1410 Lab 1
=========================================================================== */

#include <stdio.h>
#include <assert.h>

// digit_sum_iterative(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10^9
// note: implemented using iteration and not recursion
int digit_sum_iterative(int n);

// digit_sum_recursive(n) returns the decimal sum of the digits in n
// requires: 0 <= n < 10^9
// note: implemented using recursion and not iteration
int digit_sum_recursive(int n);

int main() {
  
  assert(digit_sum_iterative(0) == 0);
  assert(digit_sum_recursive(0) == 0);
  
  assert(digit_sum_iterative(999999999) == 81);
  assert(digit_sum_recursive(999999999) == 81);
  
  assert(digit_sum_iterative(3468) == 21);
  assert(digit_sum_recursive(3468) == 21);

  assert(digit_sum_iterative(5738728) == 40);
  assert(digit_sum_recursive(5738728) == 40);

  assert(digit_sum_iterative(10) == 1);
  assert(digit_sum_recursive(10) == 1);

  assert(digit_sum_iterative(102) == 3);
  assert(digit_sum_recursive(102) == 3);

  assert(digit_sum_iterative(10305001) == 10);
  assert(digit_sum_recursive(10305001) == 10);

  printf("All tests passed successfully.\n");
  
}

int digit_sum_iterative(int n)
{    
    int sum = 0;
    int digit = 0;
    
    while (n != 0)
    {
        digit = n % 10; // Obtains a digit from the right side
        sum += digit; // adds that digit to the sum
        n /= 10; // removes that digit from the number
    }

    return sum;
}

int digit_sum_recursive(int n)
{  
    if (n == 0) // runs when there are no digits left   
        return 0; // at this point, all digits have been added. Adding 0 doesn't change the sum
    

    else  
        return (n % 10) + digit_sum_recursive(n / 10); // recursively adds one digit everytime this function is called   
}