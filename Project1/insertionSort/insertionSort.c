#include <stdio.h>

void printArray(int arr[], int size) {
  int i;
  for (i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void insertionSortRecursive(int arr[], int n) {
  if (n <= 1)
    return;

  insertionSortRecursive(arr, n - 1);

  int last = arr[n - 1];
  int j = n - 2;

  while (j >= 0 && arr[j] > last) {
    arr[j + 1] = arr[j];
    j--;
  }
  arr[j + 1] = last;
}

int main() {
  int n = 10;
  int arr[n];
  printf("Enter the %d of elements in the array", n);
  for (int i = 0; i < n; i++) {
    scanf(" %d", &arr[i]);
  }
  insertionSortRecursive(arr, n);

  printArray(arr, n);
  return 0;
}
