#ifndef GUARD_IntLinkedListSortedSetADT
  #define GUARD_IntLinkedListSortedSetADT

  typedef struct listNode ListNode, *ListNodePtr;

  struct listNode {
    int elem;
    ListNodePtr next;
  };

  struct intSortedSet {
    // Punta al primo nodo dell'insieme, se l'insieme e' vuoto vale NULL
    ListNodePtr first;

    // Punta all'ultimo nodo dell'insieme, se l'insieme e' vuoto vale NULL
    ListNodePtr last;

    // Numero di elementi presenti nell'insieme
    int size;
  };

#endif