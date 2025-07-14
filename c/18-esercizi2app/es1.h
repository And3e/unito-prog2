#ifndef _ES_1_H_
#define _ES_1_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

/**
 * Modifica *lsPtr eliminando da *lsPtr il nodo median‑left
 * (cioè il nodo immediatamente a sinistra del nodo in posizione
 * centrale), se esiste.  In una lista di lunghezza n:
 *  - se n è dispari (es. 5), il nodo centrale è ⌊n/2⌋‑esimo (indice 2);
 *    il median‑left è il nodo di indice 1.
 *  - se n è pari (es. 6), i due centrali sono n/2‑1 e n/2;
 *    considera come “centrale” quello più a sinistra (indice 2),
 *    perciò il median‑left è il nodo di indice 1.
 *
 * La funzione deve:
 *   # rimuovere quel nodo, se esiste, e liberarne la memoria;
 *   # restituire:
 *       –1  se lsPtr == NULL;
 *        0  se lista vuota o se la lista ha meno di 2 nodi;
 *        1  in caso di successo.
 *
 * ESEMPI
 *  lsPtr == NULL                    →  ritorna –1
 * *lsPtr == []                      →  ritorna  0
 * *lsPtr == [7]                     →  ritorna  0
 * *lsPtr == [4, 9]                  →  elimina 4, lista [9],   ritorna 1
 * *lsPtr == [1, 2, 3]               →  elimina 1, lista [2, 3], ritorna 1
 * *lsPtr == [10, 20, 30, 40]        →  elimina 20, lista [10, 30, 40], ritorna
 * 1
 */
int eliminaMedianLeft(IntList *lsPtr);

#endif
