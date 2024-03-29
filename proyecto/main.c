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

/************** Modulo 1 *******************/
extern ListaDoble * readTxtLista(const char file_name[]);
extern nodo * readTxtArbol(const char file_name[]);
extern int imprimirAlumno(Queue *pt);
extern int imprimirCarrera(const char *file_name, Queue *pt);

static GtkWidget * makeModulo1(Navegador *nav);
void setViewModulo1(GtkButton *button, Navegador *nav);


/************** Modulo 2 *******************/
extern nodo * buscarNodo(nodo *root, int num_cuenta);

static GtkWidget * makeModulo2(Navegador *nav);
void setViewModulo2(GtkButton *button, Navegador *nav);


/************** Modulo 3 *******************/
extern Navegador * popLD(Navegador *nav);


/************** Modulo 4 *******************/
extern int buscarLDPromedio(char *nombre_file, float promedio, Navegador *nav);

static GtkWidget * makeModulo4(Navegador *nav);
void setViewModulo4(GtkButton *button, Navegador *nav);



/************** General *******************/
extern int generarTxt(Navegador *nav);

static GtkWidget * makeMainMenu(Navegador *nav);
void setViewMainMenu(GtkButton *button, Navegador *nav);
void closeTheApp(GtkWidget *window, Navegador *nav);

int main(int argc, char *argv[]){
	Navegador *nav = (Navegador *)malloc(sizeof(Navegador));

	nav->inicio = readTxtLista(STUDENT_FILE);
	nav->aux_lista = nav->inicio;

	nav->root = readTxtArbol(STUDENT_FILE);
	nav->aux_arbol = nav->root;

	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	gtk_window_set_title(GTK_WINDOW(window), "Proyecto Final");
	gtk_window_set_default_size(GTK_WINDOW(window), 600, 600);
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	
	gtk_init(&argc, &argv);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(closeTheApp), nav);
	setViewMainMenu(NULL, nav);	
	gtk_main();
	return 0;
}

