#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// FUNCTION PROTOTYPES
char optionSelection(); // WILL RETURN ONE LETTER THAT REPRESENTS ONE OF THE OPTIONS (B, U, V, A, M, R, X)

float binaryOperation();
float unaryOperation();
char operatorSelection(char l);
float binaryCalculation(float n1, char op, float n2);
float unaryCalculation(float n1, char op);

void varDeclaration();
void advancedOpSelection(); // ASKS THE USER TO ENTER AN APPROPRIATE OPERATION (B - BINARY OR  U - UNARY) WHILE MAKING a = 1 IMPLYING THAT ADVANCED OPERATION IS RUNNING
float advancedOp(char l, float n1, float n2, char op);

void memoryView();
void memoryStore(float ans); // STORES A VALID CALCULATION IN THE MEMORY ARRAY
void memoryClear();

float values[5]; // THIS ARRAY WILL BE USED TO STORE A VALUE THAT CORRESPONDS TO A VARIABLE (a to e)
float memory[1000]; // THIS ARRAY WILL BE USED TO STORE ANY CALCULATION

int a = 0; // "BOOLEAN" VALUE FOR WHETHER ADVANCED OPERATION IS RUNNING OR NOT (0 - FALSE, 1 - TRUE)
static int counter = 0; // REPRESENTS THE TOTAL NUMBER OF VALUES IN THE MEMORY ARRAY

int main(void)
{
    puts("Welcome to my Command-Line Calculator (CLC)");
    puts("Developer: Ahmad Munim");
    puts("Version: 3");
    puts("Date: December 1st, 2021");
    puts("----------------------------------------------------");
    puts("Here are your options: ");
    puts("----------------------------------------------------");
    puts("B) Binary Mathematical Operations such as addition and subtraction.");
    puts("U) Unary Mathematical Operations, such as square root, and log.");
    puts("A) Advances Mathematical Operations, using variabless, arrays.");
    puts("V) Define variables and assign them values.");
    puts("M) See the memory.");
    puts("R) Clear the memory.");
    puts("X) Exit");   
     
    while (1)
    {
        char l = optionSelection();

        if (l == 'X' || l == 'x')
          break;

        switch(l) // ORGANIZES ALL THE OPTIONS AND CALLS THE APPROPRIATE FUNCTION 
        {
          case 'B':
          case 'b':
            printf("%f", binaryOperation()); 
            break;
          case 'U':
          case 'u':
            printf("%f", unaryOperation());
            break;
          case 'V':
          case 'v':
            varDeclaration();
            break;
          case 'A':
          case 'a':
            advancedOpSelection();
            break;
          case 'M':
          case 'm':
            memoryView();
            break;
          case 'R':
          case 'r':
            memoryClear();
            break;
        }       
    }
    return 0;
}

char optionSelection() // VALIDATES THE USER'S INPUT WHEN SELECTING AN OPTION
{
    char l;

    while (1)
    {
        puts("\nSelect one of these operations (B, U, V, A, M, R, X): ");
        scanf(" %c", &l);

        if(l == 'X' || l == 'x') // EXITS THE PROGRAM
        {
            puts("Thanks for using my calculator.");
            return l;
        }

        switch(l)
        {
            case 'B':
            case 'b':
            case 'U':
            case 'u':
            case 'A':
            case 'a':
            case 'V':
            case 'v':
            case 'M':
            case 'm':
            case 'R':
            case 'r':
                return l; // RETURNS ANY OF THE ABOVE CASES FOR THE MAIN FUNCTION TO ORGANIZE
                break;
            default:
                puts("Invalid input. Please try again."); 
                continue;
        }
    }
}

