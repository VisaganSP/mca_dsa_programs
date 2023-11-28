// CIRCULAR QUEUE IMPLEMENTATION USING LINKED LIST
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct Node
{
    int data;
    struct Node *next;
};

struct CircularQueue
{
    struct Node *front, *rear;
};

void initCircularQueue(struct CircularQueue *cQueue)
{
    cQueue->front = cQueue->rear = NULL;
}

bool isEmpty(struct CircularQueue *cQueue)
{
    return cQueue->front == NULL;
}

void enQueue(struct CircularQueue *cQueue, int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(cQueue))
    {
        cQueue->front = cQueue->rear = newNode;
        newNode->next = newNode; // Point to itself to make it circular
    }
    else
    {
        newNode->next = cQueue->front;
        cQueue->rear->next = newNode;
        cQueue->rear = newNode;
    }
}

int deQueue(struct CircularQueue *cQueue)
{

    if (isEmpty(cQueue))
    {
        printf("\nCicular Queue is Empty!...");
        return -1;
    }

    struct Node *temp = cQueue->front;
    if (cQueue->front == cQueue->rear)
    {
        cQueue->front = cQueue->rear = NULL;
    }
    else
    {
        cQueue->front = cQueue->front->next;
        cQueue->rear->next = cQueue->front;
    }
    int item = temp->data;
    free(temp);

    return item;
}

void displayCircularQueue(struct CircularQueue *cQueue)
{

    if (isEmpty(cQueue))
    {
        printf("\nCircular Queue is Empty!...");
        return;
    }

    struct Node *current = cQueue->front;
    printf("\nCircular Queue elements are: ");
    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != cQueue->front);
    printf("\n");
}

int main()
{
    struct CircularQueue myCircularQueue;
    initCircularQueue(&myCircularQueue);

    enQueue(&myCircularQueue, 10);
    enQueue(&myCircularQueue, 20);
    enQueue(&myCircularQueue, 30);

    displayCircularQueue(&myCircularQueue);

    printf("Dequeued item: %d\n", deQueue(&myCircularQueue));
    printf("Dequeued item: %d\n", deQueue(&myCircularQueue));

    displayCircularQueue(&myCircularQueue);

    return 0;
}