#include <stdio.h>
#include <ctype.h>

int main(void) {
  puts("Enter the conversion type (N or n for number, C or c for letter: ");
  char c;
  scanf("%c", &c);

  switch(c) {
    case 'n':
    case 'N':
      puts("Please enter a number grade as an integer: ");
      int grade = 0;
      scanf("%d", &grade);
      if (grade <= 100) {
        if (grade >=90)
          printf("A+");
        else if(grade >= 85)
          printf("A");
        else if(grade >= 85)
          printf("A");
        else if(grade >= 80)
          printf("A-");
        else if(grade >= 77)
          printf("B+");
        else if(grade >= 73)
          printf("B");
        else if(grade >= 70)
          printf("B-");
        else if(grade >= 60)
          printf("C");
        else if(grade >= 50)
          printf("D");
        else if(grade >= 0)
          printf("F");
        else
          printf("Invalid input");
      }
      else
        printf("Invalid input");
      break;
    case 'c':
    case 'C':
      puts("Please enter a letter grade as a character: ");
      char letter;
      scanf(" %c", &letter);
      if (letter == 'a')
        printf("Excellent");
      else if (letter == 'A') 
        printf("Excellent");
      else if (letter == 'b')
        printf("Good");
      else if (letter == 'B')   
        printf("Good");
      else if (letter == 'c') 
        printf("Fair");  
      else if (letter == 'C')  
        printf("Fair"); 
      else if (letter == 'd')  
        printf("Pass"); 
      else if (letter == 'D')   
        printf("Pass");
      else if (letter == 'f') 
        printf("Failure");  
      else if (letter == 'F')   
        printf("Failure");
      else     
        printf("Invalid input");   
      break;   
  }
}