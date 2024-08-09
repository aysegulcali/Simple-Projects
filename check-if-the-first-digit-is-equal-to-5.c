#include <stdio.h>

int main()
{
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Get the first digit
    int firstDigit = number;
    while (firstDigit >= 10)
    {
        firstDigit /= 10;
    }

    // Check if the first digit is equal to 5
    if (firstDigit == 5)
    {
        printf("The first digit is 5.\n");
    }
    else
    {
        printf("The first digit is not 5.\n");
    }

    return 0;
}