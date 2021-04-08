/*
*	@file: main.c
*	@brief: Contiene el código principal de la práctica 4
*	@author: Equipo 3
*	@date: 07/04/2021
*/

#include "defP4.h"

const char * generarRandom(int n);
ListaDoble * generarLista(char nombre_file[]);
ListaDoble * buscarEnLista(ListaDoble *pt, int num);
int generarTxt(ListaDoble *pt);

int main(int argc, char *argv[]){
	int n;
	char guardar;
	char nombre_file[256];
		
	//Inicializar Random Seed
	srand(Time())

	printf("Insertar Cantiadad de Números: ")
	scanf(" %i", &n);

	printf("\nCreando Archivo...\n");
	strcpy(nombre_file, generarRandom(n));
	printf("Listo.\n");
	
	
			
	
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


