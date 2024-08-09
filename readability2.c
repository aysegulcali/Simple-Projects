#include <stdio.h>
#include <string.h>
#include <ctype.h>

float calculate_readability(const char *text);
const char* get_class_level(float readability);

int main(void) {
    char text[1000];
    printf("Text: ");
    if (fgets(text, sizeof(text), stdin) == NULL)
    {
        fprintf(stderr, "Error reading input.\n");
        return 1;
    }

    // Remove end-of-line character from text
    text[strcspn(text, "\n")] = '\0';

    // Calculate Coleman-Liau index
    float readability = calculate_readability(text);

    // Print readability score
    printf("Readability: %.2f\n", readability);

    // Get and print the class level
    const char* class_level = get_class_level(readability);
    printf("Class Level: %s\n", class_level);

    return 0;
}

float calculate_readability(const char *text)
{
    // Initialize to 1 to calculate the last word
    int letters = 0;
    int words = 1; // Initialize to count the first word
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

    // Calculate Coleman-Liau index
    float index = 0.0588 * L - 0.296 * S - 15.8;

    return index;
}

const char* get_class_level(float readability)
{
    if (readability >= 90)
    {
        return "Elementary School";
    }
    else if (readability >= 70)
    {
        return "Middle School";
    }
    else
    {
        return "High School";
    }
}
