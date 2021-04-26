/*
* @file/archivo Events.c
*
* @brief/resumen Este es un ejemplo para entender como las señales y eventos en
GTK funcionan
* está en la página 79 del libro de Peter Wright.
*
* @author/autor Guillermo Gómez Abascal
* @date/fecha 19/04/2016
*/
#include <gtk/gtk.h>
/* Declaración de prototipos */
void CloseTheApp(GtkWidget *window, gpointer data);
gboolean EventHandler(GtkWidget *window, GdkEvent *event, gpointer data);
gint main(gint argc, gchar *argv[])
{
/* Declaración de las variables de pointer a los objetos*/
GtkWidget *window;
/*1. Inicializar el ambiente*/
gtk_init (&argc, &argv);
/*2. Creación de los objetos */
window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
/*3. Registro de los CallBacks*/
/*Este es un callback que pesca los eventos en la ventana principal*/
g_signal_connect(G_OBJECT(window), "event", GTK_SIGNAL_FUNC(EventHandler),
NULL);
/*Este es un callback que detecta cuando se va a cerra la ventana*/
g_signal_connect(G_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(CloseTheApp),
NULL);
/*5. Mostrar los objetos */
gtk_widget_show(window);
/*6. Iniciando el loop*/
gtk_main();
return 0;
}
/*
* Esta función pesca el cierre de ventana (destroy).
* @author/autor Guillermo Gómez
* @param *window objeto GtkWidget
* @param data mensaje del usuario en gpointer
* @return sin retorno
*
*/
void CloseTheApp(GtkWidget *window, gpointer data)
{
gtk_main_quit();
return;
}
/*
* Esta función pesca el el evento que se realiza sobre la ventana y muestra en
un mensaje el tipo de evento.
* @author/autor Guillermo Gómez
* @param *window objeto GtkWidget
* @param *event objeto GtkEvent
* @param data mensaje del usuario en gpointer
* @return sin retorno
*
*/
gboolean EventHandler(GtkWidget *window, GdkEvent *event, gpointer data)
{
switch (event->type)
{
case GDK_CONFIGURE:
g_print("\nLa ventana está siendo configurada.\n");
break;
case GDK_EXPOSE:
g_print("\nLos contenidos de la ventana fueron redibujados\n.");
break;
case GDK_ENTER_NOTIFY:
g_print("\nEl mouse se posicionó en la ventana\n.");
break;
case GDK_LEAVE_NOTIFY:
g_print("\nEl mouse abandonó en la ventana.\n");
break;
case GDK_DELETE:
g_print("\nOuch, el usuario cerró la ventana.\n");
break;
default:
break;
}
return FALSE;
}