#include "es2.h"

bool has_single_child(IntTree tree) {
  if (!tree || (tree->left && tree->right) ||
      (!(tree->left) && !(tree->right))) {
    return false;
  }

  return true;
}

int sumXR(IntTree tree) {
  if (!tree) {
    return 0;
  }

  int sum = 0;
  if (has_single_child(tree)) {
    if (tree->left) {
      sum += tree->left->data;
    } else {
      sum += tree->right->data;
    }
  }

  return sum + sumXR(tree->left) + sumXR(tree->right);
}

int sumX(IntTree tree) {
  if (!tree) {
    return 0;
  }

  if (!(tree->left) && !(tree->right)) {
    return tree->data;
  }

  return sumXR(tree->left) + sumXR(tree->right);
}
