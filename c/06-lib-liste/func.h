#ifndef _FUNC_H_
  #define _FUNC_H_

  #include <stdio.h>
  #include <stdlib.h>

  typedef struct data {

  } data;

  typedef struct node {
    int id;
    data data;
    node *next;
  } node;

  typedef node *list;

  void *create_space(size_t count, size_t type_size);
  void *create_musthave_space(size_t count, size_t type_size, int retries);

  void add_node_first(list l, node n);
  void add_node_first_ptr(list *l, node n);
  void add_node_last(list l, node n);
  void add_node_last_ptr(list *l, node n);
  void add_node_position(list l, node n, int position);
  void add_node_position_ptr(list *l, node n, int position);

  void set_list_id(list l, int start_id);
  void set_list_id_ptr(list *l, int start_id);

  void remove_position(list l, int position);
  void remove_position_ptr(list *l, int position);
  void remove_first(list l);
  void remove_first_ptr(list *l);
  void remove_last(list l);
  void remove_last_ptr(list *l);
  void free_list(list l);
  void free_list_ptr(list *l);

  int count_nodes(list l);
  int count_nodes_ptr(list *l);
  node* search_node(list l, int target_id);
  node* search_node_ptr(list *l, int target_id);

  list reverse_list(list l);
  void reverse_list_ptr(list *l);

  void print_list(list l);
  void print_list_ptr(list *l);

#endif
