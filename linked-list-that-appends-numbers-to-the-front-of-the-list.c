#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // Initialize list to NULL
    node *list = NULL;

    // Process each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to int
        int number = atoi(argv[i]);

        // Allocate memory for a new node
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // Memory allocation failed
            return 1;
        }
        n->number = number;
        n->next = NULL;

        // Insert the new node at the beginning of the list
        n->next = list;
        list = n;
    }

    // Print the numbers in the list
    for (node *ptr = list; ptr != NULL; ptr = ptr->next)
    {
        printf("%d\n", ptr->number);
    }

    // Free the allocated memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    return 0;
}
