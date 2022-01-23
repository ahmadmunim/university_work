#include <stdio.h>
#include <math.h>

void minMaxAndAvg(int n);

int main(void)
{
    minMaxAndAvg(10);
    return 0;
}

void minMaxAndAvg(int n)
{
    
    float sum = 0;
    float inputtedNum = 0;
    float oldMax = 0;
    float newMax = 0;
    float max = -3.4 * pow(10,38);
    float min = 3.4 * pow(10,38);
    
    for (int i = 0; i < n; i++)
    {
        printf("Enter a number: ");
        scanf("%f", &inputtedNum);
        puts("");
        
        sum += inputtedNum;
        
        if (i >= 1)
        {
            oldMax = newMax;
            newMax = inputtedNum;

            if (newMax > oldMax)
            {
                if (newMax > max)
                    max = newMax;

                if (oldMax < min)
                    min = oldMax;
            }
                
            else
            {
                if (oldMax > max)
                    max = oldMax;

                if (newMax < min)
                    min = newMax;
            }
                        
        }
        
        else
            newMax = inputtedNum;  
                
    }

    float avg = (float) sum / n;

    printf("The average of the numbers you inputted is: %.1f\n", avg);
    printf("The highest value from the numbers you inputted is: %f\n", max);
    printf("The lowest value from the numbers you inputted is: %f\n", min);
}