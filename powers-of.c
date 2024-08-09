#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    long n;

    // Prompt the user for array size
    do
    {
        printf("Array size: ");
        scanf("%ld", &n);
    }
    while (n < 1);

    // Allocate memory for the array
    long *size = malloc(n * sizeof(long));
    if (size == NULL)
    {
        // Handle memory allocation failure
        return 1;
    }

    // Initialize the first element of the array
    size[0] = 1;
    printf("%ld\n", size[0]);

    // Populate the array with values
    for (long i = 1; i < n; i++)
    {
        size[i] = 2 * size[i - 1];
        printf("%ld\n", size[i]);
    }

    // Free the allocated memory
    free(size);

    return 0;
}
