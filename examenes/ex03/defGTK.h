#include <gtk/gtk.h>
#include <string.h>
#include <ctype.h>

#define True 1
#define False 0

struct elemento{
    char nombre[40];
    int  edad;
    struct elemento *next;
};
typedef struct elemento nodo;

struct datos
     {
      GtkWidget *datoNom;
      GtkWidget *datoAge;
      GtkWidget *label1;
      GtkWidget *label2;
      GtkWidget *label3;
      int cantidad_push;
      int cantidad_pop;
      nodo *ref;
     };
typedef struct datos base;
