#ifndef _ES2_H_
#define _ES2_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
  IntTree left;
  int data;
  IntTree right;

  IntTree parent;
};

int sumX(IntTree tree);
int sumX_crt(IntTree tree);

#endif
