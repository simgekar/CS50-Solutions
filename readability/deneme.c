#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string text = get_string("Text: ");
    int length = strlen(text);
    int letters = 0;
    int words = 1;
    int sentences = 0;
    float L;
    float S;
    float index;
    for ( int i = 0 ; i < length; i++)
    {
        if (isalpha(text[i]) != 0)
        {
            letters += 1;
        }
        //space ascii value 32
        if(text[i] == 32)
        {
            words += 1;
        }
        //oh 46 exclamation 33 question mark 63
        if (text[i]==46 || text[i]==33 || text[i]==63)
        {
            sentences += 1;
        }
    }
    L = (float)letters / words * 100;
    S = (float)sentences / words * 100;
    index = 0.0588 * L  - 0.296 * S - 15.8;
    index = round(index);

    printf("Grade %.f\n",index);
}