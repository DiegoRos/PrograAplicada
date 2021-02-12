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

/*
*	@brief: Obtiene el tamaño de un file que contiene n Alumnos
*	@author: Clase Guillermo Gómez Abascal
*	@param char nom_arch
*	@return int
*/
extern int numAlumnos(char *nom_arch){
	FILE *fp;
	int num, tamano_bytes;
	
	fp = fopen(nom_arch, "rb+");
	if (fp == NULL){
		printf("\n\tArchivo no disponible\n");
		exit(1);
	}
	fseek(fp,0,SEEK_END);

	tamano_bytes = ftell(fp);
	num = (int) tamano_bytes / sizeof(Alumno);

	printf("El archivo es de tamaño %i\n", tamano_bytes);
	printf("Y contiene %i alumnos.\n", num);
	
	fclose(fp);

	return num;
}

/*
*	@brief: Cambia un alumno en una posición dada.
*	@author: Clase Guillermo Gómez Abascal
*	@param char nom_arch
*	@return int
*/
extern int modificarAlumno(int num, char *nom_arch){
	FILE *fp;
	int total_alumnos = numAlumnos(nom_arch);
	Alumno datos;

	fp = fopen(nom_arch, "rb+");
	if (fp == NULL){
		printf("\n\tArchivo no disponible\n");
		exit(1);
	}
	
	if (num < total_alumnos){
		datos = mostrarAlumno(num, nom_arch);
		 
		printf("\nDame la cuenta del alumno %i: ", num);
		scanf(" %i", &datos.cuenta);

		printf("Dame su nombre: ");
		scanf(" %[^\n]", datos.nombre);
		
		printf("Dame su carrera: ");
		scanf(" %[^\n]", datos.carrera);

		printf("Dame su promedio: ");
		scanf(" %f", &datos.promedio);
		
		fseek(fp, num * sizeof(Alumno), SEEK_SET);
		fwrite(&datos, sizeof(Alumno), 1, fp);
	}

	fclose(fp);
	return 1;
}
