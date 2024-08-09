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
    // Initialize the list to NULL
    node *list = NULL;

    // Process each command-line argument
    for (int i = 1; i < argc; i++)
    {
        // Convert argument to integer
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

        // If the list is empty
        if (list == NULL)
        {
            // The new node is the only node in the list
            list = n;
        }
        // If the new number is less than the first number in the list
        else if (n->number < list->number)
        {
            // Insert the new node at the beginning of the list
            n->next = list;
            list = n;
        }
        else
        {
            // Traverse the list to find the correct insertion point
            node *ptr;
            for (ptr = list; ptr != NULL; ptr = ptr->next)
            {
                // If we are at the end of the list
                if (ptr->next == NULL)
                {
                    // Append the new node
                    ptr->next = n;
                    break;
                }

                // If the new number is less than the next node's number
                if (n->number < ptr->next->number)
                {
                    // Insert the new node in the middle of the list
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
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
