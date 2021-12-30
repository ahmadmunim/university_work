#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main(void) {
  
  puts("Welcome to my Command-Line Calculator (CLC)");
  puts("Developer: Ahmad Munim");
  puts("Version: 2");
  puts("Date: November 14th, 2021");
  puts("----------------------------------------------------");
  
  float result = 0, n1 = 0, n2 = 0;
  char l, op, v; // OPERATOR
  char letForVar[5] = {'a', 'b', 'c', 'd', 'e'};
  float varVals[5] = {0, 0, 0, 0, 0}; // SET TO DEFAULT VALUES
  int a = 0; // CHECKS TO SEE IF A WAS SELECTED BY THE USER
  
  while (1) {
    
    puts("Please select one of the following items: ");
    puts("B) Binary Mathematical Operations such as addition and subtraction.");
    puts("U) Unary Mathematical Operations, such as square root, and log.");
    puts("A) Advances Mathematical Operations, using variabless, arrays.");
    puts("V) Define variables and assign them values.");
    puts("X) Exit");

    scanf(" %c", &l);
    
    if (l == 'x' || l == 'X') { 
      puts("Thanks for using my calculator");
      break; // ENDS PROGRAM
    }

    while (1) { // ALL OF THE CODE BELOW IS UNDER ANOTHER LOOP SINCE THIS PART WILL REPEAT ASSUMING THE USER DOESN'T ENTER 'X'
      
      char sel = 'n'; // USING OPERATIONS ON NUMBERS IS THE DEFAULT MODE -> 'n'

      if (l == 'b' || l == 'B') {
        
        if (a == 1) { // THIS PART WILL RUN IF THE USER SELECTED A AND THEN SELECTED B
          
          char selVar1; // The variable user selects
          char selVar2;
          
          puts("Press 'c' to use variables, 'n' for numbers, 't' for both");
          scanf(" %c", &sel);
          
          if (sel == 'c' || sel == 'C') { // THIS IF BLOCK WILL RUN IF THE USER WANTS TO INPUT VARIABLES ONLY
            do {
              do {
                puts("Enter the first variable (a to e): ");  
                scanf(" %c", &selVar1);
              } while (getchar() != '\n' || (selVar1 != 'a' && selVar1 != 'A' &&
                                             selVar1 != 'b' && selVar1 != 'B' && 
                                             selVar1 != 'c' && selVar1 != 'C' &&
                                             selVar1 != 'd' && selVar1 != 'D' &&
                                             selVar1 != 'e' && selVar1 != 'E')); 
            
              n1 = varVals[selVar1 - 'a'];     
            
              do {
                puts("Enter an operation (+, -, *, /, %, ^)"); 
                scanf(" %c", &op);  
              } while (getchar() != '\n' || 
                      (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^'));
            
              do {
                puts("Enter the second variable (a to e): ");  
                scanf(" %c", &selVar2); 
                if (varVals[selVar2 - 'a'] == 0 && op == '/')
                  puts("Can't divide by 0.");
              } while (getchar() != '\n' || (selVar2 != 'a' && selVar2 != 'A' &&
                                             selVar2 != 'b' && selVar2 != 'B' && 
                                             selVar2 != 'c' && selVar2 != 'C' &&
                                             selVar2 != 'd' && selVar2 != 'D' &&
                                             selVar2 != 'e' && selVar2 != 'E')); 
              if(n1 == 0 && n2 == 0 && op == '^') {
                puts("0^0 is undefined");
              }
            } while (n1 == 0 && n2 == 0 && op == '^');     
          }
          
          else if (sel == 't' || sel == 'T') { // THIS IF BLOCK WILL RUN IF THE USER SELECTS 
                                               // TO INPUT BOTH A NUMBER AND A VARIABLE IN EITHER ORDER
          
            puts("Press 'c' to enter a variable first or press 'q' to enter a number first");
            scanf(" %c", &sel);
          
            if (sel == 'c' || sel == 'C') {
              do {
                do {
                  puts("Enter a variable (a to e): ");  
                  scanf(" %c", &selVar1);  
                } while (getchar() != '\n' || (selVar1 != 'a' && selVar1 != 'A' &&
                                               selVar1 != 'b' && selVar1 != 'B' && 
                                               selVar1 != 'c' && selVar1 != 'C' &&
                                               selVar1 != 'd' && selVar1 != 'D' &&
                                               selVar1 != 'e' && selVar1 != 'E')); 
            
                n1 = varVals[selVar1 - 'a'];    
            
                do {
                  puts("Enter an operation (+, -, *, /, %, ^)"); 
                  scanf(" %c", &op);  
                } while (getchar() != '\n' || 
                        (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^'));
            
                do {
                  puts("Enter a number: ");  
                  scanf("%f", &n2); 
            
                  if (n2 == 0 && op == '/')
                    puts("Can't divide by 0.");
                } while (getchar() != '\n' || (n2 == 0 && op == '/')); 
                
                if(n1 == 0 && n2 == 0 && op == '^')
                  puts("0^0 is undefined");
                  
              } while (n1 == 0 && n2 == 0 && op == '^');             
            }
          
            else if (sel == 'q' || sel == 'Q') {
              do {
                do {
                  puts("Enter a number: ");  
                  scanf("%f", &n1);  
                } while (getchar() != '\n');

                do {
                  puts("Enter an operation (+, -, *, /, %, ^)"); 
                  scanf("%1c", &op);  
                } while (getchar() != '\n' || 
                        (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^'));

                do {
                puts("Enter a variable (a to e): ");  
                scanf(" %c", &selVar2); 
                if (varVals[selVar2 - 'a'] == 0 && op == '/')
                  puts("Can't divide by 0.");
                } while (getchar() != '\n' || (selVar2 != 'a' && selVar2 != 'A' &&
                                               selVar2 != 'b' && selVar2 != 'B' && 
                                               selVar2 != 'c' && selVar2 != 'C' &&
                                               selVar2 != 'd' && selVar2 != 'D' &&
                                               selVar2 != 'e' && selVar2 != 'E')); 
            
                n2 = varVals[selVar2 - 'a'];
                if (n1 == 0 && n2 == 0 && op == '^') {
                  puts("0^0 is undefined");
                }
              } while (n1 == 0 && n2 == 0 && op == '^');
            }
          }
          a = 0;
        }

        if (sel == 'n' || sel == 'N') { // THIS IF BLOCK WILL RUN IF THE USER DIDN'T SELECT A BUT SELECTED B
          do {
            do {
              puts("Enter the first number: ");  
              scanf("%f", &n1);  
              } while (getchar() != '\n'); // VALIDATES THE USER'S INPUT
            
            do {
              puts("Enter an operation (+, -, *, /, %, ^)"); 
              scanf("%c", &op);  
              } while (getchar() != '\n' || 
                      (op != '+' && op != '-' && op != '*' && op != '/' && op != '%' && op != '^'));

            do {
              puts("Enter the second number: ");  
              scanf("%f", &n2); 
              if (n2 == 0 && op == '/')
                puts("Can't divide by 0.");
              } while (getchar() != '\n' || (n2 == 0 && op == '/'));
              if (n1 == 0 && n2 == 0 && op == '^')
                puts("0^0 is undefined.");
          } while (n1 == 0 && n2 == 0 && op == '^');

        }           

        switch (op) {
          case '+': 
            result = n1+n2; 
            printf("The sum is %f\n", result); 
            break;
          case '-': 
            result = n1-n2; 
            printf("The difference is %f\n", result); 
            break; 
          case '*': 
            result = n1*n2; 
            printf("The product is %f\n", result); 
            break;
          case '/': 
            result = n1/n2; 
            printf("The quotient is %f\n", result); 
            break;
          case '%': 
            result = (int)n1 % (int)n2; 
            printf("Remainder is %.0f\n", result); 
            break;
          case '^': 
            result = pow(n1, n2); 
            printf("The power is %f\n", result); 
            break;
        }
      }
        
      else if (l == 'u' || l == 'U') { 

        if (a == 1) { // THIS IF BLOCK WILL RUN IF THE USER SELECTED A AND THEN SELECTED U
          char selVar1; // Variables the user inputs
          char selVar2;
          puts("Press 'c' for varVals, 'n' for numbers");
          scanf(" %c", &sel);
          if (sel == 'c' || sel == 'C') {
           do {
              puts("Enter an operation (S for square root, L for log, E for exponentiation, C for ceiling, F for floor: "); 
              scanf(" %c", &op);  
            } while (getchar() != '\n' || 
                    (op != 'S' && op != 's' && op != 'L' && op != 'l' && 
                     op != 'E' && op != 'e' && op != 'C' && op != 'c' &&
                     op != 'F' && op != 'f'));            
            do {
              puts("Enter a variable (a to e): ");     
              scanf(" %1c", &selVar1);  
            } while (getchar() != '\n');
            n1 = varVals[selVar1 - 'a'];       
          }
          a = 0; // RESETS 
        }

        if (sel == 'n' || sel == 'N') { // THIS IF BLOCK WILL RUN IF THE USER DIDN'T SELECT A BUT SELECTED U
          do {
            puts("Enter an operation (S - square root, L - log, E - exponentiation, C - ceiling, F - floor: ");
            scanf(" %c", &op);         
          } while (getchar() != '\n' || 
                  (op != 'S' && op != 's' && op != 'L' && op != 'l' && 
                   op != 'E' && op != 'e' && op != 'C' && op != 'c' &&
                   op != 'F' && op != 'f'));
          
          do {
            puts("Enter a number: ");
            scanf("%f", &n1);
            if (n1 < 0 && (op == 'S' || op == 's' || op == 'L' || op == 'l')) {
              if (op == 'S' || op == 's')
                puts("Can't square root a negative number");
              else if (op == 'L' || op == 'l')
                puts("Can't log a negative number");
            }          
          } while (getchar() != '\n'|| (n1 < 0 && (op == 'S' || op == 's' || op == 'L' || op == 'l')));  
        }       

        if (op == 'S' || op == 's') {
          result = sqrt(n1);
          printf("The square root of %f is %f\n", n1, result);
        }

        else if (op == 'L' || op == 'l') {
          result = log10(n1);
          printf("The log of %f is %f\n", n1, result);
        }

        else if (op == 'E' || op == 'e') {
          result = exp(n1);
          printf("The exponentiation of %f is %f\n", n1, result);
        }

        else if (op == 'C' || op == 'c') {
          result = ceil(n1);
          printf("The ceiling of %f is %f\n", n1, result);
        }

        else if (op == 'F' || op == 'f') {
          result = floor(n1);
          printf("The floor of %f is %f\n", n1, result);
        }
      }

      else if (l == 'a' || l == 'A') {
        puts("Enter one of these letters (B, U, X)");
        scanf(" %c", &l);
        a = 1;
        continue;
      }

      if (l != 'A' && l != 'a' && 
          l != 'B' && l != 'b' && 
          l != 'U' && l != 'u' && 
          l != 'X' && l != 'x' ) {
            puts("Invalid input. Please try again");
            break;
          }
            
      break;
    }

    while (1) {
      
      if (l == 'v' || l == 'V') {
        
        for (int i = 0; i < 5; i++) {
          
          do {
            puts("Enter a letter from 'a' to 'e' as a variable (or press 'x' to exit this process)");
            scanf(" %c", &v);
          } while (getchar() != '\n' || (v != 'a' && v != 'A' &&
                                         v != 'b' && v != 'B' && 
                                         v != 'c' && v != 'C' &&
                                         v != 'd' && v != 'D' &&
                                         v != 'e' && v != 'E'));           
          
          if (v == 'x')
            break;
            
          do {
            puts("Enter a number (value for your variable): ");
            scanf("%f", &n1);
          } while (getchar() != '\n');
          
          varVals[v - 'a'] = n1; // This will give you the index where the appropriate value will be stored to the right letter 
          printf("Variable %c = %f\n", v, varVals[v - 'a']);
        }
        
        for (int i = 0; i < 5; i++)
          printf("%c = %f\n", letForVar[i], varVals[i]);
      }
      break;
    }
  }
}