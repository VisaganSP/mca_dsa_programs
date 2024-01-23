#include <stdio.h>
#include <stdlib.h>

// Node structure to represent a vertex in the adjacency list
struct Node
{
    int dest;
    struct Node *next;
};

// Graph structure with an array of pointers to the adjacency lists
struct Graph
{
    int numVertices;
    struct Node **array;
};

// Function to create a new node with a given destination
struct Node *createNode(int dest)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph *createGraph(int numVertices)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Create an array of pointers to Node
    graph->array = (struct Node **)malloc(numVertices * sizeof(struct Node *));

    // Initialize each adjacency list as empty
    for (int i = 0; i < numVertices; ++i)
    {
        graph->array[i] = NULL;
    }

    return graph;
}

// Function to add a new vertex to the graph
void addVertex(struct Graph *graph)
{
    graph->numVertices++;
    graph->array = (struct Node **)realloc(graph->array, graph->numVertices * sizeof(struct Node *));
    graph->array[graph->numVertices - 1] = NULL;
}

// Function to add an edge to a directed graph
void addDirectedEdge(struct Graph *graph, int src, int dest)
{
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;
}

// Function to add an edge to an undirected graph
void addUndirectedEdge(struct Graph *graph, int src, int dest)
{
    // Add an edge from src to dest
    struct Node *newNode = createNode(dest);
    newNode->next = graph->array[src];
    graph->array[src] = newNode;

    // Since the graph is undirected, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->array[dest];
    graph->array[dest] = newNode;
}

// Function to print the adjacency list of the graph
void printGraph(struct Graph *graph)
{
    for (int i = 0; i < graph->numVertices; ++i)
    {
        struct Node *current = graph->array[i];
        printf("Adjacency list of vertex %d\n", i);
        while (current)
        {
            printf(" -> %d", current->dest);
            current = current->next;
        }
        printf("\n");
    }
}

// Driver program to test the above functions
int main()
{
    // Create a directed graph with 5 vertices
    struct Graph *directedGraph = createGraph(5);

    // Add directed edges to the graph
    addDirectedEdge(directedGraph, 0, 1);
    addDirectedEdge(directedGraph, 0, 4);
    addDirectedEdge(directedGraph, 1, 2);
    addDirectedEdge(directedGraph, 1, 3);
    addDirectedEdge(directedGraph, 1, 4);
    addDirectedEdge(directedGraph, 2, 3);
    addDirectedEdge(directedGraph, 3, 4);

    // Add a new vertex to the directed graph
    addVertex(directedGraph);

    // Print the directed graph
    printf("Directed Graph:\n");
    printGraph(directedGraph);
    printf("\n");

    // Create an undirected graph with 5 vertices
    struct Graph *undirectedGraph = createGraph(5);

    // Add undirected edges to the graph
    addUndirectedEdge(undirectedGraph, 0, 1);
    addUndirectedEdge(undirectedGraph, 0, 4);
    addUndirectedEdge(undirectedGraph, 1, 2);
    addUndirectedEdge(undirectedGraph, 1, 3);
    addUndirectedEdge(undirectedGraph, 1, 4);
    addUndirectedEdge(undirectedGraph, 2, 3);
    addUndirectedEdge(undirectedGraph, 3, 4);

    // Add a new vertex to the undirected graph
    addVertex(undirectedGraph);

    // Print the undirected graph
    printf("Undirected Graph:\n");
    printGraph(undirectedGraph);

    return 0;
}
