#include <stdbool.h>
#include <stdlib.h>

#include "intLinkedListSortedSetADT.h"
#include "intSortedSetADT.h"

// restituisce un insieme vuoto
IntSortedSetADT mkSSet() {
  IntSortedSetADT set = malloc(sizeof(struct intSortedSet));

  if (set == NULL) {
    return NULL;
  }

  set->first = NULL;
  set->last = NULL;
  set->size = 0;

  return set;
}

// distrugge l'insieme, recuperando la memoria
_Bool dsSSet(IntSortedSetADT *ssptr) {
  if (ssptr == NULL) {
    return false;
  }

  ListNodePtr node = (*ssptr)->first;

  while (node != NULL) {
    ListNodePtr temp = node;
    node = node->next;

    free(temp);
  }

  free(*ssptr);
  *ssptr = NULL;

  return true;
}

_Bool member(const IntSortedSetADT ss, const int elem) {
  ListNodePtr node = ss->first;

  while (node != NULL) {
    if (node->elem == elem) {
      return true;
    }

    node = node->next;
  }

  return false;
}

// aggiunge un elemento all'insieme (restituisce 0 se l'elemento era gia'
// presente, 1 altrimenti)
_Bool sset_add(IntSortedSetADT ss, const int elem) {
  if (!ss) {
    return false;
  }

  ListNodePtr node = malloc(sizeof(struct listNode));

  if (!node) {
    return false;
  }

  node->elem = elem;
  node->next = NULL;

  if (isEmptySSet(ss)) {
    ss->first = node;
    ss->last = node;
    ss->size++;

    return true;
  }

  if (member(ss, elem)) {
    return false;
  }

  ListNodePtr temp = ss->first;
  ListNodePtr dummy = malloc(sizeof(struct listNode));
  ListNodePtr before = dummy;
  before->next = ss->first;

  while (temp != NULL) {
    if (elem < temp->elem) {
      // first
      if (temp->elem == ss->first->elem) {
        node->next = ss->first;
        ss->first = node;
        temp = NULL;
      } else {
        // middle
        before->next = node;
        node->next = temp;
        temp = NULL;
      }
    }

    // last
    if (temp != NULL && temp->next == NULL) {
      ss->last->next = node;
      ss->last = node;
      temp = NULL;
    }

    if (temp != NULL) {
      temp = temp->next;
      before = before->next;
    }
  }

  free(dummy);
  ss->size++;

  return true;
}

_Bool isSSetExistingEmpty(const IntSortedSetADT ss) {
  if (!ss || isEmptySSet(ss)) {
    return true;
  }

  return false;
}

// toglie un elemento all'insieme (restituisce 0 se l'elemento non era presente,
// 1 altrimenti)
_Bool sset_remove(IntSortedSetADT ss, const int elem) {
  if (isSSetExistingEmpty(ss) || !member(ss, elem)) {
    return false;
  }

  ListNodePtr temp = ss->first;
  ListNodePtr dummy = malloc(sizeof(struct listNode));
  ListNodePtr before = dummy;
  before->next = ss->first;

  while (temp != NULL) {
    if (elem == temp->elem) {
      // first
      if (temp->elem == ss->first->elem) {
        ss->first = temp->next;

        if (temp->next == NULL) {
          ss->last = NULL;
        }

        ss->size--;
        free(temp);
        free(dummy);
        return true;
      }
      // middle
      before->next = temp->next;

      // last
      if (before->next == NULL) {
        ss->last = before;
      }

      ss->size--;
      free(temp);
      free(dummy);
      return true;
    }

    if (temp != NULL) {
      temp = temp->next;
      before = before->next;
    }
  }

  return false;
}

// controlla se un elemento appartiene all'insieme

_Bool sset_member(const IntSortedSetADT ss, const int elem) {
  if (isSSetExistingEmpty(ss)) {
    return false;
  }

  ListNodePtr node = ss->first;

  while (node != NULL) {
    if (node->elem == elem) {
      return true;
    }

    node = node->next;
  }

  return false;
}

// controlla se l'insieme e' vuoto
_Bool isEmptySSet(const IntSortedSetADT ss) {
  if (!ss) {
    return false;
  }

  if (ss->size == 0 || ss->first == NULL || ss->last == NULL) {
    return true;
  }

  return false;
}

// restituisce il numero di elementi presenti nell'insieme, -1 se NULL
int sset_size(const IntSortedSetADT ss) {
  if (!ss) {
    return -1;
  }

  return ss->size;
}

int random(int min, int max) {
  if (max < min) {
    int temp = min;
    min = max;
    max = temp;
  }

  return rand() % (max - min + 1) + min;
}

// toglie e restituisce un elemento a caso dall'insieme, restituisce false se
// l'insieme è NULL oppure è vuoto
_Bool sset_extract(IntSortedSetADT ss, int *ptr) {
  // !! PER MOODLE
  srand(time(NULL));

  if (isSSetExistingEmpty(ss)) {
    return false;
  }

  int n = random(0, ss->size - 1);
  ListNodePtr temp = ss->first;

  for (; n > 0; n--) {
    temp = temp->next;
  }

  *ptr = temp->elem;

  return sset_remove(ss, *ptr);
}

