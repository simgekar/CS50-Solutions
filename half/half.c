// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    float pay_amount = 0.0;
    float tax_amount = bill * tax / 100;
    pay_amount = bill + tax_amount;
    float tip_amount = pay_amount * tip / 100;
    pay_amount = pay_amount + tip_amount;
    pay_amount = pay_amount / 2;
    return pay_amount;
}
// SOLVED
