#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Lista{
	char nombre[40];
	struct lista *next;
}Lista;

typedef struct ListaDoble{
	char val[40];
	struct ListaDoble *next;
	struct ListaDoble *prev;
}ListaDoble;

typedef struct InfoNodo{
	char pal_actual[40];
	int num_chars;
	char primer_char;
	ListaDoble *ref, *mover;
	Lista *inicio;
}Navegador;

