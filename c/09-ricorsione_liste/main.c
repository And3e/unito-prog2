#include "list_rec.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Helper function: prints the list elements.
void printList(ListNodePtr lp) {
  printf("[");
  while (lp != NULL) {
    printf("%d", lp->data);
    lp = lp->next;
    if (lp != NULL)
      printf(", ");
  }
  printf("]");
}

// Helper function: compares the list to an expected array.
// Returns true if they are identical in contents and length.
bool compareLists(ListNodePtr lp, const int expected[], int len) {
  int i = 0;
  while (lp != NULL && i < len) {
    if (lp->data != expected[i])
      return false;
    lp = lp->next;
    i++;
  }
  // Both should finish together.
  return (lp == NULL && i == len);
}

#define T1 1
#define T2 1
#define T3 1
#define T4 1
#define T5 1

int main(void) {
  ListNodePtr list1 = NULL;
  _Bool testResult;

  // -------------------------------
  // Test 1: fromTo_rec
  // Create a list of integers from 1 to 5.
  // Expected output: [1, 2, 3, 4, 5]
  if (T1) {
    printf("Test 1: fromTo_rec(1, 5)\n");
    list1 = fromTo_rec(1, 5);
    printf("Generated list: ");
    printList(list1);
    // Expected array.
    int expectedArr1[] = {1, 2, 3, 4, 5};
    testResult = compareLists(list1, expectedArr1,
                              sizeof(expectedArr1) / sizeof(expectedArr1[0]));
    printf(" --> %s\n", testResult ? "ok" : "not ok");
  }

  // -------------------------------
  // Test 2: occurrences_rec
  // Count the number of occurrences of 1 in the list: [0, 1, 1, 2, 1]
  if (T2) {
    printf("\nTest 2: occurrences_rec\n");
    // Build list: 0 -> 1 -> 1 -> 2 -> 1
    ListNodePtr listT2 = getNewNode(0);
    addNode(&listT2, 1);
    addNode(&listT2, 1);
    addNode(&listT2, 2);
    addNode(&listT2, 1);
    printf("List for occurrences: ");
    printList(listT2);
    int count = occurrences_rec(listT2, 1);
    printf("\nOccurrences of 1 [expected: 3]: %d --> %s\n", count,
           (count == 3 ? "ok" : "not ok"));
    free_list(listT2);
  }

  // -------------------------------
  // Test 3: included_rec
  // Check if list2 (created from 2 to 4) is a subsequence of list1
  // ([1,2,3,4,5]).
  if (T3) {
    printf("\nTest 3: included_rec\n");
    // list2 expected: [2, 3, 4]
    ListNodePtr list2 = fromTo_rec(2, 4);
    printf("list1: ");
    printList(list1);
    printf("\nlist2: ");
    printList(list2);
    // Using list1 from Test 1.
    testResult = included_rec(list2, list1);
    printf("\nIs list2 included in list1? (expected: true): %s --> %s\n",
           testResult ? "true" : "false", (testResult ? "ok" : "not ok"));
    testResult = included_rec(list1, list2);
    printf("\nIs list1 included in list2? (expected: false): %s --> %s\n",
           testResult ? "true" : "false", (!testResult ? "ok" : "not ok"));
    free_list(list2);
  }

  // -------------------------------
  // Test 4: reverse_rec
  // Reverse list1.
  // Expected output: [5,4,3,2,1] when list1 is [1,2,3,4,5]
  if (T4) {
    printf("\nTest 4: reverse_rec\n");
    ListNodePtr reversed = reverse_rec(list1);
    printf("Reversed list: ");
    printList(reversed);
    int expectedArr4[] = {5, 4, 3, 2, 1};
    testResult = compareLists(reversed, expectedArr4,
                              sizeof(expectedArr4) / sizeof(expectedArr4[0]));
    printf(" --> %s\n", testResult ? "ok" : "not ok");
    free_list(reversed);
  }

  // -------------------------------
  // Test 5: zipSum_rec
  // Create two lists of equal length and compute the zip-sum.
  // For example, list1: [1,2,3,4,5] and list3: reverse of list1 i.e.,
  // [5,4,3,2,1]. Expected output: [6,6,6,6,6]
  if (T5) {
    printf("\nTest 5: zipSum_rec\n");
    // Re-create list1
    list1 = fromTo_rec(1, 5);
    // Create list3 as the reverse of a new list [1,2,3,4,5]
    ListNodePtr list3 = reverse_rec(fromTo_rec(1, 5));
    printf("list1: ");
    printList(list1);
    printf("\nlist3: ");
    printList(list3);
    ListNodePtr zipList = zipSum_rec(list1, list3);
    printf("\nzipSum of list1 and list3: ");
    printList(zipList);
    int expectedArr5[] = {6, 6, 6, 6, 6};
    testResult = compareLists(zipList, expectedArr5,
                              sizeof(expectedArr5) / sizeof(expectedArr5[0]));
    printf(" --> %s\n", testResult ? "ok" : "not ok");
    free_list(zipList);
    free_list(list3);
  }

  free_list(list1);

  return 0;
}