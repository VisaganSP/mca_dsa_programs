/*  C Program to Insert Delete Edges in a directed graph using Adjacency Matrix */

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int n;

void create_graph();
void display();
void insert_edge(int origin, int destin);
void del_edge(int origin, int destin);

int main()
{
    int choice, origin, destin;

    create_graph();

    while (1)
    {
        printf("\n1.Insert an edge\n");
        printf("2.Delete an edge\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("\nEnter your choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter an edge to be inserted : ");
            scanf("%d %d", &origin, &destin);
            insert_edge(origin, destin);
            break;
        case 2:
            printf("\nEnter an edge to be deleted : ");
            scanf("%d %d", &origin, &destin);
            del_edge(origin, destin);
            break;
        case 3:
            display();
            break;
        case 4:
            exit(1);
        default:
            printf("\nWrong choice\n");
            break;
        }
    }

    return 0;
}

void create_graph()
{
    int i, max_edges, origin, destin;

    printf("\nEnter number of vertices : ");
    scanf("%d", &n);

    max_edges = n * (n - 1); /*directed graph*/

    for (i = 1; i <= max_edges; i++)
    {
        printf("\nEnter edge %d(-1 -1) to quit : ", i);
        scanf("%d %d", &origin, &destin);
        if ((origin == -1) && (destin == -1))
            break;
        if (origin >= n || destin >= n || origin < 0 || destin < 0)
        {
            printf("\nInvalid edge!\n");
            i--;
        }
        else
            adj[origin][destin] = 1;
    }
}

void insert_edge(int origin, int destin)
{
    if (origin < 0 || origin >= n)
    {
        printf("\nOrigin vertex does not exist\n");
        return;
    }
    if (destin < 0 || destin >= n)
    {
        printf("\nDestination vertex does not exist\n");
        return;
    }
    adj[origin][destin] = 1;
}

void del_edge(int origin, int destin)
{
    if (origin < 0 || origin >= n || destin < 0 || destin >= n || adj[origin][destin] == 0)
    {
        printf("\nThis edge does not exist\n");
        return;
    }
    adj[origin][destin] = 0;
}

void display()
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%4d", adj[i][j]);
        printf("\n");
    }
}