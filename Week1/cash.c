#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int owed =  0;
    int coins = 0;
    do
    {
        owed = get_int("Change owed: ");
    }
    while (owed < 1);

    while (owed >= 25)
    {
        owed -= 25;
        coins ++;
    }
    while (owed >= 10)
    {
        owed -= 10;
        coins ++;
    }
    while (owed >= 5)
    {
        owed -= 5;
        coins ++;
    }
    while (owed >= 1)
    {
        owed -= 1;
        coins ++;
    }
    printf("%i\n", coins);
}
