#ifndef ITEM_H_DEFINED
#define ITEM_H_DEFINED
#define MAX 31

typedef struct item_ { char str[MAX]; int v; int m;  } Item;

char *KEY1get(Item *proom);
int KEY2get(Item room);
int KEY3get(Item room);
Item ITEMscan(FILE *);


#endif
