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

#include "PProyectodef.h"

ListaDoble * readTxt(char file_name[]);
int imprimirAlumno(Queue *pt);
int imprimirCarrera(Queue *pt);
int generarTxt(ListaDoble *pt);


int main(int argc, char *argv[]){
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

