/* ===========================================================================
COMP-1410 Lab 4
=========================================================================== */

#include <stdio.h>
#include <assert.h>
#include <string.h>

// swap_to_front(str, c) swaps the initial character in the string str with the
//   character pointed to by c
// requires: str is a valid string that can be modified, length(str) >= 1
//           c points to a character in str
void swap_to_front(char str[], char * c)
{
    int i = 0;
    while (*(str + i) != *c) // Gets index of *c (the character we're swapping the first character of the string with)
        i++;

    char temp = str[0];
    str[0] = *c;    

    if (i == 0) // If 'i' didn't increment, the value of *c is either the first or second character of the string
    {
        if (str[0] == *c) // No swapping happens if the value of *c is the first character of the string
            str[0] = temp;
        else
            str[1] = temp; // Swaps the first two characters of the string
    }
    
    else
        str[i] = temp; // Swaps the first character and the character at index i which is where *c is in the string
}

// swap_to_back(str, c) swaps the last character in the string str with the
//   character pointed to by c
// requires: str is a valid string that can be modified, length(str) >= 1
//           c points to a character in str
void swap_to_back(char str[], char * c)
{
    int j = 0;
    while(*(str + j) != *c)
        j++;
    
    char temp = str[j];
    
    int i = 0;
    while (*(str + i) != '\0')
        i++;
    
    str[j] = str[i - 1];
    str[i - 1] = temp;
}

// select_max(str) returns a pointer to the character of maximal ASCII value
//   in the string str (the first if there are duplicates)
// requires: str is a valid string, length(str) >= 1
char * select_max(char str[])
{
    char *max = &str[0]; // set as the first character of the string
    int i = 0;
    
    while (*(str + i) != '\0') // gets the length of the string
        i++;
    
    int size = i;
    for (i = 1; i < size; i++)
    {
        if (str[i] > str[i - 1]) // compares character at current index with character at preceding index
        {
            if (str[i] > *max) // compares character at current index with a character that's currently the largest based on ascii value
                max = &str[i]; // stores the address of that particular character as the new largest character based on ascii value
        }       
    }
    
    return max;
}

// str_sort(str) sorts the characters in a string in decending order
// requires: str points to a valid string that can be modified
void str_sort(char str[]) 
{
    int i = 0;
    while (*(str + i) != '\0') // runs i times where i is the length of the string all the while moving the pointer right
    {
        char* max = select_max(str + i); // finds max character
        swap_to_front(str + i, max); // swaps first element with the max character that 'select_max()' found
        i++; // moves pointer to the next slot of the memory setting the adjecent character as the "first element" in the string   
    }
}

int main(void) 
{
    // Implement your test code here
    
    // TEST 1 //
    char str1[7] = "ethics";
    assert(strcmp(select_max(str1), &str1[1]) == 0);

    str_sort(str1);
    assert(strcmp(str1, "tsihec") == 0);

    // TEST 2 //
    char str2[7] = "zigzag";
    char *max2 = select_max(str2);
    assert(strcmp(select_max(str2), &str2[0]) == 0);
    assert(max2 < &str2[3] && max2 == &str2[0]);

    str_sort(str2);
    assert(strcmp(str2, "zzigga") == 0);

    // TEST 3 //
    char str3[3] = "he";
    assert(strcmp(select_max(str3), &str3[0]) == 0);

    str_sort(str3);
    assert(strcmp(str3, "he") == 0);

    // TEST 4 //
    char str4[2] = "a";
    assert(strcmp(select_max(str4), &str4[0]) == 0);

    str_sort(str4);
    assert(strcmp(str4, "a") == 0);

    // TEST 5 //
    char str5[5] = "cccc";
    char *max5 = select_max(str5);
    assert(strcmp(select_max(str5), &str5[0]) == 0);
    assert(max5 == &str5[0]);
    
    str_sort(str5);
    assert(strcmp(str5, "cccc") == 0);   

    printf("All tests passed successfully.\n");
    return 0;
}