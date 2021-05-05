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
int generarTxt(ListaDoble *pt);
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
	GtkWidget *boton_m1, *boton_m2, *boton_m3, *boton_m4, *label, *vbox;
	label = gtk_label_new(NULL);
	gtk_label_set_markup(GTK_LABEL(label), "<span size='xx-large' weight='ultrabold'> Escoge la Opción Deseada.</span>");


	boton_m1 = gtk_button_new_with_label("Visualizar Carreras");
	boton_m2 = gtk_button_new_with_label("Buscar Alumno");
	boton_m3 = gtk_button_new_with_label("Dar de Baja Carreara");
	boton_m4 = gtk_button_new_with_label("Navegación Mejores Alumnos");

	gtk_signal_connect(GTK_OBJECT(boton_m1), "clicked", GTK_SIGNAL_FUNC(setViewModulo1), nav);
	gtk_signal_connect(GTK_OBJECT(boton_m2), "clicked", GTK_SIGNAL_FUNC(setViewModulo2), nav);
	
	vbox = gtk_vbox_new(TRUE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), label);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_m1);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_m2);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), boton_m3);
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
	pt->nav->aux_lista = pt->nav->aux_lista->next;	
	sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	printf("%s\n", buffer);

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

void cambiarCarreraPrevia(GtkButton *button, LabelNav *pt){
	char buffer[400];
	pt->nav->aux_lista = pt->nav->aux_lista->prev;	
	sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", pt->nav->aux_lista->carrera, pt->nav->aux_lista->num_alumnos, pt->nav->aux_lista->promedio, pt->nav->aux_lista->mejor_alumno.nombre, pt->nav->aux_lista->mejor_alumno.promedio);
	printf("%s\n", buffer);

	gtk_label_set_markup(GTK_LABEL(pt->label), buffer);
}

void verListaDeAlumnos(GtkButton *button, Navegador *nav){
	char *alumnos_file = "carrera.txt";
	
	imprimirCarrera(alumnos_file, nav->aux_lista->alumnos);	
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
	printf("%s\n", file_buffer);

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

static GtkWidget * makeModulo1(Navegador *nav){
	GtkWidget *boton_izq, *boton_der, *boton_imprimir, *texto_carrera, *boton_borrar, *back;
	GtkWidget *hbox, *vbox;
	char buffer[500];
	LabelNav *pt = (LabelNav *)malloc(sizeof(LabelNav));
	pt->nav = nav;

	sprintf(buffer,"<span size='xx-large' weight='ultrabold'>Carrera: %s</span>\n<span weight='bold'>Número de Alumnos:</span> %i\n<span weight='bold'>Promedio de Carrera:</span> %f\n<span weight='bold'>Mejor Alumno:</span> %s, Promedio: %f\n", nav->aux_lista->carrera, nav->aux_lista->num_alumnos, nav->aux_lista->promedio, nav->aux_lista->mejor_alumno.nombre, nav->aux_lista->mejor_alumno.promedio);
	texto_carrera = gtk_label_new(NULL);
	//Falta agregar variable para que se imprima bien la info.
	gtk_label_set_markup(GTK_LABEL(texto_carrera), buffer);
	
	boton_izq = gtk_button_new_with_label("Previa");
	boton_der = gtk_button_new_with_label("Siguiente");
	boton_imprimir = gtk_button_new_with_label("Imprimir Listado \nAlumnos");
	boton_borrar = gtk_button_new_with_label("Borrar Carrera");
	back = gtk_button_new_with_label("BACK");
	
	pt->label = texto_carrera;
	//gtk_signal_connect(GTK_OBJECT(boton_izq), "clicked", NULL, NULL); 
	gtk_signal_connect(GTK_OBJECT(boton_izq), "clicked", GTK_SIGNAL_FUNC(cambiarCarreraPrevia), pt); 
	gtk_signal_connect(GTK_OBJECT(boton_der), "clicked", GTK_SIGNAL_FUNC(cambiarCarreraSiguiente), pt); 
	gtk_signal_connect(GTK_OBJECT(boton_imprimir), "clicked", GTK_SIGNAL_FUNC(verListaDeAlumnos), nav);
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

/*
int mainOriginal(int argc, char *argv[]){
	if (argc != 2){
		printf("Número incorrecto de entradas\n");
		exit(1);
	}

	ListaDoble *inicio = NULL, *aux = NULL;
	char opcion, guardar;

	inicio = readTxt(argv[1]);
	aux = inicio;

	do{
		if (aux != NULL){
			printf("Estás en %s:\n\tTiene %d alumnos\n\tUn promedio general de %f\n\tY el mejor alumno/a es: %s.\n", aux->carrera, aux->num_alumnos, aux->promedio, aux->mejor_alumno.nombre);
		}

		printf("\n*************************************\n");
		printf("Opciones:\n\t[i]zquierda\n\t[d]erecha\n\t[m]ostar lista entera\n\t[s]alir");
		printf("\n*************************************\n");
		scanf(" %c", &opcion);

		switch(opcion){
			case 'i':
				aux = aux->prev;	
				break;

			case 'd':
				aux = aux->next;
				break;

			case 'm':
				printf("\n");
				imprimirCarrera(aux->alumnos);
				printf("\n");
				break;

			case 's':
				printf("Saliendo...\n");
				break;

			default:
				printf("\nOpción Invalida, porfavor intentar de nuevo.\n");
				break;
		}
	}while(opcion != 's');	
	
	do{
		printf("\nDesea guardar su información [s/n]: ");
		scanf(" %c", &guardar);

		if (!((guardar == 's') || (guardar == 'n'))){
			printf("Opción inválida, intentar de nuevo.\n");
		}
	}while(!((guardar == 's') || (guardar == 'n')));

	if (guardar == 's'){
		printf("\nGuardando Archivo...\n");
		generarTxt(inicio);
		printf("Listo.\n");
	}

	return 0;
}
*/
