#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int charToNum(char c[], int size);
void numToChar(int n, char c[], int index);
int main(void) {
  
  char c1[6];
  char c2[6];
  
  puts("Guideline: Z=0, O=1, T=2, H=3, F=4, V=5, X=6, S=7, E=8, N=9");
  puts("Enter the first set of characters (maximum 6): ");
  scanf("%s", c1);
  
  int counter1 = 0;
  for (int i = 0; i < 6; i++) // Getting the length of first string
  {
    if (c1[i] != '\0')
    {
      c1[i] = toupper(c1[i]);
      counter1++;
    }
    else
      break;
  
  }
  
  puts("Enter the second set of characters (maximum of 6): "); // Getting the length of the second string
  scanf("%s", c2);
  int counter2 = 0;
  
  for (int i = 0; i < 6; i++)
  {
    if (c2[i] != '\0')
    {
      c2[i] = toupper(c2[i]);
      counter2++;
    }
    else
      break;
  }
  
  int sum = charToNum(c1, counter1) + charToNum(c2, counter2); // adding the two integers that I got from charToNum
  int digitIterator = sum; // Will use this variable to iterate over the individual digits of the sum
  int numOfDigits = 0; 
  
  while (digitIterator > 0) // Getting the number of digits in the sum 
  {
    digitIterator /= 10;
    numOfDigits += 1;
  }

  digitIterator = sum;
  int reverseSum = 0;
  while (digitIterator != 0) // reversing the sum so when I find the remainder of the sum, it'll be the first digit to the last 
  {
    int remainder = digitIterator % 10;
    reverseSum = reverseSum * 10 + remainder;
    digitIterator /= 10;
  }

  char finalC[numOfDigits]; // The converted sum (int to string) will be this array
  int digit = 0;
  int i = 0;
  while (reverseSum > 0 && i <= numOfDigits) // appending the appropriate character into the array finalC[]
  {
    digit = reverseSum % 10;
    numToChar(digit, finalC, i);
    i++;
    reverseSum /= 10;
  }

  printf("%s + %s = %s", c1, c2, finalC);
}

void numToChar(int n, char c[], int index)
{
  switch(n)
  {
    case 0:
      c[index] = 'Z';
      break;
    case 1:
      c[index] = 'O';
      break;
    case 2:
      c[index] = 'T';
      break;
    case 3:
      c[index] = 'H';
      break;
    case 4:
      c[index] = 'F';
      break;
    case 5:
      c[index] = 'V';
      break;
    case 6:
      c[index] = 'X';
      break;
    case 7:
      c[index] = 'S';
      break;
    case 8:
      c[index] = 'E';
      break;
    case 9:
      c[index] = 'N';
      break;
  }

}

int charToNum(char c[], int size)
{
  int digit = 0;
  int n = 0;
  for(int i = 0; i < size; i++)
  {
    switch(c[i])
    {
      case 'Z':
      case 'z':
        digit = 0;
        break;
      case 'O':
      case 'o':
        digit = 1;
        break;
      case 'T':
      case 't':
        digit = 2; 
        break;  
      case 'H':
      case 'h':
        digit = 3;
        break;
      case 'F':
      case 'f':
        digit = 4;
        break;
      case 'V':
      case 'v':
        digit = 5;
        break;
      case 'X':
      case 'x':
        digit = 6;
        break;
      case 'S':
      case 's':
        digit = 7; 
        break;
      case 'E':
      case 'e':
        digit = 8; 
        break;
      case 'N':
      case 'n':
        digit = 9;
        break;
      default:
        return -1;
    }
    n = n*10 + digit;
  }
  return n;
}