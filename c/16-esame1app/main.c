#include "es1.h"
#include "es2.h"
#include <stdio.h>
#include <stdlib.h>

IntTree newNode(int data) {
  IntTree node = (IntTree)malloc(sizeof(IntTreeNode));
  if (node == NULL) {
    printf("Errore: malloc fallita.\n");
    exit(EXIT_FAILURE);
  }
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  node->parent = NULL;
  return node;
}

void printTestResult(int testNumber, const char *description, int expected,
                     int obtained) {
  printf("Test %d: %s\n", testNumber, description);
  printf("  Atteso: %d\n", expected);
  printf("  Ottenuto: %d\n", obtained);
  printf("  RISULTATO: %s\n\n",
         (expected == obtained) ? "PASSATO" : "NON PASSATO");
}

IntList newListNode(int data) {
  IntList node = (IntList)malloc(sizeof(IntNode));
  if (node == NULL) {
    printf("Errore: malloc fallita.\n");
    exit(EXIT_FAILURE);
  }
  node->data = data;
  node->next = NULL;
  return node;
}

void printList(IntList ls) {
  printf("[");
  while (ls != NULL) {
    printf("%d", ls->data);
    if (ls->next != NULL)
      printf(" -> ");
    ls = ls->next;
  }
  printf("]\n");
}

void printTestResultList(int testNumber, const char *description, int expected,
                         int obtained) {
  printf("Test %d: %s\n", testNumber, description);
  printf("  Atteso: %d\n", expected);
  printf("  Ottenuto: %d\n", obtained);
  printf("  RISULTATO: %s\n\n",
         (expected == obtained) ? "PASSATO" : "NON PASSATO");
}

int main() {
  // Test 1: Lista vuota
  IntList list1 = NULL;
  int res1 = eliminaTerzultimo(&list1);
  printTestResultList(1, "Lista vuota", 0, res1);

  // Test 2: Lista con 2 elementi (non può eliminare terzultimo)
  IntList list2 = newListNode(10);
  list2->next = newListNode(20);
  int res2 = eliminaTerzultimo(&list2);
  printTestResultList(2, "Lista con 2 elementi (niente da eliminare)", 0, res2);

  // Test 3: Lista con 3 elementi (elimina il primo)
  IntList list3 = newListNode(1);
  list3->next = newListNode(2);
  list3->next->next = newListNode(3);
  int res3 = eliminaTerzultimo(&list3);
  printTestResultList(3, "Lista con 3 elementi (elimina il terzultimo: 1)", 1,
                      res3);

  // Test 4: Lista con 5 elementi
  // Prima: [10 -> 20 -> 30 -> 40 -> 50]
  // Dopo: [10 -> 20 -> 40 -> 50] (30 eliminato)
  IntList list4 = newListNode(10);
  list4->next = newListNode(20);
  list4->next->next = newListNode(30);
  list4->next->next->next = newListNode(40);
  list4->next->next->next->next = newListNode(50);
  int res4 = eliminaTerzultimo(&list4);
  printTestResultList(4, "Lista con 5 elementi (elimina terzultimo: 30)", 1,
                      res4);

  // Test 5: Lista con esattamente 4 elementi
  // Prima: [5 -> 6 -> 7 -> 8]
  // Dopo: [5 -> 7 -> 8] (6 eliminato)
  IntList list5 = newListNode(5);
  list5->next = newListNode(6);
  list5->next->next = newListNode(7);
  list5->next->next->next = newListNode(8);
  int res5 = eliminaTerzultimo(&list5);
  printTestResultList(5, "Lista con 4 elementi (elimina terzultimo: 6)", 1,
                      res5);

  ///////////////////////////////////////////////////////////////////////////////
  printf("\n\n\n");
  ///////////////////////////////////////////////////////////////////////////////

  // Test 1: Albero vuoto
  // Aspettato: somma = 0
  IntTree tree1 = NULL;
  printTestResult(1, "Albero vuoto", 0, sumX(tree1));

  // Test 2: Albero con un solo nodo
  // Aspettato: somma = 42 (è anche foglia singola)
  IntTree tree2 = newNode(42);
  printTestResult(2, "Albero con singolo nodo (foglia e radice)", 42,
                  sumX(tree2));

  // Test 3: Albero di esempio modificato
  IntTree tree3 = newNode(1);
  tree3->left = newNode(2);
  tree3->right = newNode(3);
  tree3->left->left = newNode(4);
  tree3->left->right = newNode(5);
  tree3->right->right = newNode(7);
  tree3->left->right->left = newNode(10);
  tree3->left->right->left->right = newNode(8);
  // AGGIUNTA: nuovo figlio di 5, rende 10 non figlio unico
  // Struttura:
  //       1
  //      / |
  //     2   3
  //   / \    |
  //  4   5    7   <- foglia figlio unico
  //     /
  //   10
  //     |
  //      8
  //
  // Foglia figlia unica: 7 (figlio unico di 3)
  // NOTA: 10 non è figlio unico (ha il figlio 8), quindi NON si conta
  // Aspettato: somma = 7 + 10 + 8 = 25
  printTestResult(3, "Albero di esempio con foglie figlie uniche (7,10,8)", 25,
                  sumX(tree3));

  // Test 4: Albero con radice e unico figlio foglia
  // Struttura:
  //     9
  //    /
  //   5   <- foglia figlio unico
  //
  // Aspettato: somma = 5
  IntTree tree4 = newNode(9);
  tree4->left = newNode(5);
  tree4->left->parent = tree4;
  printTestResult(4, "Albero con radice e un solo figlio foglia (5)", 5,
                  sumX(tree4));

  // Test 5: Albero con radice e due figli foglia
  // Struttura:
  //     9
  //    / |
  //   5   6
  //
  // Nessuna foglia figlio unico
  // Aspettato: somma = 0
  IntTree tree5 = newNode(9);
  tree5->left = newNode(5);
  tree5->left->parent = tree5;
  tree5->right = newNode(6);
  tree5->right->parent = tree5;
  printTestResult(5,
                  "Albero con radice e due figli foglia (nessun figlio unico)",
                  0, sumX(tree5));

  // Nota: deallocazione della memoria omessa per brevità
  return 0;
}
