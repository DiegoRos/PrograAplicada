/*
*  @file: examen3.c
*  @brief: Examen 3. Complete el programa como se indica para diseñar una
*          aplicación gráfica en GTK.
*  @author: grupo de Guillermo Gómez.
*  @date: 02/DIC/2020
*
*/

#include "defGTK.h"

void closeTheApp(GtkWidget *window, gpointer data);
void convertirPaC(GtkWidget *boton, gpointer data);
void pushLista(GtkWidget *boton, base *pt);
void popLista(GtkWidget *boton, base *pt);
void modulo1(GtkWidget *boton, base *pt);
void modulo2(GtkWidget *boton, base *pt);
void modulo3(GtkWidget *boton, base *pt);


int main(int argc, char *argv[])
{
	base manipulador;

	GtkWidget *window, *table, *boton1, *boton2, *boton3;
	GtkWidget *push, *pop;

	//1.- Inicializar el ambiente
	gtk_init (&argc, &argv);

	//2.- Crear objertos y modificar atributos
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Examen 3");
	gtk_container_set_border_width(GTK_CONTAINER(window),10);
	gtk_widget_set_size_request(window, 500, 200);

	table = gtk_table_new(5, 3, TRUE);
	manipulador.label1 = gtk_label_new("Datos de personas");
	manipulador.label2 =  gtk_label_new("Ingrese nombre y edad: ");
	manipulador.label3 =  gtk_label_new("Aquí se muestra el resultado ;)");
	manipulador.datoNom = gtk_entry_new();
	manipulador.datoAge = gtk_entry_new();  
	manipulador.cantidad_push = 0;
	manipulador.cantidad_pop = 0;     
	manipulador.ref = NULL;
	boton1 = gtk_button_new_with_label("Integrante 1");
	boton2 = gtk_button_new_with_label("Integrante 2");
	boton3 = gtk_button_new_with_label("Integrante 3");
	push = gtk_button_new_with_label("Push");
	pop = gtk_button_new_with_label("Pop");

	//3.- Registrar las llamadas a funciones (callbacks)
	g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), NULL);
	gtk_signal_connect(GTK_OBJECT(push), "clicked", GTK_SIGNAL_FUNC(pushLista), &manipulador);
	gtk_signal_connect(GTK_OBJECT(pop), "clicked", GTK_SIGNAL_FUNC(popLista), &manipulador);
	gtk_signal_connect(GTK_OBJECT(boton1), "clicked", GTK_SIGNAL_FUNC(modulo1), &manipulador);
	gtk_signal_connect(GTK_OBJECT(boton2), "clicked", GTK_SIGNAL_FUNC(modulo2), &manipulador);
	gtk_signal_connect(GTK_OBJECT(boton3), "clicked", GTK_SIGNAL_FUNC(modulo3), &manipulador);

	//4.- Definir jerarquía de instanacias, en este caso se hace por tables
	gtk_table_attach(GTK_TABLE(table), manipulador.label1, 0, 3, 0, 1, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), manipulador.label2, 0, 1, 1, 2, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), manipulador.datoNom, 1, 2, 1, 2, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), manipulador.datoAge, 2, 3, 1, 2, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), push, 0, 1, 2, 3, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), pop, 1, 2, 2, 3, GTK_EXPAND, GTK_SHRINK, 0, 0); 
	gtk_table_attach(GTK_TABLE(table), boton1, 0, 1, 3, 4, GTK_EXPAND, GTK_SHRINK, 0, 0);  
	gtk_table_attach(GTK_TABLE(table), boton2, 1, 2, 3, 4, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), boton3, 2, 3, 3, 4, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_attach(GTK_TABLE(table), manipulador.label3, 0, 3, 4, 5, GTK_EXPAND, GTK_SHRINK, 0, 0);
	gtk_table_set_row_spacings(GTK_TABLE(table), 8);
	gtk_table_set_col_spacings(GTK_TABLE(table), 8);

	gtk_container_add(GTK_CONTAINER(window), table);

	//5.- Mostrar los widgets
	gtk_widget_show_all(window);

	//6.- Iniciar el loop
	gtk_main();
	return 0;
 }
