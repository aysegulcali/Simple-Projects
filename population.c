#include <stdio.h>

int main(void)
{
    // Prompt for start size
    int startSize;
    printf("Enter the starting population of the Sumatran Orangutan: ");
    while (scanf("%d", &startSize) != 1 || startSize < 9)
    {
        printf("Invalid input. Enter a number greater than or equal to 9: ");
        while (getchar() != '\n'); // Clear invalid input from the buffer
    }

    // Prompt for end size
    int endSize;
    printf("Enter the ending population of the Sumatran Orangutan: ");
    while (scanf("%d", &endSize) != 1 || endSize < startSize)
    {
        printf("Invalid input. Enter a number greater than or equal to the starting population: ");
        while (getchar() != '\n'); // Clear invalid input from the buffer
    }

    // Calculate number of years until we reach threshold
    int years = 0;
    while (startSize < endSize)
    {
        startSize = startSize + (startSize / 3) - (startSize / 4);
        years++;
    }

    // Print number of years
    printf("Years: %i\n", years);

    return 0;
}
