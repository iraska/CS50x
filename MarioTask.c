// The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramid should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

// Pseudocode
  // 1. Ask the user for height.
  // 2. If the height is less than 1 or greater than 8 or not an integer, go back to step 1.
  // 3. The i of the application from 1 to the entered number (height input). step, first print i hashes and then move to a new line.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;
    do
    {
        height = get_int("Please enter a height value:\n");
    }
    while (height < 1 || height > 8);

    for (int i = 0; i < height; i++)
    {
        for (int d = 0; d < height-(i+1); d++)
        {
            printf(" ");                
        }
    
        for (int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
