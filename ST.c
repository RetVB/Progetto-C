#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ST.h"
#include "Item.h"


struct symboltable { Item *a; int maxN; int size;};

ST STinit(int maxN) {
  ST st;
  st = malloc(sizeof(*st));
  if (st == NULL) {
    printf("Memory allocation error\n");
    return NULL;
  }
  st->a = malloc(maxN * sizeof(Item) );
  st->maxN = maxN;
  st->size = 0;
  return st;
}

int STcount(ST st) {
  return st->size;
}

void STinsert(ST st, Item room) {
  int i = st->size++;
  if (st->size > st->maxN) {
    st->a = realloc(st->a, (2*st->maxN)*sizeof(Item));
    if (st->a == NULL)
      return;
    st->maxN = 2*st->maxN;
  }
  st->a[i] = room;
  return;
}


int STsearch(ST st, char *str) {
  int i;
  if (st->size == 0)
    return -1;
  for (i = 0; i  < st->size; i++) {
    if (strcmp(str, KEY1get(&(st->a[i])))==0)
      return i;
  }
  return -1;
}

char * STretrieveKey1(ST st, int i){
  return KEY1get(&(st->a[i]));
}

int STretrieveKey2(ST st, int i){
  return KEY2get(st->a[i]);
}

int STretrieveKey3(ST st, int i){
  return KEY3get(st->a[i]);
}
