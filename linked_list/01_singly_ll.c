#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
} *start = NULL;

struct node *create_linked_list(struct node *start)
{
    struct node *newNode, *ptr;
    int num;

    printf("\nEnter -1 to end");
    printf("\nEnter the data");
    scanf("%d", &num);

    while (num != -1)
    {
        newNode = (struct node *)malloc(sizeof(struct node));
        newNode->data = num;

        if (start == NULL)
        {
            start = newNode;
            newNode->next = NULL;
        }
        else
        {
            ptr = start;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = newNode;
            newNode->next = NULL;
        }

        printf("\nEnter the data");
        scanf("%d", &num);
    }

    return start;
}

struct node *display(struct node *start)
{
    struct node *ptr;

    ptr = start;
    while (ptr != NULL)
    {
        printf(" %d ", ptr->data);
        ptr = ptr->next;
    }
    return start;
}

struct node *insert_beg(struct node *start)
{
    struct node *newNode, ptr;
    int num;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &num);

    newNode->data = num;

    if (start == NULL)
    {
        start = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = start;
        start = newNode;
    }

    return start;
}

struct node *insert_end(struct node *start)
{
    struct node *newNode, *ptr;
    int num;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &num);
    newNode->data = num;

    ptr = start;
    while (ptr->next != NULL)
        ptr = ptr->next;

    ptr->next = newNode;
    newNode->next = NULL;

    return start;
}

struct node *insert_before(struct node *start)
{
    struct node *newNode, *preptr, *ptr;
    int num, val;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("Enter the value before you want to insert: ");
    scanf("%d", &val);
    newNode->data = num;

    ptr = start;
    while (ptr->data != val)
    {
        preptr = ptr;
        ptr = ptr->next;
    }
    preptr->next = newNode;
    newNode->next = ptr;

    return start;
}

struct node *insert_after(struct node *start)
{
    struct node *newNode, *ptr;
    int num, val;

    newNode = (struct node *)malloc(sizeof(struct node));

    printf("\nEnter the data: ");
    scanf("%d", &num);
    printf("\nEnter the value after you want to insert: ");
    scanf("%d", &val);

    newNode->data = num;

    ptr = start;
    while (ptr->data != val)
        ptr = ptr->next;

    newNode->next = ptr->next;
    ptr->next = newNode;

    return start;
}

struct node *delete_beg(struct node *start)
{
    struct node *ptr;

    ptr = start;
    if (start != NULL)
        start = start->next;
    free(ptr);

    return start;
}

struct node *delete_end(struct node *start)
{
    struct node *ptr, *preptr;

    if (start != NULL)
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = NULL;
        free(ptr);
    }
    return start;
}

struct node *delete_node(struct node *start)
{
    struct node *preptr, *ptr;
    int num;

    printf("\nEnter the data of the node you wanna delete: ");
    scanf("%d", &num);

    ptr = start;
    if (ptr->data == num)
    {
        start = delete_beg(start);
        return start;
    }
    else
    {
        while (ptr->data != num)
        {
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = ptr->next;
        free(ptr);
        return start;
    }
}

struct node *delete_list(struct node *start)
{
    struct node *ptr;

    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_beg(start);
            ptr = start;
        }
    }
}

struct node *sort_list(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;

    if (start != NULL)
    {
        ptr1 = start;
        while (ptr1->next != NULL)
        {
            ptr2 = ptr1->next;
            while (ptr2 != NULL)
            {
                if (ptr1->data > ptr2->data)
                {
                    temp = ptr1->data;
                    ptr1->data = ptr2->data;
                    ptr2->data = temp;
                }
                ptr2 = ptr2->next;
            }
            ptr1 = ptr1->next;
        }
    }

    return start;
}

int main()
{
    int option;

    do
    {
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a list");
        printf("\n 2: Display the list");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Add a node at the end");
        printf("\n 5: Add a node before a given node");
        printf("\n 6: Add a node after a given node");
        printf("\n 7: Delete a node from the beginning");
        printf("\n 8: Delete a node from the end");
        printf("\n 9: Delete a given node");
        printf("\n 10: Delete a node after a given node");
        printf("\n 11: Delete the entire list");
        printf("\n 12: Sort the list");
        printf("\n 13: Exit");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = create_linked_list(start);
            printf("\n LINKED LIST CREATED");
            break;
        case 2:
            start = display(start);
            break;
        case 3:
            start = insert_beg(start);
            break;
        case 4:
            start = insert_end(start);
            break;
        case 5:
            start = insert_before(start);
            break;
        case 6:
            start = insert_after(start);
            break;
        case 7:
            start = delete_beg(start);
            break;
        case 8:
            start = delete_end(start);
            break;
        case 9:
            start = delete_node(start);
            break;
        // case 10:
        //     start = delete_after(start);
        //     break;
        case 11:
            start = delete_list(start);
            printf("\n LINKED LIST DELETED");
            break;
        case 12:
            start = sort_list(start);
            break;
        }
    } while (option != 13);
    return 0;
}