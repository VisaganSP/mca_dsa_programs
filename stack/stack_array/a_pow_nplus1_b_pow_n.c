/*
 * write a program to check whether the given string is of the form A^n+1B^n, n>=1,
 * using stack data structure. Also validate the given string where always 'A' precedes 'B'.
 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

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
        printf("Stack Overflow!...");
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

bool isAnPlus1Bn(char *str)
{
    struct Stack stack;
    char top;
    int length = strlen(str);

    if (length < 3)
        return false;

    init(&stack);

    for (int i = 0; i < length; i++)
    {
        if (str[i] == 'A')
            push(&stack, str[i]);
        else if (str[i] == 'B')
        {
            printf("TOP: %d", stack.top);
            top = pop(&stack);

            if (top != 'A')
                return false;
        }
        else
            return false; // Characters other than A and B
    }

    if (stack.top == 0 && top == 'A')
        return true;
    else
        return false;
}

int main()
{
    char str[50];

    printf("\nEnter the string: ");
    scanf("%s", &str);

    if (isAnPlus1Bn(str))
        printf("\nCorrect form");
    else
        printf("\nIncorrect form");

    return 0;
}