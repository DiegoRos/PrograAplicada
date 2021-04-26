#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
void tomaTexto(GtkWidget *boton, gpointer entry);
void closeTheApp(GtkWidget *window, gpointer data);
void borraTexto(GtkWidget *boton, gpointer entry);
int main(int argc, char *argv[])
{
/*0. Declaración de variables */
GtkWidget *window, *vbox, *hbox, *question, *label, *entrada, *boton;
GtkWidget *botonLimpia;
/*1. Inicializar el ambiente*/
gtk_init(&argc,&argv);
/*2. Creación de los objetos y modificación de atributos */
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title (GTK_WINDOW(window), "Ejemplo de Entry");
gtk_container_set_border_width(GTK_CONTAINER(window),10);
question = gtk_label_new("¿Deseas ingresar datos?");
label = gtk_label_new("Entrada (Entry):");
boton = gtk_button_new_with_label("Guarda");
botonLimpia = gtk_button_new_with_label("Limpia");
entrada = gtk_entry_new();
/*3. Registro de los Callbacks */
g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp),
NULL);
g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(tomaTexto),
entrada);
g_signal_connect(GTK_OBJECT(botonLimpia), "clicked", GTK_SIGNAL_FUNC
(borraTexto), entrada);
/* Comando para insertar testo en el campo de entrada (Entry) */
gtk_entry_set_text(GTK_ENTRY(entrada),"Escribe un dato..." );
/* 4. Define jerarquía de instancias (pack the widgets)*/
hbox = gtk_hbox_new(FALSE, 5);
gtk_box_pack_start_defaults(GTK_BOX(hbox), label);
gtk_box_pack_start_defaults(GTK_BOX(hbox), entrada);
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
void tomaTexto(GtkWidget *boton, gpointer entry)
{
FILE *fp;
char datos[20];
fp = fopen("datos.txt", "a");
if (fp == NULL)
{
g_print("\nArchivo no disponible.");
exit(1);
}
strcpy(datos, gtk_entry_get_text(entry));
fprintf(fp,"%s\n",datos);
gtk_entry_set_text(GTK_ENTRY(entry),"Guardado en archivo..." );
fclose(fp);
return;
}
void borraTexto(GtkWidget *boton, gpointer entry)
{
gtk_entry_set_text(GTK_ENTRY(entry),"" );
return;
}
void closeTheApp(GtkWidget *window, gpointer data)
{
gtk_main_quit();
return;
}