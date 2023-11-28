#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct TreeNode
{
    char data;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *createNode(char data)
{
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

struct TreeNode *constructBinaryTree(const char *expr)
{
    struct TreeNode *stack[100];
    int top = -1;
    for (int i = 0; i < strlen(expr); i++)
    {
        struct TreeNode *newNode = createNode(expr[i]);
        if (isOperator(expr[i]))
        {
            if (top < 1)
            {
                printf("Invalid postfix expression.\n");
                exit(1);
            }
            newNode->right = stack[top--];
            newNode->left = stack[top--];
            // printf("pushed elememt: %c\n", stack[top]);
        }
        stack[++top] = newNode;

        if (top > -1)
        {
            printf("\nStack: ");
            for (int j = 0; j <= top; j++)
            {
                printf("%c", stack[j]->data);
            }
        }
    }
    if (top != 0)
    {
        printf("Invalid postfix expression.\n");
        exit(1);
    }
    return stack[top];
}

void printInfix(struct TreeNode *root)
{
    if (root)
    {

        printInfix(root->left);
        printf("%c", root->data);
        printInfix(root->right);
    }
}

void printPrefix(struct TreeNode *root)
{
    if (root)
    {
        printf("%c", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

void toPostfix(struct TreeNode *root)
{
    if (root)
    {
        toPostfix(root->left);
        toPostfix(root->right);
        printf("%c", root->data);
    }
}

void findParent(struct TreeNode *root, const char *exp, char data)
{
    struct TreeNode *parent = root;

    for (int i = 0; i < strlen(exp); i++)
    {
        if (exp[i] == data) {
            i++;
            for (int k = i; k < strlen(exp); k++) {
                if(isOperator(exp[k])) {
                    printf("\nParent: %c\n", exp[k]);
                    return;
                }
            }
        }
    }

}

int main()
{
    char postfixExpr[50];
    char charToFind;
    printf("Enter Expression as postfix string: ");
    scanf("%s", postfixExpr);

    struct TreeNode *root = constructBinaryTree(postfixExpr);

    printf("\nEnter character to find the parent if any: ");
    scanf(" %c", &charToFind);

    if (root)
    {
        // printf("\nInfix expression: ");
        // printInfix(root);
        // printf("\n");

        findParent(root, postfixExpr, charToFind);
    // printf("\n%c\n", parent->data);

        // printf("Prefix expression: ");
        // printPrefix(root);
        // printf("\n");

        printf("Postorder expression: ");
        toPostfix(root);
        printf("\n");

        // freeTree(root);
    }
    return 0;
}
