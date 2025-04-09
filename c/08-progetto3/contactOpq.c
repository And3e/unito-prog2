#include "contact.h"

typedef struct contact {
  char *name;
  char *surname;
  char *mobile;
  char *url;
} contact;

ContactPtr mkContact(char *name, char *surname, char *mobile, char *url) {
  ContactPtr c = malloc(sizeof(contact));

  if (c == NULL) {
    return NULL;
  }

  if ((name == NULL) || (surname == NULL)) {
    return NULL;
  }

  c->name = name;
  c->surname = surname;
  c->mobile = mobile;
  c->url = url;

  return c;
}

void dsContact(ContactPtr *cntptr) {
  *cntptr = NULL;
  free(*cntptr);
}

void updateMobile(ContactPtr cnt, char *newMobile) { cnt->mobile = newMobile; }

void updateUrl(ContactPtr cnt, char *newUrl) { cnt->url = newUrl; }

char *getName(const ContactPtr cnt) { return cnt->name; }

char *getSurname(const ContactPtr cnt) { return cnt->surname; }

char *getMobile(const ContactPtr cnt) { return cnt->mobile; }

char *getUrl(const ContactPtr cnt) { return cnt->url; }

char *to_upper(char *string) {
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

_Bool equalsContact(const ContactPtr cnt1, const ContactPtr cnt2) {
  char *cnt1_name = to_upper(cnt1->name);
  char *cnt2_name = to_upper(cnt2->name);
  char *cnt1_surname = to_upper(cnt1->surname);
  char *cnt2_surname = to_upper(cnt2->surname);

  return !strcmp(cnt1_name, cnt2_name) && !strcmp(cnt1_surname, cnt2_surname);
}

int cmpContact(const ContactPtr cnt1, const ContactPtr cnt2) {
  char *cnt1_name = to_upper(cnt1->name);
  char *cnt2_name = to_upper(cnt2->name);
  char *cnt1_surname = to_upper(cnt1->surname);
  char *cnt2_surname = to_upper(cnt2->surname);

  int cmp_surname = strcmp(cnt1_surname, cnt2_surname);

  if (cmp_surname != 0) {
    return (cmp_surname < 0) ? -1 : 1;
  }

  int cmp_name = strcmp(cnt1_name, cnt2_name);

  if (cmp_name < 0) {
    return -1;
  }
  return cmp_name > 0;
}
