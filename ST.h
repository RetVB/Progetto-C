#ifndef ST_H_DEFINED
#define ST_H_DEFINED
#include "Item.h"
typedef struct symboltable *ST;

ST  	STinit(int) ;
int     STcount(ST);
void 	STinsert(ST, Item) ;
int     STsearch(ST, char *) ;
char*	STretrieveKey1(ST, int) ;
int	    STretrieveKey2(ST, int) ;
int	    STretrieveKey3(ST, int) ;

#endif
