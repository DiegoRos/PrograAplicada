/*
*	@file: main.c	
*	@brief: Cotine el código principal, puede abrir un archivo de n estudiantes
*			organizarlos por carrera y colocar a cada estudiante en su carrera correspondiente.
*			También organiza los estudiantes en un árbol por número de cuenta.
*			Todo esto se coloca en un display gráfico y se pueden hacer varias operaciones.
*	@author: Equipo 3
*	@date: 04/04/2021
*/

#include "Proyectodef.h"
// VARIABLES GLOBALES DE main.c
const char STUDENT_FILE[] = "alumnos.txt";

GtkWidget *window, *display_box;

extern ListaDoble * readTxtLista(const char file_name[]);
extern nodo * readTxtArbol(const char file_name[]);
extern int imprimirAlumno(Queue *pt);
extern int imprimirCarrera(const char *file_name, Queue *pt);
extern Navegador * popLD(Navegador *nav);
extern int generarTxt(Navegador *nav);
static GtkWidget * makeMainMenu(Navegador *nav);
static GtkWidget * makeModulo1(Navegador *nav);
static GtkWidget * makeModulo2(Navegador *nav);
static GtkWidget * makeModulo3(Navegador *nav);
static GtkWidget * makeModulo4(Navegador *nav);
void setViewMainMenu(GtkButton *button, Navegador *nav);
void setViewModulo1(GtkButton *button, Navegador *nav);
void setViewModulo2(GtkButton *button, Navegador *nav);
void setViewModulo3(GtkButton *button, Navegador *nav);
void setViewModulo4(GtkButton *button, Navegador *nav);

int main(int argc, char *argv[]){
	Navegador *nav = (Navegador *)malloc(sizeof(Navegador));

	nav->inicio = readTxtLista(STUDENT_FILE);
	nav->aux_lista = nav->inicio;

	nav->root = readTxtArbol(STUDENT_FILE);
	nav->aux_arbol = nav->root;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Proyecto Final");
	gtk_window_set_default_size(GTK_WINDOW(window), 500, 500);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	
	gtk_init(&argc, &argv);
	setViewMainMenu(NULL, nav);	
	return 0;
}

void setViewMainMenu(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeMainMenu(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
	
}

static GtkWidget * makeMainMenu(Navegador *nav){
	GtkWidget *boton_m1, *boton_m2, *boton_m4, *label, *vbox;
	label = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label), "<span size='xx-large' weight='ultrabold'> Escoge la Opción Deseada.</span>");


	boton_m1 = gtk_button_new_with_label("Visualizar Carreras");
	boton_m2 = gtk_button_new_with_label("Buscar Alumno");
	boton_m4 = gtk_button_new_with_label("Navegación Mejores Alumnos");

	gtk_signal_connect(GTK_OBJECT(boton_m1), "clicked", GTK_SIGNAL_FUNC(setViewModulo1), nav);
	gtk_signal_connect(GTK_OBJECT(boton_m2), "clicked", GTK_SIGNAL_FUNC(setViewModulo2), nav);
	gtk_signal_connect(GTK_OBJECT(boton_m4), "clicked", GTK_SIGNAL_FUNC(setViewModulo4), nav);
	
	vbox = gtk_vbox_new(TRUE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), label);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_m1);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_m2);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_m4);

	return vbox;
}

/******************* FUNCIONES MÓDULO 1 y 3 *******************/
/******************* Manipulación  Listas Estudiantes *******************/

