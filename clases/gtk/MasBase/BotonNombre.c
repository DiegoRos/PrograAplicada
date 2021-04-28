/*
* @file/archivo BotonNombre.c
*
* @brief/resumen Este es un ejemplo para entender como un botón cambia el nombre
de un label.
* Este ejemplo está basado en un ejercicio diseñado en GTK+ por Iker Llorens.
* @author/autor Guillermo Gómez Abascal
* @date/fecha 24/04/2016
*/
#include <gtk/gtk.h>
/* Declaración de Prototipos */
void CloseTheApp(GtkWidget *window, gpointer data);
void ChangeText(GtkButton *button, gpointer data);
gint main(gint argc, gchar *argv[]){
	/* Declaración de variables de tipo puntero para objetos */
	GtkWidget *window;
	GtkWidget *label;
	GtkWidget *mainbox;
	GtkWidget *button;
	/*1. Inicializar el ambiente*/
	gtk_init(&argc, &argv);

	/*2. Creación de los objetos */
	/*2b. Ventana principal y atributos*/
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_default_size(GTK_WINDOW(window),320,200);
	gtk_window_set_title(GTK_WINDOW(window),"Label Sample");
	gtk_container_set_border_width(GTK_CONTAINER(window),10);

	/*2b. Contenedor*/
	mainbox = gtk_vbox_new(FALSE,5);
	/*2b. Etiquieta*/
	label = gtk_label_new("Esta es una etiqueta :)");
	gtk_box_pack_start(GTK_BOX(mainbox),label,TRUE,TRUE,5);
	/*2b. Boton*/
	button = gtk_button_new_with_label("Botón que cambia nombre etiqueta");
	gtk_box_pack_end(GTK_BOX(mainbox),button,TRUE,TRUE,5);
	gtk_signal_connect(GTK_OBJECT(button),"clicked",GTK_SIGNAL_FUNC(ChangeText),
	label);
	/*3. Registro de los CallBacks*/
	gtk_signal_connect(GTK_OBJECT(window),"destroy",GTK_SIGNAL_FUNC(CloseTheApp),
	NULL);
	/* 4. Define jerarquía de instancias (pack the widgets)*/
	/*Agregar el contenedor a la ventana*/
	gtk_container_add(GTK_CONTAINER(window),mainbox);

	/* 5. Mostrar los widgets */
	/*Mostrar Ventana*/
	gtk_widget_show_all(window);
	/* 6. El programa se queda en loop */
	/*Inicia gtk*/
	gtk_main();
	return 0;
}
/*
* Esta función pesca el cierre de ventana (destroy).
* @author/autor Guillermo Gómez
* @param GtkWidget *window, pointer a objeto ventana
* @param data mensaje del usuario en gpointer
* @return sin retorno
*
*/
void CloseTheApp(GtkWidget *window, gpointer data){
	gtk_main_quit();
	return;
}

/*
* Esta función pesca el el evento que se realiza en el click del botón y cambia
el nombre del labal.
* @author/autor Guillermo Gómez
* @param GtkWidget *button, pointer a objeto botón
* @param gpointer data, mensaje del usuario en gpointer
* @return sin retorno
*
*/
void ChangeText(GtkButton *button, gpointer data){
	static gboolean textType = TRUE;
	if(textType){
		gtk_label_set_text(GTK_LABEL(data),"Ya cambió ;)");
	}
	else{
		gtk_label_set_text(GTK_LABEL(data),"Otra vez cambió :(");
	}
	
	textType = !textType;
	return;
}
