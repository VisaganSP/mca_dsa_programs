#include <stdio.h>
#include <string.h>

#define TABLE_SIZE 10

typedef struct
{
    char key[50];
    int value;
} KeyValuePair;

typedef struct
{
    KeyValuePair table[TABLE_SIZE];
} HashTable;

// Simple hash function using the length of the key
int hash(char key[])
{
    return strlen(key) % TABLE_SIZE;
}

// Insert key-value pair into the hash table using linear probing
void insert(HashTable *ht, char key[], int value)
{
    int index = hash(key);

    // Linear probing
    while (ht->table[index].value != 0)
    {
        index = (index + 1) % TABLE_SIZE;
    }
    printf("hash: %d\n", index);

    // Insert the key-value pair
    strcpy(ht->table[index].key, key);
    ht->table[index].value = value;
}

// Search for a key in the hash table and return its value
int search(HashTable *ht, char key[])
{
    int index = hash(key);

    // Linear probing to find the key
    while (strcmp(ht->table[index].key, key) != 0)
    {
        if (ht->table[index].value == 0)
        {
            return -1; // Key not found
        }
        index = (index + 1) % TABLE_SIZE;
    }

    return ht->table[index].value; // Key found, return its value
}

int main()
{
    HashTable myHashTable = {0}; // Initialize all values to 0

    // Insert some key-value pairs
    insert(&myHashTable, "John", 25);
    insert(&myHashTable, "Alice", 30);
    insert(&myHashTable, "Bob", 22);
    insert(&myHashTable, "Aob", 22);

    // Search for values
    printf("John's age: %d\n", search(&myHashTable, "John"));
    printf("Alice's age: %d\n", search(&myHashTable, "Alice"));
    printf("Bob's age: %d\n", search(&myHashTable, "Bob"));
    printf("Aob's age: %d\n", search(&myHashTable, "Aob"));
    printf("Unknown's age: %d\n", search(&myHashTable, "Unknown"));

    return 0;
}
