#ifndef LIST_REC_H
  #define LIST_REC_H

  #include <stdbool.h>
  #include <stdio.h>

  typedef struct listNode ListNode, *ListNodePtr;

  struct listNode {
    int data;
    ListNodePtr next;
  };

  // Ritorna una lista contenente tutti i numeri interi compresi tra @m ed @n,
  // estremi inclusi.
  ListNodePtr fromTo_rec(int m, int n);

  // Conta il numero di occorrenze di @x nella lista @lp.
  int occurrences_rec(ListNodePtr lp, int x);

  // Ritorna true se tutti gli elementi nella lista @lp1 compaiono nello stesso
  // ordine anche nella lista @lp2.
  _Bool included_rec(ListNodePtr l1p, ListNodePtr l2p);
  
  // Ritorna una nuova lista con gli elementi di @lp in ordine inverso.
  ListNodePtr reverse_rec(ListNodePtr lp);

  // Ritorna la lista i cui elementi sono le somme a coppie degli elementi
  // corrispondenti di due liste @lp1 e @lp2 di uguale lunghezza ricorsiva.
  ListNodePtr zipSum_rec(ListNodePtr lp1, ListNodePtr lp2);

#endif