float binaryOperation()
{
    float n1 = 0;
    float n2 = 0;
    char op;
    float advanced;

    if (a == 1) // ADVANCED OPTION 'A' IS SELECTED
    {
        advanced = advancedOp('B', n1, n2, op);
        printf("%f", advanced); // DISPLAYS THE RESULT OF THE CALCULATION 
        memoryStore(advanced);
        return advanced;
    }
      
    else
    {
        do
        {
            do
            {
                while(getchar() != '\n');
                puts("Enter the first number: ");
            } while (scanf("%f", &n1) != 1);

            op = operatorSelection('B');

            do
            {
                do
                {
                    while (getchar() != '\n');
                    puts("Enter the second number: ");
                } while (scanf("%f", &n2) != 1);
                  
                if (n2 == 0 && op == '/')
                    puts("Can't divide by 0.");
                    
            } while (n2 == 0 && op == '/');       

            if (n1 == 0 && n2 == 0 && op == '^')
                puts("0^0 is undefined");
            
        } while (n1 == 0 && n2 == 0 && op == '^');
    
    float result = binaryCalculation(n1, op, n2);
    memoryStore(result);
    return result;
    }
}

float unaryOperation() 
{
    char op;
    float n1 = 0;
    float advanced;

    if (a == 1) // ADVANCED OPTION 'A' IS SELECTED
    {
        advanced = advancedOp('U', n1, 0, op);
        memoryStore(advanced);
        printf("%f", advanced);
        return advanced;
    }

    else
    {
        do
        {
            do
            {
                while(getchar() != '\n');
                puts("Enter the first number: ");
            } while (scanf("%f", &n1) != 1);

            op = operatorSelection('U');

            if (n1 < 0 && (op == 'L' || op == 'l'))
                puts("You can't find the log of a negative number.");

        } while (n1 < 0 && (op == 'L' || op == 'l'));
      
        float result = unaryCalculation(n1, op);
        memoryStore(result);
        return result;  
    }
}

char operatorSelection(char l) // ASKS THE USER TO ENTER AN OPERATION AND VALIDATES THE INPUT DEPENDING ON THE OPTION (B or U) SELECTED
{
    char op;

    switch(l)
    {
        case 'B':
        case 'b':
            do
            {
                while (getchar() != '\n');                
                puts("Enter an operation (+, -, *, /, ^, % (remainder), x (max), i (min): ");
            } while (scanf("%c", &op) != 1 || (op != '+' && op != '-' && op != '*' && op != '/' && op != '^' && op != '%' && op != 'x' && op != 'i'));
            return op;
        case 'U':
        case 'u':
            do
            { 
                while (getchar() != '\n');             
                puts("Enter an operation (s for root, l for logarithm, e for exponentation, f for floor, c or ceiling): ");
            } while (scanf("%c", &op) != 1 || (op != 'S' && op != 'L' && op != 'E' && op != 'F' && op != 'C' && op != 's' && op != 'l' && op != 'e' && op != 'f' && op != 'c'));
            return op;                     
    }
    return 0;
}

