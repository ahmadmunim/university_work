/* ===========================================================================
COMP-1410 Lab 2
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// order(a, b) orders the values pointed to by a and b so that *a <= *b;
//   *diff is set to absolute value of the difference between *a and *b;
//   returns true if the values were switched and false otherwise
// requires: a, b, and diff point to memory that can be modified
bool order(int * const a, int * const b, int * const diff)
{
    *diff = abs(*a - *b);
    
    if (*b >= *a)
        return false;

    else    
    {
        int temp = *a;
        *a = *b;
        *b = temp;
        return true;
    }
           
}

int main(void) {
    int dummyVar;
    int* diffPtr = &dummyVar;
    int a = 10;
    int b = 5;
    assert(order(&a, &b, diffPtr) == 1);
    assert(*diffPtr == 5);
    assert(a == 5 & b == 10);

    a = 6;
    b = 12;
    assert(order(&a, &b, diffPtr) == 0);
    assert(*diffPtr == 6);
    assert(a == 6 & b == 12);

    a = 20;
    b = 20;
    assert(order(&a, &b, diffPtr) == 0);
    assert(*diffPtr == 0);
    assert(a == 20 & b == 20);

    printf("All tests passed successfully.\n");
}