/*
*	@brief: Hace que la vista de la pantalla sea el menu principal
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void setViewMainMenu(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeMainMenu(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	
}


/*
*	@brief: Crea los objetos de GTK que salen en la pantalla del menu principal
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
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

/*
*	@brief: Hace que lo que se vea en pantalla sea el módulo 1 y 3
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void setViewModulo1(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeModulo1(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
}

/*
*	@brief: Cambia la carrera vista en la pantalla a la siguiente
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *pt: Navegador con lista doble, arbol y label a cambiar
*	@return void
*/
void cambiarCarreraSiguiente(GtkButton *button, LabelNav *pt){
	char buffer[400];
	if (pt->nav->aux_lista){
		pt->nav->aux_lista = pt->nav->aux_lista->next;	
		sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	}
	else{
		sprintf(buffer, "<span size='xx-large' weight='ultrabold'>No hay carreras\nen la lista.</span>");
	}

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

/*
*	@brief: Cambia la carrera vista en la pantalla a la previa
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *pt: Navegador con lista doble, arbol y label a cambiar
*	@return void
*/
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

/*
*	@brief: Hace una nueva pantalla con el listado de alumnos
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void verListaDeAlumnos(GtkButton *button, Navegador *nav){
	char *alumnos_file = "carrera.txt";
	
	if (nav->aux_lista)
		imprimirCarrera(alumnos_file, nav->aux_lista->alumnos);
	else	
		imprimirCarrera(alumnos_file, NULL);

	GtkWidget *window_lista, *label_view;
	gchar *file_buffer; // String
	GError *error; // Tipo especial de GTK para errores
	gboolean read_file_status; // Booleano

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

/*
*	@brief: Borra una carrera
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param LabelNav *pt: Navegador con lista doble, arbol y label a cambiar
*	@return void
*/
void borrarNodoCarrera(GtkButton *button, LabelNav *pt){	
	pt->nav = popLD(pt->nav);
	char buffer[400];

	if (pt->nav->aux_lista){
		sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	}
	else{	
		sprintf(buffer, "<span size='xx-large' weight='ultrabold'>No hay carreras\nen la lista.</span>");
	}

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

/*
*	@brief: Hace que la vista de la pantalla sea el módulo 1 y módulo 3
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
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
		sprintf(buffer, "<span size='xx-large' weight='ultrabold'>No hay carreras\nen la lista.</span>");
	}
	texto_carrera = gtk_label_new(NULL);
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
	gtk_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(setViewMainMenu), nav); 

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
/*
*	@brief: Hace que la vista de la pantalla sea el módulo 2
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void setViewModulo2(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeModulo2(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
}

/*
*	@brief: Hace que la vista de la pantalla sea el menu principal
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void buscarAlumno(GtkButton *boton, EntryLabelNav *pt){
	int num_cuenta;
	char buffer[500];
	
	sscanf(gtk_entry_get_text(GTK_ENTRY(pt->entry)), "%i", &num_cuenta);
	
	nodo *aux = buscarNodo(pt->nav->root, num_cuenta);
	if (aux){
		sprintf(buffer,"<span size='x-large' weight='ultrabold'>Alumno: %s</span>\n<span weight='bold'>Número de Cuenta:</span> %i\n<span weight='bold'>Carreara:</span>%s\n<span weight='bold'>Promedio:</span>%f", aux->alumno.nombre, aux->alumno.num_cuenta, aux->alumno.carrera, aux->alumno.promedio);
	}
	else{
		sprintf(buffer, "<span size='x-large'>No se encontró el estudiante, intentar de nuevo\n:(</span>");
	}

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
	
}

/*
*	@brief: Crea los objetos de GTK para el módulo 2.
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
static GtkWidget * makeModulo2(Navegador *nav){
	EntryLabelNav *pt = (EntryLabelNav *)malloc(sizeof(EntryLabelNav));
	GtkWidget *label_cuenta, *num_cuenta, *buscar, *alumno, *back, *vbox;

	label_cuenta = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label_cuenta), "<span weight='bold'>Introducir Número de Cuenta</span>");

	num_cuenta = gtk_entry_new();
	buscar = gtk_button_new_with_label("Buscar");
	alumno = gtk_label_new("Escribir número de cuenta en caja \ny presionar Buscar para encontrar alumno.\n");
	back = gtk_button_new_with_label("BACK");

	pt->nav = nav;
	pt->label = alumno;
	pt->entry = num_cuenta;
	gtk_signal_connect(GTK_OBJECT(buscar), "clicked", GTK_SIGNAL_FUNC(buscarAlumno), pt); 
	gtk_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(setViewMainMenu), nav); 
	
	vbox = gtk_vbox_new(FALSE, 3);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), label_cuenta);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), num_cuenta);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), buscar);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), alumno);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), back);	
	return vbox;
}

/******************* FUNCIONES MÓDULO 4 *******************/
/*
*	@brief: Hace que la vista de la pantalla sea el módulo 4
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void setViewModulo4(GtkButton *button, Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));

	nav->aux_lista = nav->inicio;
	nav->aux_arbol = nav->root;

	display_box = makeModulo4(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
}

/*
*	@brief: Busca dentro de los mejores alumnos arriba de cierto promedio y los imprime a pantalla
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void buscarPromedio(GtkButton *boton, EntryLabelNav *pt){
	float promedio;
	char *promedios_file = "alumnosModulo4.txt";
	gchar *file_buffer;
	GError *error;
	gboolean read_file_status;
	if(sscanf(gtk_entry_get_text(GTK_ENTRY(pt->entry)), "%f", &promedio) == 1){
		buscarLDPromedio(promedios_file, promedio, pt->nav);

		read_file_status = g_file_get_contents(promedios_file, &file_buffer, NULL, &error);
		if (read_file_status == FALSE){
			g_error("Error opening file: %s\n", error && error->message ? error->message : "No detail");
			return;
		}	
		gtk_label_set_markup(GTK_LABEL(pt->label), file_buffer);
	}
	else{
		gtk_label_set_markup(GTK_LABEL(pt->label), "<span size='xx-large' weight='ultrabold'>Entrada no válida.\nIntentar de nuevo.\n</span>");
	}

}

/*
*	@brief: Crea los objetos de GTK para ver el módulo 4
*	@author: Equipo 3
*	@param GtkButton *button: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
static GtkWidget * makeModulo4(Navegador *nav){
	GtkWidget *vbox, *label1, *entrada, *boton_buscar, *label_display, *back;
	EntryLabelNav *pt = (EntryLabelNav *)malloc(sizeof(EntryLabelNav));
	
	label1 = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label1), "<span weight='ultrabold' size='x-large'>Introduzca un promedio</span>");
	
	entrada = gtk_entry_new();
	boton_buscar = gtk_button_new_with_label("Buscar");
	label_display = gtk_label_new("Escribir promeido a buscar,\n y presionar el botón de buscar.\n");
	back = gtk_button_new_with_label("Back");

	pt->nav = nav;
	pt->label = label_display;
	pt->entry = entrada;
	gtk_signal_connect(GTK_OBJECT(boton_buscar), "clicked", GTK_SIGNAL_FUNC(buscarPromedio), pt);
	gtk_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(setViewMainMenu), nav); 

	vbox = gtk_vbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(vbox),label1);
	gtk_box_pack_start_defaults(GTK_BOX(vbox),entrada);
	gtk_box_pack_start_defaults(GTK_BOX(vbox),boton_buscar);
	gtk_box_pack_start_defaults(GTK_BOX(vbox),label_display);
	gtk_box_pack_start_defaults(GTK_BOX(vbox),back);	
	
	return vbox;
}

/******************* Cerrar Aplicación con Request *******************/

/*
*	@brief: Cierra la aplicación y muestra opción para cambiar
*	@author: Equipo 3
*	@param GtkButton *window: Boton presionado para entrar
*	@param Navegador *nav: Navegador con lista doble y arbol
*	@return void
*/
void closeTheApp(GtkWidget *window, Navegador *nav){
	GtkWidget *dialog;

	dialog = gtk_message_dialog_new(GTK_WINDOW(window), GTK_DIALOG_DESTROY_WITH_PARENT, GTK_MESSAGE_INFO, GTK_BUTTONS_YES_NO, NULL);
	gtk_message_dialog_set_markup(GTK_MESSAGE_DIALOG(dialog), "<span weight='bold'>Desea guardar los cambios?</span>");
	gint result = gtk_dialog_run(GTK_DIALOG(dialog));
	switch(result){
		case GTK_RESPONSE_YES:
			generarTxt(nav);
			break;
		default:
			break;
	}
	gtk_widget_destroy(dialog);
	gtk_main_quit();
}

