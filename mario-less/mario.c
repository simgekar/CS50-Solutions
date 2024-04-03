#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, j, k, l;
    do
    {
        l = get_int("Height: ");
    }
    while (l <= 0 || l >= 9);

    for (i = 1; i <= l; i++)
    {
        for (k = l - 1; k >= i; k--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}