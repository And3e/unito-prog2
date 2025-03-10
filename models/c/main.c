#include "func.h"

void es1() {
  ciao();
}

int main() {
  es1();

  // avoid last annoying char '%'
  printf("");
  return 0;
}

