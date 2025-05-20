#include "ram.h"

RAM initram(int M) {
  if (M < 1 || (M & (M - 1)) != 0) {
    return NULL;
  }

  RAM ram = malloc(sizeof(struct nodo));

  if (!ram) {
    return NULL;
  }

  ram->KB = M;
  ram->s = LIBERO;
  ram->parent = NULL;
  ram->lbuddy = NULL;
  ram->rbuddy = NULL;

  return ram;
}

RAM allocram(int K, RAM ram) {
  if (!ram || ram->s == OCCUPATO || ram->KB < K || K < 1) {
    return NULL;
  }

  if (ram->s == LIBERO) {
    if (ram->KB == K || ram->KB / 2 < K) {
      ram->s = OCCUPATO;
      return ram;
    }
  }

  ram->s = INTERNO;

  // Creo sub-buddies se non esistono
  if (!ram->lbuddy) {
    ram->lbuddy = initram(ram->KB / 2);

    if (!ram->lbuddy) {
      return NULL;
    }
    ram->lbuddy->parent = ram;
  }

  if (!ram->rbuddy) {
    ram->rbuddy = initram(ram->KB / 2);

    if (!ram->rbuddy) {
      return NULL;
    }
    ram->rbuddy->parent = ram;
  }

  RAM left = allocram(K, ram->lbuddy);
  if (left) {
    return left;
  }

  return allocram(K, ram->rbuddy);
}

Risultato compatta(RAM ram) {
  if (!ram) {
    return NOK;
  }

  if (ram->lbuddy && ram->lbuddy->s == LIBERO && ram->rbuddy &&
      ram->rbuddy->s == LIBERO) {
    free(ram->lbuddy);
    free(ram->rbuddy);
    ram->lbuddy = NULL;
    ram->rbuddy = NULL;
    ram->s = LIBERO;
    return OK;
  }

  return NOK;
}

Risultato deallocram(RAM ram) {
  if (!ram || ram->s != OCCUPATO) {
    return NOK;
  }

  ram->s = LIBERO;

  do {
    ram = ram->parent;
  } while (compatta(ram) == OK);

  return OK;
}

int numfree(RAM ram) {
  if (!ram) {
    return -1;
  }

  if (ram->s == LIBERO) {
    return ram->KB;
  }

  if (ram->s == OCCUPATO) {
    return 0;
  }

  int sum = 0;
  if (ram->lbuddy) {
    sum += numfree(ram->lbuddy);
  }

  if (ram->rbuddy) {
    sum += numfree(ram->rbuddy);
  }

  return sum;
}

// https://www.cs.yale.edu/homes/aspnes/pinewiki/C(2f)Structs.html
typedef struct {
  char *str;
  size_t lenght, capacity;
} String;

void init_string(String *s) {
  s->capacity = 128;
  s->lenght = 0;
  s->str = malloc(s->capacity);

  s->str[0] = '\0';
}

void append_char(String *s, char c) {
  if (s->lenght + 2 > s->capacity) {
    s->capacity *= 2;
    s->str = realloc(s->str, s->capacity);
  }

  s->str[s->lenght++] = c;
  s->str[s->lenght] = '\0';
}

void append_str(String *s, char *string) {
  size_t lenght = strlen(string);

  if (s->lenght + lenght + 1 > s->capacity) {
    s->capacity = s->lenght + lenght + 1;
    s->str = realloc(s->str, s->capacity);
  }

  // copio string in str + lenght
  memcpy(s->str + s->lenght, string, lenght + 1);
  s->lenght += lenght;
}

void ram2strR(RAM ram, String *out, int lvl, char bud) {
  if (!ram) {
    return;
  }

  char temp[32];
  char state = ram->s == LIBERO ? 'L' : ram->s == INTERNO ? 'I' : 'O';

  // metto "#<lvl><bud>:<state> dentro temp"
  snprintf(temp, sizeof temp, "#%d%c:%c", lvl, bud, state);

  append_str(out, temp);

  ram2strR(ram->lbuddy, out, lvl + 1, 'l');
  ram2strR(ram->rbuddy, out, lvl + 1, 'r');
}

// https://www.ibm.com/docs/it/i/7.6.0?topic=files-stringh
// https://www.ibm.com/docs/it/i/7.6.0?topic=functions-snprintf-print-formatted-data-buffer
char *ram2str(RAM ram) {
  if (!ram) {
    char *out = malloc(1);
    *out = '\0';
    return out;
  }

  //          r─ 2KB [L]
  //      r─ 4KB [I]
  //          l─ 2KB [O]
  //  *─ 8KB [I]
  //          r─ 2KB [O]
  //      l─ 4KB [I]
  //              r─ 1KB [L]
  //          l─ 2KB [I]
  //              l─ 1KB [O]
  //
  // "8:I#1l:I#2l:I#3l:O#3r:L#2r:O#1r:I#2l:O#2r:L"

  String out;
  init_string(&out);

  char tmp[32];

  char state = ram->s == LIBERO ? 'L' : ram->s == INTERNO ? 'I' : 'O';
  snprintf(tmp, sizeof tmp, "%d:%c", ram->KB, state);

  append_str(&out, tmp);

  ram2strR(ram->lbuddy, &out, 1, 'l');
  ram2strR(ram->rbuddy, &out, 1, 'r');

  return out.str;
}

