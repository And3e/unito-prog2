#include "contact.h"

int main() {
  char n1[] = "";
  char c1[] = "coli";
  char m1[] = "333187439";
  char u1[] = "tghoòsthg";

  char n2[] = "luca";
  char c2[] = "coli";
  char m2[] = "356934850";
  char u2[] = "wwwwwwwwww";

  ContactPtr a = mkContact(n1, c1, m1, u1);
  ContactPtr b = mkContact(n2, c2, m2, u2);

  printf("old mob a: %s\n", getMobile(a));
  char nb[] = "555555555";
  updateMobile(a, nb);
  printf("new mob a: %s\n\n", getMobile(a));

  printf("old url b: %s\n", getUrl(b));
  char nu[] = "xxxxxxxxxx";
  updateUrl(b, nu);
  printf("new url b: %s\n\n", getUrl(b));

  printf("nome a: %s\n", getName(a));
  printf("cognome a: %s\n", getSurname(a));
  printf("mobile a: %s\n", getMobile(a));
  printf("url a: %s\n\n", getUrl(a));

  printf("nome b: %s\n", getName(b));
  printf("cognome b: %s\n", getSurname(b));
  printf("mobile b: %s\n", getMobile(b));
  printf("url b: %s\n\n", getUrl(b));

  printf("sono uguali?  %d\n", equalsContact(a, b));
  printf("ordine lessicografio  %d\n", cmpContact(a, b));

  dsContact(&a);
  dsContact(&b);

  return 0;
}