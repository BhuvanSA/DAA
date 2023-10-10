#include <stdbool.h>
#include <stdio.h>

#define MAX_VERTICES 100

void dfs(int vertex, int num_vertices, int graph[][MAX_VERTICES],
         bool visited[], int component[]) {
  visited[vertex] = true;
  component[vertex] = num_vertices;

  for (int i = 0; i < num_vertices; i++) {
    if (graph[vertex][i] && !visited[i]) {
      dfs(i, num_vertices, graph, visited, component);
    }
  }
}

int main() {
  int num_vertices;
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);

  int graph[MAX_VERTICES][MAX_VERTICES];
  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  bool visited[MAX_VERTICES] = {false};
  int component[MAX_VERTICES] = {0};
  int num_components = 0;

  for (int i = 0; i < num_vertices; i++) {
    if (!visited[i]) {
      num_components++;
      dfs(i, num_vertices, graph, visited, component);
    }
  }

  printf("Number of connected components: %d\n", num_components);
  for (int i = 1; i <= num_components; i++) {
    printf("Component %d:", i);
    for (int j = 0; j < num_vertices; j++) {
      if (component[j] == i) {
        printf(" %d", j);
      }
    }
    printf("\n");
  }

  return 0;
}
