#include "func.h"

int main() {
  Contact c1, c2;

  c1.name = "Giulio";
  c1.surname = "Ciglione";

  c2.name = "Andrea";
  c2.surname = "Favaro";

  printf("Test su c1 e c2 (contatti diversi):\n");
  printf("contactEq(c1, c2): %d -> %s\n", contactEq(c1, c2),
         contactEq(c1, c2) == 0 ? "Test passato" : "Test non passato");
  printf("contactEqEff(&c1, &c2): %d -> %s\n", contactEqEff(&c1, &c2),
         contactEqEff(&c1, &c2) == 0 ? "Test passato" : "Test non passato");

  int cmp = contactCmp(c1, c2);
  int cmpEff = contactCmpEff(&c1, &c2);
  printf("contactCmp(c1, c2): %d -> %s\n", cmp,
         cmp < 0 ? "Test passato" : "Test non passato");
  printf("contactCmpEff(&c1, &c2): %d -> %s\n", cmpEff,
         cmpEff < 0 ? "Test passato" : "Test non passato");

  if (cmp < 0) {
    printf("c1 precede c2 (in base al cognome e nome)\n");
  } else if (cmp > 0) {
    printf("c1 succede c2 (in base al cognome e nome)\n");
  } else {
    printf("c1 e c2 sono uguali (in base a cognome e nome)\n");
  }

  // Test con c3 e c4: contatti uguali
  Contact c3, c4;
  c3.name = "Marco";
  c3.surname = "Rossi";

  c4.name = "Marco";
  c4.surname = "Rossi";

  printf("\nTest su c3 e c4 (contatti uguali):\n");
  printf("contactEq(c3, c4): %d -> %s\n", contactEq(c3, c4),
         contactEq(c3, c4) == 1 ? "Test passato" : "Test non passato");
  printf("contactEqEff(&c3, &c4): %d -> %s\n", contactEqEff(&c3, &c4),
         contactEqEff(&c3, &c4) == 1 ? "Test passato" : "Test non passato");

  cmp = contactCmp(c3, c4);
  cmpEff = contactCmpEff(&c3, &c4);
  printf("contactCmp(c3, c4): %d -> %s\n", cmp,
         cmp == 0 ? "Test passato" : "Test non passato");
  printf("contactCmpEff(&c3, &c4): %d -> %s\n", cmpEff,
         cmpEff == 0 ? "Test passato" : "Test non passato");

  // Test con c5 e c6: stessi cognomi, nomi differenti
  Contact c5, c6;
  c5.name = "Alberto";
  c5.surname = "Verdi";

  c6.name = "Zeno";
  c6.surname = "Verdi";

  printf("\nTest su c5 e c6 (stesso cognome, nome diverso):\n");
  printf("contactEq(c5, c6): %d -> %s\n", contactEq(c5, c6),
         contactEq(c5, c6) == 0 ? "Test passato" : "Test non passato");
  printf("contactEqEff(&c5, &c6): %d -> %s\n", contactEqEff(&c5, &c6),
         contactEqEff(&c5, &c6) == 0 ? "Test passato" : "Test non passato");

  cmp = contactCmp(c5, c6);
  cmpEff = contactCmpEff(&c5, &c6);
  printf("contactCmp(c5, c6): %d -> %s\n", cmp,
         cmp < 0 ? "Test passato" : "Test non passato");
  printf("contactCmpEff(&c5, &c6): %d -> %s\n", cmpEff,
         cmpEff < 0 ? "Test passato" : "Test non passato");

  if (cmp < 0) {
    printf("c5 precede c6 (in base al nome, dato che il cognome è uguale)\n");
  } else if (cmp > 0) {
    printf("c5 succede c6 (in base al nome, dato che il cognome è uguale)\n");
  } else {
    printf("c5 e c6 sono uguali (in base a cognome e nome)\n");
  }

  return 0;
}
