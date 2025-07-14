#ifndef LIST_ITER_H
#define LIST_ITER_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct listNode ListNode, *ListNodePtr;

struct listNode {
  int data;
  ListNodePtr next;
};

ListNodePtr create_node(int data);

void add_node(ListNodePtr *lst, int data);

// Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
// estremi inclusi.
ListNodePtr fromTo_iter(int m, int n);

// Ritorna true se tutti gli elementi nella lista @ls1 compaiono nello stesso
// ordine anche nella lista @ls2.
_Bool included_iter(ListNodePtr ls1, ListNodePtr ls2);

// Ritorna una nuova lista con gli elementi di @ls in ordine inverso (non
// modifica la lista @ls).
ListNodePtr reverse_iter(ListNodePtr ls);

// Ritorna la lista i cui elementi sono le somme a coppie degli elementi
// corrispondenti di due liste @ls1 e @ls2 di uguale lunghezza (non modifica la
// liste @ls1 e @ls2).
ListNodePtr zipSum_iter(ListNodePtr ls1, ListNodePtr ls2);

// Conta il numero di occorrenze di @x nella lista @ls.
int occurrences_iter(ListNodePtr ls, int x);

// Toglie tutte le occorrenze di @x dalla lista *@p_ls  (modifica *@p_ls).
void remove_all_iter(ListNodePtr *p_ls, int x);

// Duplica tutti i nodi della lista *@p_ls che contengono un numero pari
// (modifica *@p_ls).
void duplicate_even_iter(ListNodePtr *p_ls);

#endif