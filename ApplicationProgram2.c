#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int left, int mid, int right)
{
  int i, j, k;
  int n1 = mid - left + 1;
  int n2 = right - mid;

  // Create temporary arrays
  int L[n1], R[n2];

  // Copy data to temp arrays L[] and R[]
  for (i = 0; i < n1; i++)
    L[i] = arr[left + i];
  for (j = 0; j < n2; j++)
    R[j] = arr[mid + 1 + j];

  // Merge the temp arrays back into arr[left..right]
  i = 0;    // Initial index of first subarray
  j = 0;    // Initial index of second subarray
  k = left; // Initial index of merged subarray
  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      arr[k] = L[i];
      i++;
    }
    else
    {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  // Copy the remaining elements of L[], if there are any
  while (i < n1)
  {
    arr[k] = L[i];
    i++;
    k++;
  }

  // Copy the remaining elements of R[], if there are any
  while (j < n2)
  {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int left, int right)
{
  if (left < right)
  {
    int mid = left + (right - left) / 2; // Calculate middle index
    mergeSort(arr, left, mid);           // Sort first half
    mergeSort(arr, mid + 1, right);      // Sort second half
    merge(arr, left, mid, right);        // Merge the sorted halves
  }
}

int main(int argc, char *argv[])
{
  int totalNumbers;
  int *phoneNumbers;

  if (argc == 2)
  {
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
      printf("ERROR: Unable to open file %s\n", argv[1]);
      return 1;
    }

    // Read the number of phone numbers from the file
    if (fscanf(file, "%d", &totalNumbers) != 1)
    {
      printf("Error: Failed to read the number of phone numbers from the file.\n");
      fclose(file);
      return 1;
    }

    phoneNumbers = (int *)malloc(totalNumbers * sizeof(int));

    // Read phone numbers from the file
    for (int i = 0; i < totalNumbers; ++i)
    {
      if (fscanf(file, "%d", &phoneNumbers[i]) != 1)
      {
        printf("Error: Failed to read a phone number from the file.\n");
        fclose(file);
        return 1;
      }
    }

    fclose(file);
  }
  else if (argc == 1)
  {
    // Ask the user for the number of phone numbers
    printf("Enter the number of phone numbers: ");
    scanf("%d", &totalNumbers);

    phoneNumbers = (int *)malloc(totalNumbers * sizeof(int));

    // Ask the user to enter phone numbers
    for (int i = 0; i < totalNumbers; ++i)
    {
      printf("Enter phone number %d: ", i + 1);
      scanf("%d", &phoneNumbers[i]);
    }
  }
  else
  {
    printf("Usage: %s [filename]\n", argv[0]);
    return 1;
  }

  // Perform merge sort
  mergeSort(phoneNumbers, 0, totalNumbers - 1);

  // Print sorted phone numbers
  printf("Sorted phone numbers:\n");
  for (int i = 0; i < totalNumbers; ++i)
  {
    printf("%d\n", phoneNumbers[i]);
  }

  free(phoneNumbers);

  return 0;
}
