#include <stdio.h>

int main(void)
{
    int rows = 0;
    
    do
    {
        printf("please enter the number of rows: ");
        scanf("%d", &rows);
    } while (rows <= 2);

    printf("printing a half pyramid of %d rows\n", rows);

    for(int i = 1; i <= rows; i++)
    {
        printf("\n");
        for (int j = 1; j <= i; j++) 
            printf("%d ", i*j);
    }
    
    return 0;
}