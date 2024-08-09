#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // The user is asked how many cents they will receive
    int cents = get_cents();

    // Calculate the number of quarters to give to the user
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of tens to give to the user
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of 5s to give to the user
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of cents to give to the user
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Calculate the total number of coins
    int coins = quarters + dimes + nickels + pennies;

    // Print the total number of coins to give to the user
    printf("Total number of coins to be given to the user: %i\n", coins);

    return 0;
}

int get_cents(void)
{
    int cents;
    // Ask again until a valid input is received from the user
    while (1)
    {
        printf("How many cents are owed? ");
        if (scanf("%d", &cents) == 1 && cents >= 0)
        {
            break;
        }
        else
        {
            // If there is an invalid entry, clear the buffer and try again
            printf("Invalid input. Please enter a non-negative integer.\n");
            while (getchar() != '\n'); // Clear input buffer
        }
    }
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
