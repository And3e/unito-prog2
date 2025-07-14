#include "es2.h"

bool has_sigle_child(IntTree tree) {
  return (!tree->left && tree->right) || (tree->left && !tree->right);
}

int productOfSingleChildWithEvenParentR(IntTree tree) {
  if (!tree) {
    return 1;
  }

  int multiplier = 1;
  if (tree->parent && !(tree->parent->data % 2) && has_sigle_child(tree)) {
    multiplier *= tree->data;
  }

  return multiplier * productOfSingleChildWithEvenParentR(tree->left) *
         productOfSingleChildWithEvenParentR(tree->right);
}

/**
 * Restituisce il prodotto (moltiplicazione) dei valori `data`
 * di tutti i nodi che:
 *   # hanno esattamente UN solo figlio (sinistro o destro),
 *   # e il cui padre ha valore pari.
 *
 * Se l'albero è vuoto la funzione deve restituire 0.
 *
 * Vincoli:
 *   - non usare variabili globali;
 *   - complessità temporale O(n) dove n è il numero di nodi.
 *
 * PROTOTIPO
 */
int productOfSingleChildWithEvenParent(IntTree tree) {
  if (!tree) {
    return 0;
  }

  return productOfSingleChildWithEvenParentR(tree);
}
