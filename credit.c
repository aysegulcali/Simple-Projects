#include <stdio.h>
#include <stdbool.h>

bool isLuhnValid(long long number)
{
    int sum = 0;
    bool doubleDigit = false;

    while (number > 0)
    {
        int digit = number % 10;

        if (doubleDigit)
        {
            digit *= 2;
            if (digit > 9)
            {
                digit = digit % 10 + digit / 10;
            }
        }

        sum += digit;
        doubleDigit = !doubleDigit;
        number /= 10;
    }

    return (sum % 10 == 0);
}

// Calculates and returns the number of digits in the given card number
int getNumDigits(long long number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 10;
        count++;
    }
    return count;
}

// Subtracts the starting digits
int getStartingDigits(long long number, int numDigits)
{
    while (numDigits > 2)
    {
        number /= 10;
        numDigits--;
    }
    return number;
}

int main(void)
{
    // Get card number from user
    long long number;
    printf("Number: ");
    scanf("%lld", &number);

    // Calculate the number of digits in the entered card number
    int numDigits = getNumDigits(number);

    // Extract the starting digits of the card number
    int startingDigits = getStartingDigits(number, numDigits);

    // Check if the card number is valid
    bool isValid = isLuhnValid(number);

    // Cards verification process
    if (isValid)
    {
        if (numDigits == 15 && (startingDigits == 34 || startingDigits == 37))
        {
            printf("AMEX\n");
        }
        else if (numDigits == 16 && (startingDigits >= 51 && startingDigits <= 55))
        {
            printf("MASTERCARD\n");
        }
        else if ((numDigits == 13 || numDigits == 16) && (startingDigits / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;
}
