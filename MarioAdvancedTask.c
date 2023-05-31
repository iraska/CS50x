// The program we’ll write will be called mario. And let’s allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between, say, 1 and 8, inclusive.

#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height = 0;

    do
    {
        height = get_int("Please enter a height value:\n");
    }
    while(height<1 || height>8);

    for (int i=0; i<height; i++)
    {
        for(int d=0; d<height-(i+1); d++)
        {
            printf(" ");                
        }   
        for(int j=0; j<=i; j++)
        {
            printf("#");
        }
        for(int k=0; k<2; k++)
        {
            printf(" ");
        }
        for(int l=0; l<=i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}
