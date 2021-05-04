/*
*	@file: reporteAlumnos.c	
*	@brief: Cotine el código principal, puede abrir un archivo de n estudiantes
*			organizarlos por carrera y colocar a cada estudiante en su carrera correspondiente.
*			Como resultado se puede visualizar el mejor estudiante de cada carrera,
*			cambiar de carrera y visualizar todos los estudiantes. Se puede imprimir
*			un archivo final que contiene a todos los estudiantes (Nota: este no se 
*			puede leer al volver a correr el código).
*	@author: Equipo 3
*	@date: 16/03/2021
*/

#include "Proyectodef.h"
const char STUDENT_FILE[] = "alumnos.txt";

GtkWidget *window, *display_box;
GtkWidget * (*display_func)(void);

ListaDoble * readTxtLista(const char file_name[]);
nodo * readTxtArbol(const char file_name[]);
int imprimirAlumno(Queue *pt);
int imprimirCarrera(Queue *pt);
int generarTxt(ListaDoble *pt);
static GtkWidget * makeMainMenu(Navegador *nav);
static GtkWidget * makeModulo1(Navegador *nav);
static GtkWidget * makeModulo2(Navegador *nav);
static GtkWidget * makeModulo3(Navegador *nav);
static GtkWidget * makeModulo4(Navegador *nav);


void setViewMainMenu(Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();
	gtk_init(NULL, NULL);
	display_box = makeMainMenu(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();

	
}

void setViewModulo1(Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();
	gtk_init(NULL, NULL);
	display_box = makeModulo1(nav);
	
	imprimirCarrera(nav->inicio->alumnos);

	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

void setViewModulo2(Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();
	gtk_init(NULL, NULL);
	display_box = makeModulo2(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

void setViewModulo3(Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();
	gtk_init(NULL, NULL);
	display_box = makeModulo3(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}

void setViewModulo4(Navegador *nav){
	gtk_widget_destroy(GTK_WIDGET(display_box));
	gtk_main_quit();
	gtk_init(NULL, NULL);
	display_box = makeModulo4(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();
}



static GtkWidget * makeModulo1(Navegador *nav){
	GtkWidget *boton_izq, *boton_der, *texto_carrera, *back;
	GtkWidget *hbox, *vbox;

	texto_carrera = gtk_label_new(NULL);
	//Falta agregar variable para que se imprima bien la info.
	gtk_label_set_markup(GTK_LABEL(texto_carrera), "Hello\nHello.");
	
	boton_izq = gtk_button_new_with_label("Izq");
	boton_der = gtk_button_new_with_label("Der");
	back = gtk_button_new_with_label("BACK");
	
	//gtk_signal_connect(GTK_OBJECT(boton_izq), "clicked", NULL, NULL); 
	//gtk_signal_connect(GTK_OBJECT(boton_der), "clicked", NULL, NULL); 
	gtk_signal_connect(GTK_OBJECT(back), "clicked", GTK_SIGNAL_FUNC(setViewMainMenu), nav); 

	hbox = gtk_hbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), boton_izq);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), texto_carrera);
	gtk_box_pack_start_defaults(GTK_BOX(hbox), boton_der);
	
	vbox = gtk_vbox_new(FALSE, 5);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
	gtk_box_pack_start_defaults(GTK_BOX(vbox), back);	
	return vbox;
}

static GtkWidget * makeModulo2(Navegador *nav){

}

static GtkWidget * makeModulo3(Navegador *nav){

}

static GtkWidget * makeModulo4(Navegador *nav){

}

static GtkWidget * makeMainMenu(Navegador *nav){
	GtkWidget *boton_m1, *boton_m2, *boton_m3, *boton_m4, *label, *vbox;
	
	
	imprimirCarrera(nav->inicio->alumnos);

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
	
	gtk_init(NULL, NULL);
	display_box = makeMainMenu(nav);
	
	gtk_container_add(GTK_CONTAINER(window), display_box);	
	gtk_widget_show_all(window);
	gtk_signal_connect(GTK_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
	gtk_main();

	return 0;
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
