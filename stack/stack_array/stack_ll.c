// Updated

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct
{
    Node *top;
} Stack;

Node *createNode(char data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void initializeStack(Stack *stack)
{
    stack->top = NULL;
}

bool isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, char data)
{
    Node *newNode = createNode(data);
    if (newNode == NULL)
        return;

    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty. Cannot pop.\n");
        return '\0';
    }

    Node *temp = stack->top;
    stack->top = stack->top->next;
    char data = temp->data;
    free(temp);
    return data;
}

bool isValidString(char *str)
{
    Stack stack;
    initializeStack(&stack);
    int length = strlen(str);
    int countA = 0;
    int countB = 0;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'A')
        {
            countA++;
            push(&stack, 'A');
        }
        else if (str[i] == 'B')
        {
            countB++;
            if (isEmpty(&stack))
                return false;
            pop(&stack);
        }
        else
        {
            return false;
        }
    }

    return (countA > 0) && (countA == (countB + 1));
}

int main()
{
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);

    if (isValidString(str))
    {
        printf("The string is of the form ((A^(n+1)) * B^n) where n >= 1 and 'A' always precedes 'B'\n");
    }
    else
    {
        printf("The string is not of the specified form ((A^(n+1)) * B^n) where n >= 1 or 'A' does not precede 'B'\n");
    }

    return 0;
}