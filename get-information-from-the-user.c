#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void)
{
    // Get name and place of residence from the user
    char name[MAX_LENGTH];
    char location[MAX_LENGTH];

    // Get information from the user to enter a name
    printf("What is your name? ");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Information is received from the user for entering the place where he/she lives
    printf("Where do you live? ");
    if (fgets(location, sizeof(location), stdin) == NULL)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // The fgets function also reads the newline character at the end of the entered text,
    // so a check is made to remove this character
    // Remove newline character for name
    size_t len = strlen(name);
    if (len > 0 && name[len - 1] == '\n')
    {
        name[len - 1] = '\0';
    }

    // Remove the newline character for the place of residence
    len = strlen(location);
    if (len > 0 && location[len - 1] == '\n')
    {
        location[len - 1] = '\0';
    }

    // Greeting by name and place of residence
    printf("Hello, %s, from %s!\n", name, location);

    return 0;
}
