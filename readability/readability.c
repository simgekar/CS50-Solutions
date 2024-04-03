#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text_message);
int count_words(string text_message);
int count_sentences(string text_message);
void print_index(int letter, int word, int sentence);

int main(void)
{
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);
    print_index(letters, words, sentences);
}

int count_letters(string text_message)
{
    int letters = 0;
    int length = strlen(text_message);
    for (int i = 0; i < length; i++)
    {
        if (isalpha(text_message[i]) != 0)
        {
            letters += 1;
        }
    }
    return letters;
}

int count_words(string text_message)
{
    int words = 1;
    int length = strlen(text_message);
    for (int i = 0; i < length; i++)
    {
        // Blank space's ascii value is 32
        if (text_message[i] == 32)
        {
            words += 1;
        }
    }
    return words;
}

int count_sentences(string text_message)
{
    int sentences = 0;
    int length = strlen(text_message);
    for (int i = 0; i < length; i++)
    {
        // dot's ascii value is 46 exclamation's ascii value is 33 question mark's ascii value is 63
        if (text_message[i] == 46 || text_message[i] == 33 || text_message[i] == 63)
        {
            sentences += 1;
        }
    }
    return sentences;
}
void print_index(int letter, int word, int sentence)
{
    float L;
    float S;
    float index;
    L = (float) letter / word * 100;
    S = (float) sentence / word * 100;
    index = 0.0588 * L - 0.296 * S - 15.8;
    index = round(index);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %.f\n", index);
    }
}