#include <gtk/gtk.h>
/*Prototipos de funciones */
void print_and_quit (GtkButton *was_clicked, gpointer user_data);
gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data);

int main(int argc, char *argv[]){
	GtkWidget *top_widget, *box, *label, *separator, *exit_btn;
	/* 1. Se inicializa el entorno */
	gtk_init(&argc, &argv);

	/* 2. Crea los widgets */
	top_widget = gtk_window_new( GTK_WINDOW_TOPLEVEL );
	box = gtk_vbox_new( FALSE, 10);
	label = gtk_label_new( "GTK+ is fun!" );
	separator = gtk_hseparator_new( );
	exit_btn = gtk_button_new_with_label ( "Exit" );

	/* 2b. Inicializa atributos */
	gtk_window_set_title(GTK_WINDOW(top_widget), "gtkfun");
	gtk_container_set_border_width(GTK_CONTAINER(top_widget), 15);
	gtk_widget_set_name(top_widget, "gtkfun");
	gtk_widget_set_name(box, "vertical box");
	gtk_widget_set_name(label, "fun_label");
	gtk_widget_set_name(separator, "separator");
	gtk_widget_set_name(exit_btn, "exit");

	/* 3. Registro de callbacks */
	g_signal_connect(G_OBJECT(exit_btn), "clicked", G_CALLBACK(print_and_quit),
	NULL);
	g_signal_connect(G_OBJECT(top_widget), "delete_event", G_CALLBACK
	(delete_event_handler), NULL);
	g_signal_connect(G_OBJECT(top_widget), "destroy", G_CALLBACK(print_and_quit),
	NULL);

	/* 4. Define jerarquía de instancias (pack the widgets)*/
	gtk_container_add(GTK_CONTAINER(top_widget), box);
	gtk_box_pack_start_defaults(GTK_BOX(box), label);
	gtk_box_pack_start_defaults(GTK_BOX(box), separator);
	gtk_box_pack_start_defaults(GTK_BOX(box), exit_btn);

	/* 5. Mostrar los widgets */
	gtk_widget_show_all(top_widget);
	/* 6. El programa se queda en loop */
	gtk_main();
	g_print("Bye!\n");
	return 0;
}


/* Callbacks llamados. Desarrollo de las funciones. */
void print_and_quit (GtkButton *was_clicked, gpointer user_data){
	/* Use glibs printf equivalent to print a message */
	g_print("Gracias por usarme.\n");
	gtk_main_quit();
}

gboolean delete_event_handler(GtkWidget *widget, GdkEvent *event, gpointer user_data){
	/* Recibe cierre de ventana del window manager */
	g_print("El window manager está preguntando por cerrar esta aplicación\n");
	return(FALSE); /* FALSE no previene de cierre*/
}