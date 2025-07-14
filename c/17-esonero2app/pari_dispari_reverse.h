#ifndef _PARI_DISPARI_REVERSE_H_
#define _PARI_DISPARI_REVERSE_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

/**
 * @brief Ricevuta una lista *lsPtr, mette tutti gli elementi in posizione pari
 * nella lista *lsPari, e tutti gli elementi in posizione dispari nella lista
 * *lsDispari.
 * Infine fa il reverse delle liste *lsPari e *lsDispari.
 * Alla fine dell'esecuzione *lsPtr dovrebbe essere NULL.
 */
void pariDispariReverse(IntList *lsPtr, IntList *lsPari, IntList *lsDispari);

#endif
