#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 9

// Preferences and locked arrays
int preferences[MAX][MAX];
bool locked[MAX][MAX];

typedef struct
{
    int winner;
    int loser;
} pair;

char* candidates[MAX];
pair pairs[MAX * (MAX - 1) / 2];

int pair_count;
int candidate_count;

// Function prototypes
bool vote(int rank, const char* name, int ranks[]);
void record_preferences(int ranks[]);
void add_pairs(void);
void sort_pairs(void);
void lock_pairs(void);
void print_winner(void);

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        printf("Usage: tideman [candidate ...]\n");
        return 1;
    }

    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }

    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i] = argv[i + 1];
    }

    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            locked[i][j] = false;
        }
    }

    pair_count = 0;
    int voter_count;
    printf("Number of voters: ");
    if (scanf("%d", &voter_count) != 1 || voter_count < 1)
    {
        printf("Invalid number of voters.\n");
        return 1;
    }

    // Clear the newline left in buffer by scanf
    while (getchar() != '\n');

    for (int i = 0; i < voter_count; i++)
    {
        int ranks[candidate_count];

        for (int j = 0; j < candidate_count; j++)
        {
            char name[100]; // Assuming names won't be longer than 99 characters
            printf("Rank %i: ", j + 1);
            if (fgets(name, sizeof(name), stdin) == NULL)
            {
                printf("Error reading input.\n");
                return 1;
            }

            // Remove newline character from fgets
            size_t len = strlen(name);
            if (len > 0 && name[len - 1] == '\n')
            {
                name[len - 1] = '\0';
            }

            if (!vote(j, name, ranks))
            {
                printf("Invalid vote.\n");
                return 3;
            }
        }

        record_preferences(ranks);
        printf("\n");
    }

    add_pairs();
    sort_pairs();
    lock_pairs();
    print_winner();
    return 0;
}

bool vote(int rank, const char* name, int ranks[])
{
    int candidate_index = -1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i], name) == 0)
        {
            candidate_index = i;
            break;
        }
    }

    if (candidate_index == -1)
    {
        return false;
    }

    ranks[rank] = candidate_index;
    return true;
}

void record_preferences(int ranks[])
{
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            int preferred_candidate = ranks[i];
            int less_preferred_candidate = ranks[j];
            preferences[preferred_candidate][less_preferred_candidate]++;
        }
    }
}

void add_pairs(void)
{
    pair_count = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        for (int j = i + 1; j < candidate_count; j++)
        {
            if (preferences[i][j] > preferences[j][i])
            {
                pairs[pair_count].winner = i;
                pairs[pair_count].loser = j;
                pair_count++;
            }
            else if (preferences[i][j] < preferences[j][i])
            {
                pairs[pair_count].winner = j;
                pairs[pair_count].loser = i;
                pair_count++;
            }
        }
    }
}

void sort_pairs(void)
{
    for (int i = 0; i < pair_count - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < pair_count - i - 1; j++)
        {
            int strength_current = preferences[pairs[j].winner][pairs[j].loser];
            int strength_next = preferences[pairs[j + 1].winner][pairs[j + 1].loser];

            if (strength_current < strength_next)
            {
                pair temp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = temp;
                swapped = true;
            }
        }

        if (!swapped)
        {
            break;
        }
    }
}

bool is_cyclic(int start, int current, bool visited[])
{
    if (visited[current])
    {
        return current == start;
    }

    visited[current] = true;

    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[current][i] && is_cyclic(start, i, visited))
        {
            return true;
        }
    }

    return false;
}

void lock_pairs(void)
{
    for (int i = 0; i < pair_count; i++)
    {
        int winner = pairs[i].winner;
        int loser = pairs[i].loser;

        locked[winner][loser] = true;

        bool visited[candidate_count];
        for (int j = 0; j < candidate_count; j++)
        {
            visited[j] = false;
        }

        if (!is_cyclic(winner, winner, visited))
        {
            continue;
        }

        locked[winner][loser] = false;
    }
}

bool has_incoming_edges(int candidate_index)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (locked[i][candidate_index])
        {
            return true;
        }
    }
    return false;
}

void print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (!has_incoming_edges(i))
        {
            printf("%s\n", candidates[i]);
            return;
        }
    }
}
