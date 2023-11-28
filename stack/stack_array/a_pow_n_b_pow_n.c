/*
 * write a program to check whether the given string is of the form A^nB^n, n>=1,
 * using stack data structure. Also validate the given string where always 'A' precedes 'B'.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ARR_SIZE 100

struct Stack
{
    char items[MAX_ARR_SIZE];
    int top;
};

void init(struct Stack *stack)
{
    stack->top = -1;
}

void push(struct Stack *stack, char c)
{
    if (stack->top < MAX_ARR_SIZE - 1)
    {
        stack->items[++(stack->top)] = c;
    }
    else
    {
        printf("Stack Overflow");
    }
}

char pop(struct Stack *stack)
{
    if (stack->top >= 0)
    {
        return stack->items[(stack->top)--];
    }
    return '\0';
}

bool isAnBn(char *str)
{
    struct Stack stack;
    char top;
    int length = strlen(str);

    if (length < 2)
        return false;

    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'A')
            push(&stack, str[i]);
        else if (str[i] == 'B')
        {
            top = pop(&stack);

            if (top != 'A')
                return false; // Invalid sequence
        }
        else
            return false; // Characters other than A and B
    }

    printf("TOP: %d", stack.top);

    if (stack.top == 0)
        return true; // Valid sequence
    else if (top == 'A')
        return false; // Invalid sequence
    else
        false; // Invalid sequence
}

int main()
{
    char str[50];

    printf("\nEnter the string: ");
    scanf("%s", &str);

    if (isAnBn(str))
        printf("\nCorrect form");
    else
        printf("\nIncorrect form");

    return 0;
}