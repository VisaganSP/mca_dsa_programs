#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the linked list
struct Node
{
    int data;
    int priority;
    struct Node *next;
};

// Structure for the Priority Queue
struct PriorityQueue
{
    struct Node *front, *rear;
};

// Initialize an empty priority queue
void initPriorityQueue(struct PriorityQueue *queue)
{
    queue->front = queue->rear = NULL;
}

// Check if the priority queue is empty
bool isEmpty(struct PriorityQueue *queue)
{
    return queue->front == NULL;
}

// Enqueue (add) an element with priority to the priority queue
// Function to enqueue an element with a given priority
void enqueue(struct PriorityQueue *pq, int data, int priority)
{
    struct Node *newElement = (struct Node *)malloc(sizeof(struct Node));
    newElement->data = data;
    newElement->priority = priority;
    newElement->next = NULL;

    if (isEmpty(pq) || priority < pq->front->priority)
    {
        newElement->next = pq->front;
        pq->front = newElement;
        if (pq->rear == NULL)
        {
            pq->rear = newElement;
        }
    }
    else
    {
        struct Node *current = pq->front;
        while (current->next != NULL && current->next->priority <= priority)
        {
            current = current->next;
        }
        newElement->next = current->next;
        current->next = newElement;
        if (current == pq->rear)
        {
            pq->rear = newElement;
        }
    }
}

// Dequeue (remove) the element with the highest priority from the priority queue
int dequeue(struct PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    struct Node *temp = queue->front;
    int item = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return item;
}

// Display all elements in the priority queue
void displayPriorityQueue(struct PriorityQueue *queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        return;
    }
    printf("Priority Queue elements: ");
    struct Node *current = queue->front;
    while (current != NULL)
    {
        printf("(%d, Priority: %d) ", current->data, current->priority);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    struct PriorityQueue myPriorityQueue;
    initPriorityQueue(&myPriorityQueue);

    enqueue(&myPriorityQueue, 10, 2);
    enqueue(&myPriorityQueue, 20, 1);
    enqueue(&myPriorityQueue, 40, 1);
    enqueue(&myPriorityQueue, 30, 3);
    enqueue(&myPriorityQueue, 40, 0);

    displayPriorityQueue(&myPriorityQueue);

    printf("Dequeued item: %d\n", dequeue(&myPriorityQueue));

    displayPriorityQueue(&myPriorityQueue);

    printf("Dequeued item: %d\n", dequeue(&myPriorityQueue));

    displayPriorityQueue(&myPriorityQueue);

    return 0;
}
