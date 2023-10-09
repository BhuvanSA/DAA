#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define MAX_NAME_LENGTH 20

void swap(char **a, char **b)
{ // Pointer to a pointer
  char *temp = *a;
  *a = *b;
  *b = temp;
}

int partition(char **arr, int start, int end)
{
  char *pivot = malloc(sizeof(char) * MAX_NAME_LENGTH);
  strcpy(pivot, arr[end]);

  int i = (start - 1);

  for (int j = start; j <= end - 1; j++)
  {
    if (strcmp(arr[j], pivot) < 0)
    {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[end]);
  return (i + 1);
}

void quickSort(char **arr, int start, int end)
{
  if (start <= end)
  {
    int pi = partition(arr, start, end);
    quickSort(arr, start, pi - 1);
    quickSort(arr, pi + 1, end);
  }
}

int main(int argc, char *argv[])
{
  int totalstrings;
  char **array;

  if (argc == 2)
  {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
      printf("ERROR: Unable to open file %s\n", argv[1]);
      return 1;
    }

    // Read the number of strings from the file
    if (fscanf(file, "%d", &totalstrings) != 1)
    {
      printf("Error: Failed to read the number of names from the file.\n");
      fclose(file);
      return 1;
    }

    array = malloc(totalstrings * sizeof(char *));

    // Read names from the file
    for (int i = 0; i < totalstrings; ++i)
    {
      array[i] = malloc((MAX_NAME_LENGTH + 1) * sizeof(char *));
      if (fscanf(file, " %20[^\n]", array[i]) != 1)
      {
        printf("Error: Failed to read a name from the file.\n");
        fclose(file);
        return 1;
      }
    }

    fclose(file);
  }
  else if (argc == 1)
  {
    // Ask the user for the number of strings
    printf("Enter the number of names: ");
    scanf("%d", &totalstrings);

    // Allocate memory for the array
    array = malloc(totalstrings * sizeof(char *));

    // Ask the user to enter names
    for (int i = 0; i < totalstrings; ++i)
    {
      array[i] = malloc((MAX_NAME_LENGTH + 1) * sizeof(char *));
      printf("Enter name %d (up to 20 characters): ", i + 1);
      scanf(" %20[^\n]", array[i]);
    }
  }
  else
  {
    printf("Usage: %s [filename]\n", argv[0]);
    return 1;
  }

  // Perform quicksort
  quickSort(array, 0, totalstrings - 1);

  // Print and free memory
  for (int i = 0; i < totalstrings; ++i)
  {
    printf("%s\n", array[i]);
    free(array[i]);
  }
  free(array);

  return 0;
}
