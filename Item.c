#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Item.h"


char *KEY1get(Item *proom) {
  return proom->str;
}

int KEY2get(Item room) {
  return room.v;
}

int KEY3get(Item room) {
  return room.m;
}

Item ITEMscan(FILE *fin) {
  Item room;
  fscanf(fin, "%s %d %d", room.str, &(room.m), &(room.v));
  return room;
}

