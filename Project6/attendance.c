// An attendance register is commonly used to keep track of students' presence in a class or an event.
//  Sorting the names in the attendance register alphabetically is essential for easy access and analysis.
// The task is to develop a program that takes a list of names in an attendance register as input and sorts them alphabetically using the quick sort algorithm.
//  The program should read the names from a file or accept user input, sort them, and display the sorted list of names.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to swap two memory locations
void swap(char **a, char **b)
{
  char *temp = *a;
  *a = *b;
  *b = temp;
}

int partition(char **arr, int low, int high)
{
  char *pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++)
  {
    if (strcmp(arr[j], pivot) < 0)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quicksort(char **arr, int low, int high)
{
  if (low < high)
  {
    int pi = partition(arr, low, high);
    quicksort(arr, low, pi - 1);
    quicksort(arr, pi + 1, high);
  }
}

int main(int argc, char *argv[])
{
  if (argc != 2)
  {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  FILE *file = fopen(argv[1], "r");
  if (file == NULL)
  {
    printf("Error opening file \n");
    return 1;
  }

    int n;
  printf("Enter the number of names: ");
  scanf("%d", &n);

  char **names = (char **)malloc(n * sizeof(char *));
  printf("Enter the names:\n");
  for (int i = 0; i < n; i++)
  {
    names[i] = (char *)malloc(100 * sizeof(char));
    scanf(" %99[^\n]", names[i]);
  }

  quicksort(names, 0, n - 1);

  printf("Sorted Names:\n");
  for (int i = 0; i < n; i++)
  {
    printf("%s\n", names[i]);
    free(names[i]);
  }
  free(names);

  return 0;
}
