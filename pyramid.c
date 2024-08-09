#include <stdio.h>

// Function prototype to draw a pyramid of height n
void draw(int n);

int main(void)
{
    int height;

    // Prompt the user for the height of the pyramid
    printf("Height: ");
    scanf("%d", &height);

    // Draw the pyramid
    draw(height);

    return 0;
}

void draw(int n)
{
    // If nothing to draw
    if (n <= 0)
    {
        return;
    }

    // Draw pyramid of height n - 1
    draw(n - 1);

    // Draw one more row of width n
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}
