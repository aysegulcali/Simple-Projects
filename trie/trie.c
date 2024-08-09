#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_OF_ALPHABET 26
#define MAXCHAR 20

typedef struct node
{
    bool is_word;
    struct node *children[SIZE_OF_ALPHABET];
}
node;

// Function prototypes
bool check(const char *word);
bool unload(void);
void unloader(node *current);

// Root of trie
node *root;

// Buffer to read words into
char name[MAXCHAR];

int main(int argc, char *argv[])
{
    // Check for command line args
    if (argc != 2)
    {
        printf("Usage: ./trie infile\n");
        return 1;
    }

    // File with names
    FILE *infile = fopen(argv[1], "r");
    if (!infile)
    {
        printf("Error opening file!\n");
        return 1;
    }

    // Allocate root of trie
    root = malloc(sizeof(node));
    if (root == NULL)
    {
        fclose(infile);
        return 1;
    }

    root->is_word = false;
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        root->children[i] = NULL;
    }

    // Add words to the trie
    while (fscanf(infile, "%s", name) == 1)
    {
        node *cursor = root;

        for (int i = 0, n = strlen(name); i < n; i++)
        {
            int index = tolower(name[i]) - 'a';
            if (cursor->children[index] == NULL)
            {
                // Make node
                node *new_node = malloc(sizeof(node));
                if (new_node == NULL)
                {
                    fclose(infile);
                    unload();
                    return 1;
                }
                new_node->is_word = false;
                for (int j = 0; j < SIZE_OF_ALPHABET; j++)
                {
                    new_node->children[j] = NULL;
                }
                cursor->children[index] = new_node;
            }

            // Go to node which we may have just been made
            cursor = cursor->children[index];
        }

        // if we are at the end of the word, mark it as being a word
        cursor->is_word = true;
    }

    fclose(infile);

    // Prompt user for a word to check
    printf("Check word: ");
    if (fgets(name, sizeof(name), stdin) != NULL)
    {
        // Remove newline character from fgets
        size_t len = strlen(name);
        if (len > 0 && name[len - 1] == '\n')
        {
            name[len - 1] = '\0';
        }

        if (check(name))
        {
            printf("Found!\n");
        }
        else
        {
            printf("Not Found.\n");
        }
    }
    else
    {
        printf("Error reading input.\n");
        unload();
        return 1;
    }

    if (!unload())
    {
        printf("Problem freeing memory!\n");
        return 1;
    }

    return 0;
}

// Check if the word is in the trie
bool check(const char *word)
{
    node *cursor = root;
    for (int i = 0, n = strlen(word); i < n; i++)
    {
        int index = tolower(word[i]) - 'a';
        if (cursor->children[index] == NULL)
        {
            return false;
        }
        cursor = cursor->children[index];
    }
    return cursor != NULL && cursor->is_word;
}

// Unload trie from memory
bool unload(void)
{
    // The recursive function handles all of the freeing
    unloader(root);
    return true;
}

void unloader(node *current)
{
    // Iterate over all the children to see if they point to anything and go there if they do point
    for (int i = 0; i < SIZE_OF_ALPHABET; i++)
    {
        if (current->children[i] != NULL)
        {
            unloader(current->children[i]);
        }
    }

    // After we check all the children point to null we can get rid of the node
    free(current);
}
