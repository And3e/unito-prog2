#include "es1.h"
#include "es2.h"

#include <stdio.h>
#include <string.h> // for strcmp if needed

IntList newList(int *arr, int size) {
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

void printList(IntList L) {
  printf("[");
  for (; L; L = L->next) {
    printf("%d", L->data);
    if (L->next)
      printf(", ");
  }
  printf("]");
}

void freeList(IntList L) {
  while (L) {
    IntNode *tmp = L;
    L = L->next;
    free(tmp);
  }
}

bool listEquals(IntList a, int *arr, int n) {
  for (int i = 0; i < n; i++) {
    if (!a || a->data != arr[i])
      return false;
    a = a->next;
  }
  return a == NULL;
}

IntTree newTreeNode(int v) {
  IntTree p = malloc(sizeof(IntTreeNode));
  p->data = v;
  p->left = p->right = NULL;
  p->parent = NULL;
  return p;
}

IntTree buildTreeExample1() {
  //        4
  //    3       6
  //  2  x    5   8

  IntTree n4 = newTreeNode(4);
  IntTree n3 = newTreeNode(3);
  IntTree n6 = newTreeNode(6);
  IntTree n2 = newTreeNode(2);
  IntTree n5 = newTreeNode(5);
  IntTree n8 = newTreeNode(8);

  n4->left = n3;
  n4->right = n6;
  n3->parent = n4;
  n6->parent = n4;

  n3->left = n2;
  n2->parent = n3;

  n6->left = n5;
  n6->right = n8;
  n5->parent = n6;
  n8->parent = n6;

  return n4;
}

IntTree buildTreeExample2() {
  //        4
  //    3       6
  //  2  x    x   8

  IntTree n4 = newTreeNode(4);
  IntTree n3 = newTreeNode(3);
  IntTree n6 = newTreeNode(6);
  IntTree n2 = newTreeNode(2);
  IntTree n8 = newTreeNode(8);

  n4->left = n3;
  n4->right = n6;
  n3->parent = n4;
  n6->parent = n4;

  n3->left = n2;
  n2->parent = n3;

  n6->right = n8;
  n8->parent = n6;

  return n4;
}

void freeTree(IntTree root) {
  if (!root)
    return;
  freeTree(root->left);
  freeTree(root->right);
  free(root);
}

void test_eliminaMedianLeft(int *input, int inputSize, int *expected,
                            int expectedSize, int expectedRet) {
  IntList list = newList(input, inputSize);
  printf("Input: ");
  printList(list);
  int ret = eliminaMedianLeft(&list);
  printf(" -> ret=%d, Result: ", ret);
  printList(list);

  bool passed =
      (ret == expectedRet) && listEquals(list, expected, expectedSize);
  printf(" => %s\n", passed ? "PASSED" : "FAILED");

  freeList(list);
}

void test_productOfSingleChildWithEvenParent(IntTree tree, int expected) {
  int result = productOfSingleChildWithEvenParent(tree);
  printf("Result = %d (expected: %d) => %s\n", result, expected,
         result == expected ? "PASSED" : "FAILED");
}

int main() {
  printf("=== Test eliminaMedianLeft ===\n");

  int a1[] = {4, 9};
  int e1[] = {9};
  test_eliminaMedianLeft(a1, 2, e1, 1, 1);

  int a2[] = {10, 20, 30, 40};
  int e2[] = {10, 30, 40};
  test_eliminaMedianLeft(a2, 4, e2, 3, 1);

  int a3[] = {7};
  int e3[] = {7};
  test_eliminaMedianLeft(a3, 1, e3, 1, 0);

  test_eliminaMedianLeft(NULL, 0, NULL, 0, 0); // empty list

  int r = eliminaMedianLeft(NULL);
  printf("Null pointer test -> ret=%d => %s\n", r,
         r == -1 ? "PASSED" : "FAILED");

  printf("\n=== Test productOfSingleChildWithEvenParent ===\n");
  IntTree T1 = buildTreeExample1();
  test_productOfSingleChildWithEvenParent(
      T1, 3); // 3 is only single child with even parent (4)
  freeTree(T1);

  IntTree T2 = buildTreeExample2();
  test_productOfSingleChildWithEvenParent(
      T2, 18);
  freeTree(T2);

  test_productOfSingleChildWithEvenParent(NULL, 0); // empty tree

  return 0;
}
