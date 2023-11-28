/*
 * write a program to check whether the given string is of the form X^nY^n+1, n>=1,
 * using stack data structure. Also validate the given string where always 'A' precedes 'B'.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define a stack structure
#define MAX_STACK_SIZE 100

struct Stack
{
    char items[MAX_STACK_SIZE];
    int top;
};

// Function to initialize the stack
void init(struct Stack *stack)
{
    stack->top = -1;
}

// Function to push an element onto the stack
void push(struct Stack *stack, char c)
{
    if (stack->top < MAX_STACK_SIZE - 1)
    {
        stack->items[++(stack->top)] = c;
    }
}

// Function to pop an element from the stack
char pop(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->items[(stack->top)--];
    }
    return '\0'; // Return null character if the stack is empty
}

bool isXnYnPlus1(char *str)
{
    struct Stack stack;
    char top;
    int len = strlen(str), ycount = 0;

    if (len < 3)
        return false;

    init(&stack);

    for (int i = 0; i < len; i++)
    {
        if (str[i] == 'X')
        {
            push(&stack, 'X');
        }
        else if (str[i] == 'Y')
        {
            top = pop(&stack);

            if (top == '\0')
                ycount++;
        }
        else
        {
            return false; // Characters other than X and Y
        }
    }

    if (top == 'X')
    {
        return false; // Invalid sequence
    }
    else if (stack.top == -1 && ycount == 1)
    {
        return true; // Valid sequence
    }
    else
    {
        return false; // Unmatched 'X'
    }
}

int main()
{
    char str[] = "Y";

    if (isXnYnPlus1(str))
    {
        printf("The string is of the form X^nY^n+1\n");
    }
    else
    {
        printf("The string is NOT of the form X^nY^n+1\n");
    }

    return 0;
}