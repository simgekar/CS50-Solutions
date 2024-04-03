#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{

    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plain_text = get_string("plaintext: ");
    printf("ciphertext: ");

    // For each character in the plaintext:
    for (int j = 0; j < strlen(plain_text); j++)
    {
        // Rotate the character if it's a letter

        if (isupper(plain_text[j]))
        {
            printf("%c", ((plain_text[j] - 65 + key) % 26 + 65));
        }
        else if (islower(plain_text[j]))
        {
            printf("%c", ((plain_text[j] - 97 + key) % 26 + 97));
        }
        else
        {
            printf("%c", plain_text[j]);
        }
    }
    printf("\n");
    return 0;
}
