/*
*	@file: main.c	
*	@brief: Cotine el código principal del examen diagnóstio 2
*	@author: Equipo 3
*	@date: 26/03/2021
*/

#include "defex02.h"

ArbolCiudad * leerTxt(char nombre_file[]);
ListaCiudad * generarContagiosTodas(ArbolCiudad *root, ListaCiudad *pt);
void imprimirListaCiudades(ListaCiudad *pt);
ListaPacientes * unirPacientesGripe(ArbolCiudad *root, ListaPacientes *pt);
ListaPacientes * unirPacientesResfriado(ArbolCiudad *root, ListaPacientes *pt);
void bubbleSortNombre(ListaPacientes *start);
void bubbleSortCiudad(ListaPacientes *start);
void imprimirPacientes(ListaPacientes *start, char file_name[]);
void imprimirCiudad(ArbolCiudad *aux);
ArbolCiudad * ciudadEnArbol(ArbolCiudad *root, char ciudad[]);

int main(int argc, char *argv[]){
	ArbolCiudad *root = NULL, *aux;
	ListaCiudad *pt = NULL;
	ListaPacientes *pacientes_gripe = NULL, *pacientes_resfriado = NULL;
	if (argc == 2){
		root = leerTxt(argv[1]);
		
		pt = generarContagiosTodas(root, pt);
		imprimirListaCiudades(pt);
	}

	else if (argc == 3){
		root = leerTxt(argv[1]);
		if (strcmp(argv[2], "-g") == 0){
			pacientes_gripe = unirPacientesGripe(root, pacientes_gripe);
			bubbleSortNombre(pacientes_gripe);

			imprimirPacientes(pacientes_gripe, "gripe.txt");
		}
		else if (strcmp(argv[2], "-r") == 0){
			pacientes_resfriado = unirPacientesResfriado(root, pacientes_resfriado);
			bubbleSortCiudad(pacientes_resfriado);

			imprimirPacientes(pacientes_resfriado, "resfriado.txt");
		}
		else{
			aux = ciudadEnArbol(root, argv[2]);
			if (aux == NULL){
				printf("Ciudad no encontrada\n");
			}
			
		}
	}

	else{
		printf("Opción no válida.\n");
	}

	return 0;
}

