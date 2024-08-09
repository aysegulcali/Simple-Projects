#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // Initially allocate a list of 3 elements
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        perror("Memory allocation failed");
        return 1;
    }

    // Initially fill the list
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // Resize the list to 4 elements
    int *tmp = realloc(list, 4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        perror("Memory resizing failed");
        return 1;
    }
    list = tmp;

    // Assign value to new element
    list[3] = 4;

    // Print list
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n", list[i]);
    }

    // Free up memory space
    free(list);

    return 0;
}
