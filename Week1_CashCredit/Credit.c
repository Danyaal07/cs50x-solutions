#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdbool.h>

bool checksum(long number);
int get_length(long number);
int get_first_two(long number);
void get_type(int firstTwo, int len);

int main(void)
{
    long number = get_long("Enter credit card number: ");
    if (!checksum(number))
    {
        printf("INVALID\n");
        return 0;
    }
    int len = get_length(number);
    int firstTwo = get_first_two(number);
    get_type(firstTwo, len);
}

void get_type(int n, int len)
{
    if ((n == 34 || n == 37) && (len == 15))
    {
        printf("AMEX\n");
    }
    else if ((n >= 51 && n <= 55) && (len == 16))
    {
        printf("MASTERCARD\n");
    }
    else if ((n / 10 == 4) && (len == 13 || len == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

int get_first_two(long n)
{
    while (n >= 100)
    {
        n /= 10;
    }
    return n;
}

int get_length(long n)
{
    int length = 0;

    while (n>0)
    {
        n /= 10;
        length ++;
    }
    return length;
}

bool checksum(long number)
{
    int sum = 0;
    int position = 0;
    while (number > 0)
    {
        int digit = number % 10;
        if (position%2 ==0)
        {
            sum += digit;
        }
        else
        {
            int product = digit * 2;
            if (product > 9)
            {
            sum += product % 10 + product / 10;
            }
            else
            {
            sum += product;
            }
        }
        number /= 10;
        position ++;
    }
    return (sum%10 == 0);
}
