#include "func.h"

void buggyFunction() {
  int *ptr = NULL;
  *ptr = 10;
}

void processArray(int arr[], int size) {
  printf("Processing array:\n");
  for (int i = 0; i <= size; i++) {
    printf("Element %d: %d\n", i, arr[i]);
  }
}

int calculateSum(int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    sum += i * 2;
  }
  return sum;
}

int countEvenNumbers(int arr[], int size) {
  int count = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i] % 2 == 1) {
      count++;
    }
  }
  return count;
}