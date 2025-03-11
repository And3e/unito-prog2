#include "func.h"

int main() {
  puts("Starting program...");

  // ---------------------------------------------

  puts("buggyFunction");
  buggyFunction();

  // ---------------------------------------------

  int numbers[] = {1, 2, 3, 4, 5};
  int size = sizeof(numbers) / sizeof(numbers[0]);

  printf("Array size: %d\n", size);
  processArray(numbers, size);

  // ---------------------------------------------

  int n = 5;
  printf("Calculating the sum of numbers from 1 to %d...\n", n);

  int result = calculateSum(n);
  printf("Result: %d\n",
         result); // Expected: 15, but it prints 30 due to the bug

  // ---------------------------------------------

  int numbers2[] = {2, 4, 6, 8, 10};
  int size2 = sizeof(numbers) / sizeof(numbers2[0]);

  int evenCount = countEvenNumbers(numbers2, size2);
  printf("Number of even elements: %d\n", evenCount);

  // ---------------------------------------------

  puts("\nEnd of program");
  return 0;
}
