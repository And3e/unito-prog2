#include "func.h"

char *to_upper(const char *string) {
  if (string == NULL) {
    return NULL;
  }

  char *upperstr = malloc(strlen(string) + 1);
  if (upperstr == NULL) {
    return NULL;
  }

  strcpy(upperstr, string);

  for (char *p = upperstr; *p != '\0'; p++) {
    if (*p >= 'a' && *p <= 'z') {
      *p -= ('a' - 'A');
    }
  }

  return upperstr;
}

_Bool contactEq(Contact c1, Contact c2) {
  return (strcmp(to_upper(c1.name), to_upper(c2.name)) == 0 &&
          strcmp(to_upper(c1.surname), to_upper(c2.surname)) == 0);
}

_Bool contactEqEff(const Contact *pc1, const Contact *pc2) {
  return (strcmp(to_upper(pc1->name), to_upper(pc2->name)) == 0 &&
          strcmp(to_upper(pc1->surname), to_upper(pc2->surname)) == 0);
}

int contactCmp(Contact c1, Contact c2) {
  char *c1_surname = to_upper(c1.surname);
  char *c2_surname = to_upper(c2.surname);
  char *c1_name = to_upper(c1.name);
  char *c2_name = to_upper(c2.name);

  int cmp_surname = strcmp(c1_surname, c2_surname);

  if (cmp_surname != 0) {
    return (cmp_surname < 0) ? -1 : 1;
  }

  int cmp_name = strcmp(c1_name, c2_name);

  if (cmp_name < 0) {
    return -1;
  }
  return cmp_name > 0;
}

int contactCmpEff(const Contact *pc1, const Contact *pc2) {
  char *pc1_surname = to_upper(pc1->surname);
  char *pc2_surname = to_upper(pc2->surname);
  char *pc1_name = to_upper(pc1->name);
  char *pc2_name = to_upper(pc2->name);

  int cmp_surname = strcmp(pc1_surname, pc2_surname);

  if (cmp_surname != 0) {
    return (cmp_surname < 0) ? -1 : 1;
  }

  int cmp_name = strcmp(pc1_name, pc2_name);

  if (cmp_name < 0) {
    return -1;
  }
  return cmp_name > 0;
}
