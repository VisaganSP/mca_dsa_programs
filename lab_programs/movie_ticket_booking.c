#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_PRIZE 0

struct Node {
    int seatNumber;
    double ticketCharge;
    double popcornCharge;
    double beveragesCharge;
    char name[50];
    struct Node *next;
};

struct MovieTicketQueue {
    struct Node *front, *rear;
};

bool isEmpty(struct MovieTicketQueue *queue) {
    return queue->front == NULL;
}

void enQueue(struct MovieTicketQueue *queue, int seatNumber, char *name, double ticketCharge, double popcorncharge = 0, double beveragesCharge = 0) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->seatNumber = seatNumber;
    strcpy(newNode->name, name);
    newNode->next = NULL;

    if (isEmpty(queue)) {
        queue->front = queue->rear = newNode;
    } else {
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

int main()
{
    struct MovieTicketQueue movieTicketQueue;

    enQueue(&movieTicketQueue, 123, "Visagan");
    enQueue(&movieTicketQueue, 42, "Tamil");
    enQueue(&movieTicketQueue, 12, "Naveen");

    return 0;
}