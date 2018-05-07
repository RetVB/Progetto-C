#include <stdlib.h>
#include <stdio.h>
#include<string.h>
#include "Graph.h"

#define MAX 31

struct graph {int V; int E; int **adj; ST tab; };

int **MATRIXint(int r, int c, int val) {
  int i, j;
  int **t = malloc(r * sizeof(int *));
  for (i=0; i < r; i++)
    t[i] = malloc(c * sizeof(int));
  for (i=0; i < r; i++)
    for (j=0; j < c; j++)
      t[i][j] = val;
  return t;
}

Graph GRAPHinit(int V) {
  Graph G = malloc(sizeof *G);
  if (G == NULL)
    return NULL;
  G->V = V;
  G->E = 0;
  G->adj = MATRIXint(V, V, 0);
  G->tab = STinit(V);
  if (G->tab == NULL)
    return NULL;
  return G;
}

void  insertE(Graph G, Edge e) {
  int v = e.v, w = e.w;

  if (G->adj[v][w] == 0)
    G->E++;
  G->adj[v][w] = 1;
  G->adj[w][v] = 1;
}

void GRAPHread(FILE *fin, Graph g) {
  char src[MAX], dst[MAX];
  int i, id1, id2;
  Item room;
  for(i=0; i<g->V; i++) {
    room = ITEMscan(fin);
    STinsert(g->tab, room);
  }
  while(fscanf(fin, "%s %s", src, dst) == 2) {
    id1 = STsearch(g->tab, src);
    id2 = STsearch(g->tab, dst);
    insertE(g, EDGEcreate(id1, id2));
  }
  return;
}

void pathR(Graph G, int currv, int start, int *currpath, int currlen, int currval, int *bestpath, int *bestlen, int *bestval, int *visited) {
  int i;
  if (start == (G->V-1)) {
    if (currval > *bestval) {
      *bestlen = currlen;
      *bestval = currval;
      for (i=0; i < currlen; i++)
        bestpath[i] = currpath[i];
    }
    return;
  }

  visited[start] = 1;
  for (i = 0 ; i < G->V ; i++)
    if (G->adj[start][i] == 1)
      if (visited[i] == 0)
        if (STretrieveKey2(G->tab, i)< currv) {
          currpath[currlen] = i;
          pathR(G, currv-STretrieveKey2(G->tab, i), i, currpath, currlen+1, currval+STretrieveKey3(G->tab, i), bestpath, bestlen, bestval, visited);

        }
  visited[start] = 0;
  return;
}

void GRAPHpath(Graph G) {
  int *visited, *bestpath, *currpath, len = 0, val = 0, i, V;

  printf("Inserisci punti-ferita iniziali: ");
  scanf("%d", &V);

  visited = calloc(G->V, sizeof(int));
  bestpath = calloc(G->V, sizeof(int));
  currpath = calloc(G->V, sizeof(int));

  pathR(G, V, 0, currpath, 0, 0, bestpath, &len, &val, visited);

  printf("Cammino migliore: %d monete d'oro\n", val);
  printf("%s\n", STretrieveKey1(G->tab, 0));
  for(i=0; i<len; i++)
    printf("%s\n", STretrieveKey1(G->tab, bestpath[i]));

  free(bestpath);
  free(visited);
  free(currpath);
  return;
}


