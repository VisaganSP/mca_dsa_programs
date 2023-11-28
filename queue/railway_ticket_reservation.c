#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

#define MAX_TICKET_SIZE 6

struct Node
{
    int ticketNumber;
    struct Node *next;
};

struct Queue
{
    struct Node *front, *rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = NULL;
}

bool isEmpty(struct Queue *q)
{
    return q->front == NULL;
}

void enQueue(struct Queue *q, int ticketNumber)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->ticketNumber = ticketNumber;
    newNode->next = NULL;

    if (isEmpty(q))
    {
        q->front = q->rear = newNode;
    }
    else
    {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

int deQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty! Cannot dequeue");
        return -1;
    }

    struct Node *temp = q->front;

    int item = temp->ticketNumber;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
        q->rear = NULL;

    return item;
}

int frontElement(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty.");
        return -1;
    }
    return queue->front->ticketNumber;
}

int rearElement(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty.");
        return -1;
    }
    return queue->rear->ticketNumber;
}

void displayQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty.");
        return;
    }

    struct Node *current = q->front;

    while (current != NULL)
    {
        printf(" %d ", current->ticketNumber);
        current = current->next;
    }
    printf("\n");
}

void cancelTicketAndAllotFromWait(struct Queue *q, struct Queue *waitQ, int ticketNumberForCancel)
{
    int isTicketCancelled = 0;

    if (isEmpty(q))
    {
        printf("\nQueue is Empty!.");
        return;
    }
    else if (isEmpty(waitQ))
    {
        printf("\nWait list Queue is Empty!.");
        return;
    }

    struct Node *current = q->front;

    while (current != NULL)
    {
        if (current->ticketNumber == ticketNumberForCancel)
        {
            int firstWaitingPerson = deQueue(waitQ);

            current->ticketNumber = firstWaitingPerson;
            isTicketCancelled = 1;
            break;
        }
        else
        {
            isTicketCancelled = 0;
        }
        current = current->next;
    }

    if (isTicketCancelled == 1)
    {
        printf("\n\nTicket Cancelled successfully...");
        printf("\nAfter cancellation and waiting list first person ticket is added: ");
        displayQueue(q);
    }
    else
    {
        printf("\n\nCheck whether you've entered correct ticket number or not!");
    }
}

int main()
{
    struct Queue trainTicketQueue;
    struct Queue waitQueue;
    char passengerName[50];
    int trainTicketNumber = 0, choice, ticketNumberForCancel;

    initQueue(&trainTicketQueue);
    initQueue(&waitQueue);

    printf("\n||======================================||");
    printf("\n|| TRAIN TICKET RESERVATION USING QUEUE ||");
    printf("\n||======================================||");

    while (choice != 5)
    {
        printf("\n1. Display all the train ticket allotted ticket number");
        printf("\n2. Display all the waiting list passengers ticket number");
        printf("\n3. Allot train ticket or else in the waiting list");
        printf("\n4. Cancellation of allotted train ticket and allotment of the cancelled seat to a waiting list member");
        printf("\n5. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nTrain ticket number of allotted train ticket queue: ");
            displayQueue(&trainTicketQueue);
            break;

        case 2:
            printf("\nTrain ticket number of waiting lsit of train tickets queue: ");
            displayQueue(&waitQueue);
            break;

        case 3:
            printf("\nEnter passenger name to allot you a train ticket: ");
            scanf(" %s", &passengerName);

            if (trainTicketNumber < MAX_TICKET_SIZE)
            {
                trainTicketNumber++;
                enQueue(&trainTicketQueue, trainTicketNumber);
                printf("\n%s Ticket allotted successfully...\n", passengerName);
            }
            else
            {
                trainTicketNumber++;
                printf("\nAlready all the tickets were occupied!...You are in wait list management\n");
                enQueue(&waitQueue, trainTicketNumber);
            }
            break;

        case 4:
            printf("\nEnter your train ticket number to cancel the ticket that allotted for you : ");
            scanf("%d", &ticketNumberForCancel);

            cancelTicketAndAllotFromWait(&trainTicketQueue, &waitQueue, ticketNumberForCancel);
            break;

        case 5:
            return 0;
            break;
        }
    }

    return 0;
}