#include <stdio.h>
#include <stdbool.h>
#include <string.h>
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

void initCircularQueue(struct CircularQueue *queue)
{
    queue->front = queue->rear = NULL;
}

bool isEmpty(struct CircularQueue *queue)
{
    return queue->front == NULL;
}

void enQueue(struct CircularQueue *queue, int item)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = item;
    newNode->next = NULL;

    if (isEmpty(queue))
    {
        queue->front = queue->rear = newNode;
        newNode->next = newNode;
    }
    else
    {
        newNode->next = queue->front;
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int deQueue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty. Cannot Dequeue!.\n");
        return -1;
    }

    struct Node *temp = queue->front;

    if (queue->front == queue->rear)
    {
        queue->front = queue->rear = NULL;
    }
    else
    {
        queue->front = queue->front->next;
        queue->rear->next = queue->front;
    }
    int item = temp->data;
    free(temp);

    return item;
}

void displayCircularQueue(struct CircularQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty!.\n");
        return;
    }

    struct Node *current = queue->front;

    do
    {
        printf("%d ", current->data);
        current = current->next;
    } while (current != queue->front);
    printf("\n");
}

int main()
{
    struct CircularQueue circularQueue;

    initCircularQueue(&circularQueue);

    enQueue(&circularQueue, 10);
    enQueue(&circularQueue, 20);
    enQueue(&circularQueue, 30);
    enQueue(&circularQueue, 40);
    enQueue(&circularQueue, 50);
    enQueue(&circularQueue, 60);

    printf("\nCircular Queue after enqueue: ");
    displayCircularQueue(&circularQueue);

    deQueue(&circularQueue);

    printf("\nCircular Queue after dequeue: ");
    displayCircularQueue(&circularQueue);

    deQueue(&circularQueue);

    printf("\nCircular Queue after dequeue: ");
    displayCircularQueue(&circularQueue);
    return 0;
}