// QUEUE IMPLEMENTATION USING LINKED LIST
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct Node
{
    int data;
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

void enQueue(struct Queue *q, int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = item;
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
        printf("\nQueue is Empty! Cannot dequeue!...");
        return -1;
    }

    struct Node *temp = q->front;

    int item = temp->data;
    q->front = q->front->next;
    free(temp);

    if (q->front == NULL)
        q->rear = NULL;

    return item;
}

// Display the front element of the queue
int frontElement(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

// Display the rear element of the queue
int rearElement(struct Queue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return -1;
    }
    return queue->rear->data;
}

void displayQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty!...");
        return;
    }

    struct Node *current = q->front;

    printf("\nQueue Elements are:");
    while (current != NULL)
    {
        printf(" %d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct Queue myQueue;
    initQueue(&myQueue);

    enQueue(&myQueue, 10);
    enQueue(&myQueue, 20);
    enQueue(&myQueue, 30);

    displayQueue(&myQueue);

    printf("Front element: %d\n", frontElement(&myQueue));
    printf("Rear element: %d\n", rearElement(&myQueue));

    printf("Dequeued item: %d\n", deQueue(&myQueue));

    displayQueue(&myQueue);

    return 0;
}