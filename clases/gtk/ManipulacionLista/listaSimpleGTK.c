/*
* @file listaSimpleGTK.c
*
* @brief Este programa permite manejar una lista Push/Pop desde una interfaz
* diseñada en GTK. Un usurio puede colocar una cadena en el campo de ingreso
de
* datos y tiene como opciones dar Push o Pop. Si se oprime el botón de Push,
* la cadena del campo se anexa a la lista simple; si se oprime el botón de
* Pop, el programa libera de la lista el último elemento de la lista que fue
* ingresado. El programa manda imprimir un mensaje, a modo terminal, en el que
* indica cuál fue la operación realizada.
*
* @author Guillermo Gómez
*
* @date 11/20/2019
*
*/
#include "tiposGTK.h"
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
void pushTexto(GtkWidget *boton, gpointer estructura);
void closeTheApp(GtkWidget *window, gpointer estructura);
void popTexto(GtkWidget *boton, gpointer estructura);
nodo *push(char text[], nodo *p);
extern nodo *pop(nodo *p);
void recorreLista(nodo *p);
struct referencia{
GtkWidget *entrada;
nodo *inicio;
int contPush, contPop;
};
typedef struct referencia ref;

int main(int argc, char *argv[]){
    ref base;
    base.contPush = 0;
    base.contPop = 0;
    base.inicio = NULL;
    /*0. Declaración de variables */
    GtkWidget *window, *vbox, *hbox, *question, *label, *boton;
    GtkWidget *botonLimpia;
    /*1. Inicializar el ambiente*/
    gtk_init(&argc,&argv);
    /*2. Creación de los objetos y modificación de atributos */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW(window), "Ejemplo Push/Pop");
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    question = gtk_label_new("¿Deseas ingresar datos?");
    label = gtk_label_new("Entrada (Entry):");
    boton = gtk_button_new_with_label("Push");
    botonLimpia = gtk_button_new_with_label("Pop");
    base.entrada = gtk_entry_new();
    /*3. Registro de los Callbacks */
    g_signal_connect(GTK_OBJECT(window), "destroy",
    GTK_SIGNAL_FUNC(closeTheApp), &base);
    g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(pushTexto),
    &base);
    g_signal_connect(GTK_OBJECT(botonLimpia), "clicked",
    GTK_SIGNAL_FUNC(popTexto), &base);
    /* Comando para insertar texto en el campo de entrada (Entry) */
    gtk_entry_set_text(GTK_ENTRY(base.entrada),"Escribe un dato..." );
    /* 4. Define jerarquía de instancias (pack the widgets)*/
    hbox = gtk_hbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), base.entrada);
    vbox = gtk_vbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), question);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), boton);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), botonLimpia);
    gtk_container_add(GTK_CONTAINER(window),vbox);
    /* 5. Mostrar los widgets */
    gtk_widget_show_all(window);
    /* 6. El programa se queda en loop */
    gtk_main();
    return 0;
}

void pushTexto(GtkWidget *boton, gpointer estructura){
    char datos[20];
    ref *pt = (ref *)estructura;
    pt->contPush++;
    strcpy(datos, gtk_entry_get_text(GTK_ENTRY(pt->entrada)));
    pt->inicio = push(datos, pt->inicio);
    return;
}

void popTexto(GtkWidget *boton, gpointer estructura){
    ref *pt = (ref *)estructura;
    gtk_entry_set_text(GTK_ENTRY(pt->entrada),"" );
    pt->contPop++;
    pt->inicio = pop(pt->inicio);
    return;
}

void closeTheApp(GtkWidget *window, gpointer estructura){
    ref *pt = (ref *)estructura;
    recorreLista(pt->inicio);
    g_print("\nSe hicieron %i pushes y %i popes\n", pt->contPush, pt->contPop);
    gtk_main_quit();
    return;
}

nodo *push(char text[], nodo *p){
    nodo *aux;
    aux = (nodo *)malloc(sizeof(nodo));
    if (aux == NULL){
        g_print("error, Stack overflow");
        exit(1);
    }
    g_print("Le dimos push a: %s\n", text);
    aux->next = p;
    strcpy(aux->texto,text);
    p = aux;
    return p;
}

void recorreLista(nodo *p){
    while(p != NULL){
        g_print("\n Este es: %s", p->texto);
        p = p->next;
        }
    return;
}