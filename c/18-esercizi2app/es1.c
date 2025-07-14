#include "es1.h"

/**
 * Modifica *lsPtr eliminando da *lsPtr il nodo median‑left
 * (cioè il nodo immediatamente a sinistra del nodo in posizione
 * centrale), se esiste.  In una lista di lunghezza n:
 *  - se n è dispari (es. 5), il nodo centrale è ⌊n/2⌋‑esimo (indice 2);
 *    il median‑left è il nodo di indice 1.
 *  - se n è pari (es. 6), i due centrali sono (n/2)‑1 e n/2;
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
int eliminaMedianLeft(IntList *lsPtr) {
  if (!lsPtr) {
    return -1;
  }

  if (!(*lsPtr) || !(*lsPtr)->next) {
    return 0;
  }

  IntList prev = NULL;
  IntList current = (*lsPtr)->next;
  IntList middle = *lsPtr;

  int flag = 0;

  while (current->next) {
    if (flag) {
      prev = middle;
      middle = middle->next;
      flag = -1;
    }

    flag++;
    current = current->next;
  }

  if (!prev) {
    *lsPtr = middle->next;
  } else {
    prev->next = middle->next;
  }

  free(middle);

  return 1;
}

// suggested
// int eliminaMedianLeft(IntList *lsPtr) {
//   if (!lsPtr) {
//     return -1;
//   }

//   if (!(*lsPtr) || !(*lsPtr)->next) {
//     return 0;
//   }

//   IntList slow = *lsPtr;
//   IntList fast = *lsPtr;
//   IntList prev = NULL;
//   IntList beforePrev = NULL;

//   while (fast && fast->next) {
//     fast = fast->next->next;
//     beforePrev = prev;
//     prev = slow;
//     slow = slow->next;
//   }

//   if (!beforePrev) {
//     *lsPtr = prev->next;
//   } else {
//     beforePrev->next = prev->next;
//   }

//   free(prev);
//   return 1;
// }