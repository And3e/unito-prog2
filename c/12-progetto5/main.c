#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "intLinkedListSortedSetADT.h"
#include "intSortedSetADT.h"

IntSortedSetADT mkSSetv(int count, ...) {
  IntSortedSetADT set = mkSSet();

  va_list args;
  va_start(args, count);
  for (int i = 0; i < count; ++i) {
    int num = va_arg(args, int);
    sset_add(set, num);
  }
  va_end(args);
  return set;
}

char *toString(IntSortedSetADT set) {
  char *sout = malloc(100);

  ListNodePtr nptr = set->first;
  sprintf(sout, "{");
  while (nptr) {
    if (nptr == set->first) {
      sprintf(sout + strlen(sout), "%d", nptr->elem);
    } else {
      sprintf(sout + strlen(sout), ",%d", nptr->elem);
    }

    nptr = nptr->next;
  }

  sprintf(sout + strlen(sout), "}");

  return sout;
}

int check_mkSSet() {
  int passed = 1;
  printf("mkSet()\n");

  IntSortedSetADT sptr = mkSSet();
  if (!sptr) {
    printf("FAILED");
    printf("EXPECTED: not %d\n", 0);
  } else {
    printf("OK\n");
  }

  printf("RESULT:%ld\n\n", (long)sptr);
  return passed;
}

int check_dsSSet() {
  int passed = 1;

  if (passed) {
    _Bool rv;
    IntSortedSetADT sptr = mkSSet();
    printf("dsSSet({})\n");
    rv = dsSSet(&sptr);
  
    if (!rv || sptr) {
      printf("FAILED\n");
      printf("EXPECTED: NOT %d AND PTR %ld\n", 0, (long)NULL);
      passed = 0;
    } else {
      printf("OK\n");
    }
    printf("RESULT:%d AND PTR %ld\n\n", rv, (long)sptr);
  }

  if (passed) {
    _Bool rv;
    printf("dsSSet(NULL)\n");
    rv = dsSSet(NULL);
  
    if (rv) {
      printf("FAILED\n");
      printf("EXPECTED: %d\n", 0);
      passed = 0;
    } else {
      printf("OK\n");
    }
    printf("RESULT:%d\n\n", rv);
  }

  return passed;
}

int check_sset_add() {
  int passed = 1;

  return passed;
}

int check_sset_remove() {
  int passed = 1;

  return passed;
}

int check_sset_member() {
  int passed = 1;

  return passed;
}

int check_isEmptySSet() {
  int passed = 1;

  return passed;
}

int check_sset_size() {
  int passed = 1;

  return passed;
}

int check_sset_extract() {
  int passed = 1;

  return passed;
}

int check_sset_equals() {
  int passed = 1;

  return passed;
}

int check_sset_subseteq() {
  int passed = 1;

  return passed;
}

int check_sset_subset() {
  int passed = 1;

  return passed;
}

int check_sset_union() {
  int passed = 1;

  return passed;
}

int check_sset_intersection() {
  int passed = 1;

  return passed;
}

int check_sset_subtraction() {
  int passed = 1;

  return passed;
}

int check_sset_min() {
  int passed = 1;

  return passed;
}

int check_sset_max() {
  int passed = 1;

  return passed;
}

int check_sset_extractMin() {
  int passed = 1;

  return passed;
}

int check_sset_extractMax() {
  int passed = 1;

  return passed;
}

int main(int argc, char *argv[]) {
  srand(time(NULL));

  puts("BEGIN TEST intLinkedListSortedSetADT");

  {
    printf("TEST mkSSet\n");
    check_mkSSet();
    printf("\n");
  }

  {
    printf("TEST dsSSet\n");
    check_dsSSet();
    printf("\n");
  }

  {
    printf("TEST sset_add\n");
    check_sset_add();
    printf("\n");
  }

  {
    printf("TEST sset_remove\n");
    check_sset_remove();
    printf("\n");
  }

  {
    printf("TEST sset_member\n");
    check_sset_member();
    printf("\n");
  }

  {
    printf("TEST isEmptySSet\n");
    check_isEmptySSet();
    printf("\n");
  }

  {
    printf("TEST sset_size\n");
    check_sset_size();
    printf("\n");
  }

  {
    printf("TEST sset_extract\n");
    check_sset_extract();
    printf("\n");
  }

  {
    printf("TEST sset_equals\n");
    check_sset_equals();
    printf("\n");
  }

  {
    printf("TEST sset_subseteq\n");
    check_sset_subseteq();
    printf("\n");
  }

  {
    printf("TEST sset_subset\n");
    check_sset_subset();
    printf("\n");
  }

  {
    printf("TEST sset_union\n");
    check_sset_union();
    printf("\n");
  }

  {
    printf("TEST sset_intersection\n");
    check_sset_intersection();
    printf("\n");
  }

  {
    printf("TEST sset_subtraction\n");
    check_sset_subtraction();
    printf("\n");
  }

  {
    printf("TEST sset_min\n");
    check_sset_min();
    printf("\n");
  }

  {
    printf("TEST sset_max\n");
    check_sset_max();
    printf("\n");
  }

  {
    printf("TEST sset_extractMin\n");
    check_sset_extractMin();
    printf("\n");
  }

  {
    printf("TEST sset_extractMax\n");
    check_sset_extractMax();
    printf("\n");
  }
}