#include "tree_iter.h"

enum response { ADDED, OVERWRITTEN, OUT_OF_MEMORY, ERROR };

typedef enum response Response;

typedef struct intTreeNode IntTreeNode, *IntTree;
struct intTreeNode {
  IntTree left;
  int data;
  IntTree right;
};

/**
 * @brief Mette nell'albero l'elemento e nella  posizione identificata da path
 * (una stringa di caratteri ``L '' per left e ``R'' per right). Ovvero:
 *  - se path porta a un nodo, assegna e al campo `data`di quel nodo
 *  - se path porta fuori dall'abero, inserisce come figlio della foglia da cui
 * è usciti dallalbero un nuovo nodo che contiene e. Restituisce:
 * - ADDED se ha aggiunto un nuovo nodo,
 *   - OUT_OF_MEMORY se la malloc fallisce,
 * - OVERWRITTEN se ha modificato nodo esistente,
 * - ERROR se path`contiene un carattere diverso da `L`o `R prima di uscire
 * dall'albero
 */

IntTree create_tree(int data) {
  IntTree out = malloc(sizeof(IntTreeNode));

  if (!out) {
    return NULL;
  }

  out->data = data;
  out->left = NULL;
  out->right = NULL;

  return out;
}

Response putIter(IntTree *treePtr, char *path, int e) {
  if (!treePtr)
    return ERROR;

  if (path[0] == '\0') {
    if (*treePtr == NULL) {
      *treePtr = create_tree(e);
      return *treePtr ? ADDED : OUT_OF_MEMORY;
    } else {
      (*treePtr)->data = e;
      return OVERWRITTEN;
    }
  }

  IntTree *current = treePtr;
  char *p = path;

  while (*(p + 1)) {
    if (*p == 'L' || *p == 'l') {
      if (*current == NULL) {
        *current = create_tree(0);

        if (*current == NULL) {
          return OUT_OF_MEMORY;
        }
      }
      current = &((*current)->left);
    } else if (*p == 'R' || *p == 'r') {
      if (*current == NULL) {
        *current = create_tree(0);

        if (*current == NULL) {
          return OUT_OF_MEMORY;
        }
      }
      current = &((*current)->right);
    } else {
      return ERROR;
    }
    p++;
  }

  if (*p == 'L' || *p == 'l') {
    if (*current == NULL) {
      *current = create_tree(0);
      if (*current == NULL) {
        return OUT_OF_MEMORY;
      }
    }

    if ((*current)->left) {
      (*current)->left->data = e;
      return OVERWRITTEN;
    } else {
      (*current)->left = create_tree(e);
      return (*current)->left ? ADDED : OUT_OF_MEMORY;
    }

  } else if (*p == 'R' || *p == 'r') {
    if (*current == NULL) {
      *current = create_tree(0);
      if (*current == NULL) {
        return OUT_OF_MEMORY;
      }
    }

    if ((*current)->right) {
      (*current)->right->data = e;
      return OVERWRITTEN;
    } else {
      (*current)->right = create_tree(e);
      return (*current)->right ? ADDED : OUT_OF_MEMORY;
    }
  }

  return ERROR;
}

typedef struct {
  char *str;
  size_t length, capacity;
} String;

void init_string(String *s) {
  s->capacity = 128;
  s->length = 0;
  s->str = malloc(s->capacity);

  s->str[0] = '\0';
}

void append_str(String *s, char *string) {
  size_t length = strlen(string);

  if (s->length + length + 1 > s->capacity) {
    s->capacity = s->length + length + 1;
    s->str = realloc(s->str, s->capacity);
  }

  // copio string in str + length
  memcpy(s->str + s->length, string, length + 1);
  s->length += length;
}

void tree_to_strR(IntTree tree, String *out, int lvl, char bud) {
  if (!tree) {
    return;
  }

  char temp[32];

  // "#<lvl><bud>:<data>"
  snprintf(temp, sizeof temp, "#%d%c:%d", lvl, bud, tree->data);

  append_str(out, temp);

  tree_to_strR(tree->left, out, lvl + 1, 'l');
  tree_to_strR(tree->right, out, lvl + 1, 'r');
}

char *tree_to_str(IntTree tree) {
  if (!tree) {
    char *out = malloc(1);
    *out = '\0';
    return out;
  }

  String out;
  init_string(&out);

  char tmp[32];

  // "@:<data>"
  snprintf(tmp, sizeof tmp, "@:%d", tree->data);

  append_str(&out, tmp);

  tree_to_strR(tree->left, &out, 1, 'l');
  tree_to_strR(tree->right, &out, 1, 'r');

  return out.str;
}

_Bool str_contains(char *str, char *target) {
  char *tmp = target;
  bool checking = false;

  while (*str != '\0' && *tmp != '\0') {
    if (*tmp == *str) {
      checking = true;
      tmp++;
    } else {
      checking = false;
      tmp = target;
    }

    str++;
  }

  if (checking && *tmp == '\0') {
    return true;
  }

  return false;
}

/**
 * @brief Controlla se il secondo albero è una potatura del primo
 */
_Bool isPruningIter(IntTree tree, IntTree pruned) {
  char *tree_str = tree_to_str(tree);
  char *pruned_str = tree_to_str(pruned);

  if (str_contains(tree_str, pruned_str)) {
    return true;
  }

  return false;
}

int count_tree_nodes(IntTree tree) {
  if (!tree) {
    return 0;
  }

  return 1 + count_tree_nodes(tree->left) + count_tree_nodes(tree->right);
}

/**
 * @brief Dato un ARB con restituisce un array che contiene tutti gli elementi
 * dell'ARB in un pre-ordine tale che, se gli elementi sono tutti distinti,
 * allora inserendoli in quell'ordine nell'ARB vuoto si ricostruisce l'ARB
 * originale.
 */

void tree_to_arrayR(IntTree tree, int *array, int *index) {
  if (!tree) {
    return;
  }

  array[(*index)] = tree->data;
  (*index)++;

  tree_to_arrayR(tree->left, array, index);
  tree_to_arrayR(tree->right, array, index);
}

int *treeToArray(IntTree tree) {
  if (!tree)
    return NULL;

  int size = count_tree_nodes(tree);
  int *array = malloc(sizeof(int) * size);
  if (!array)
    return NULL;

  int index = 0;
  tree_to_arrayR(tree, array, &index);

  return array;
}

typedef struct report Report, *ReportPtr;

struct report {
  int min;
  int max;
};

typedef struct charTreeNode CharTreeNode, *CharTree;

struct charTreeNode {
  CharTree left;
  char data;
  CharTree right;
};

/**
 * @brief Dato un albero binario restituisce le profondità minima e massima
 * delle sue foglie (considerate entrambe -1 se l’albero è vuoto).
 */
// ReportPtr minMaxLevel_iter(CharTree tree) {}
