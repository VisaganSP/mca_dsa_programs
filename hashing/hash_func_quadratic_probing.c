#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Entry structure for hash table
typedef struct
{
    char key[50];
    int value;
} Entry;

// Hash table structure
typedef struct
{
    Entry *table[TABLE_SIZE];
} HashTable;

// Hash function using the length of the key
int hash(char key[])
{
    return strlen(key) % TABLE_SIZE;
}

// Initialize hash table
void initializeHashTable(HashTable *ht)
{
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        ht->table[i] = NULL;
    }
}

// Quadratic probing function to find the next available slot
int quadraticProbe(int index, int attempt, int size)
{
    return (index + attempt * attempt) % size;
}

// Insert key-value pair into the hash table using quadratic probing
void insert(HashTable *ht, char key[], int value)
{
    int index = hash(key);
    int attempt = 0;

    // Find the next available slot using quadratic probing
    while (ht->table[index] != NULL)
    {
        attempt++;
        index = quadraticProbe(index, attempt, TABLE_SIZE);
    }

    // Create a new entry
    Entry *newEntry = (Entry *)malloc(sizeof(Entry));
    if (newEntry == NULL)
    {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Copy key and value to the new entry
    strcpy(newEntry->key, key);
    newEntry->value = value;

    // Insert the new entry into the hash table
    ht->table[index] = newEntry;
}

// Search for a key in the hash table and return its value
int search(HashTable *ht, char key[])
{
    int index = hash(key);
    int attempt = 0;

    // Search for the key using quadratic probing
    while (ht->table[index] != NULL)
    {
        if (strcmp(ht->table[index]->key, key) == 0)
        {
            return ht->table[index]->value; // Key found, return its value
        }

        attempt++;
        index = quadraticProbe(index, attempt, TABLE_SIZE);
    }

    return -1; // Key not found
}

int main()
{
    HashTable myHashTable;
    initializeHashTable(&myHashTable);

    // Insert some key-value pairs
    insert(&myHashTable, "John", 25);
    insert(&myHashTable, "Alice", 30);
    insert(&myHashTable, "Bob", 22);
    insert(&myHashTable, "Dave", 40);

    // Search for values
    printf("John's age: %d\n", search(&myHashTable, "John"));
    printf("Alice's age: %d\n", search(&myHashTable, "Alice"));
    printf("Bob's age: %d\n", search(&myHashTable, "Bob"));
    printf("Dave's age: %d\n", search(&myHashTable, "Dave"));
    printf("Unknown's age: %d\n", search(&myHashTable, "Unknown"));

    return 0;
}
