#include "pari_dispari_reverse.h"

void reverseIntList(IntList *lsPtr) {
  if (!lsPtr || !(*lsPtr)) {
    return;
  }

  IntList prev = NULL;
  IntList current = *lsPtr;
  IntList next;

  while (current) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }

  *lsPtr = prev;
}

void pariDispariReverse(IntList *lsPtr, IntList *lsPari, IntList *lsDispari) {
  if (!lsPtr || !(*lsPtr)) {
    return;
  }

  int pos = 0;

  IntList head = *lsPtr;

  IntList pCurrent = *lsPari;
  IntList pHead = *lsPari;

  IntList dHead = *lsDispari;
  IntList dCurrent = *lsDispari;

  while (head) {
    if (pos % 2) {
      if (dCurrent) {
        dCurrent->next = head;
        dCurrent = dCurrent->next;
      } else {
        dHead = head;
        dCurrent = head;
      }
    } else {
      if (pCurrent) {
        pCurrent->next = head;
        pCurrent = pCurrent->next;
      } else {
        pHead = head;
        pCurrent = head;
      }
    }

    pos++;
    head = head->next;
  }

  *lsPtr = NULL;

  *lsPari = pHead;
  if (pCurrent) {
    pCurrent->next = NULL;
  }

  *lsDispari = dHead;
  if (dCurrent) {
    dCurrent->next = NULL;
  }

  reverseIntList(lsPari);
  reverseIntList(lsDispari);
}