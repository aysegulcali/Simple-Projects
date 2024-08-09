#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount;
    float tax_percent;
    int tip_percent;

    // Get bill_amount, tax_percent and tip_percent from the user
    printf("Bill before tax and tip: ");
    if (scanf("%f", &bill_amount) != 1)
    {
        fprintf(stderr, "Invalid input for bill amount.\n");
        return 1;
    }

    printf("Sale Tax Percent: ");
    if (scanf("%f", &tax_percent) != 1)
    {
        fprintf(stderr, "Invalid input for tax percent.\n");
        return 1;
    }

    printf("Tip percent: ");
    if (scanf("%d", &tip_percent) != 1)
    {
        fprintf(stderr, "Invalid input for tip percent.\n");
        return 1;
    }

    // Print the calculated amount on the screen
    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));

    return 0;
}

// Calculation function
float half(float bill, float tax, int tip)
{
    // Total cost including tax and gratuity
    float total = bill * (1 + tax / 100) * (1 + tip / 100);
    // Cost per person
    return total / 2;
}
