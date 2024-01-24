#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 10

// Node structure for linked list
typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;

// Hash table structure
typedef struct {
    Node* table[TABLE_SIZE];
} HashTable;

// Hash function using the length of the key
int hash(char key[]) {
    return strlen(key) % TABLE_SIZE;
}

// Initialize hash table
void initializeHashTable(HashTable* ht) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        ht->table[i] = NULL;
    }
}

// Insert key-value pair into the hash table using separate chaining
void insert(HashTable* ht, char key[], int value) {
    int index = hash(key);

    // Create a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Copy key and value to the new node
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;

    // Insert the new node into the hash table using separate chaining
    if (ht->table[index] == NULL) {
        ht->table[index] = newNode;
    } else {
        // Add the new node at the beginning of the linked list
        newNode->next = ht->table[index];
        ht->table[index] = newNode;
    }
}

// Search for a key in the hash table and return its value
int search(HashTable* ht, char key[]) {
    int index = hash(key);
    Node* current = ht->table[index];

    // Traverse the linked list at the given index
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value; // Key found, return its value
        }
        current = current->next;
    }

    return -1; // Key not found
}

int main() {
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
