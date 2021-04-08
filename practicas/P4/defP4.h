#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct ListaDoble{
	int val;
	struct ListaDoble *next;
	struct ListaDoble *prev;
}ListaDoble;

