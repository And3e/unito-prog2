#include "ram.h"
#include <stdio.h>
#include <string.h>

/* Manually build the example tree:
 *
 *      [8:I]
 *        /   \
 *   [4:I]     [4:I]
 *    /   \     /   \
 * [2:I] [2:I] [2:O] [2:L]
 *  /\     \
 * O  L     O
 */

static RAM build_example_ram(void) {
  RAM root = initram(8);
  root->s = INTERNO;

  // left subtree
  root->lbuddy = initram(4);
  root->lbuddy->s = INTERNO;
  root->lbuddy->parent = root;

  RAM l2 = initram(2);
  l2->s = INTERNO;
  l2->parent = root->lbuddy;
  root->lbuddy->lbuddy = l2;

  RAM leaf = initram(1);
  leaf->s = OCCUPATO;
  leaf->parent = l2;
  l2->lbuddy = leaf;

  leaf = initram(1);
  leaf->s = LIBERO;
  leaf->parent = l2;
  l2->rbuddy = leaf;

  RAM right2 = initram(2);
  right2->s = OCCUPATO;
  right2->parent = root->lbuddy;
  root->lbuddy->rbuddy = right2;

  // right subtree
  root->rbuddy = initram(4);
  root->rbuddy->s = INTERNO;
  root->rbuddy->parent = root;

  RAM r2 = initram(2);
  r2->s = OCCUPATO;
  r2->parent = root->rbuddy;
  root->rbuddy->lbuddy = r2;

  RAM r2b = initram(2);
  r2b->s = LIBERO;
  r2b->parent = root->rbuddy;
  root->rbuddy->rbuddy = r2b;

  return root;
}

void print_ram_tree(RAM ram, int depth, char side) {
  if (!ram) {
    return;
  }

  if ((ram->lbuddy && !ram->rbuddy) || (!ram->lbuddy && ram->rbuddy)) {
    for (int i = 0; i < depth; ++i)
      printf("    ");
    printf("%c─ %dKB [INVALID: one child only]\n", side, ram->KB);
    return;
  }

  print_ram_tree(ram->rbuddy, depth + 1, 'r');

  for (int i = 0; i < depth; ++i) {
    printf("    ");
  }

  const char *label = ram->s == LIBERO ? "L" : ram->s == INTERNO ? "I" : "O";
  printf("%c─ %dKB [%s]\n", side, ram->KB, label);

  print_ram_tree(ram->lbuddy, depth + 1, 'l');
}

int main(void) {
  RAM example = build_example_ram();

  print_ram_tree(example, 0, '*');

  printf("\n\n");

  char *s = ram2str(example);
  const char *expected = "8:I#1l:I#2l:I#3l:O#3r:L#2r:O#1r:I#2l:O#2r:L";

  printf("got:      %s\n", s);
  printf("expected: %s\n\n", expected);

  if (strcmp(s, expected) == 0) {
    printf("✅ ram2str test passed!\n");
  } else {
    printf("❌ ram2str test FAILED!\n");
  }

  free(s);
  freeram(&example);
  return 0;
}
