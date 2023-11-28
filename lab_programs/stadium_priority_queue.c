#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <malloc.h>

struct Node
{
    char ticketHolderName[50];
    int ticketNo;
    int ticketPriority;
    struct Node *next;
};

struct StadiumPriorityQueue
{
    struct Node *front, *rear;
};

void initPriorityQueue(struct StadiumPriorityQueue *queue)
{
    queue->front = queue->rear = NULL;
}

bool isEmpty(struct StadiumPriorityQueue *queue)
{
    return queue->front == NULL;
}

void enQueue(struct StadiumPriorityQueue *queue, char *ticketHolderName, int ticketNo, int ticketPriority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    strcpy(newNode->ticketHolderName, ticketHolderName);
    newNode->ticketNo = ticketNo;
    newNode->ticketPriority = ticketPriority;
    newNode->next = NULL;

    if (isEmpty(queue) || ticketPriority < queue->front->ticketPriority)
    {
        newNode->next = queue->front;
        queue->front = newNode;

        if (queue->rear == NULL)
            queue->rear = newNode;
    }
    else
    {
        struct Node *current = queue->front;

        while (current->next != NULL && current->next->ticketPriority <= ticketPriority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

        if (current == queue->rear)
            queue->rear = newNode;
    }
}

int deQueue(struct StadiumPriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty. Cannot Dequeue!.\n");
        return -1;
    }

    struct Node *temp = queue->front;

    int item = temp->ticketNo;
    queue->front = queue->front->next;
    free(temp);

    return item;
}

void displayPriorityQueue(struct StadiumPriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty!.\n");
        return;
    }

    struct Node *current = queue->front;
    int counter = 0;

    printf("\n\nStadium Queue tickets: ");
    while (current != NULL && counter != 5)
    {
        if (current->ticketPriority == 1) {
            printf("\n(Name: %s), (Ticket no: %d), (Priority: VIP pass)", current->ticketHolderName, current->ticketNo);
            counter++;
        }
        else {
            printf("\n(Name: %s), (Ticket no: %d), (Priority: NORMAL pass)", current->ticketHolderName, current->ticketNo);
            counter++;
        }
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct StadiumPriorityQueue priorityQueue;
    int choice, ticketNo = 0, ticketPriority = 1;
    char ticketHolderName[30];

    initPriorityQueue(&priorityQueue);

    printf("\n||================================================================||");
    printf("\n|| STADIUM TICKET COUNTER RESERVATION SYSTEM USING PRIORITY QUEUE ||");
    printf("\n||================================================================||\n");

    printf("\n1. You wanna buy a ticket");
    printf("\n2. Cancel ticket");
    printf("\n3. Display the stadium ticket queue");
    printf("\n4. Exit\n");

    while (choice != 4)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n||================||");
            printf("\n|| TICKET COUNTER ||");
            printf("\n||================||\n");

            printf("\n1. VIP Pass");
            printf("\n2. Normal Ticket\n");

            printf("\nEnter your choice of ticket: ");
            scanf("%d", &ticketPriority);

            if (ticketPriority == 1)
            {
                ticketNo++;
                printf("\nEnter your name: ");
                scanf("%s", &ticketHolderName);

                enQueue(&priorityQueue, ticketHolderName, ticketNo, ticketPriority);
                printf("\n%s your VIP pass has been confirmed successfully. %d is your ticket number.", ticketHolderName, ticketNo);
                displayPriorityQueue(&priorityQueue);
            }
            else if (ticketPriority == 2)
            {
                ticketNo++;
                printf("\nEnter your name: ");
                scanf("%s", &ticketHolderName);

                enQueue(&priorityQueue, ticketHolderName, ticketNo, ticketPriority);
                printf("\n%s your normal ticket has been confirmed successfully. %d is your ticket number.", ticketHolderName, ticketNo);
                displayPriorityQueue(&priorityQueue);
            }
            else
            {
                printf("\nNo ticket available for the given option!...");
            }
            break;

        case 2:
            printf("Dequeued ticket no: %d\n", deQueue(&priorityQueue));
            displayPriorityQueue(&priorityQueue);
            break;

        case 3:
            displayPriorityQueue(&priorityQueue);
            break;

        case 4:
            return 0;
            break;

        default:
            break;
        }
    }

    return 0;
}