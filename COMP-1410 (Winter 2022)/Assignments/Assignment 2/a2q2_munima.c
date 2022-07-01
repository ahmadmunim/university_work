/* ===========================================================================
COMP-1410 Assignment 2
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// first_capital(str, n) returns the first capital letter in str;
//   returns 0 if str contains no capital letters
// requires: str is a string of length n
//           str contains only lower-case and upper-case letters
//           all lower-case letters appear before upper-case letters
char first_capital(const char str[], int n)
{
    int begin = 0;
    int end = n - 1;
    int mid;

    if (n == 1 && (str[0] >= 65 && str[0] <= 90))
        return str[0];
        

    while (begin <= end) // BINARY SEARCH FTW
    {
        mid = (begin+end) / 2;

        if (mid == 0 && (str[mid] >= 65 && str[mid] <= 90)) // When there's only one element in the char array and it's a capital letter
            return str[mid];

        if (str[mid] >= 65 && str[mid] <= 90) // checks whether the middle element is a capital letter or not
        {
            if (str[mid - 1] >= 97) // if the preceding element is a lower case letter
                return str[mid];
            else
                end = mid - 1; // If the above statement isn't true, then the first capital letter has to come way before
        }

        else
        {
            if (str[mid + 1] >= 65 && str[mid] <= 90) // If the succeeding element is a capital letter
                return str[mid + 1]; // it has to be the first capital letter if the middle element is a lowercase letter
            else
                begin = mid + 1; // if the above statement is false, then the first captial has to come way after
        }
    }

    return 0;
}

int main(void)
{
    char str[10] = "abZNJFKSF";
    assert(first_capital(str, 9) == 'Z');

    char str2[9] = "sfsdFSFA";
    assert(first_capital(str2, 8) == 'F');

    char str3[2] = "a";
    assert(first_capital(str3, 1) == 0);

    char str4[2] = "H";
    assert(first_capital(str4, 1) == 'H');

    char str5[7] = "DKSDAW";
    assert(first_capital(str5, 6) == 'D');

    printf("All tests passed successfully\n");
}