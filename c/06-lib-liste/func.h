#ifndef _FUNC_H_
  #define _FUNC_H_

  #include "stdio.h"

  typedef struct data {

  } data;

  typedef struct node {
    int id;
    data data;
    node *next;
  } node;

  typedef node* list;

  void add_node(list l, node n);
  void add_node_last(list l, node n);
  void add_node_position(list l, node n, int position);

  void set_list_id(list l, int start_id);

  void remove_position(list l, int position);
  void remove_first(list l);
  void remove_last(list l);

  void print_list(list l);

#endif
