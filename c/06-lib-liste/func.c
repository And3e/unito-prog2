#include "func.h"

void *create_space(size_t count, size_t type_size) {
  void *ptr = malloc(count * type_size);
  if (ptr == NULL) {
    perror("Error while allocating a variable");
  }
  return ptr;
}

void *create_musthave_space(size_t count, size_t type_size, int retries) {
  void *ptr = NULL;
  while (retries-- > 0) {
    ptr = malloc(count * type_size);
    if (ptr != NULL) {
      return ptr;
    }
  }

  perror("Error while allocating a variable");
  exit(EXIT_FAILURE);
}

void add_node_last(list l, node n) {
  if (l == NULL) {
    return;
  }

  node *new_node = malloc(sizeof(node));
  if (!new_node) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }

  *new_node = n;
  new_node->next = NULL;

  node *tmp = l;
  while (tmp->next != NULL) {
    tmp = tmp->next;
  }
  new_node->id = tmp->id + 1;
  tmp->next = new_node;
}

void add_node_last_ptr(list *l, node n) {
  node *new_node = malloc(sizeof(node));
  if (!new_node) {
    perror("malloc");
    exit(EXIT_FAILURE);
  }
  *new_node = n;
  new_node->next = NULL;
  if (*l == NULL) {
    new_node->id = 0;
    *l = new_node;
  } else {
    node *tmp = *l;
    while (tmp->next)
      tmp = tmp->next;
    new_node->id = tmp->id + 1;
    tmp->next = new_node;
  }
}

void add_node_first(list l, node n) {
  if (l == NULL) {
    return;
  }

  node *new_node = create_musthave_space(1, sizeof(node), 5);
  *new_node = n;

  new_node->next = l->next;
  new_node->id = l->id + 1;
  l->next = new_node;
}

void add_node_first_ptr(list *l, node n) {
  node *new_node = create_musthave_space(1, sizeof(node), 5);
  *new_node = n;
  new_node->next = *l;
  new_node->id = 0;
  *l = new_node;
}

void add_node_position(list l, node n, int position) {
  if (l == NULL) {
    return;
  }

  if (position <= 0) {
    add_node_first(l, n);
    return;
  }
  node *current = l;
  int i = 0;

  while (i < position && current->next != NULL) {
    current = current->next;
    i++;
  }

  node *new_node = create_musthave_space(1, sizeof(node), 5);
  *new_node = n;
  new_node->next = current->next;

  new_node->id = current->id + 1;
  current->next = new_node;
}

void add_node_position_ptr(list *l, node n, int position) {
  if (position <= 0 || *l == NULL) {
    add_node_first_ptr(l, n);
    return;
  }
  node *current = *l;
  int i = 0;
  while (i < position - 1 && current->next) {
    current = current->next;
    i++;
  }
  node *new_node = create_musthave_space(1, sizeof(node), 5);
  *new_node = n;
  new_node->next = current->next;
  new_node->id = current->id + 1;
  current->next = new_node;
}

void set_list_id(list l, int start_id) {
  node *current = l;
  int id = start_id;

  while (current != NULL) {
    current->id = id;
    id++;
    current = current->next;
  }
}

void set_list_id_ptr(list *l, int start_id) {
  node *current = *l;
  int id = start_id;
  while (current) {
    current->id = id++;
    current = current->next;
  }
}

void remove_position(list l, int position) {
  if (l == NULL) {
    return;
  }

  if (position <= 0) {
    remove_first(l);
    return;
  }

  node *prev = l;
  node *current = l->next;

  int i = 0;
  while (current != NULL && i < position) {
    prev = current;
    current = current->next;
    i++;
  }

  if (current != NULL) {
    prev->next = current->next;
    free(current);
  }
}

void remove_position_ptr(list *l, int position) {
  if (*l == NULL)
    return;
  if (position <= 0) {
    remove_first_ptr(l);
    return;
  }
  node *prev = *l;
  node *current = (*l)->next;
  int i = 1;
  while (current && i < position) {
    prev = current;
    current = current->next;
    i++;
  }
  if (current) {
    prev->next = current->next;
    free(current);
  }
}

void remove_first(list l) {
  if (l == NULL || l->next == NULL) {
    return;
  }

  node *first = l->next;
  l->next = first->next;
  free(first);
}

void remove_first_ptr(list *l) {
  if (*l == NULL)
    return;
  node *temp = *l;
  *l = (*l)->next;
  free(temp);
}

void remove_last(list l) {
  if (l == NULL || l->next == NULL) {
    return;
  }
  node *prev = l;
  node *current = l->next;
  while (current->next != NULL) {
    prev = current;
    current = current->next;
  }
  prev->next = NULL;
  free(current);
}

void remove_last_ptr(list *l) {
  if (*l == NULL)
    return;
  if ((*l)->next == NULL) {
    free(*l);
    *l = NULL;
    return;
  }
  node *prev = *l;
  node *current = (*l)->next;
  while (current->next) {
    prev = current;
    current = current->next;
  }
  prev->next = NULL;
  free(current);
}

void free_list(list l) {
  node *current = l;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
}

void free_list_ptr(list *l) {
  node *current = *l;
  while (current != NULL) {
    node *next = current->next;
    free(current);
    current = next;
  }
}

int count_nodes(list l) {
  int count = 0;
  node *current = l;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

int count_nodes_ptr(list *l) {
  int count = 0;
  node *current = *l;
  while (current != NULL) {
    count++;
    current = current->next;
  }
  return count;
}

node *search_node(list l, int target_id) {
  node *current = l;
  while (current != NULL) {
    if (current->id == target_id) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

node *search_node_ptr(list *l, int target_id) {
  node *current = *l;
  while (current != NULL) {
    if (current->id == target_id) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

node *reverse_listR(node *head) {
  if (head == NULL || head->next == NULL) {
    return head;
  }
  node *rest = reverse_listR(head->next);
  head->next->next = head;
  head->next = NULL;
  return rest;
}

list reverse_list(list l) { return reverse_listR(l); }

void reverse_list_ptr(list *l) {
  if (l == NULL) {
    return;
  }
  *l = reverse_list(*l);
}

void print_list(list l) {
  if (l == NULL) {
    return;
  }

  node *current = l;
  while (current != NULL) {
    printf("Node ID: %d\n", current->id);
    current = current->next;
  }
}

void print_list_ptr(list *l) {
  if (*l == NULL)
    return;
  node *current = *l;
  while (current) {
    printf("Node ID: %d\n", current->id);
    current = current->next;
  }
}
