#include "func.h"

_Bool contactEq(Contact c1, Contact c2) {
  return (strcmp(c1.name, c2.name) == 0 && strcmp(c1.surname, c2.surname) == 0);
}

_Bool contactEqEff(const Contact *pc1, const Contact *pc2) {
  return (strcmp(pc1->name, pc2->name) == 0 &&
          strcmp(pc1->surname, pc2->surname) == 0);
}

int contactCmp(Contact c1, Contact c2) {
  int cmp_surname = strcmp(c1.surname, c2.surname);

  if (cmp_surname != 0) {
    return (cmp_surname < 0) ? -1 : 1;
  }

  int cmp_name = strcmp(c1.name, c2.name);

  return (cmp_name < 0) ? -1 : (cmp_name > 0 ? 1 : 0);
}

int contactCmpEff(const Contact *pc1, const Contact *pc2) {
  int cmp_surname = strcmp(pc1->surname, pc2->surname);

  if (cmp_surname != 0) {
    return (cmp_surname < 0) ? -1 : 1;
  }

  int cmp_name = strcmp(pc1->name, pc2->name);

  return (cmp_name < 0) ? -1 : (cmp_name > 0 ? 1 : 0);
}
