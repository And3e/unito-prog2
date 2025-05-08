#include "func.h"

int main(void) {
  int n = 10, m = n;

  int **mat = malloc(sizeof(int *) * n);
  if (!mat) {
    return 1;
  }

  for (int i = 0; i < n; i++) {
    mat[i] = calloc(m, sizeof(int));

    if (!mat[i]) {
      while (i-- > 0) {
        free(mat[i]);
      }

      free(mat);
      return 1;
    }
  }

  int *result = pari_dispari(mat, n);
  printf("first call returned %lx\n", (unsigned long int)result);

  mat[0][5] = 1;
  mat[0][9] = 1;

  free(result);
  result = pari_dispari(mat, n);

  if (result) {
    for (int i = 0; i < n; i++) {
      printf("%d", result[i]);
    }

    printf("\n");
    free(result);
  }

  for (int i = 0; i < n; i++) {
    free(mat[i]);
  }
  free(mat);

  return 0;
}
