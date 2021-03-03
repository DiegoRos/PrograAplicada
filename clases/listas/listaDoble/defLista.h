#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListaDoble{
	char val[40];
	struct ListaDoble *next;
	struct ListaDoble *prev;
}ListaDoble;