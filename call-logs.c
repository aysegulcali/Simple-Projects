#include <stdio.h>
#include <string.h>

int main(void)
{
    // Prompt user for name
    char name[100];  // Adjust size as needed
    printf("Enter name: ");
    if (fgets(name, sizeof(name), stdin) == NULL)
    {
        fprintf(stderr, "Error reading name.\n");
        return 1;
    }

    // Remove the newline character from the input
    name[strcspn(name, "\n")] = '\0';

    // Prompt user for age
    int age;
    printf("Enter age: ");
    if (scanf("%d", &age) != 1)
    {
        fprintf(stderr, "Error reading age.\n");
        return 1;
    }

    // Prompt user for phone number
    int number;
    printf("Enter phone number: ");
    if (scanf("%d", &number) != 1)
    {
        fprintf(stderr, "Error reading phone number.\n");
        return 1;
    }

    // Print the collected information
    printf("Number: %d\n", number);
    printf("Age: %d\n", age);
    printf("Name: %s\n", name);

    return 0;
}
