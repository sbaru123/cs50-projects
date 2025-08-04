#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    string encrypt(string text, string key);
    string plaintext = "";
    string key = argv[1];

    if (argc != 2)
    {

        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < 26; i++)
    {
        if (!(isalpha(key[i])))
        {
            printf("The key can only contain letters.\n");
            return 1;
        }

        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("The key must have no duplicates\n");
                return 1;
            }
        }
    }

    plaintext = get_string("plaintext: ");
    string newtext = encrypt(plaintext, key);
    printf("ciphertext: %s\n", newtext);
    return 0;
}

string encrypt(string text, string key)
{

    string ciphertext = malloc(26);
    int index = 0;
    for (int i = 0; i < strlen(text); i++)
    {

        if (text[i] >= 97 && text[i] <= 122)
        {
            index = text[i] - 97;
            ciphertext[i] = tolower(key[index]);
        }
        else if (text[i] >= 65 && text[i] <= 90)
        {
            index = text[i] - 65;
            ciphertext[i] = toupper(key[index]);
        }
        else
        {
            ciphertext[i] = text[i];
        }
    }
    return ciphertext;
}
