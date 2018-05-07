#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

#include "Graph.h"
#include "Item.h"


int main() {
  FILE *fin;
  Graph g;
  int nV;
  char name[MAX];

  printf("Input nome file: ");
  scanf("%s", name);
  fin = fopen(name, "r");
  if (fin == NULL)
    exit(-1);

  fscanf(fin, "%d", &nV);
  g = GRAPHinit(nV);
  GRAPHread(fin, g);
  GRAPHpath(g);

  return 0;
}
