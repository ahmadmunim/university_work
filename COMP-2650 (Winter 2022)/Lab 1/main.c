#include <stdio.h>

int main(void)
{
    while (1) // Continues listing options until 0 is entered
    {
        int option;
        int x;
        int y;
        
        puts("Enter the command number: ");
        puts("  0) Exit");
        puts("  1) AND");
        puts("  2) OR");

        scanf("%d", &option);

        if (option == 0) // Breaks loop and terminates the program
            break;

        else if (option == 1)
        {
            do
            {
                printf("x = ");
                scanf("%d", &x);

                if (x != 0 && x != 1)
                    puts("Invalid input. You must enter 1 or 0"); // Error message    

            } while (x != 0 && x != 1);

            do
            {
                printf("y = ");
                scanf("%d", &y);

                if (y != 0 && y != 1)
                    puts("Invalid input. You must enter 1 or 0"); 

            } while (y != 0 && y != 1); // Checks for valid input
            
            printf("%d AND %d is %d\n", x, y, x&y); // AND operator
        }             
        
        else if (option == 2)
        {
            do
            {
                printf("x = ");
                scanf("%d", &x);

                if (x != 0 && x != 1)
                    puts("Invalid input. You must enter 1 or 0");
                    
            } while (x != 0 && x != 1);

            do
            {
                printf("y = ");
                scanf("%d", &y);
                
                if (y != 0 && y != 1)
                    puts("Invalid input. You must enter 1 or 0");       

            } while (y != 0 && y != 1);
            
            printf("%d OR %d is %d\n", x, y, x|y); // OR operator
        }

        else
            puts("Wrong input. Your input should 0, 1 or 2"); // Error message
            
    }
    
    return 0;
}