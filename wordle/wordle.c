#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>

// each of our text files contains 1000 words
#define LISTSIZE 1000

// values for colors and score (EXACT == right letter, right place; CLOSE == right letter, wrong place; WRONG == wrong letter)
#define EXACT 2
#define CLOSE 1
#define WRONG 0

// ANSI color codes for boxed in letters
#define GREEN   "\e[38;2;255;255;255;1m\e[48;2;106;170;100;1m"
#define YELLOW  "\e[38;2;255;255;255;1m\e[48;2;201;180;88;1m"
#define RED     "\e[38;2;255;255;255;1m\e[48;2;220;20;60;1m"
#define RESET   "\e[0;39m"

// user-defined function prototypes
char* get_guess(int wordsize);
int check_word(const char* guess, int wordsize, int status[], const char* choice);
void print_word(const char* guess, int wordsize, const int status[]);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    if (argc != 2)
    {
        printf("Usage: %s wordsize\n", argv[0]);
        return 1;
    }

    // Convert the command-line argument to an integer
    int wordsize = atoi(argv[1]);

    // Check if the argument is a valid wordsize (5, 6, 7, or 8)
    if (wordsize < 5 || wordsize > 8)
    {
        printf("Invalid wordsize. Please choose 5, 6, 7, or 8.\n");
        return 1;
    }

    // open correct file, each file has exactly LISTSIZE words
    char wl_filename[6];
    sprintf(wl_filename, "%i.txt", wordsize);
    FILE *wordlist = fopen(wl_filename, "r");
    if (wordlist == NULL)
    {
        printf("Error opening file %s.\n", wl_filename);
        return 1;
    }

    // load word file into an array of size LISTSIZE
    char options[LISTSIZE][wordsize + 1];

    for (int i = 0; i < LISTSIZE; i++)
    {
        fscanf(wordlist, "%s", options[i]);
    }

    // pseudorandomly select a word for this game
    srand(time(NULL));
    const char* choice = options[rand() % LISTSIZE];

    // allow one more guess than the length of the word
    int guesses = wordsize + 1;
    bool won = false;

    // print greeting, using ANSI color codes to demonstrate
    printf(GREEN"This is WORDLE50"RESET"\n");
    printf("You have %i tries to guess the %i-letter word I'm thinking of\n", guesses, wordsize);

    // main game loop, one iteration for each guess
    for (int i = 0; i < guesses; i++)
    {
        // obtain user's guess
        char* guess = get_guess(wordsize);

        // array to hold guess status, initially set to zero
        int status[wordsize];

        // Calculate score for the guess
        int score = check_word(guess, wordsize, status, choice);

        printf("Guess %i: ", i + 1);

        // Print the guess
        print_word(guess, wordsize, status);

        // if they guessed it exactly right, set terminate loop
        if (score == EXACT * wordsize)
        {
            won = true;
            free(guess);
            break;
        }

        free(guess);
    }

    // Print the game's result
    printf("Word was: %s\n", choice);

    if (won)
    {
        printf("Congratulations! You won!\n");
    }
    else
    {
        printf("Game Over. You're out of guesses.\n");
    }

    fclose(wordlist);
    return 0;
}

char* get_guess(int wordsize)
{
    // Allocate memory for the guess
    char* guess = malloc(wordsize + 1);
    if (guess == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    // ensure users actually provide a guess that is the correct length
    do
    {
        printf("Input a %d-letter word: ", wordsize);
        if (fgets(guess, wordsize + 2, stdin) == NULL)
        {
            printf("Error reading input.\n");
            free(guess);
            exit(1);
        }

        // Remove newline character from fgets if present
        size_t len = strlen(guess);
        if (len > 0 && guess[len - 1] == '\n')
        {
            guess[len - 1] = '\0';
        }
    }
    while (strlen(guess) != wordsize);

    return guess;
}

int check_word(const char* guess, int wordsize, int status[], const char* choice)
{
    int score = 0;

    // Per-letter score
    for (int i = 0; i < wordsize; i++)
    {
        if (guess[i] == choice[i])
        {
            status[i] = EXACT;
            score += EXACT;
        }
        else if (strchr(choice, guess[i]) != NULL)
        {
            status[i] = CLOSE;
            score += CLOSE;
        }
        else
        {
            status[i] = WRONG;
        }
    }

    return score;
}

void print_word(const char* guess, int wordsize, const int status[])
{
    for (int i = 0; i < wordsize; i++)
    {
        if (status[i] == EXACT)
        {
            printf(GREEN "%c" RESET, guess[i]);
        }
        else if (status[i] == CLOSE)
        {
            printf(YELLOW "%c" RESET, guess[i]);
        }
        else
        {
            printf(RED "%c" RESET, guess[i]);
        }
    }

    printf("\n");
}
