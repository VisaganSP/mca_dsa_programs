
// write a c program that stimulates waiting list allotment in a train ticket reservation system.imagine total number of tickets available is 5. maintain a separate list for the extra requests and allot them a ticket whenever there is a cancellation. identify a suitable data structure and write procedure for the following:

// 1. Display the allotment,
// 2.Display waitlist details,
// 3.Cancellation and allotment

// ++++++++++++++++++++++++++++++++++++++++++++++++
#include <stdio.h>
#include <stdbool.h>

#define TOTAL_TICKETS 5
#define WAITLIST_SIZE 10

// Structure to represent a reservation
typedef struct
{
    int seatNumber;
    int bookingID;
} Reservation;

// Structure to represent a request in the waiting list
typedef struct
{
    int requestID;
} Request;

// Structure to represent a queue
typedef struct
{
    Request array[WAITLIST_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isQueueEmpty(Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
bool isQueueFull(Queue *queue)
{
    return ((queue->rear + 1) % WAITLIST_SIZE == queue->front);
}

// Function to enqueue a request into the queue
void enqueue(Queue *queue, int requestID)
{
    if (isQueueFull(queue))
    {
        printf("Waiting list is full. Cannot add request ID %d. Reservation system is full.\n", requestID);
        return;
    }

    if (isQueueEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % WAITLIST_SIZE;
    }

    queue->array[queue->rear].requestID = requestID;
    printf("Request ID %d added to the waiting list.\n", requestID);
}

// Function to dequeue a request from the queue
int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Waiting list is empty. Cannot dequeue.\n");
        return -1;
    }

    int requestID = queue->array[queue->front].requestID;

    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % WAITLIST_SIZE;
    }

    return requestID;
}

// Function to display the reservation status
void displayReservationStatus(Reservation *reservations)
{
    printf("Reservation Status (Seat Number, Booking ID):\n");
    for (int i = 0; i < TOTAL_TICKETS; i++)
    {
        printf("Seat %d: ", i + 1);
        if (reservations[i].bookingID != -1)
            printf("Booked (Booking ID: %d)\n", reservations[i].bookingID);
        else
            printf("Not booked\n");
    }
}