void varDeclaration() // ASKS THE USER TO ASSIGN A VALUE TO A VARIABLE (a to e)
{  
    char var;
    float n1; 

    do
    {
        do
        {
            while (getchar() != '\n');
            puts("Enter a letter (a to e) or press x to exit");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e' && var != 'x'));

        if (var == 'x')
            break;

        do
        {
            while (getchar() != '\n');
            puts("Enter a number: ");
        } while (scanf("%f", &n1) != 1);
        
        values[var - 'a'] = n1; // ASCII VALUES FOR CHARACTERS ARE USED TO GET AN INDEX TO STORE THE VALUE

        printf("%c = %f\n", var, n1);   
    } while (var != 'x');
}

void advancedOpSelection()
{ 
    a = 1; // ADVANCED OPERATION IS SELECTED WHEN a = 1
    
    char l;
    do
    {
      while (getchar() != '\n');
      puts("Enter one of these letters (B, U, X)");
    } while (scanf("%c", &l) != 1 || (l != 'B' && l != 'b' && l != 'U' && l != 'u' && l != 'X' && l != 'x'));
    
    switch(l) // CALLS THE APPROPRIATE FUNCTION TO DO THE ADVANCED OPERATION WITH VARIABLES
    {
      case 'B':
      case 'b':
        binaryOperation();
        break;
      case 'U':
      case 'u':
        unaryOperation();
        break;
    }
}

float advancedOp(char l, float n1, float n2, char op)
{ 
  char var;
  char selection;
  a = 0;

  if (l == 'B') // IF THE USER WANTS TO DO A BINARY OPERATION WITH VARIABLES
  {
    do
    {
      while (getchar() != '\n');
      puts("Press 'v' to enter two letters or 't' to enter a variable and a number: "); // ASKS THE USER IF THE USER WANTS THE PROGRAM TO CALCULATE WITH TWO VARIABLES OR
                                                                                        // ONE VARIABLE AND ONE NUMBER
    } while (scanf("%c", &selection) != 1 || (selection != 't' && selection != 'T' && selection != 'v' && selection != 'V'));
    
    switch(selection)
    {
      case 'V': // AKS THE USER TO ENTER THE ACCEPTED TWO LETTERS FROM a TO e AND AN OPERATOR
      case 'v':
        do
        {
            while (getchar() != '\n');
            puts("Enter a variable (a to e): ");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n1 = values[var - 'a']; // STORES THE CORRESONDING VALUE TO THE INPUTTED VARIABLE USING THE ASCII VALUES OF THE VARIABLES IN n1

        op = operatorSelection('B');

        do
        {
            while (getchar() != '\n');
            puts("Enter a variable (a to e): ");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n2 = values[var - 'a'];
        float result = binaryCalculation(n1, op, n2);
        return result;
    case 'T':
    case 't':
      do
      {
        while (getchar() != '\n');
        puts("What do you want to enter first? ('v' for variable, 'n' for number: "); // ASKS THE USER IF THE USER WANTS TO ENTER A VARIABLE OR A NUMBER FIRST
      } while (scanf("%c", &selection) != 1 || (selection != 't' && selection != 'T' && selection != 'v' && selection != 'V'));

      if (selection == 'v') // IF THE USER WANTS TO ENTER A VARIABLE FIRST
      {
        do
        {
            while (getchar() != '\n');
            puts("Enter a variable (a to e): "); // ASKS FOR A VARIABLE FIRST
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n1 = values[var - 'a'];

        op = operatorSelection(l);

        do
        {
          while (getchar() != '\n');
          puts("Enter a number: ");
        } while (scanf("%f", &n2) != 1);
        return binaryCalculation(n1, op, n2);     
      }
      else
      {
        do
        {
          while (getchar() != '\n');
          puts("Enter a number: ");
        } while (scanf("%f", &n1) != 1);

        op = operatorSelection(l);

        do
        {
          while (getchar() != '\n');
          puts("Enter a variable (a to e): ");
        } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

        n2 = values[var - 'a'];
        float result = binaryCalculation(n1, op, n2);
        return result;                  
      }
    }
  }
  else 
  {   
      do
      {
          while (getchar() != '\n');
          puts("Enter a variable (a to e): ");
      } while (scanf("%c", &var) != 1 || (var != 'a' && var != 'b' && var != 'c' && var != 'd' && var != 'e'));

      n1 = values[var - 'a'];

      op = operatorSelection('U');

      float result = unaryCalculation(n1, op);
      return result;
  }
  return 0;
}

void memoryView() // SHOWS THE USER THE VALUES THAT ARE STORED IN THE MEMORY
{

    int selection;

    if (counter == 0)
      puts("Currently, there are no items saved in the memory.");

    else 
    {
      printf("The past %d results are stored (maximum is 1000)\n", counter);
      
      do
      {
        while(getchar() != '\n');
        puts("Enter '0' to see all the stored items. Enter a number between 1 and the total number of values stored to see the corresponding value.");
      } while (scanf("%d", &selection) != 1 || (selection > counter)); // CONTINUES ASKING THE USER TO INPUT A NUMBER AS LONG AS THE USER
                                                                       // INPUTS A NUMBER THAT'S GREATER THAN THE NUMBER OF VALUES IN
                                                                       // THE MEMORY
      
      if (selection == 0) // PRINTS ALL THE VALUES STORED IN THE MEMORY ALONG WITH IT'S POSITION
      {
        for (int i = 0; i < counter; i++)
        {
          printf("[%d] %f\n", i+1, memory[i]);
        }      
      }
      
      else
        printf("[%d] %f\n", selection, memory[selection - 1]); // PRINTS THE CORRESPONDING VALUE TO THE POSTION VALUE THE USER INPUTS
    }
}

void memoryStore(float ans) // STORES A CALCULATION IN AN ARRAY WHICH REPRESENTS THE MEMORY OF THE CALCULATOR
{
  counter++; // THIS COUNTER REPRESENTS THE NUMBER OF CALCULATIONS DONE

  if (counter >= 1000) // THIS IS FOR WHEN THERE ARE 1000 ITEMS IN THE MEMORY ARRAY 
  {
    counter = 1000;
    for (int i = 0; i < counter - 1; i++)
    {
      memory[i+1] = memory[i]; // THE FIRST ELEMENT GETS PUSHED OUT THE THE ARRAY AND THE SUCCEEDING ELEMENT'S POSITION SUBTRACTS BY 1     
    }
    memory[counter - 1] = ans;
  }
  else
    memory[counter - 1] = ans; // STORES THE CALCULATION IN THE ARRAY
}

void memoryClear() // CLEARS MEMORY WHEN THE USER ENTERS 'R' AS AN OPTION
{
  counter = 0; // THE COUNTER ALSO RESETS TO 0 SINCE A MEMORY RESET WOULD MEAN THAT THERE ARE NO CALCULATED VALUES IN THE MEMORY ARRAY
  for (int i = 0; i < 1000; i++) // RESETS THE MEMORY ARRAY BY MAKING ALL THE VALUES IN IT TO 0
    memory[i] = 0;
  puts("Memory cleared!");
}

float binaryCalculation(float n1, char op, float n2) // TWO FUNCTIONS BELOW ORGANIZES THE POTENTIAL OPERATIONS AND SELECTS THE APPROPRIATE ONE TO RETURN A VALUE
{
  switch (op)
  {
    a = 0; // ADVANCED OPTION RESETS TO ZERO IF THIS FUNCTION IS CALLED WITHIN THE ADVANCED OPERATION FUNCTION
    case '+':
      printf("The sum is: ");
      return n1+n2;
    case '-':
      printf("The difference is: ");
      return n1-n2;           
    case '*':
      printf("The product is: ");
      return n1*n2;           
    case '/':
      printf("The quotient is: ");
      return n1/n2;                      
    case '^':
      printf("The power is: ");
      return pow(n1, n2);                      
    case '%':
      printf("The remainder is: ");
      return (int)n1 % (int)n2; 
    case 'x':
      printf("The max is: ");
      return n1 >= n2 ? n1 : n2; // THE FIRST NUMBER IS OUTPUTTED IF IT'S GREATER THEN THE SECOND ONE. VICE-VERSA OTHERWISE
    case 'i':
      printf("The min is: ");
      return n1 >= n2 ? n2 : n1;               
  }
  return 0;
}

float unaryCalculation(float n1, char op)
{
  switch (op)
  {
    a = 0; // ADVANCED OPTION RESETS TO ZERO IF THIS FUNCTION IS CALLED WITHIN THE ADVANCED OPERATION FUNCTION
    case 'S':
    case 's':
        printf("The root is: ");
        return sqrt(n1);
    case 'L':
    case 'l':
        printf("The logarithm is: ");
        return log10(n1);
    case 'E':
    case 'e':
        printf("The exponentation is: ");
        return exp(n1);
    case 'F':
    case 'f':
        printf("The floor is: ");
        return floor(n1);           
    case 'C':
    case 'c':
        printf("The ceiling is: ");
        return ceil(n1);           
  }
  return 0;
}