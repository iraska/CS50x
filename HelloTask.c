// Getting Input from User
// Modify this program in such a way that it prompts the user to enter their name first (prompt). Then let it print hello, dunk-who, - here i-know-who will be the user's real name.

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("What is your name\n");
    printf("hello, %s\n", name);
}
