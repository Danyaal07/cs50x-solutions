#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool check_duplicate(string str);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("ERROR | You must enter one command line argument\n");
        return 1;
    }

    string key = argv[1];

    // Check key length and if all characters are alphabetic
    if (strlen(key) != 26)
    {
        printf("ERROR | Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("ERROR | Key must only contain letters.\n");
            return 1;
        }
    }

    // Check for duplicates
    if (check_duplicate(key))
    {
        printf("Key must not contain duplicate letters.\n");
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    int len = strlen(plaintext);
    char ciphertext[len + 1]; // +1 for null terminator

    for (int i = 0; i < len; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            int index = tolower(c) - 'a';
            char substitute = key[index];

            if (isupper(c))
            {
                ciphertext[i] = toupper(substitute);
            }
            else
            {
                ciphertext[i] = tolower(substitute);
            }
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    ciphertext[len] = '\0'; // null terminate the string
    printf("ciphertext: %s\n", ciphertext);
    return 0;
}

bool check_duplicate(string str)
{
    bool seen[26] = { false };

    for (int i = 0; i < 26; i++)
    {
        char c = tolower(str[i]);
        int pos = c - 'a';

        if (seen[pos])
        {
            return true;
        }

        seen[pos] = true;
    }

    return false;
}
