#include "list_rec.h"

// typedef struct listNode ListNode, *ListNodePtr;

// struct listNode {
//   int data;
//   ListNodePtr next;
// };

void free_list(ListNodePtr list) {
  list = NULL;
  free(list);
}

ListNodePtr getNewNode(int data) {
  ListNodePtr new_node = malloc(sizeof(ListNode));

  new_node->data = data;
  new_node->next = NULL;

  return new_node;
}

void addNode(ListNodePtr *list, int data) {
  ListNodePtr new_node = getNewNode(data);
  if (*list == NULL) {
    *list = new_node;
  } else {
    ListNodePtr current = *list;
    while (current->next != NULL) {
      current = current->next;
    }
    current->next = new_node;
  }
}

void fromTo_recR(ListNodePtr l, int n) {
  if (l != NULL && l->data < n) {
    addNode(&l, l->data + 1);
    fromTo_recR(l->next, n);
  }
}

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
// estremi inclusi.
ListNodePtr fromTo_rec(int m, int n) {
  int first = m > n ? n : m;
  int last = m > n ? m : n;

  ListNodePtr new_list = getNewNode(first);

  fromTo_recR(new_list, last);

  return new_list;
}

// Conta il numero di occorrenze di @x nella lista @lp.
int occurrences_rec(ListNodePtr lp, int x) {
  if (lp == NULL) {
    return 0;
  }

  if (lp->data == x) {
    return 1 + occurrences_rec(lp->next, x);
  }

  return occurrences_rec(lp->next, x);
}

// Ritorna true se tutti gli elementi nella lista @lp1 compaiono nello stesso
// ordine anche nella lista @lp2.
_Bool included_rec(ListNodePtr l1p, ListNodePtr l2p) {
  if (l1p->data != l2p->data && l1p->next != NULL && l2p->next == NULL) {
    return false;
  }

  if (l1p->next == NULL) {
    return true;
  }

  if (l1p->data != l2p->data) {
    return included_rec(l1p, l2p->next);
  }

  return included_rec(l1p->next, l2p->next);
}

void reverse_recR(ListNodePtr lp, ListNodePtr *reversed) {
  if(lp->next != NULL) {
    reverse_recR(lp->next, reversed);
  }

  addNode(reversed, lp->data);
}

// Ritorna una nuova lista con gli elementi di @lp in ordine inverso.
ListNodePtr reverse_rec(ListNodePtr lp) {
  ListNodePtr reversed = NULL;

  reverse_recR(lp, &reversed);

  return reversed;
}

void zipSum_recR(ListNodePtr lp1, ListNodePtr lp2, ListNodePtr *sum) {
  if(lp1 != NULL || lp2 != NULL) {
    addNode(sum, lp1->data + lp2->data);
    zipSum_recR(lp1->next, lp2->next, sum);
  }
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi
// corrispondenti di due liste @lp1 e @lp2 di uguale lunghezza ricorsiva.
ListNodePtr zipSum_rec(ListNodePtr lp1, ListNodePtr lp2) {
  ListNodePtr sum = NULL;

  zipSum_recR(lp1, lp2, &sum);

  return sum;
}