#ifndef _ES_2_H_
#define _ES_2_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode IntTreeNode, *IntTree;
struct treeNode {
  IntTree left;
  int data;
  IntTree right;

  IntTree parent;
};

/**
 * Restituisce il prodotto (moltiplicazione) dei valori `data`
 * di tutti i nodi che:
 *   • hanno esattamente UN solo figlio (sinistro o destro),
 *   • e il cui padre ha valore pari.
 *
 * Se l'albero è vuoto (`tree == NULL`) oppure non esistono nodi che
 * soddisfano la condizione, la funzione deve restituire 0.
 *
 * Vincoli:
 *   – non usare variabili globali;
 *   – complessità temporale O(n) dove n è il numero di nodi.
 *
 * PROTOTIPO
 */
int productOfSingleChildWithEvenParent(IntTree tree);

#endif
