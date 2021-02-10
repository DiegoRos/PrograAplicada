/*
*	@file: funciones.c	
*	@brief: Este programa permite manejar un expediente de alumnos. Los datos de los alumnos quedan
			almacenados en un archivo binario. El programa debe detectar cuántos alumnos han sido dados
			de alta en el archivo binario. También debe de permitir modificar los datos de un alumno 
			en una posición espefíficada del archivo.
*	@author: Clase de Guillermo Gómez
*	@date: 10/02/2021
*/

#include "defAlumno.h"

/*
*	@brief: Toma un alumno y el nombre del archivo e imprime el alumno a el file
*	@author: Clase de Guillermo Gómez
*	@param Alumno dat
*	@param char nomArch[]
*	@return
*/
extern int darAltaAlumnos(Alumno dat, char *nom_arch){
	FILE *fp;

	fp = fopen(nom_arch, "ab+");
	if (fp == NULL){
		printf("\n\tArchivo no disponible\n");
		exit(1);
	}
	fwrite(&dat, sizeof(Alumno), 1, fp);
	fclose(fp);

	return 1;
}

/*
*	@brief: Imprime todos los alumnos
*	@author: Clase Guillermo Gómez Abascal
*	@param char nomArch
*	@return
*/
extern int imprimirLista(char *nom_arch){
	FILE *fp;
	Alumno dat;
	int	num_alumnos = 0;
	
	fp = fopen(nom_arch, "ab+");
	if (fp == NULL){
		printf("\n\tArchivo no disponible\n");
		exit(1);
	}
	while(fread(&dat, sizeof(Alumno), 1, fp) == 1){
		num_alumnos++;
		printf("\n%i.- Cuenta: %i\n\tNombre: %s\n\tCarrera: %s\n\tPromedio: %f\n", num_alumnos, dat.cuenta, dat.nombre, dat.carrera, dat.promedio);
	}
	fclose(fp);
	
	return num_alumnos;
}

/*
*	@brief: Imprime y regresa el alumno alumno despues de un brinco n
*	@author: Clase Guillermo Gómez Abascal
*	@param int num
*	@param char nom_arch
*	@return
*/

extern Alumno mostrarAlumno(int num, char *nom_arch){
	FILE *fp;
	Alumno dat;
		
	fp = fopen(nom_arch, "ab+");
	if (fp == NULL){
		printf("\n\tArchivo no disponible\n");
		exit(1);
	}
	
	fseek(fp, num * sizeof(Alumno), SEEK_SET);
	// Tenemos 3 opciones:
		// 		1. SEEK_SET: seeks from the beginning of the file
		//		2. SEEK_CUR: seeks from current position of file pointer
		//		3. SEEK_END: seeks from final position of file
	fread(&dat, sizeof(Alumno), 1, fp);
	printf("\nAlumno- Cuenta: %i\n\tNombre: %s\n\tCarrera: %s\n\tPromedio: %f\n", dat.cuenta, dat.nombre, dat.carrera, dat.promedio);

	return dat;
}
