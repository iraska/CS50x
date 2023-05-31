// promt user for an amount of change
   // the amount must make sense
   // what values are excepted?
   // get_float
// always use the largest coin possible
// keep track of coins used
// print the final number of coins

// Pseudocode
  // get amount in dollars
  // convert to cents
  // while(quarters can be used)
    // increase count
    // decrease amount by quarter
  // while(dimes can be used)
    // increase count
    // decrease amount by a dime 

# include <stdio.h>
# include <cs50.h>
# include <math.h>

int main(void)
{
    float cash;

    do
    {
        cash = get_float("Please enter cash value:\n");
    }
    while(cash<0);

    int cent = round(cash*100);
    int coin = 0;

    while(cent>0)
    {
        if(cent>=25)
        {
            cent -= 25;
            //cent = cent%25;
            coin++;
        }
        else if(cent>=10)
        {
            cent -= 10;
            coin++;
        }
        else if(cent>=5)
        {
            cent -= 5;
            coin++;
        }
        else if(cent>=1)
        {
            cent -= 1;
            coin++;
        }
    }
    printf("Number of coins required: %i\n", coin);
}
