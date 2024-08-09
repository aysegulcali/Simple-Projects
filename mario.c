#include <stdio.h>

int main(void)
{
    int height;

    // Prompt user for height
    do
    {
        printf("Height: ");
        // Get height from user
        scanf("%d", &height);
    }
    while (height < 1 || height > 8);

    int i, j;
    for (i = 1; i <= height; i++)
    {
        // Space before the pyramid
        for (j = 1; j <= height - i; j++)
        {
            printf(" ");
        }

        // First pyramid
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }

        // Space between two pyramids
        printf("  ");

        // Second pyramid
        for (j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }

    return 0;
}
