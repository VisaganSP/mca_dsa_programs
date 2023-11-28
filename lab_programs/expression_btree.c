#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_STACK_SIZE 100

struct TreeNode
{
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct Stack
{
    char *expression[MAX_STACK_SIZE];
    int top;
};

void initStack(struct Stack *stack)
{
    stack->top = -1;
}

void push(struct Stack *stack, char *symbol)
{
    if (stack->top < MAX_STACK_SIZE - 1)
    {
        stack->expression[++(stack->top)] = symbol;
    }
}

char *pop(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->expression[(stack->top)--];
    }
    return '\0'; // Return null character if the stack is empty
}

struct TreeNode *create(int value)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

void inorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%c ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    printf("%c ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct TreeNode *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%c ", root->data);
}

struct TreeNode *insertLeft(struct TreeNode *root, int value)
{
    root->left = create(value);
    return root->left;
}

struct TreeNode *insertRight(struct TreeNode *root, int value)
{
    root->right = create(value);
    return root->right;
}

struct TreeNode *getParent(struct TreeNode *root, struct TreeNode *child)
{
    if (root == NULL || child == NULL)
        return NULL;

    if (root->left == child || root->right == child)
        return root;

    struct TreeNode *leftParent = getParent(root->left, child);
    struct TreeNode *rightParent = getParent(root->right, child);

    // If the child is not found in either subtree
    if (leftParent == NULL && rightParent == NULL)
        return NULL;

    // If the child is found in the left subtree
    if (leftParent != NULL)
        return leftParent;

    // If the child is found in the right subtree
    return rightParent;
}

struct TreeNode *findNode(struct TreeNode *root, char data)
{
    if (root == NULL)
        return NULL;

    if (root->data == data)
        return root;

    struct TreeNode *leftResult = findNode(root->left, data);
    if (leftResult != NULL)
        return leftResult;

    return findNode(root->right, data);
}

void printAncestors(struct TreeNode *root, struct TreeNode *node)
{
    if (root == NULL || node == NULL)
        return;

    if (root == node)
        return; // Reached the target node, stop recursion

    if (root->left == node || root->right == node)
    {
        printf("%c ", root->data);
        return;
    }

    printAncestors(root->left, node);
    printAncestors(root->right, node);
}

struct TreeNode *constructExpressionTree(char *expression)
{
    char *operators = "+-*/";

    int len = strlen(expression);
    struct TreeNode *stack[len];
    int top = -1;

    for (int i = 0; i < len; i++)
    {
        char c = expression[i];
        if (strchr(operators, c))
        {
            struct TreeNode *right = stack[top--];
            struct TreeNode *left = stack[top--];
            struct TreeNode *new_node = create(c);
            new_node->left = left;
            new_node->right = right;
            stack[++top] = new_node;
        }
        else
        {
            stack[++top] = create(c);
        }
    }
    return stack[top];
}

// void freeTree(struct TreeNode* root) {
//     if (root) {
//         freeTree(root->left);
//         freeTree(root->right);
//         free(root);
//     }
// }

int main()
{
    // struct TreeNode *root = constructExpressionTree("ab+c*");
    // printf("Prefix expression: ");
    // inorderTraversal(root);
    // printf("\n");
    // printf("Postfix expression: ");
    // postorderTraversal(root);
    // printf("\n");
    // printf("Infix expression: ");
    // preorderTraversal(root);
    // printf("\n");
    // Construct your expression tree
    struct TreeNode *root = constructExpressionTree("ab+cd-*");
    inorderTraversal(root);

    // Example: Find the parent of the node with data 'b'
    struct TreeNode *nodeB = findNode(root, 'b');
    struct TreeNode *parentB = getParent(root, nodeB);

    if (parentB != NULL)
        printf("Parent of 'b' is: %c\n", parentB->data);
    else
        printf("'b' is the root or not found.\n");

    // Example: Find the ancestors of the node with data 'd'
    struct TreeNode *nodeD = findNode(root, 'd');

    printf("Ancestors of 'd': ");
    printAncestors(root, nodeD);
    return 0;
}