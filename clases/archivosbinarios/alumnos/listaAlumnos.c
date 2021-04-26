/*
*	@file: listaAlumnos.c	
*	@brief: Este programa permite manejar un expediente de alumnos. Los datos de los alumnos quedan
			almacenados en un archivo binario. El programa debe detectar cuántos alumnos han sido dados
			de alta en el archivo binario. También debe de permitir modificar los datos de un alumno 
			en una posición espefíficada del archivo.
*	@author: Clase de Guillermo Gómez
*	@date: 10/02/2021
*/

#include "defAlumno.h"

int darAltaAlumnos(Alumno dat, char *nom_arch);
int imprimirLista(char *nom_arch);
Alumno mostrarAlumno(int num, char *nom_arch);
int numAlumnos(char *nom_arch); 
int modificarAlumno(int num, char *nom_arch);

int main(int argc, char *argv[]){
	
	Alumno datos;
	int i = 1, posicion;
	char opcion;
	/*
	do {
	printf("\nDame la cuenta del alumno %i: ", i);
	scanf(" %i", &datos.cuenta);

	printf("Dame su nombre: ");
	scanf(" %[^\n]", datos.nombre);
	
	printf("Dame su carrera: ");
	scanf(" %[^\n]", datos.carrera);

	printf("Dame su promedio: ");
	scanf(" %f", &datos.promedio);

	darAltaAlumnos(datos, argv[1]);

	printf("\nDeseas dar de alta otro alumno: [s/n]");
	scanf(" %c", &opcion);

	}while(opcion == 's');
	*/
	imprimirLista(argv[1]);
	
	printf("\nEntra el número de alumno que deseas reviasr y cambiar: (VALOR MAXIMO = %d)", numAlumnos(argv[1]));
	scanf(" %d", &posicion);
	//mostrarAlumno(posicion, argv[1]);

	modificarAlumno(posicion, argv[1]);
	return 0;
}