int main()
{
    Reservation reservations[TOTAL_TICKETS];
    for (int i = 0; i < TOTAL_TICKETS; i++)
    {
        reservations[i].seatNumber = i + 1;
        reservations[i].bookingID = -1;
    }

    Queue waitlist;
    initializeQueue(&waitlist);

    int choice;
    int requestID = 1;

    do
    {
        printf("\nMenu:\n");
        printf("1. Display Reservation Status\n");
        printf("2. Reserve a Ticket\n");
        printf("3. Cancel Reservation and Allot from Waiting List\n");
        printf("4. Display Waiting List Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayReservationStatus(reservations);
            break;

        case 2:
        {
            if (isQueueFull(&waitlist))
            {
                printf("Waiting list is full. Cannot add more requests. Reservation system is full.\n");
                break;
            }

            bool reserved = false;

            for (int i = 0; i < TOTAL_TICKETS; i++)
            {
                if (reservations[i].bookingID == -1)
                {
                    reservations[i].bookingID = requestID;
                    printf("Seat %d reserved successfully. Booking ID: %d\n", reservations[i].seatNumber, reservations[i].bookingID);
                    reserved = true;
                    break;
                }
            }

            if (!reserved)
            {
                enqueue(&waitlist, requestID);
                printf("All tickets are reserved. Adding request ID %d to the waiting list.\n", requestID);
            }

            requestID++;
        }
        break;

        case 3:
        {
            printf("Enter seat number to cancel reservation: ");
            int seatToCancel;
            scanf("%d", &seatToCancel);

            if (seatToCancel < 1 || seatToCancel > TOTAL_TICKETS)
            {
                printf("Invalid seat number. Please try again.\n");
                break;
            }

            if (reservations[seatToCancel - 1].bookingID != -1)
            {
                int cancelledBookingID = reservations[seatToCancel - 1].bookingID;
                printf("Seat %d reservation (Booking ID: %d) cancelled.\n", seatToCancel, cancelledBookingID);

                // Allot from the waiting list, if available
                if (!isQueueEmpty(&waitlist))
                {
                    int requestID = dequeue(&waitlist);
                    if (requestID != -1)
                    {
                        reservations[seatToCancel - 1].bookingID = requestID;
                        printf("Request ID %d allotted to seat %d.\n", requestID, seatToCancel);
                    }
                }
                else
                {
                    printf("Waiting list is empty. No requests to process.\n");
                }
            }
            else
            {
                printf("Seat %d is not reserved. No reservation to cancel.\n", seatToCancel);
            }
        }
        break;

        case 4:
            printf("Waiting List Details:\n");
            if (isQueueEmpty(&waitlist))
                printf("Waiting list is empty.\n");
            else
            {
                printf("Request IDs in the Waiting List:\n");
                int current = waitlist.front;
                while (current != -1)
                {
                    printf("%d ", waitlist.array[current].requestID);
                    current = (current + 1) % WAITLIST_SIZE;
                    if (current == (waitlist.rear + 1) % WAITLIST_SIZE)
                        break;
                }
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#include <stdio.h>
#include <stdbool.h>

#define TOTAL_TICKETS 5
#define WAITLIST_SIZE 10

// Structure to represent a reservation
typedef struct
{
    int seatNumber;
    int bookingID;
} Reservation;

// Structure to represent a request in the waiting list
typedef struct
{
    int requestID;
} Request;

// Structure to represent a queue
typedef struct
{
    Request array[WAITLIST_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initializeQueue(Queue *queue)
{
    queue->front = -1;
    queue->rear = -1;
}

// Function to check if the queue is empty
bool isQueueEmpty(Queue *queue)
{
    return (queue->front == -1 && queue->rear == -1);
}

// Function to check if the queue is full
bool isQueueFull(Queue *queue)
{
    return ((queue->rear + 1) % WAITLIST_SIZE == queue->front);
}

// Function to enqueue a request into the queue
void enqueue(Queue *queue, int requestID)
{
    if (isQueueFull(queue))
    {
        printf("Waiting list is full. Cannot add request ID %d.\n", requestID);
        return;
    }

    if (isQueueEmpty(queue))
    {
        queue->front = 0;
        queue->rear = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % WAITLIST_SIZE;
    }

    queue->array[queue->rear].requestID = requestID;
    printf("Request ID %d added to the waiting list.\n", requestID);
}

// Function to dequeue a request from the queue
int dequeue(Queue *queue)
{
    if (isQueueEmpty(queue))
    {
        printf("Waiting list is empty. Cannot dequeue.\n");
        return -1;
    }

    int requestID = queue->array[queue->front].requestID;

    if (queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % WAITLIST_SIZE;
    }

    return requestID;
}

// Function to display the reservation status
void displayReservationStatus(Reservation *reservations)
{
    printf("Reservation Status (Seat Number, Booking ID):\n");
    for (int i = 0; i < TOTAL_TICKETS; i++)
    {
        printf("Seat %d: ", i + 1);
        if (reservations[i].bookingID != -1)
            printf("Booked (Booking ID: %d)\n", reservations[i].bookingID);
        else
            printf("Not booked\n");
    }
}

int main()
{
    Reservation reservations[TOTAL_TICKETS];
    for (int i = 0; i < TOTAL_TICKETS; i++)
    {
        reservations[i].seatNumber = i + 1;
        reservations[i].bookingID = -1;
    }

    Queue waitlist;
    initializeQueue(&waitlist);

    int choice;
    int requestID = 1;

    do
    {
        printf("\nMenu:\n");
        printf("1. Display Reservation Status\n");
        printf("2. Reserve a Ticket\n");
        printf("3. Cancel Reservation and Allot from Waiting List\n");
        printf("4. Display Waiting List Details\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            displayReservationStatus(reservations);
            break;

        case 2:
        {
            bool reserved = false;

            for (int i = 0; i < TOTAL_TICKETS; i++)
            {
                if (reservations[i].bookingID == -1)
                {
                    reservations[i].bookingID = requestID;
                    printf("Seat %d reserved successfully. Booking ID: %d\n", reservations[i].seatNumber, reservations[i].bookingID);
                    reserved = true;
                    break;
                }
            }

            if (!reserved)
            {
                enqueue(&waitlist, requestID);
                printf("All tickets are reserved. Adding request ID %d to the waiting list.\n", requestID);
            }

            requestID++;
        }
        break;

        case 3:
        {
            printf("Enter seat number to cancel reservation: ");
            int seatToCancel;
            scanf("%d", &seatToCancel);

            if (seatToCancel < 1 || seatToCancel > TOTAL_TICKETS)
            {
                printf("Invalid seat number. Please try again.\n");
                break;
            }

            if (reservations[seatToCancel - 1].bookingID != -1)
            {
                int cancelledBookingID = reservations[seatToCancel - 1].bookingID;
                printf("Seat %d reservation (Booking ID: %d) cancelled.\n", seatToCancel, cancelledBookingID);

                // Allot from the waiting list, if available
                if (!isQueueEmpty(&waitlist))
                {
                    int requestID = dequeue(&waitlist);
                    if (requestID != -1)
                    {
                        reservations[seatToCancel - 1].bookingID = requestID;
                        printf("Request ID %d allotted to seat %d.\n", requestID, seatToCancel);
                    }
                }
                else
                {
                    printf("Waiting list is empty. No requests to process.\n");
                }
            }
            else
            {
                printf("Seat %d is not reserved. No reservation to cancel.\n", seatToCancel);
            }
        }
        break;

        case 4:
            printf("Waiting List Details:\n");
            if (isQueueEmpty(&waitlist))
                printf("Waiting list is empty.\n");
            else
            {
                printf("Request IDs in the Waiting List:\n");
                int current = waitlist.front;
                while (current != -1)
                {
                    printf("%d ", waitlist.array[current].requestID);
                    current = (current + 1) % WAITLIST_SIZE;
                    if (current == (waitlist.rear + 1) % WAITLIST_SIZE)
                        break;
                }
                printf("\n");
            }
            break;

        case 5:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 5);

    return 0;
}
// _________________________________________________________________________________________________

#include <stdio.h>

#define MAX_SIZE 10

struct Queue
{
    int data[MAX_SIZE];
    int front;
    int rear;
};

void initializeQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue *q)
{
    return (q->front == -1 && q->rear == -1);
}

int isFull(struct Queue *q)
{
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(struct Queue *q, int value)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    else if (isEmpty(q))
    {
        q->front = 0;
        q->rear = 0;
    }
    else
    {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->data[q->rear] = value;
}

int dequeue(struct Queue *q)
{
    int value;

    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    else if (q->front == q->rear)
    {
        value = q->data[q->front];
        q->front = -1;
        q->rear = -1;
    }
    else
    {
        value = q->data[q->front];
        q->front = (q->front + 1) % MAX_SIZE;
    }

    return value;
}

void reserveTicket(struct Queue *waitlist, int *availableTickets, int reservedTickets[])
{
    if (*availableTickets > 0)
    {
        (*availableTickets)--;
        int ticketNumber = MAX_SIZE - *availableTickets;
        reservedTickets[ticketNumber - 1] = 1;
        printf("Ticket %d reserved successfully.\n", ticketNumber);
    }
    else
    {
        if (!isFull(waitlist))
        {
            enqueue(waitlist, 1);
            printf("No available tickets. Added to waiting list. Ticket number will be %d.\n", waitlist->rear + 1);
        }
        else
        {
            printf("No available tickets and waiting list is full.\n");
        }
    }
}

void cancelReservation(struct Queue *waitlist, int *availableTickets, int reservedTickets[])
{
    if (*availableTickets < MAX_SIZE)
    {
        (*availableTickets)++;
        int ticketNumber = MAX_SIZE - *availableTickets;
        reservedTickets[ticketNumber - 1] = 0;
        printf("Ticket %d cancelled successfully.\n", ticketNumber);

        if (!isEmpty(waitlist))
        {
            ticketNumber = dequeue(waitlist);
            (*availableTickets)--;
            reservedTickets[ticketNumber - 1] = 1;
            printf("Ticket %d allocated to waiting list.\n", ticketNumber);
        }
    }
    else
    {
        printf("No tickets to cancel.\n");
    }
}

void displayWaitingList(struct Queue *waitlist)
{
    if (isEmpty(waitlist))
    {
        printf("Waiting list is empty.\n");
    }
    else
    {
        printf("Waiting list details:\n");
        int i = waitlist->front;
        while (i != waitlist->rear)
        {
            printf("Ticket %d\n", waitlist->data[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("Ticket %d\n", waitlist->data[i]);
    }
}

void displayReservedTickets(int reservedTickets[])
{
    printf("Reserved ticket details:\n");
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (reservedTickets[i] == 1)
        {
            printf("Ticket %d: Reserved\n", i + 1);
        }
    }
}

int main()
{
    struct Queue waitlist;
    initializeQueue(&waitlist);

    int availableTickets = MAX_SIZE;
    int reservedTickets[MAX_SIZE] = {0};
    int choice;

    do
    {
        printf("\n1. Reserve Ticket\n");
        printf("2. Cancel Reservation\n");
        printf("3. Display Waiting List Details\n");
        printf("4. Display Reserved Ticket Details\n");
        printf("5. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            reserveTicket(&waitlist, &availableTickets, reservedTickets);
            break;
        case 2:
            cancelReservation(&waitlist, &availableTickets, reservedTickets);
            break;
        case 3:
            displayWaitingList(&waitlist);
            break;
        case 4:
            displayReservedTickets(reservedTickets);
            break;
        case 5:
            printf("Quitting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}

// ___________________

#include <stdio.h>
#include <stdlib.h>

int count = 0, i;
struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = value;
    ptr->next = NULL;
    if ((front == NULL) && (rear == NULL))
    {
        front = rear = ptr;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
    }
    printf("Ticket with PNR = %d has been reserved\n\n", value);
    count++;
}

int dequeue()
{
    if (front == NULL)
    {
        printf("\nThere are no tickets in waiting queue\n\n");
        return -1;
    }
    else
    {
        struct node *temp = front;
        int temp_data = front->data;
        front = front->next;
        free(temp);
        return temp_data;
    }
    count--;
}

void displayAlloted()
{
    if ((front == NULL) && (rear == NULL))
    {
        printf("\nThere are no tickets in alloted queue\n\n");
    }
    else
    {
        printf("\nThe alloted queue is \n\n");
        struct node *temp;
        // temp = (struct node * ) malloc(sizeof(struct node));
        temp = front;
        i = 0;
        while (temp)
        {
            printf("TNtrPNR%d\n", temp->data);
            temp = temp->next;
            i++;
            if (i == 5)
                break;
        }
        printf("\n");
    }
}

void displayWaiting()
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if (count > 5)
    {
        temp = front;
        for (i = 0; i < 5; i++)
        {
            temp = temp->next;
        }
        printf("\nThe waiting queue is \n\n");
        while (temp)
        {
            printf("TNtrPNR%d\n", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
    else
    {
        printf("\nThere are no tickets in waiting queue\n\n");
    }
}

int main()
{
    int choice, value;
    printf("\nTrain ticket reservation\n\n");
    while (choice != 5)
    {
        printf("1. Book ticket\n2. Cancel ticket\n3. Display alloted list\n4. Display waiting list\n5. Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter ticket PNR: ");
            scanf("%d", &value);
            enqueue(value);
            break;
        case 2:
            printf("The ticket with PNR = %d has been cancelled\n", dequeue());
            break;
        case 3:
            displayAlloted();
            break;
        case 4:
            displayWaiting();
            break;
        case 5:
            exit(0);
            break;
        default:
            printf("\nWrong Choice\n");
        }
    }
    return 0;
}
