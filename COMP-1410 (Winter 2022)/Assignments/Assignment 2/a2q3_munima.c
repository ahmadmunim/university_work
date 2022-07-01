/* ===========================================================================
COMP-1410 Assignment 2
=========================================================================== */

#include <ctype.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>

// deepest_substring(str, out) updates out to be the deepest substring of
//   str; the first is used if multiple possibilities exist
// requires:
//   str is a string with balanced parenthesis
//   out points to enough memory to store the deepest substring of str
void deepest_substring(const char str[], char out[])
{
    // two variables below to find the depth of the left bracket in the string
    int currentLeftBracket = 0; 
    int deepestLeftBracket = 0; 
    int position = 0; // will be used to get the index of the deepest left bracker
    
    for (int i = 0; i < strlen(str); i++) // iterates over the original string 
    {
        if (str[i] == '(')
        {
            currentLeftBracket++; // 1 level deeper
            if (currentLeftBracket > deepestLeftBracket) // if the current level is deeper...
            {
                deepestLeftBracket = currentLeftBracket;
                position = i; // index of that bracket is set
            }
        }

        else if (str[i] == ')') // got out of current depth
            currentLeftBracket--;

    }

    int strLength = 0;
    int k = 1;
    while(*(str+position+k) != ')') // gets length of deepest substring starting at the first character after the deepest left bracket
    {
        strLength++; k++;
    }

    strncpy(out, str+position+1, strLength); // copies deepest substring 
    out[strLength] = '\0'; // adds null character as last element to make it a string
}

int main(void)
{
    char str4[15] = "(Hello(World))";
    char out4[7];
    deepest_substring(str4, out4);
    assert(strcmp(out4, "World") == 0);
    printf("%s\n", out4);

    char str5[10] = "(Welcome)";
    char out5[9];
    deepest_substring(str5, out5);
    assert(strcmp(out5, "Welcome") == 0);
    printf("%s\n", out5);

    char str1[12] = "a+((b+c)+d)";
    char out1[5];
    deepest_substring(str1, out1);
    assert(strcmp(out1, "b+c") == 0);
    printf("%s\n", out1);

    char str6[22] = "(abc((de(f))hi(jkl)))";
    char out6[2];
    deepest_substring(str6, out6);
    assert(strcmp(out6, "f") == 0);
    printf("%s\n", out6);

    char str7[22] = "(abc((def)hi(jk(l))))";
    char out7[2];
    deepest_substring(str7, out7);
    assert(strcmp(out7, "l") == 0);
    printf("%s\n", out7); 

    char str2[5] = "(())";
    char out2[1];
    deepest_substring(str2, out2);
    assert(strcmp(out2, "") == 0);
    printf("%s", out2);  

    char str3[7] = "(ss())";
    char out3[1];
    deepest_substring(str3, out3);
    assert(strcmp(out3, "") == 0);
    printf("%s", out3);         
}