#include "es1.h"

/**
 * Modifica *lsPtr togliendo da *lsPtr il suo terzultimo nodo,
 * se esiste (ovvero se la lista contiene almeno tre elementi),
 * e liberando la memoria da esso occupata.
 * restituisce :
 * -1 se lsPtr == NULL;
 * 0 se lista vuota o in caso di fallimento
 * 1 in caso di successo
 *
 * ESEMPI
se lsPtr == NULL, dopo l’esecuzione lsPtr == NULL e ritorna -1.
se *lsPtr == NULL, dopo l’esecuzione *lsPtr == NULL e ritorna 0.
se *lsPtr == [25], dopo l’esecuzione *lsPtr == [25] e ritorna 0.
se *lsPtr == [25, 50], dopo l’esecuzione *lsPtr == [25, 50] e ritorna 0.
se *lsPtr == [10, 8, 12, 3], dopo l’esecuzione *lsPtr == [10, 12, 3] e
restituisce 1.

 */
int eliminaTerzultimo_crt(IntList *lsPtr) {
  if (lsPtr == NULL) {
    return -1;
  }

  if (*lsPtr == NULL || (*lsPtr)->next == NULL ||
      (*lsPtr)->next->next == NULL) {
    return 0;
  }

  IntList prev = NULL;
  IntList curr = *lsPtr;

  while (curr->next->next->next != NULL) {
    prev = curr;
    curr = curr->next;
  }

  IntList tmp;

  if (prev == NULL) {
    tmp = *lsPtr;
    *lsPtr = (*lsPtr)->next;
    free(tmp);
  } else {
    tmp = curr;
    prev->next = curr->next;
    free(tmp);
  }

  return 1;
}
