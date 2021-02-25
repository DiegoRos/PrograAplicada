/*
*	@file: main.c	
*	@brief: Programa de C que permita abrir archivo de texto o binario, los cuales contienen una lista de información de pacientes
*			y hace ciertas manipulaciones sobre de los pacientes.
*	@author: Equipo 3
*	@date: 01/03/2021
*/

#include "defP2.h"

ListaCircular * leerTxt(char nombre_file[], ListaCircular *pt); 
ListaCircular * leerBinario(char nombre_file[], ListaCircular *pt);
int imprimirPaciente(ListaCircular *pt);
int imprimirLista(ListaCircular *pt);
ListaCircular * modificarPaciente(ListaCircular *aux, ListaCircular *pt);
int imprimirPacientesCovid(ListaCircular *pt);
int guardarDatosTxt(ListaCircular *pt);
int guardarDatosBin(ListaCircular *pt);


int main(int argc, char *argv[]){
	if (argc < 2){
		printf("No se recibieron entradas adecuadas\n");
		exit(1);
	}
	
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
			printf("\n=====================================================\n");
			printf("Opciones:\n\tr: Imprimir paciente\n\tm: Modificar algún paciente\n\tc: Imprimir Pacientes con COVID.\n\tt: Imprimir lista en orden alfabética.\n");
			printf("\ts: Salir del programa\n");
			printf("=====================================================\n");
			printf("\t\tOpcion: ");	
			scanf(" %c", &opcion);
			switch(opcion){
				case 'r':
					imprimirPaciente(aux);	
					aux = aux->next;
					break;

				case 'm':
					aux = modificarPaciente(aux, inicio);
					printf("Lista modificada de pacientes\n");
					imprimirLista(inicio);
					printf("\n");
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

