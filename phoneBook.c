#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// We created our own data types.
typedef struct
{
    char *name;
    char *number;
} person;

#define NUM_PEOPLE 3
#define MAX_LENGTH 100

// We have defined our own strdup function.
char *my_strdup(const char *str)
{
    // We allocate memory
    char *dup = malloc(strlen(str) + 1);
    if (dup == NULL)
    {
        return NULL; // If memory allocation fails
    }
    strcpy(dup, str); // Copy operation
    return dup;
}

int main(void)
{
    // We created and placed the person array
    person people[NUM_PEOPLE];

    // Dynamic memory allocation and personal information assignment
    people[0].name = my_strdup("Cansu");
    people[0].number = my_strdup("+1-617-495-1000");

    people[1].name = my_strdup("Murat");
    people[1].number = my_strdup("+1-949-468-2750");

    people[2].name = my_strdup("Ayşegül");
    people[2].number = my_strdup("+90-545-887-6423");

    // Name search
    char name[MAX_LENGTH];
    printf("Name: ");
    if (fgets(name, sizeof(name), stdin) != NULL)
    {
        // Remove newline character
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
        }

        // Name search
        for (int i = 0; i < NUM_PEOPLE; i++)
        {
            if (strcmp(people[i].name, name) == 0)
            {
                printf("Found. Person's number: %s\n", people[i].number);
                // Memory cleanup
                for (int j = 0; j < NUM_PEOPLE; j++)
                {
                    free(people[j].name);
                    free(people[j].number);
                }
                return 0;
            }
        }
    }
    printf("Not found\n");

    // Memory cleanup
    for (int j = 0; j < NUM_PEOPLE; j++)
    {
        free(people[j].name);
        free(people[j].number);
    }

    return 1;
}
