/*
*	@file: archbin.c	
*	@brief: Aprendiendo a utilizar archivos binarios
*	@author: Clase Guillermo Gómez Abascal
*	@date: 08/01/2021
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void capturarReales(float num, char nombre_archivo[]);
int cuantificarArchivo(char nombre_archivo[]);
void imprimirDatosArch(char nombre_archivo[]);
void modificarNumero(float num, int pos, char nombre_archivo[]);

int main(int argc, char *argv[]){
	float numero;
	int posicion;
	char nombre[40];

	strcpy(nombre, argv[1]);

	do{
		printf("Ingresar un número real: ");
		scanf(" %f", &numero);
		if(numero != 0) capturarReales(numero, nombre);
	}while(numero != 0);

	printf("Tu archivo de reales tiene %i números capturados\n", cuantificarArchivo(nombre));
	imprimirDatosArch(nombre);

	return 0;
}

/*
*	@brief: Guarda un valor flotante en un archivo binario.
*	@author: Guillermo Gómez Abascal
*	@param float num
*	@param char nombre_archivo[]
*	@return void
*/

void capturarReales(float num, char nombre_archivo[]){
	FILE *fp;
	fp = fopen(nombre_archivo, "ab+");
	if (fp == NULL){
		printf("\nArchivo no disponible\n");
		exit(1);
	}
	
	fwrite(&num, sizeof(float), 1, fp);

	fclose(fp);
}


/*
*	@brief: Obtiene la cantidad de flotantes que tiene el file. 
*	@author: Guillermo Gómez Abascal
*	@param char nombre_archivo[]
*	@return void
*/

int cuantificarArchivo(char nombre_archivo[]){
	int count = 0;
	float val;

	FILE *fp;
	fp = fopen(nombre_archivo, "ab+");
	if (fp == NULL){
		printf("\nArchivo no disponible.\n");
		exit(1);
	}

	while(fread(&val, sizeof(float), 1, fp))
		count++;

	fclose(fp);

	return count;				
}

/*
*	@brief: Guarda un valor flotante en un archivo binario.
*	@author: Guillermo Gómez Abascal
*	@param float num
*	@param char nombre_archivo[]
*	@return void
*/

void imprimirDatosArch(char nombre_archivo[]){
	float val;

	FILE *fp;
	fp = fopen(nombre_archivo, "rb+");
	if (fp == NULL){
		printf("\nArchivo no disponible\n");
		exit(1);
	}
	
	while(fread(&val, sizeof(float), 1, fp)){
		printf("%f\n", val);
	}

	fclose(fp);
}


void modificarNumero(float num, int pos, char nombre_archivo[]);