// controlla se due insiemi sono uguali
_Bool sset_equals(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if (s1 == s2) {
    return true;
  }

  if (!s1 || !s2 || s1->size != s2->size) {
    return false;
  }

  ListNodePtr l1 = s1->first;
  ListNodePtr l2 = s2->first;

  for (int i = 0; l1 != NULL; i++) {
    if (l1->elem != l2->elem) {
      return false;
    }

    l1 = l1->next;
    l2 = l2->next;
  }

  return true;
}

// controlla se il primo insieme e' incluso nel secondo
_Bool sset_subseteq(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if (!s1 || !s2 || s1->size > s2->size) {
    return false;
  }

  ListNodePtr l1 = s1->first;
  ListNodePtr l2 = s2->first;

  int i = 0;
  bool exit = false;
  while (l1 && l2 && !exit) {
    if (l1->elem == l2->elem) {
      l1 = l1->next;
      l2 = l2->next;
      i++;
    } else if (l1->elem > l2->elem) {
      l2 = l2->next;
    } else {
      exit = true;
    }
  }

  return (bool)(i == s1->size);
}

// contr. se il primo ins. e' incluso strettamente nel secondo
_Bool sset_subset(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if (!s1 || !s2 || s1->size >= s2->size) {
    return false;
  }

  ListNodePtr l1 = s1->first;
  ListNodePtr l2 = s2->first;

  int i = 0;
  bool exit = false;
  while (l1 && l2 && !exit) {
    if (l1->elem == l2->elem) {
      l1 = l1->next;
      l2 = l2->next;
      i++;
    } else if (l1->elem > l2->elem) {
      l2 = l2->next;
    } else {
      exit = true;
    }
  }

  return (bool)(i == s1->size);
}

// restituisce l'unione di due insiemi
IntSortedSetADT sset_union(const IntSortedSetADT s1, const IntSortedSetADT s2) {
  if (!s1 || !s2) {
    return NULL;
  }

  IntSortedSetADT set = mkSSet();

  if (!set) {
    return NULL;
  }

  if (!s1->size && !s2->size) {
    return set;
  }

  ListNodePtr temp = s1->first;
  while (temp != NULL) {
    sset_add(set, temp->elem);
    temp = temp->next;
  }

  temp = s2->first;
  while (temp != NULL) {
    sset_add(set, temp->elem);
    temp = temp->next;
  }

  return set;
}

// restituisce l'intersezione di due insiemi
IntSortedSetADT sset_intersection(const IntSortedSetADT s1,
                                  const IntSortedSetADT s2) {
  if (!s1 || !s2) {
    return NULL;
  }

  IntSortedSetADT set = mkSSet();

  if (!set) {
    return NULL;
  }
  if (!s1->size || !s2->size) {
    return set;
  }

  IntSortedSetADT little = s1;
  IntSortedSetADT big = s2;
  if (s2->size < s1->size) {
    little = s2;
    big = s1;
  }

  ListNodePtr temp = little->first;
  while (temp != NULL) {
    if (member(big, temp->elem)) {
      sset_add(set, temp->elem);
    }
    temp = temp->next;
  }

  return set;
}

IntSortedSetADT sset_deep_copy(const IntSortedSetADT ss) {
  IntSortedSetADT set = mkSSet();

  if (!ss || !set) {
    return NULL;
  }

  ListNodePtr temp = ss->first;
  while (temp != NULL) {
    sset_add(set, temp->elem);
    temp = temp->next;
  }

  return set;
}

// restituisce l’insieme ottenuto dal primo togliendo gli elementi del secondo
IntSortedSetADT sset_subtraction(const IntSortedSetADT s1,
                                 const IntSortedSetADT s2) {
  if (!s1 || !s2) {
    return NULL;
  }

  if (!s2->size) {
    return sset_deep_copy(s1);
  }

  IntSortedSetADT set = mkSSet();

  if (!set) {
    return NULL;
  }

  ListNodePtr temp = s1->first;
  while (temp != NULL) {
    if (!member(s2, temp->elem)) {
      sset_add(set, temp->elem);
    }
    temp = temp->next;
  }
  return set;
}

// restituisce l'elemento minimo
_Bool sset_min(const IntSortedSetADT ss, int *ptr) {
  if (!ss || !ss->size) {
    return false;
  }

  ListNodePtr temp = ss->first;
  *ptr = temp->elem;

  temp = temp->next;
  while (temp != NULL) {
    if (temp->elem < *ptr) {
      *ptr = temp->elem;
    }
    temp = temp->next;
  }

  return true;
}

// restituisce l'elemento massimo
_Bool sset_max(const IntSortedSetADT ss, int *ptr) {
  if (!ss || !ss->size) {
    return false;
  }

  ListNodePtr temp = ss->first;
  *ptr = temp->elem;

  temp = temp->next;
  while (temp != NULL) {
    if (temp->elem > *ptr) {
      *ptr = temp->elem;
    }
    temp = temp->next;
  }
  return true;
}

// toglie e restituisce l'elemento minimo, restituisce false se l'insieme è NULL
// oppure è vuoto
_Bool sset_extractMin(IntSortedSetADT ss, int *ptr) {
  bool min = sset_min(ss, ptr);

  if (!min) {
    return false;
  }

  return sset_remove(ss, *ptr);
}

// toglie e restituisce l'elemento massimo, restituisce false se l'insieme è
// NULL oppure è vuoto
_Bool sset_extractMax(IntSortedSetADT ss, int *ptr) {
  bool max = sset_max(ss, ptr);

  if (!max) {
    return false;
  }

  return sset_remove(ss, *ptr);
}
