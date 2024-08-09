#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LENGTH 1024

int main(int argc, char *argv[])
{
    // Check if there is a command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Convert the command-line argument to an integer
    int key = atoi(argv[1]);

    // Check if the argument is a non-negative integer
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: %s key\n", argv[0]);
            return 1;
        }
    }

    // Print a message to indicate that the user needs to enter plaintext
    printf("The key for encryption is %d.\n", key);
    printf("Please enter the plaintext that you want to encrypt:\n");

    // Get user string
    char plaintext[MAX_LENGTH];
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n')
    {
        plaintext[len - 1] = '\0';
    }

    // Encrypt the plaintext using the Caesar cipher
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];

        if (isalpha(c))
        {
            char base = isupper(c) ? 'A' : 'a';
            char encrypted_char = (c - base + key) % 26 + base;
            printf("%c", encrypted_char);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");

    return 0;
}
