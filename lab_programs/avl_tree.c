#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    char key;
    struct Node *left;
    struct Node *right;
    int height;
};

int getHeight(struct Node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *createNode(char key)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

int getBalanceFactor(struct Node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

void inOrderTraversel(struct Node *node)
{
    if (node != NULL)
    {
        inOrderTraversel(node->left);
        printf("Node: %c Balance factor: %d\n", node->key, getBalanceFactor(node));
        inOrderTraversel(node->right);
    }
}

bool isHeightBalanced(struct Node *node)
{
    if (node == NULL)
        return true;

    if (abs(getBalanceFactor(node)) <= 1 && isHeightBalanced(node->left) && isHeightBalanced(node->right))
        return true;

    return false;
}

char *suggestRotation(struct Node *node)
{
    int balanceF = getBalanceFactor(node);

    // LL Rotation case
    if (balanceF > 1)
    {
        return "LL Rotation or RL Rotation";
    }
    // RR Rotaion case
    else if (balanceF < -1)
    {
        return "RR Rotation or LR Rotation";
    }
}

struct Node *insert(struct Node *node, char key)
{
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    node->height = 1 + max(getHeight(node->left), getHeight(node->right));
    // int balance = getBalanceFactor(node);

    return node;
}

int main()
{
    int height = 0;
    struct Node *root = createNode('D');
    insert(root, 'F');
    insert(root, 'G');
    insert(root, 'C');
    insert(root, 'B');
    insert(root, 'A');
    // Left Sub Tree
    // root->height = height++;
    // root->right = createNode('F');
    // root->right->height = height++;
    // root->right->left = createNode('G');
    // root->right->left->height = height++;
    // root->left = createNode('B');
    // root->left->left = createNode('A');
    // root->left->right = createNode('C');
    // // Right Sub Tree
    // root->right = createNode('F');
    // root->right->left = createNode('E');
    // root->right->right = createNode('G');
    // root->right->right->right = createNode('H');
    // root->right->right->right->right = createNode('I');

    inOrderTraversel(root);

    if (isHeightBalanced(root))
    {
        printf("The given tree is height balanced\n");
    }
    else
    {
        printf("The given tree is not height balanced\n");
        printf("The Suggested Rotation: %s\n", suggestRotation(root));
    }

    return 0;
}