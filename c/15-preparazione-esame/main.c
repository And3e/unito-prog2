#include "list_iter.h"
#include "tree_iter.h"
#include <stdio.h>
#include <string.h>

// Funzione di utilità per stampare una lista
void printList(ListNodePtr ls) {
  while (ls) {
    printf("%d ", ls->data);
    ls = ls->next;
  }
  printf("\n");
}

// Funzione di utilità per creare una lista da un array
ListNodePtr createListFromArray(int *arr, int len) {
  if (len <= 0)
    return NULL;
  ListNodePtr head = malloc(sizeof(ListNode));
  head->data = arr[0];
  head->next = NULL;
  ListNodePtr curr = head;
  for (int i = 1; i < len; i++) {
    curr->next = malloc(sizeof(ListNode));
    curr = curr->next;
    curr->data = arr[i];
    curr->next = NULL;
  }
  return head;
}

// Funzione per confrontare due liste
_Bool compareLists(ListNodePtr a, ListNodePtr b) {
  while (a && b) {
    if (a->data != b->data)
      return false;
    a = a->next;
    b = b->next;
  }
  return a == NULL && b == NULL;
}

// Test da m a n
void test_fromTo_iter() {
  ListNodePtr ls = fromTo_iter(3, 6);
  int expected[] = {3, 4, 5, 6};
  ListNodePtr exp = createListFromArray(expected, 4);
  printf("fromTo_iter: %s\n",
         compareLists(ls, exp) ? "PASSATO" : "NON PASSATO");
}

// Test inclusione
void test_included_iter() {
  int a1[] = {1, 3, 5};
  int a2[] = {0, 1, 2, 3, 4, 5, 6};
  ListNodePtr ls1 = createListFromArray(a1, 3);
  ListNodePtr ls2 = createListFromArray(a2, 7);
  printf("included_iter: %s\n",
         included_iter(ls1, ls2) ? "PASSATO" : "NON PASSATO");
}

// Test reverse
void test_reverse_iter() {
  int a[] = {1, 2, 3};
  int rev[] = {3, 2, 1};
  ListNodePtr ls = createListFromArray(a, 3);
  ListNodePtr r = reverse_iter(ls);
  ListNodePtr expected = createListFromArray(rev, 3);
  printf("reverse_iter: %s\n",
         compareLists(r, expected) ? "PASSATO" : "NON PASSATO");
}

// Test zipSum
void test_zipSum_iter() {
  int a[] = {1, 2, 3};
  int b[] = {4, 5, 6};
  int sum[] = {5, 7, 9};
  ListNodePtr ls1 = createListFromArray(a, 3);
  ListNodePtr ls2 = createListFromArray(b, 3);
  ListNodePtr z = zipSum_iter(ls1, ls2);
  ListNodePtr expected = createListFromArray(sum, 3);
  printf("zipSum_iter: %s\n",
         compareLists(z, expected) ? "PASSATO" : "NON PASSATO");
}

// Test occurrences
void test_occurrences_iter() {
  int a[] = {1, 2, 3, 2, 2};
  ListNodePtr ls = createListFromArray(a, 5);
  printf("occurrences_iter: %s\n",
         occurrences_iter(ls, 2) == 3 ? "PASSATO" : "NON PASSATO");
}

// Test remove_all
void test_remove_all_iter() {
  int a[] = {1, 2, 3, 2, 4};
  int res[] = {1, 3, 4};
  ListNodePtr ls = createListFromArray(a, 5);
  remove_all_iter(&ls, 2);
  ListNodePtr expected = createListFromArray(res, 3);
  printf("remove_all_iter: %s\n",
         compareLists(ls, expected) ? "PASSATO" : "NON PASSATO");
}

// Test duplicate_even_iter
void test_duplicate_even_iter() {
  int a[] = {1, 2, 3, 4};
  int dup[] = {1, 2, 2, 3, 4, 4};
  ListNodePtr ls = createListFromArray(a, 4);
  duplicate_even_iter(&ls);

  ListNodePtr expected = createListFromArray(dup, 6);
  printf("duplicate_even_iter: %s\n",
         compareLists(ls, expected) ? "PASSATO" : "NON PASSATO");
}

/////////////////////////////////////////////////////////////////////////////

#define TEST(cond, msg) printf("[%-7s] %s\n", (cond) ? "PASSED" : "FAILED", msg)

void free_tree(IntTree tree) {
  if (!tree)
    return;
  free_tree(tree->left);
  free_tree(tree->right);
  free(tree);
}

