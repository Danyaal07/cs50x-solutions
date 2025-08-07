#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

bool is_numeric(string s);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR | You must enter one number\n");
        return 1;
    }

    if (!is_numeric(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    int number = atoi(argv[1]) % 26; // Wrap around alphabet

    string plain = get_string("plaintext:  ");
    int length = strlen(plain);

    // Make a char array to store the ciphertext
    char newstr[length + 1]; // +1 for null terminator

    for (int i = 0; i < length; i++)
    {
        if (isalpha(plain[i]))
        {
            char base = isupper(plain[i]) ? 'A' : 'a';
            newstr[i] = (plain[i] - base + number) % 26 + base;
        }
        else
        {
            newstr[i] = plain[i];
        }
    }

    newstr[length] = '\0'; // null-terminate the string

    printf("ciphertext: %s\n", newstr);
    return 0;
}

bool is_numeric(string s)
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit(s[i]))
        {
            return false;
        }
    }
    return true;
}
