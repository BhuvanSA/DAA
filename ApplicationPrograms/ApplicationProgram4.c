#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Structure to represent an edge
struct Edge
{
  int source, destination, weight;
};

// Structure to represent a graph
struct Graph
{
  int V, E;           // V = number of vertices, E = number of edges
  struct Edge *edges; // Array of edges
};

// Function to create a graph with V vertices and E edges
struct Graph *createGraph(int V, int E)
{
  struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
  graph->V = V;
  graph->E = E;
  graph->edges = (struct Edge *)malloc(E * sizeof(struct Edge));
  return graph;
}

// Function to perform the Bellman-Ford algorithm
void bellmanFord(struct Graph *graph, int source)
{
  int V = graph->V;
  int E = graph->E;
  int distances[V];

  // Initialize distances to a maximum value
  for (int i = 0; i < V; i++)
  {
    distances[i] = INT_MAX;
  }
  distances[source] = 0;

  // Relaxation step
  for (int i = 1; i <= V - 1; i++)
  {
    for (int j = 0; j < E; j++)
    {
      int u = graph->edges[j].source;
      int v = graph->edges[j].destination;
      int weight = graph->edges[j].weight;

      if (distances[u] != INT_MAX && distances[u] + weight < distances[v])
      {
        distances[v] = distances[u] + weight;
      }
    }
  }

  // Check for negative-weight cycles
  for (int i = 0; i < E; i++)
  {
    int u = graph->edges[i].source;
    int v = graph->edges[i].destination;
    int weight = graph->edges[i].weight;

    if (distances[u] != INT_MAX && distances[u] + weight < distances[v])
    {
      printf("Graph contains negative-weight cycle!\n");
      return;
    }
  }

  // Print the shortest distances
  printf("Shortest distances from source %d:\n", source);
  for (int i = 0; i < V; i++)
  {
    printf("To vertex %d: %d\n", i, distances[i]);
  }
}

int main()
{
  int V = 5; // Number of vertices
  int E = 8; // Number of edges
  struct Graph *graph = createGraph(V, E);

  // Example edges: source, destination, weight
  graph->edges[0] = (struct Edge){0, 1, -1};
  graph->edges[1] = (struct Edge){0, 2, 4};
  graph->edges[2] = (struct Edge){1, 2, 3};
  graph->edges[3] = (struct Edge){1, 3, 2};
  graph->edges[4] = (struct Edge){1, 4, 2};
  graph->edges[5] = (struct Edge){3, 2, 5};
  graph->edges[6] = (struct Edge){3, 1, -1};
  graph->edges[7] = (struct Edge){4, 3, 3};

  int source = 0; // Source vertex
  bellmanFord(graph, source);

  return 0;
}
