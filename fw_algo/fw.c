#include <stdio.h>
#include <stdlib.h>

#define INF 99999

void floyd_warshall(int **graph, int num_vertices) {
  int i, j, k;
  for (k = 0; k < num_vertices; k++) {
    for (i = 0; i < num_vertices; i++) {
      for (j = 0; j < num_vertices; j++) {
        if (graph[i][k] + graph[k][j] < graph[i][j])
          graph[i][j] = graph[i][k] + graph[k][j];
      }
    }
  }
}

int main() {
  int num_vertices;
  printf("Enter the number of vertices: ");
  scanf("%d", &num_vertices);

  int **graph = (int **)malloc(num_vertices * sizeof(int *));
  for (int i = 0; i < num_vertices; i++)
    graph[i] = (int *)malloc(num_vertices * sizeof(int));

  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      scanf("%d", &graph[i][j]);
      if (i != j && graph[i][j] == 0)
        graph[i][j] = INF;
    }
  }

  floyd_warshall(graph, num_vertices);

  printf("Shortest distances between all pairs of vertices:\n");
  for (int i = 0; i < num_vertices; i++) {
    for (int j = 0; j < num_vertices; j++) {
      if (graph[i][j] == INF)
        printf("INF\t");
      else
        printf("%d\t", graph[i][j]);
    }
    printf("\n");
  }

  for (int i = 0; i < num_vertices; i++)
    free(graph[i]);
  free(graph);

  return 0;
}
