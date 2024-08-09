#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    char name[100]; // Assuming candidate names won't exceed 99 characters
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, char name[]);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, char *argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %d\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        strncpy(candidates[i].name, argv[i + 1], sizeof(candidates[i].name));
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    // Get number of voters
    printf("Number of voters: ");
    if (scanf("%d", &voter_count) != 1 || voter_count > MAX_VOTERS)
    {
        printf("Invalid number of voters.\n");
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            char name[100]; // Buffer to hold the name
            printf("Rank %d: ", j + 1);
            scanf("%s", name);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, char name[])
{
    // Find the candidate with the given name
    int candidate_index = -1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && strcmp(candidates[i].name, name) == 0)
        {
            candidate_index = i;
            break;
        }
    }

    // If the candidate is not found or has already been eliminated, return false
    if (candidate_index == -1)
    {
        return false;
    }

    // Update the voter's preference for the given rank
    preferences[voter][rank] = candidate_index;

    return true;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // Reset the vote counts for each candidate before tabulating
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;
    }

    // Tabulate votes based on the first non-eliminated candidate on each voter's preference list
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];
            if (!candidates[candidate_index].eliminated)
            {
                // Assign the vote to the first non-eliminated candidate found in the voter's preference list
                candidates[candidate_index].votes++;

                // Stop counting votes for this voter
                break;
            }
        }
    }
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // Calculate the minimum number of votes needed to win (more than half of the total votes)
    int majority = voter_count / 2;

    // Find the candidate(s) with the most votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes > majority)
        {
            // Print the name of the winning candidate
            printf("%s\n", candidates[i].name);
            // Return true if winner is found
            return true;
        }
    }

    // No candidate has won the majority yet, return false
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // Initialize min_votes to a large value to make sure the first non-eliminated candidate's votes will be less than min_votes
    int min_votes = voter_count;

    // Find the minimum vote count among the remaining (non-eliminated) candidates
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes < min_votes)
        {
            min_votes = candidates[i].votes;
        }
    }
    return min_votes;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // Check if every remaining candidate has the same number of votes (equal to min)
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes != min)
        {
            // If any non-eliminated candidate has a different vote count, it's not a tie
            return false;
        }
    }

    // If all remaining candidates have the same vote count it's a tie
    return true;
}

// Eliminate the candidate (or candidates) with the fewest votes (equal to min)
void eliminate(int min)
{
    // Eliminate candidates who have min votes
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}
