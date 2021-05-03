#include <gtk/gtk.h>
#include "tiposGTK.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
extern nodo *pop(nodo *p){
    char text[20];
    nodo *aux;
    aux = p;
    if (p == NULL){
        g_print("Stack vacío\n");
        exit(1);
    }
    strcpy(text, p->texto);
    p = p->next;
    free(aux);
    g_print("Le dimos pop a: %s\n", text);
    return p;
}