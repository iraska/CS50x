// Luhn’s Algorithm
// Most cards use an algorithm invented by Hans Peter Luhn of IBM. According to Luhn’s algorithm, you can determine if a credit card number is (syntactically) valid as follows:
  // 1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
  // 2. Add the sum to the sum of the digits that weren’t multiplied by 2.
  // 3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
# include <stdio.h>
# include <cs50.h>

int main(void)
{
    // AMEX: 15 digits, start with 34 or 37 
    // MASTERCARD: 16 digits, start with 51, 52, 53, 54 or 55
    // VISA: 13 or 16 digits, start with 4
    // INVALID

    long credit = get_long("Please enter a credit card number: ");
    long check = credit;
    int counter = 0, two_digits = 0;    // for number of digits

    //printf("Sorry, this is a invalid code %li\n", credit);
    
    while(check>0)
    {
        if(check<100 && check>10)   // to find the first two digits identifying the card
        {
            two_digits = check;
            // switch(check)
            // {
            //     case check == 20:
            //         printf("VISA\n");
            //         break;
            // }
        }

        counter++;
        check /= 10;    // 13554635256456.5, how many digits are calculated according to the output of counter
    }

    if(counter != 13 && counter != 15 && counter != 16)
    {
        printf("INVALID\n");
    }
    else        // Check Luhn Algorithm
    {
        int not_line_numb = 0, line_numb = 0, a = 0;       // the sum of underlined and non-underlined numbers

        while(credit>0)
        {
            not_line_numb += credit%10;     // 12945
            credit /= 10;                   // 1294,5

            if(credit>0)
            {
                a = (credit%10)*2;          // 129,4*2

                // 9*2 = 18, 1+8 = 9, 18/10 = 1 + 18%10 = 8 = 9
                line_numb += a/10;
                line_numb += a%10;

                credit /= 10;       // 12,9
            }
        }

        int remaind = (not_line_numb + line_numb)%10;       // Check if the last digit is zero

        if(remaind != 0)
        {
            printf("INVALID\n");
        }
        else if(remaind == 0)
        {
            if(((counter == 13) || (counter == 16)) && (two_digits/10 == 4))
            {
                printf("VISA\n");
            }
            else if((counter == 15) && ((two_digits == 34) || (two_digits == 37)))
            {
                printf("AMEX\n");
            }
            else if((counter == 16) && ((two_digits == 51) || (two_digits == 52) || (two_digits == 53) || (two_digits == 54) || (two_digits == 55)))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
    }
}