// https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
int split(char *src_string, char delimiter, char ***out_array) {
  int el_count = 0;
  char *p;

  // se stringa vuota = 0 elementi
  if (src_string[0] != '\0') {
    el_count = 1;
    for (p = src_string; *p != '\0'; p++) {
      if (*p == delimiter) {
        el_count++;
      }
    }
  }

  char **tokens = malloc((el_count + 1) * sizeof(char *));
  if (!tokens) {
    *out_array = NULL;
    return 0;
  }

  int current = 0;
  char *token_start = src_string;
  bool exit = false;

  for (p = src_string; !exit; p++) {
    if (*p == delimiter || *p == '\0') {
      size_t len = p - token_start;

      tokens[current] = malloc(len + 1);

      if (!tokens[current]) {
        // cancello tutto se uno non alloca
        for (int i = 0; i < current; i++) {
          free(tokens[i]);
        }
        free(tokens);

        *out_array = NULL;
        return 0;
      }

      // copio token_start fino a len dentro tokens[current]
      memcpy(tokens[current], token_start, len);
      tokens[current][len] = '\0';
      current++;

      if (*p == '\0' || *(p + 1) == '\0') {
        exit = true;
      }
      // skippo il delimiter
      token_start = p + 1;
    }
  }

  tokens[current] = NULL;

  *out_array = tokens;

  return el_count;
}

int first_number(char *s) {
  while (*s) {
    if ((unsigned char)*s >= '0' && (unsigned char)*s <= '9') {
      int value = 0;

      while ((unsigned char)*s >= '0' && (unsigned char)*s <= '9') {
        value = value * 10 + (*s - '0');
        s++;
      }

      return value;
    }
    s++;
  }
  return 0;
}

void str2ramR(RAM parent, char **tokens, int size, int level) {
  if (!parent || size <= 0) {
    return;
  }

  int child_level = level + 1;
  // default split index = il più a DX
  int split = size;

  // split index
  for (int i = 0; i < size; i++) {
    int level = first_number(tokens[i]);

    const char *p = tokens[i];
    while (*p >= '0' && *p <= '9') {
      p++;
    }

    // gemello DX del parent
    if (level == child_level && *p == 'r') {
      split = i;

      // exit
      i = size;
    }
  }

  // left buddy  -->  |---|___|
  if (split > 0) {
    RAM left = initram(parent->KB / 2);
    
    left->parent = parent;
    parent->lbuddy = left;
    
    char state = tokens[0][strlen(tokens[0]) - 1];
    left->s = (state == 'L' ? LIBERO : state == 'O' ? OCCUPATO : INTERNO);
    
    str2ramR(left, tokens + 1, split - 1, child_level);
  }
  
  // right buddy  -->  |___|---|
  if (split < size) {
    RAM right = initram(parent->KB / 2);

    right->parent = parent;
    parent->rbuddy = right;

    char state = tokens[split][strlen(tokens[split]) - 1];
    right->s = (state == 'L' ? LIBERO : state == 'O' ? OCCUPATO : INTERNO);

    str2ramR(right, tokens + 1 + split, size - 1 - split, child_level);
  }
}

RAM str2ram(char *str) {
  if (!str || *str == '\0') {
    return NULL;
  }

  char **tokens;

  int count = split(str, '#', &tokens);
  if (count <= 0) {
    return NULL;
  }

  // "<size>:<state>"
  int size = first_number(tokens[0]);
  RAM ram = initram(size);

  if (ram) {
    char state = tokens[0][strlen(tokens[0]) - 1];
    ram->s = (state == 'L' ? LIBERO : state == 'O' ? OCCUPATO : INTERNO);

    if (ram->s == INTERNO) {
      // recurse on all remaining tokens
      str2ramR(ram, tokens + 1, count - 1, 0);
    }
  }

  for (int i = 0; i < count; i++) {
    free(tokens[i]);
  }
  free(tokens);

  return ram;
}

Risultato freeram(RAM *ramptr) {
  if (!ramptr || !*ramptr) {
    return NOK;
  }

  RAM node = *ramptr;

  if (node->lbuddy) {
    freeram(&node->lbuddy);
  }
  if (node->rbuddy) {
    freeram(&node->rbuddy);
  }

  free(node);

  *ramptr = NULL;

  return OK;
}
