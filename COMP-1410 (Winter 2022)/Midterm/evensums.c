#include <stdio.h>
#include <assert.h>

// sum_even_up_to_n(n) returns the sum of the nonnegative even integers up to n
// requires : 0 <= n < 10ˆ4
int sum_even_up_to_n(int n)
{
    if (n == 0)
        return 0;
    
    else
    {
        if (n % 2 == 0)
            return n + sum_even_up_to_n(n-2);
        else
            return 0 + sum_even_up_to_n(n-1); 
    }
}

int main(void)
{
    assert(sum_even_up_to_n(13) == 42);
    assert(sum_even_up_to_n(0) == 0);
    assert(sum_even_up_to_n(20) == 110);
    printf("All tests passed successfully.\n");
    return 0;
}

// EXPLANATION //

// My implementation of the recursive function goes over every number recursively from n to 0.

// BASE CASE: When n eventually reaches 0 thanks to the recursive case, 0 is returned since adding 0
//            is insignificant

// RECURSIVE CASE: In my recursive case, I have a conditional statement that checks whether the current value
//                 of n is an even number by checking the remainder of n when n is divided by 2. If the remainder is
//                 0, then n is for sure an even number. When this case is true, the current function returns the sum 
//                 of the current value of n (which is an even number) and a new function call where the argument is
//                 n-2 which is guaranteed to be an even number. This continues to happen recursively until n reaches
//                 0. The code in the else block only runs once and that's when the initial value of n ends up being
//                 an odd number. What's returned is the sum of 0 (because in this case, n is odd) and a new function 
//                 call where the argument is n-1 which means the new argument is an even number.