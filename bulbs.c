#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);

int main(void)
{
    char message[1024]; // The string from which we will receive the user message (for example, 1024 characters)

    // Get user input
    printf("Enter a message: ");
    if (fgets(message, sizeof(message), stdin) == NULL)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    size_t len = strlen(message);
    if (len > 0 && message[len - 1] == '\n')
    {
        message[len - 1] = '\0';
    }

    // Loop through each character in the message
    for (size_t i = 0, n = strlen(message); i < n; i++)
    {
        char current_char = message[i];

        // Loop through each bit in the current character (8 bits in a byte)
        for (int j = BITS_IN_BYTE - 1; j >= 0; j--)
        {
            int bit = (current_char >> j) & 1;

            // Print the bulb representation for the bit
            print_bulb(bit);
        }

        // Print a newline after each byte of 8 symbols
        printf("\n");
    }

    return 0;
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}
