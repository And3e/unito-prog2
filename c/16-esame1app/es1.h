#ifndef _ES1_H_
#define _ES1_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node IntNode, *IntList;
struct node {
  int data;
  IntList next;
};

int eliminaTerzultimo(IntList *lsPtr);
int eliminaTerzultimo_crt(IntList *lsPtr);
#endif
