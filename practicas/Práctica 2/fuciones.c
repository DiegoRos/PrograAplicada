#include "defP2.h"

/*
*	@brief: Acomoda a un paciente nuevo en una existente en orden alfabético.
*	@autor: Equipo <3
*	@param Paciente nuevo
*	@param Paciente *pt
*	@return Paciente *
*/
ListaCircular * acomodarLista(Paciente nuevo, ListaCircular *pt){
	
	return pt;
}

/*
*	@brief: Lee archivo de texto que contiene pacientes y los guarada en una lista circular.
*	@autor: Equipo <3
*	@param string nombre_file
* 	@param Paciente *pt
*	@return Paciente *
*/
ListaCircular * leerTxt(char nombre_file[], ListaCircula *pt){
	FILE *fp;
	fopen(nombre_file, "r");
	if (fp == NULL){
		printf("File no encontrado\n");
		exit(1);
	}
	
	Paciente nuevo;
	while(fscanf(fp, "%[^\t]%[^\t]%i\t%c\n", nuevo.nombre, nuevo.direccion, &nuevo.telefono, &nuevo.covid) == 4){
		pt = acomodarLista(nuevo, pt);
	}

	fclose(fp);
	return pt;
}

/*
*	@brief: Lee un archivo binario que contiene pacientes y los guarda en una lista circular;
*	@autor: Equipo <3
*	@param string nombre_file
*	@param Paciente *lista
*	@return Paciente * 
*/
ListaCircular * leerBinario(char nombre_file[], ListaCircular *pt){
	FILE *fp;
	fopen(nombre_file, "rb");
	if (fp == NULL){
		printf("File no encontrado\n");
		exit(1);
	}
	
	Paciente nuevo;
	while(fread(&nuevo, sizeof(Paciente), 1, fp) == 1){
		pt = acomodarLista(nuevo, pt);
	}

	fclose(fp);

	return pt;
}

/*
*	@brief: 
*	@autor:
*	@param 
*	@param
*	@return
*/
int imprimirPaciente(ListaCircular *pt){

}

/*
*	@brief: 
*	@autor:
*	@param 
*	@param
*	@return
*/
int modificarPaciente(ListaCircular *pt){

}

/*
*	@brief: 
*	@autor:
*	@param 
*	@param
*	@return
*/
int imprimirPacientesCovid(ListaCircular *pt){

}

/*
*	@brief: 
*	@autor:
*	@param 
*	@param
*	@return
*/
int guardarDatosTxt(ListaCircular *pt){

}

/*
*	@brief: 
*	@autor:
*	@param 
*	@param
*	@return
*/
int guardarDatosBin(ListaCircular *pt){

}

