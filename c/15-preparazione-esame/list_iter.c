#include "list_iter.h"

ListNodePtr create_node(int data) {
  ListNodePtr out = malloc(sizeof(ListNode));

  if (!out) {
    return NULL;
  }

  out->data = data;
  out->next = NULL;

  return out;
}

void add_node(ListNodePtr *lst, int data) {
  if (!lst || !(*lst)) {
    return;
  }

  ListNodePtr node = create_node(data);
  if (!node) {
    return;
  }

  ListNodePtr tmp = *lst;

  while (tmp->next) {
    tmp = tmp->next;
  }

  tmp->next = node;
}

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
// estremi inclusi.
ListNodePtr fromTo_iter(int m, int n) {
  int min = m < n ? m : n;
  int max = m > n ? m : n;

  ListNodePtr out = create_node(min);
  ListNodePtr tmp = out;

  for (int i = min + 1; i <= max; i++) {
    tmp->next = create_node(i);
    tmp = tmp->next;
  }

  return out;
}

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso
// ordine anche nella lista @ls2.
_Bool included_iter(ListNodePtr ls1, ListNodePtr ls2) {
  while (ls1->next && ls2->next) {
    if(ls1->data == ls2->data) {
      ls1 = ls1->next;
    }

    ls2 = ls2->next;
  }

  if(ls1->next) {
    return false;
  }

  return true;
}

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non
// modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls) {
  if (!ls) {
    return NULL;
  }

  ListNodePtr out = create_node(ls->data);
  ls = ls->next;

  ListNodePtr tmp;
  while (ls) {
    tmp = out;
    out = create_node(ls->data);
    out->next = tmp;

    ls = ls->next;
  }

  return out;
}

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi
// corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la
// liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2) {
  if (!ls1 || !ls2) {
    return NULL;
  }

  ListNodePtr out = create_node(ls1->data + ls2->data);
  ls1 = ls1->next;
  ls2 = ls2->next;

  while (ls1 && ls2) {
    add_node(&out, ls1->data + ls2->data);

    ls1 = ls1->next;
    ls2 = ls2->next;
  }

  return out;
}

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x) {
  if (!ls) {
    return 0;
  }

  int count = 0;
  while (ls) {
    if (ls->data == x) {
      count++;
    }
    ls = ls->next;
  }

  return count;
}

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x) {
  if (!p_ls || !(*p_ls)) {
    return;
  }

  ListNodePtr prev = NULL;
  ListNodePtr current = *p_ls;
  ListNodePtr tmp;

  while (current) {
    if (current->data == x) {
      if (!prev) {
        tmp = current;
        current = current->next;
        free(tmp);
      } else {
        prev->next = current->next;
        free(current);
        current = prev->next;
      }
    }

    prev = current;
    current = current->next;
  }
}

// Duplica tutti i nodi della lista *@p_ls che contengono un numero pari
// (modifica *@p_ls).
void duplicate_even_iter(ListNodePtr *p_ls) {
  if (!p_ls || !(*p_ls)) {
    return;
  }

  ListNodePtr current = *p_ls;
  ListNodePtr tmp;

  while (current) {
    if (!(current->data % 2)) {
      tmp = current->next;
      current->next = create_node(current->data);
      current->next->next = tmp;
      current = current->next;
    }

    current = current->next;
  }
}