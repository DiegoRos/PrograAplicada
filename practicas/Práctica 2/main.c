/*
*	@file: main.c	
*	@brief: Programa de C que permita abrir archivo de texto o binario, los cuales contienen una lista de información de pacientes
*			y hace ciertas manipulaciones sobre de los pacientes.
*	@author: Equipo 3
*	@date: 01/03/2021
*/

#include "defP2.h"

ListaCircular * leerTxt(char nombre_file[], ListaCircular *pt); //-> lee un paciente -> acomodaLista() ret -> lista
ListaCircular * leerBinario(char nombre_file[], ListaCircular *pt); //-> lee un paciente -> acomodaLista() ret-> lista
int imprimirPaciente(ListaCircular *pt);
int imprimirLista(ListaCircular *pt);
ListaCircular * modificarPaciente(ListaCircular *pt);
int imprimirPacientesCovid(ListaCircular *pt); // Intentar juntar imprimirPacientesCovid e imprimirPacientes
int guardarDatosTxt(ListaCircular *pt);
int guardarDatosBin(ListaCircular *pt);


int main(int argc, char *argv[]){
	if (argc < 2){
		printf("No se recibieron entradas adecuadas\n");
		exit(1);
	}
	
	int es_nodo_inicio = 0;
	char opcion;
	ListaCircular *inicio = NULL, *aux;
	if (strcmp(argv[1], "-t") == 0){
		inicio = leerTxt("pacientes.txt", inicio);
	}
	else if(strcmp(argv[1], "-b") == 0){
		inicio = leerBinario("pacientes.bin", inicio);
	}
	else{
		printf("Opción no válida.\n");
		exit(1);
	}
	
	imprimirLista(inicio);

	aux = inicio;
	if (inicio != NULL){
		do{
			printf("\nOpciones:\n\tr: Imprimir todos los pacientes\n\tm: Modificar algún paciente\n\tc: Imprimir Pacientes con COVID.\n\ts: Salir del programa.\n");
			scanf(" %c", &opcion);
			es_nodo_inicio = 0;
			switch(opcion){
				case 'r':
					imprimirPaciente(aux);	
					aux = aux->next;
					break;

				case 'm':
					if (aux == inicio){
						es_nodo_inicio = 1;
					}
					aux = modificarPaciente(aux);
					if (es_nodo_inicio){
						inicio = aux;
					}
					//aux = aux->next;
					break;

				case 'c':
					imprimirPacientesCovid(inicio);
					break;
				
				case 't':
					imprimirLista(inicio);
					break;
				
				case 's':
					break;

				default:
					printf("\nOpción no válida.\n");
					break;
			}

		}while(opcion != 's');
			
		printf("\nGracias, sus datos están siendo guardados.\n");
		guardarDatosTxt(inicio);
		guardarDatosBin(inicio);
	}	
	return 0;
}

