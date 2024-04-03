#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int i, j, k, l, m;
    do
    {
        m = get_int("Height: ");
    }
    while (m <= 0 || m >= 9);

    for (i = 1; i <= m; i++)
    {
        for (k = m - 1; k >= i; k--)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("  ");
        for (l = 1; l <= i; l++)
        {
            printf("#");
        }
        printf("\n");
    }
}