#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(const char* word);

int main(void)
{
    // Define buffers to hold input words
    char word1[100];
    char word2[100];

    // Get input words from both players
    printf("Player 1: ");
    scanf("%99s", word1); // Read input for Player 1

    printf("Player 2: ");
    scanf("%99s", word2); // Read input for Player 2

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }

    return 0;
}

int compute_score(const char* word)
{
    int score = 0;
    int length = strlen(word);

    for (int i = 0; i < length; i++)
    {
        // Convert the letter to uppercase to match the POINTS array
        char letter = toupper(word[i]);

        // Check if the character is an uppercase letter (A-Z)
        if (letter >= 'A' && letter <= 'Z')
        {
            // Calculate the index in the POINTS array for the letter
            int index = letter - 'A';

            // Add the corresponding score for the letter to the total score
            score += POINTS[index];
        }
    }

    return score;
}
