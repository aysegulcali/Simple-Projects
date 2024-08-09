#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function prototypes
char* read_input(const char* prompt);
char* capitalize_first_letter(const char* str);

int main(void)
{
    // Get user input
    char *a = read_input("Enter a value for 'a': ");
    if (a == NULL)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Allocate memory for another string
    char *b = malloc(strlen(a) + 1);
    if (b == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        free(a);  // Free the allocated memory before returning
        return 1;
    }

    // Copy and capitalize the first letter of the string
    strcpy(b, a);
    char *b_capitalized = capitalize_first_letter(b);

    // Print strings
    printf("a: %s\n", a);
    printf("b: %s\n", b_capitalized);

    // Free memory
    free(a);
    free(b_capitalized);

    return 0;
}

// Function to read input from the user
char* read_input(const char* prompt)
{
    // Print the prompt
    printf("%s", prompt);

    // Allocate initial buffer size
    size_t size = 128;
    char *buffer = malloc(size);
    if (buffer == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    // Read the input line
    if (fgets(buffer, size, stdin) == NULL)
    {
        free(buffer);
        return NULL;
    }

    // Check if buffer is too small and resize if necessary
    size_t length = strlen(buffer);
    while (buffer[length - 1] != '\n' && buffer[length - 1] != '\0')
    {
        size *= 2;
        char *new_buffer = realloc(buffer, size);
        if (new_buffer == NULL)
        {
            free(buffer);
            return NULL;
        }
        buffer = new_buffer;
        if (fgets(buffer + length, size - length, stdin) == NULL)
        {
            free(buffer);
            return NULL;
        }
        length = strlen(buffer);
    }

    // Remove the newline character if it exists
    if (buffer[length - 1] == '\n')
    {
        buffer[length - 1] = '\0';
    }

    return buffer;
}

// Function to capitalize the first letter of a string
char* capitalize_first_letter(const char* str)
{
    // Allocate memory for the capitalized string
    char *capitalized = malloc(strlen(str) + 1);
    if (capitalized == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    // Copy the original string
    strcpy(capitalized, str);

    // Capitalize the first letter
    if (strlen(capitalized) > 0)
    {
        capitalized[0] = toupper(capitalized[0]);
    }

    return capitalized;
}
