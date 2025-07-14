#include "pari_dispari_reverse.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Crea una lista da un array di interi
IntList createList(int *arr, int size) {
  if (size <= 0 || arr == NULL)
    return NULL;

  IntList head = NULL, *curr = &head;
  for (int i = 0; i < size; i++) {
    *curr = malloc(sizeof(IntNode));
    (*curr)->data = arr[i];
    (*curr)->next = NULL;
    curr = &((*curr)->next);
  }
  return head;
}

// Stampa una lista
void printList(IntList list) {
  while (list != NULL) {
    printf("%d -> ", list->data);
    list = list->next;
  }
  printf("NULL\n");
}

// Confronta due liste
bool compareLists(IntList a, IntList b) {
  while (a && b) {
    if (a->data != b->data) {
      return false;
    }
    a = a->next;
    b = b->next;
  }
  return a == NULL && b == NULL;
}

// Libera la memoria di una lista
void freeList(IntList *list) {
  IntList curr = *list;
  while (curr) {
    IntList tmp = curr;
    curr = curr->next;
    free(tmp);
  }
  *list = NULL;
}

// Funzione test
void runTest(const char *desc, int input[], int size, int expectedPari[],
             int sizePari, int expectedDispari[], int sizeDispari) {
  IntList ls = createList(input, size);
  IntList pari = NULL, dispari = NULL;

  printf("Test: %s\n", desc);
  pariDispariReverse(&ls, &pari, &dispari);

  IntList expectedPariList = createList(expectedPari, sizePari);
  IntList expectedDispariList = createList(expectedDispari, sizeDispari);

  bool passed = compareLists(pari, expectedPariList) &&
                compareLists(dispari, expectedDispariList) && ls == NULL;

  printf("Lista pari ottenuta:    ");
  printList(pari);
  printf("Lista dispari ottenuta: ");
  printList(dispari);
  printf("Test %s\n\n", passed ? "PASSATO ✅" : "FALLITO ❌");

  freeList(&pari);
  freeList(&dispari);
  freeList(&expectedPariList);
  freeList(&expectedDispariList);
}

int main() {
  // TEST 1: Lista con elementi alternati
  int input1[] = {1, 2, 3, 4, 5, 6};
  int expectedPari1[] = {5, 3, 1}; // Posizioni 0, 2, 4 -> 1, 3, 5 -> reversed
  int expectedDispari1[] = {6, 4,
                            2}; // Posizioni 1, 3, 5 -> 2, 4, 6 -> reversed
  runTest("Lista con 6 elementi", input1, 6, expectedPari1, 3, expectedDispari1,
          3);

  // TEST 2: Lista vuota
  int input2[1];
  int expectedPari2[1];
  int expectedDispari2[1];
  runTest("Lista vuota", input2, 0, expectedPari2, 0, expectedDispari2, 0);

  // TEST 3: Lista con 1 elemento
  int input3[] = {10};
  int expectedPari3[] = {10};
  int expectedDispari3[1];
  runTest("Lista con 1 elemento", input3, 1, expectedPari3, 1, expectedDispari3,
          0);

  // TEST 4: Lista con 2 elementi
  int input4[] = {7, 8};
  int expectedPari4[] = {7};
  int expectedDispari4[] = {8};
  runTest("Lista con 2 elementi", input4, 2, expectedPari4, 1, expectedDispari4,
          1);

  // TEST 5: Lista con elementi dispari
  int input5[] = {9, 8, 7};
  int expectedPari5[] = {7, 9};
  int expectedDispari5[] = {8};
  runTest("Lista con 3 elementi", input5, 3, expectedPari5, 2, expectedDispari5,
          1);

  return 0;
}
