#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

struct Node
{
    int data;
    int priority;
    struct Node *next;
};

struct PriorityQueue
{
    struct Node *front, *rear;
};

void initPriorityQueue(struct PriorityQueue *queue)
{
    queue->front = queue->rear = NULL;
}

bool isEmpty(struct PriorityQueue *queue)
{
    return queue->front == NULL;
}

void enQueue(struct PriorityQueue *queue, int data, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;

    if (isEmpty(queue) || priority < queue->front->priority)
    {
        newNode->next = queue->front;
        queue->front = newNode;

        if (queue->rear == NULL)
            queue->rear = newNode;
    }
    else
    {
        struct Node *current = queue->front;

        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;

        if (current == queue->rear)
            queue->rear = newNode;
    }
}

int deQueue(struct PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty. Cannot Dequeue!.\n");
        return -1;
    }

    struct Node *temp = queue->front;

    int item = temp->data;
    queue->front = queue->front->next;
    free(temp);

    return item;
}

void displayPriorityQueue(struct PriorityQueue *queue) {
    if (isEmpty(queue))
    {
        printf("\nQueue is Empty!.\n");
        return;
    }

    struct Node *current = queue->front;

    printf("\nPriority Queue elements: ");
    while(current != NULL) {
        printf("\n(%d, priority), (%d, data)", current->priority, current->data
        );
        current = current->next;
    }
    printf("\n");
}

int main()
{

    struct PriorityQueue priorityQueue;

    initPriorityQueue(&priorityQueue);

    enQueue(&priorityQueue, 10, 3);
    enQueue(&priorityQueue, 440, 3);
    enQueue(&priorityQueue, 450, 3);
    enQueue(&priorityQueue, 20, 5);
    enQueue(&priorityQueue, 50, 2);
    enQueue(&priorityQueue, 30, 6);
    enQueue(&priorityQueue, 40, 8);
    enQueue(&priorityQueue, 50, 1);

    displayPriorityQueue(&priorityQueue);

    printf("Dequeued item: %d\n", deQueue(&priorityQueue));

    displayPriorityQueue(&priorityQueue);

    printf("Dequeued item: %d\n", deQueue(&priorityQueue));

    displayPriorityQueue(&priorityQueue);

    printf("Dequeued item: %d\n", deQueue(&priorityQueue));

    displayPriorityQueue(&priorityQueue);
    printf("Dequeued item: %d\n", deQueue(&priorityQueue));

    displayPriorityQueue(&priorityQueue);

    return 0;
}