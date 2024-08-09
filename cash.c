#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask the user how many cents to pay
    int cents = get_cents();

    // Calculate the number of quarters to be given to the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give to the client
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of 5-cent coins that should be given to the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    //Calculate the number of 1-cent coins that should be given to the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    //Calculate total number of coins
    int coins = quarters + dimes + nickels + pennies;

    // Print the total number of coins that should be given to the customer
    printf("Change: %i\n", coins);

    return 0;
}

int get_cents(void)
{
    int cents;
    do
    {
        printf("How many cents are owed? ");
        scanf("%d", &cents);
    }
    while (cents < 0);
    return cents;
}

int calculate_quarters(int cents)
{
    return cents / 25;
}

int calculate_dimes(int cents)
{
    return cents / 10;
}

int calculate_nickels(int cents)
{
    return cents / 5;
}

int calculate_pennies(int cents)
{
    return cents;
}
