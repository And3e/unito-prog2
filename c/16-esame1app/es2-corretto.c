#include "es2.h"

bool has_single_child_crt(IntTree tree) {
  if (!tree) {
    return false;
  }

  return (tree->left && !tree->right) || (!tree->left && tree->right);
}

bool is_leaf_crt(IntTree tree) {
  if (!tree)
    return false;
  return !tree->left && !tree->right;
}

int sumXR_crt(IntTree tree) {
  if (!tree)
    return 0;

  int sum = 0;
  if (has_single_child_crt(tree)) {
    IntTree child = tree->left ? tree->left : tree->right;
    if (is_leaf_crt(child)) {
      sum = child->data;
    }
  }

  return sum + sumXR_crt(tree->left) + sumXR_crt(tree->right);
}

int sumX_crt(IntTree tree) {
  if (!tree)
    return 0;

  if (is_leaf_crt(tree)) {
    return tree->data;
  }

  return sumX_crt(tree->left) + sumX_crt(tree->right);
}
