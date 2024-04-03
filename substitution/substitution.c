#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Checking if there are 26 characters
    int L = strlen(argv[1]);
    if (L != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Checking if characters are alphabetic
    for (int i = 0; i < L; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Each character must be alphabetic!\n");
            return 1;
        }
    }

    // Checking contain each letter once in Key
    for (int j = 0; j < L; j++)
    {
        for (int k = 0; k < L; k++)
        {
            if (j != k)
            {
                //Checking key if the same character included twice, i.e. "c" & "C" / "C" & "C" / "C" & "c"
                if (argv[1][j] == argv[1][k] || argv[1][j] == argv[1][k] + 32 || argv[1][j] == argv[1][k] - 32)
                {
                    printf("Contain each letter once.\n");
                    return 1;
                }
            }
        }
    }

    // Get plaintext from User
    string plaintext = get_string("plaintext: ");
    printf("ciphertext: ");

    for (int m = 0; m < strlen(plaintext); m++)
    {
        if (isalpha(plaintext[m]))
        {
            if (islower(plaintext[m]))
            {
                int normal_char = argv[1][plaintext[m] % 97];
                // if both are lower there is no problem
                if (islower(normal_char))
                {
                    printf("%c", normal_char);
                }
                // if plaintext is lower, key is upper it must print as a lower character
                else
                {
                    printf("%c", normal_char + 32);
                }
            }
            else if (isupper(plaintext[m]))
            {
                int normal_char2 = argv[1][plaintext[m] % 65];
                if (isupper(normal_char2))
                {
                    printf("%c", normal_char2);
                }
                // if plaintext is upper, key is lower it must print as a upper character
                else
                {
                    printf("%c", normal_char2 - 32);
                }
            }
        }
        // Non-alphabetical characters should be outputted unchanged.
        else
        {
            printf("%c", plaintext[m]);
        }
    }
    printf("\n");
    return 0;
}
