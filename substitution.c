#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// Function prototypes
bool is_valid_key(const char* key);
char substitute_char(char c, const char* key);

int main(int argc, char* argv[])
{
    // Check for a single command-line argument
    if (argc != 2)
    {
        printf("Usage: %s key\n", argv[0]);
        return 1;
    }

    // Get the key from the command-line argument and validate it
    const char* key = argv[1];
    if (!is_valid_key(key))
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Get plaintext from the user
    char plaintext[1024]; // Buffer to hold the plaintext input
    printf("plaintext: ");
    if (fgets(plaintext, sizeof(plaintext), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove the newline character from fgets
    size_t len = strlen(plaintext);
    if (len > 0 && plaintext[len - 1] == '\n')
    {
        plaintext[len - 1] = '\0';
    }

    // Encrypt the plaintext to get the ciphertext
    printf("ciphertext: ");
    for (size_t i = 0, n = strlen(plaintext); i < n; i++)
    {
        char c = plaintext[i];
        printf("%c", isalpha(c) ? substitute_char(c, key) : c);
    }
    printf("\n");

    return 0;
}

bool is_valid_key(const char* key)
{
    int key_length = strlen(key);

    if (key_length != 26)
    {
        return false;
    }

    bool found[26] = {false};

    for (int i = 0; i < key_length; i++)
    {
        char c = tolower(key[i]);
        // Character classification functions with isalpha
        if (!isalpha(c))
        {
            return false;
        }

        int index = c - 'a';
        if (found[index])
        {
            return false;
        }

        found[index] = true;
    }

    return true;
}

char substitute_char(char c, const char* key)
{
    bool is_uppercase = isupper(c);
    char lower_c = tolower(c);
    int index = lower_c - 'a';
    char substitution = key[index];
    return is_uppercase ? toupper(substitution) : substitution;
}
