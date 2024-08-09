#include <stdio.h>
#include <stdlib.h>

// Implements a list of numbers with a dynamic size array
int main(void)
{
    // 3-dimensional list
    int *list = malloc(3 * sizeof(int));
    if (list == NULL)
    {
        return 1;
    }

    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // 4-dimensional list
    int *tmp = malloc(4 * sizeof(int));
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // Copy list 3 into list 4
    for (int i = 0; i < 3; i++)
    {
        tmp[i] = list[i];
    }

    // Add number to list of 4
    tmp[3] = 4;

    // Empty list of 3
    free(list);

    list = tmp;

    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // Empty list
    free(list);
    return 0;
}
