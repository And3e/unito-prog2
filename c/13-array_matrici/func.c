#include "func.h"

char *binarizza(char *str) {
  
}

int conv_palindroma(char *str) {

}

int *pari_dispari(int **str, int N) {
  if (!str) {
    return NULL;
  }

  int *out = malloc(sizeof(int) * N);
  if (!out) {
    return NULL;
  }

  for (int i = 0; i < N; i++) {
    if (!str[i]) {
      free(out);
      return NULL;
    }

    int s = 0;
    for (int j = 0; j < N; j++) {
      s += str[i][j];
    }

    out[i] = !(s % 2);
  }

  return out;
}
