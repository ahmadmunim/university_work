#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

// num_divisors_up_to_k(n,k) returns the number of positive divisors
//   of n that are less than or equal to k
// requires: 1 <= k <= n
int num_divisors_up_to_k(int n, int k)
{
    
    if (k == 1)
        return 1; // Base case: here k is a factor of n hence 1 is added and indicates this program went though all possible k values
    
    else
    {
        // Calls the function with new k value
        if (n % k == 0) 
            return 1 + num_divisors_up_to_k(n, --k); // Adds 1 since k here is a factor of n 
        
        else
            return 0 + num_divisors_up_to_k(n, --k); // Adds nothing here since k is not a factor of n     
    }
}

// is_prime(n) returns true if n is a prime number and false otherwise
// requires: 1 <= n
bool is_prime(int n)
{
    
    if (n == 1)
        return false; // 1 is not a prime number 
    
    else
        return num_divisors_up_to_k(n, n) == 2 ? true : false; // 2 factors = prime, not 2 factors = not a prime number
}

int main(void)
{
    assert(num_divisors_up_to_k(8,8) == 4);
    assert(num_divisors_up_to_k(20,4) == 3);
    assert(num_divisors_up_to_k(1,1) == 1);
    assert(num_divisors_up_to_k(9,1) == 1);

    assert(is_prime(17) == 1);
    assert(is_prime(2) == 1);
    assert(is_prime(16) == 0);
    assert(is_prime(1) == 0);

    puts("All tests passed");    
    return 0;
}