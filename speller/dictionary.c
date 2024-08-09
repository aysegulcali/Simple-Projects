// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Convert word to lowercase
    char lowercase_word[LENGTH + 1];
    for (int i = 0; word[i]; i++)
    {
        lowercase_word[i] = tolower(word[i]);
    }
    lowercase_word[strlen(word)] = '\0';

    // Calculate hash value to determine the bucket
    unsigned int bucket = hash(lowercase_word);

    // Traverse the linked list in the bucket
    node *cursor = table[bucket];
    while (cursor != NULL)
    {
        // Compare lowercase word with word in the linked list
        if (strcmp(lowercase_word, cursor->word) == 0)
        {
            return true; // Word found
        }
        cursor = cursor->next; // Move to the next node
    }

    return false; // Word not found
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // Initialize hash value to 0
    unsigned int hash_value = 0;

    // Calculate hash value using a simple algorithm
    for (int i = 0; word[i]; i++)
    {
        // Convert character to lowercase and add its ASCII value to hash
        hash_value = (hash_value << 2) ^ tolower(word[i]);
    }

    // Reduce the hash value to fit within the number of buckets
    return hash_value % N;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false; // Return false if file cannot be opened
    }

    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        table[i] = NULL;
    }

    // Buffer to store each word read from the dictionary
    char word[LENGTH + 1];

    // Read words from the dictionary and insert into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        // Create a new node for the word
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            fclose(file);
            return false; // Return false if memory cannot be allocated
        }

        // Copy the word into the new node
        strcpy(new_node->word, word);

        // Calculate the bucket index for the word
        unsigned int bucket = hash(word);

        // Insert the new node at the beginning of the linked list
        new_node->next = table[bucket];
        table[bucket] = new_node;
    }

    fclose(file); // Close the dictionary file

    return true; // Return true to indicate success
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int total_words = 0;

    // Iterate through each bucket
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            total_words++;
            cursor = cursor->next;
        }
    }

    return total_words;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // Iterate through each bucket
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }

    return true; // Successfully unloaded
}
