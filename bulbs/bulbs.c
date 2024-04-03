#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    // Get input from user
    string message = get_string("Message: ");
    int len_message = strlen(message);

    // Define bit array to keep all binary digit which are converted from ascii value
    int bit_arr[8];

    for (int i = 0; i < len_message; i++)
    {
        // Convert text into ascii
        int ascii = (int) (message[i]);

        // Convert ascii into binary
        for (int j = 0; j < BITS_IN_BYTE; j++)
        {
            int mod = ascii % 2;
            // append each digit to binary_arr
            bit_arr[j] = mod;
            ascii = ascii / 2;
        }

        // get digit values from bit_arr and send it print_bulb function backwards
        for (int k = BITS_IN_BYTE - 1; k >= 0; k--)
        {
            print_bulb(bit_arr[k]);
        }
        printf("\n");
    }
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
