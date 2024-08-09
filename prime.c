#include <stdio.h>
#include <stdbool.h>

// Function prototype
bool prime(int number);

int main(void)
{
    int min;
    printf("Minimum: ");
    while (scanf("%d", &min) != 1 || min < 1)
    {
        printf("Invalid input. Please enter a number greater than 0: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    int max;
    printf("Maximum: ");
    while (scanf("%d", &max) != 1 || min >= max)
    {
        printf("Invalid input. Maximum must be greater than minimum: ");
        while (getchar() != '\n'); // Clear the input buffer
    }

    for (int i = min; i <= max; i++)
    {
        if (prime(i))
        {
            printf("%i\n", i);
        }
    }

    return 0;
}

// Function to determine if a number is prime
bool prime(int number)
{
    if (number <= 1)
    {
        return false;
    }
    if (number <= 3)
    {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0)
    {
        return false;
    }
    for (int i = 5; i * i <= number; i += 6)
    {
        if (number % i == 0 || number % (i + 2) == 0)
        {
            return false;
        }
    }
    return true;
}