void free_char_tree(CharTree tree) {
  if (!tree)
    return;
  free_char_tree(tree->left);
  free_char_tree(tree->right);
  free(tree);
}

void test_putIter() {
  IntTree tree = NULL;
  Response res;

  res = putIter(&tree, "", 10);
  TEST(res == ADDED, "Insert root");

  res = putIter(&tree, "L", 5);
  TEST(res == ADDED, "Insert left child");

  res = putIter(&tree, "L", 99);
  TEST(res == OVERWRITTEN && tree->left->data == 99, "Overwrite left child");

  res = putIter(&tree, "X", 3);
  TEST(res == ERROR, "Invalid path character");

  free_tree(tree);
}

void test_isPruningIter() {
  IntTree tree = NULL, subtree = NULL;

  putIter(&tree, "", 1);
  putIter(&tree, "L", 2);
  putIter(&tree, "R", 3);
  putIter(&tree, "LL", 4);
  putIter(&tree, "LR", 5);

  putIter(&subtree, "", 2);
  putIter(&subtree, "L", 4);
  putIter(&subtree, "R", 5);

  TEST(isPruningIter(tree, subtree), "Subtree is a pruning");

  putIter(&subtree, "R", 99); // Change a value to make it fail
  TEST(!isPruningIter(tree, subtree), "Subtree not a pruning (value mismatch)");

  free_tree(tree);
  free_tree(subtree);
}

// Move this OUTSIDE of test_treeToArray()
void flatten(IntTree t, int *result, int *index) {
  if (!t)
    return;
  result[(*index)++] = t->data;
  flatten(t->left, result, index);
  flatten(t->right, result, index);
}

void test_treeToArray() {
  IntTree tree = NULL;
  putIter(&tree, "", 10);
  putIter(&tree, "L", 5);
  putIter(&tree, "R", 20);
  putIter(&tree, "LL", 3);
  putIter(&tree, "LR", 7);

  int size = count_tree_nodes(tree);
  int *result = malloc(sizeof(int) * size);
  int index = 0;

  flatten(tree, result, &index);

  int expected[] = {10, 5, 3, 7, 20};
  _Bool pass = 1;
  for (int i = 0; i < size; i++) {
    if (result[i] != expected[i]) {
      pass = 0;
      break;
    }
  }

  TEST(pass, "treeToArray gives correct pre-order");

  free(result);
  free_tree(tree);
}

ReportPtr minMaxLevel_iter(CharTree tree) {
  if (!tree) {
    ReportPtr r = malloc(sizeof(Report));
    r->min = r->max = -1;
    return r;
  }

  int min = -1, max = -1;
  typedef struct {
    CharTree node;
    int depth;
  } StackNode;

  StackNode stack[128];
  int top = 0;
  stack[top++] = (StackNode){tree, 0};

  while (top > 0) {
    StackNode current = stack[--top];
    if (!current.node->left && !current.node->right) {
      if (min == -1 || current.depth < min)
        min = current.depth;
      if (current.depth > max)
        max = current.depth;
    }
    if (current.node->left)
      stack[top++] = (StackNode){current.node->left, current.depth + 1};
    if (current.node->right)
      stack[top++] = (StackNode){current.node->right, current.depth + 1};
  }

  ReportPtr r = malloc(sizeof(Report));
  r->min = min;
  r->max = max;
  return r;
}

void test_minMaxLevel_iter() {
  CharTree root = malloc(sizeof(CharTreeNode));
  root->data = 'A';
  root->left = malloc(sizeof(CharTreeNode));
  root->left->data = 'B';
  root->left->left = NULL;
  root->left->right = NULL;

  root->right = malloc(sizeof(CharTreeNode));
  root->right->data = 'C';
  root->right->left = malloc(sizeof(CharTreeNode));
  root->right->left->data = 'D';
  root->right->left->left = NULL;
  root->right->left->right = NULL;
  root->right->right = NULL;

  ReportPtr r = minMaxLevel_iter(root);
  TEST(r->min == 1 && r->max == 2, "minMaxLevel_iter returns correct depths");

  free(r);
  free_char_tree(root);
}

int main() {
  printf("List Iter\n");

  test_fromTo_iter();
  test_included_iter();
  test_reverse_iter();
  test_zipSum_iter();
  test_occurrences_iter();
  test_remove_all_iter();
  test_duplicate_even_iter();

  printf("\n\n----------\n");
  printf("\n\nTree Iter\n");

  // ...

  test_putIter();
  test_isPruningIter();
  test_treeToArray();
  test_minMaxLevel_iter();

  return 0;
}
