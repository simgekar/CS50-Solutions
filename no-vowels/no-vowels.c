// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>

string replace(string text);
int main(int argc, string argv[])
{

    if (argc != 2)
    {
        printf("Usage: ./no-vowels word\n");
        return 1;
    }
    string word = argv[1];
    string result = replace(word);
    printf("%s\n", result);
}

string replace(string text)
{
    string new_word = text; // In C we cannot initialize an empty string!!!!
    for (int j = 0; j < strlen(text); j++)
    {
        if (text[j] == 'a')     // In C while using char use single quotes (''), not double quotes("") 
        {
            new_word[j] = '6';
        }
        else if (text[j] == 'e')
        {
            new_word[j] = '3';
        }
        else if (text[j] == 'i')
        {
            new_word[j] = '1';
        }
        else if (text[j] == 'o')
        {
            new_word[j] = '0';
        }
        else
        {
            new_word[j] = text[j];
        }
    }
    return new_word;
}
