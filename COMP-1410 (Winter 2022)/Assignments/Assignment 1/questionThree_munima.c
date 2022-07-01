#include <stdio.h>
#include <assert.h>

// collatz(n) returns the number of steps it takes to reach 1 by
//   by repeatedly applying the Collatz mapping on n; prints each
//   number in the sequence starting at n
// requires: 1 <= n
int collatz(int n)
{
    
    if (n == 1)
    {
        printf("%d\n", 1);
        return 0;
    }

    else
    {
        printf("%d -> ", n); // Prints all n values until 1 is reached
        
        // Adds one step and changes n depending on whether it's even or odd
        if (n % 2 == 0)
            return 1 + collatz(n / 2); 

        else
            return 1 + collatz(3*n + 1);
    }
}

int main(void)
{
    int n = 0;
    while (1)
    {
        printf("Enter an integer: ");
        
        if (scanf("%d", &n) != 1) // Checks if the user input is a number or not. Loop is terminated if the input is not a number
            break;

        else if (n < 1)
        {
            puts("Error: Invalid integer"); // Error message is printed and the loop starts at the beginning again
            continue;
        }

        else
            collatz(n);
    }

    assert(collatz(5) == 5);
    assert(collatz(1) == 0);
    assert(collatz(2) == 1);
    assert(collatz(10) == 6);
    assert(collatz(11) == 14);
    
    puts("All tests passed");    
    return 0;
}