void setViewModulo1(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeModulo1(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

void cambiarCarreraSiguiente(GtkButton *button, LabelNav *pt){
	char buffer[400];
	if (pt->nav->aux_lista){
		pt->nav->aux_lista = pt->nav->aux_lista->prev;	
		sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	}
	else{
		sprintf(buffer, "<span size='xx-large' weight='ultrabold'>No hay carreras\nen la lista.</span>");
	}

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

void cambiarCarreraPrevia(GtkButton *button, LabelNav *pt){
	char buffer[400];
	if (pt->nav->aux_lista){
		pt->nav->aux_lista = pt->nav->aux_lista->prev;	
		sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	}
	else{
		sprintf(buffer, "<span size='xx-large' weight='ultrabold'>No hay carreras\nen la lista.</span>");
	}
	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

void verListaDeAlumnos(GtkButton *button, Navegador *nav){
	char *alumnos_file = "carrera.txt";
	
	if (nav->aux_lista)
		imprimirCarrera(alumnos_file, nav->aux_lista->alumnos);
	else	
		imprimirCarrera(alumnos_file, NULL);

	GtkWidget *window_lista, *label_view;
	gchar *file_buffer;
	GError *error;
	gboolean read_file_status;

	label_view = gtk_label_new(NULL);

	read_file_status = g_file_get_contents(alumnos_file, &file_buffer, NULL, &error);
	if (read_file_status == FALSE){
		g_error("Error opening file: %s\n", error && error->message ? error->message : "No detail");
		return;
	}

	window_lista = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window_lista), "Listado de Alumnos");
	gtk_window_set_default_size(GTK_WINDOW(window_lista), 400, 400);
	gtk_container_set_border_width(GTK_CONTAINER(window_lista), 10);
	
	gtk_init(NULL, NULL);
	gtk_label_set_markup(GTK_LABEL(label_view), file_buffer);

	
	gtk_container_add(GTK_CONTAINER(window_lista), label_view);	
	gtk_widget_show_all(window_lista);
	gtk_signal_connect(GTK_OBJECT(window_lista), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
	
}

void borrarNodoCarrera(GtkButton *button, LabelNav *pt){	
	pt->nav = popLD(pt->nav);
	char buffer[400];

	if (pt->nav->aux_lista){
		sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	}
	else{	
		sprintf(buffer, "<span size='xx-large' weight='ultrabold'>No hay carreras en el archivo de texto.</span>\n");
	}

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

void backMainModule1(GtkButton * button, Navegador *nav){
	printf("Aqui\n");
	setViewMainMenu(button, nav);	
}

static GtkWidget * makeModulo1(Navegador *nav){
	GtkWidget *boton_izq, *boton_der, *boton_imprimir, *texto_carrera, *boton_borrar, *back;
	GtkWidget *hbox, *vbox;
	char buffer[500];
	LabelNav *pt = (LabelNav *)malloc(sizeof(LabelNav));
	pt->nav = nav;
	
	if (nav->inicio){
		sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", nav->aux_lista->carrera, nav->aux_lista->num_alumnos, nav->aux_lista->promedio, nav->aux_lista->mejor_alumno.nombre, nav->aux_lista->mejor_alumno.promedio);
	}
	else{
		sprintf(buffer, "No hay carreras en el archivo de texto.\n");
	}
	texto_carrera = gtk_label_new(NULL);
	//Falta agregar variable para que se imprima bien la info.
	gtk_label_set_markup(GTK_LABEL(texto_carrera), buffer);
	
	boton_izq = gtk_button_new_with_label("Previa");
	boton_der = gtk_button_new_with_label("Siguiente");
	boton_imprimir = gtk_button_new_with_label("Imprimir Listado \nAlumnos");
	boton_borrar = gtk_button_new_with_label("Borrar Carrera");
	back = gtk_button_new_with_label("BACK");
	
	pt->label = texto_carrera;
	gtk_signal_connect(GTK_OBJECT(boton_izq), "clicked", GTK_SIGNAL_FUNC(cambiarCarreraPrevia), pt); 
	gtk_signal_connect(GTK_OBJECT(boton_der), "clicked", GTK_SIGNAL_FUNC(cambiarCarreraSiguiente), pt); 
	gtk_signal_connect(GTK_OBJECT(boton_imprimir), "clicked", GTK_SIGNAL_FUNC(verListaDeAlumnos), nav);
	gtk_signal_connect(GTK_OBJECT(boton_borrar), "clicked", GTK_SIGNAL_FUNC(borrarNodoCarrera), pt);
	gtk_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(backMainModule1), nav); 

	hbox = gtk_hbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), boton_izq);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), texto_carrera);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), boton_der);
	
	vbox = gtk_vbox_new(FALSE, 5);
	gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_imprimir);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_borrar);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), back);	
	return vbox;
}



/******************* FUNCIONES MÓDULO 2 *******************/
void setViewModulo2(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeModulo2(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

static GtkWidget * makeModulo2(Navegador *nav){

}

/******************* FUNCIONES MÓDULO 4 *******************/
void setViewModulo4(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeModulo4(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

static GtkWidget * makeModulo4(Navegador *nav){

}

/******************* Cerrar Aplicación con Request *******************/
void closeTheApp(GtkWidget *window, WindowDestroy *pt){
	GtkWidget *dialog, *hbox, *yes_button, *no_button;
	
	yes_button = gtk_button_new_with_label("Si");
	no_button = gtk_button_new_with_label("No");

	gtk_signal_connect(GTK_OBJECT(yes_button), "clicked", GTK_SIGNAL_FUNC(generarTxt(pt->nav)), pt); 
	gtk_signal_connect(GTK_OBJECT(no_button), "clicked", G_CALLBACK(gtk_main_quit), NULL); 
	
	hbox = gtk_hbox_new(TRUE, 2);

	gtk_box_pack_start_defaults(GTK(hbox), yes_button);
	gtk_box_pack_start_defaults(GTK(hbox), no_button);
	
	
	dialog = gtk_dialog_new_with_buttons("Salir", GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, _("_Si"), GTK_RESPONSE_ACCEPT, _("No"), GTK_RESPONSE_REJECT, NULL);
	printf("Aqui 2\n");
	int result = gtk_dialog_run(dialog);
	switch(result){
		case GTK_RESPONSE_ACCEPT:
			generarTxt(pt->nav);
			break;
		default:
			break;
	}
	gtk_widget_destroy(dialog);
}
