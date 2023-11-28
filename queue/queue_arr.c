// QUEUE IMPLEMENTATION USING ARRAY
#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct Queue
{
    int data[MAX_SIZE];
    int front, rear;
};

void initQueue(struct Queue *q)
{
    q->front = q->rear = -1;
}

bool isEmpty(struct Queue *q)
{
    return q->front == -1 || q->front == q->rear;
}

bool isFull(struct Queue *q)
{
    return q->rear == MAX_SIZE - 1;
}

void enQueue(struct Queue *q, int item)
{
    if (isFull(q))
    {
        printf("\nQueue if full and can't able to enqueue!...");
        return;
    }

    if (isEmpty(q))
        q->front = 0;

    q->rear++;
    q->data[q->rear] = item;
}

int deQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty and can't able to dequeue");
        q->front = q->rear = -1;
        return -1;
    }

    int item = q->data[q->front];

    // if (q->front == q->rear)
    //     q->front = q->rear = -1;
    // else
    q->front++;

    return item;
}

int frontElement(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty!...");
        return -1;
    }
    else
    {
        return q->data[q->front];
    }
}

int rearElement(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty!...");
        return -1;
    }
    else
    {
        return q->data[q->rear];
    }
}

void displayQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("\nQueue is Empty!...");
        return;
    }
    else
    {
        printf("\nQueue Elements are: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
        printf("\n");
    }
}

// Clear the queue
void clearQueue(struct Queue *queue)
{
    initQueue(queue);
}

int main()
{
    struct Queue queue;
    initQueue(&queue);

    enQueue(&queue, 10);
    enQueue(&queue, 20);
    enQueue(&queue, 30);

    printf("Front element: %d\n", frontElement(&queue));
    printf("Rear element: %d\n", rearElement(&queue));

    displayQueue(&queue);

    printf("Dequeued item: %d\n", deQueue(&queue));

    displayQueue(&queue);

    clearQueue(&queue);

    displayQueue(&queue);

    return 0;
}