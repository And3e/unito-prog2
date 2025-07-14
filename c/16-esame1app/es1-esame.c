#include "es1.h"

int count_nodes(IntList list) {
  if (!list) {
    return 0;
  }

  int count = 0;
  while (list) {
    count++;
    list = list->next;
  }

  return count;
}

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
int eliminaTerzultimo(IntList *lsPtr) {
  if (!lsPtr) {
    return -1;
  }

  int count = count_nodes(*lsPtr);

  if (count < 3) {
    return 0;
  }

  IntList tmp;
  IntList prev = NULL;
  IntList current = *lsPtr;

  for (int i = 0; i < count - 3; i++) {
    prev = current;
    current = current->next;
  }

  if (!prev) {
    tmp = *lsPtr;
    *lsPtr = (*lsPtr)->next;
    free(tmp);
    return 1;
  }

  tmp = prev->next;
  prev->next = tmp->next;
  free(tmp);

  return 1;
}
