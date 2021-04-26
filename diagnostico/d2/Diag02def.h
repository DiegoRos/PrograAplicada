#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define True 1
#define False 0

typedef struct Arbol{
	char val[40];
	int tamanio;
	int repeticion;
	struct Arbol *left, *right;
}Arbol;
