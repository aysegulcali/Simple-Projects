#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#define MAX_LENGTH 1000  // Define maximum text length

// A simple rounding function
int round_number(float number)
{
    return (int)(number + 0.5);
}

int main(void)
{
    // Get user input
    char text[MAX_LENGTH];
    printf("Text: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        printf("Error reading input.\n");
        return 1;
    }

    // Remove newline character if present
    text[strcspn(text, "\n")] = '\0';

    // Count the number of letters, words, and sentences in the text
    int letters = 0;
    int words = 1;  // Start with 1 because the first word is not preceded by a space
    int sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        char c = text[i];

        if (isalpha(c))
        {
            letters++;
        }
        else if (c == ' ')
        {
            words++;
        }
        else if (c == '.' || c == '!' || c == '?')
        {
            sentences++;
        }
    }

    // Calculate the average number of letters and sentences
    float L = (float) letters / words * 100.0;
    float S = (float) sentences / words * 100.0;

    // Calculate the Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    // Round the index to the nearest integer using custom round function
    int rounded_index = round_number(index);

    // Print the grade level based on the rounded index
    if (rounded_index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (rounded_index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", rounded_index);
    }

    return 0;
}
