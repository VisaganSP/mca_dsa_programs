#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct Node {
    char name[50];
    int age;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(char* name, int age) {
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->age = age;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void inOrderTraversel(struct Node *node) {
    if (node != NULL) {
        inOrderTraversel(node->left);
        printf("Name: %s Age: %d\n", node->name, node->age);
        inOrderTraversel(node->right);
    }
}

void preOrderTraversel(struct Node *node) {
    if (node != NULL) {
        printf("Name: %s Age: %d\n", node->name, node->age);
        preOrderTraversel(node->left);
        preOrderTraversel(node->right);
    }
}

struct Node *insert(struct Node *node, char* name, int age) {
    if (node == NULL)
        return createNode(name, age);

    if (age < node->age)
        node->left = insert(node->left, name, age);
    else if (age > node->age)
        node->right = insert(node->right, name, age);

    return node;
}

int main() {
    char name[50];
    int age;
    struct Node *root = NULL;
    printf("-1 to exit\n");
    while(age != 0) {
        printf("\nEnter your age: ");
        scanf("%d", &age);

        printf("\nEnter your name: ");
        scanf("%s", &name);

        insert(root, name, age);
    }

    // insert(root, "Nancy", 15);
    // insert(root, "Alice", 19);
    // insert(root, "Abc", 3);
    // insert(root, "def", 12);
    // insert(root, "fdgf", 10);

    inOrderTraversel(root);
    printf("\n\n");
    preOrderTraversel(root);

    return 0;
}