/*
*	@file: main.c	
*	@brief: Cotine el código principal del examen diagnóstio 2
*	@author: Equipo 3
*	@date: 26/03/2021
*/

#include "Ddef.h"


int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Número incorrecto de entradas\n");
		exit(1);
	}

	char opcion, guardar;

	do{
		printf("\n*************************************\n");
		printf("Opciones:\n\t[i]zquierda\n\t[d]erecha\n\t[m]ostar lista entera\n\t[s]alir");
		printf("\n*************************************\n");
		scanf(" %c", &opcion);

		switch(opcion){
			case 'i':
				// aux = aux->prev;	
				break;

			case 'd':
				// aux = aux->next;
				break;

			case 'm':
				// printf("\n");
				// imprimirCarrera(aux->alumnos);
				// printf("\n");
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
		// generarTxt(inicio);
		printf("Listo.\n");
	}

	return 0;
}

