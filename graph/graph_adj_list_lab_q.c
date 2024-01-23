#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

struct node
{
    int data;
    struct node *next;
};

struct graph
{
    int V;
    struct node **adjlist;
};

struct node *createnode(int data)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct graph *creategraph(int V)
{
    struct graph *g = (struct graph *)malloc(sizeof(struct graph));
    g->V = V;
    g->adjlist = (struct node **)malloc(V * sizeof(struct node *));
    for (int i = 0; i < V; ++i)
    {
        g->adjlist[i] = NULL;
    }
    return g;
}

void addedge(struct graph *g, int src, int dest)
{
    struct node *newnode = createnode(dest);
    newnode->next = g->adjlist[src];
    g->adjlist[src] = newnode;
}

void printgraph(struct graph *g)
{
    for (int i = 0; i < g->V; ++i)
    {
        printf("Adjacency list of vertex %d:\n", i);
        struct node *current = g->adjlist[i];
        while (current)
        {
            printf(" -> %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

int countCyclesUtil(int v, int visited[], int parent, struct graph *g)
{
    visited[v] = 1;
    struct node *temp = g->adjlist[v];
    while (temp)
    {
        int n = temp->data;
        if (!visited[n])
        {
            if (countCyclesUtil(n, visited, v, g))
            {
                return 1;
            }
        }
        else if (n != parent)
        {
            return 1;
        }
        temp = temp->next;
    }
    return 0;
}

int countCycles(struct graph *g)
{
    int count = 0;
    int visited[MAX_VERTICES];
    for (int i = 0; i < g->V; i++)
    {
        visited[i] = 0;
    }
    for (int u = 0; u < g->V; u++)
    {
        if (!visited[u])
        {
            if (countCyclesUtil(u, visited, -1, g))
            {
                count++;
            }
        }
    }
    return count / 2;
}

int main()
{
    int choice, V, src, dest;
    printf("Enter no of vertices:");
    scanf("%d", &V);

    struct graph *g = creategraph(V);

    do
    {
        printf("\nMenu\n1. Add edge\n2. Print graph\n3. Count the cycles\n4. Exit\nEnter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter source and destination vertices:");
            scanf("%d %d", &src, &dest);
            addedge(g, src, dest);
            break;
        case 2:
            printgraph(g);
            break;
        case 3:
            printf("Number of cycles: %d\n", countCycles(g));
            break;
        case 4:
            exit(0);
        default:
            printf("Incorrect choice. Please enter correct choice!");
        }
    } while (choice != 4);
    return 0;
}