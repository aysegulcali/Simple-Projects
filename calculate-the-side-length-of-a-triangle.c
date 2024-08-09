#include <stdio.h>
#include <stdbool.h>

// Function prototype for checking if a triangle is valid
bool valid_triangle(float x, float y, float z);

int main(void)
{
    float x, y, z;

    // Prompt the user to enter the lengths of the sides of the triangle
    printf("Enter the length of the first side: ");
    scanf("%f", &x);

    printf("Enter the length of the second side: ");
    scanf("%f", &y);

    printf("Enter the length of the third side: ");
    scanf("%f", &z);

    // Check if the provided sides form a valid triangle
    if (valid_triangle(x, y, z))
    {
        printf("The sides form a valid triangle.\n");
    }
    else
    {
        printf("The sides do not form a valid triangle.\n");
    }

    return 0;
}

// Function to check if the given sides form a valid triangle
bool valid_triangle(float x, float y, float z)
{
    // Check if all sides are positive
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }

    // Check if the sum of any two sides is greater than the third side
    if (x + y <= z || x + z <= y || y + z <= x)
    {
        return false;
    }

    // If all checks pass, the triangle is valid
    return true;
}
