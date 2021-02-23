/*
*	@file: funciones.c
*	@brief: Contiene las funciones utilizadas en main.c.
*	@author: Equipo 3
*	@date: 01/03/2021
*/

#include "defP2.h"

/*
*	@brief: Acomoda a un paciente nuevo en una existente en orden alfabético.
*	@autor: Equipo <3
*	@param Paciente nuevo
*	@param Paciente *pt
*	@return Paciente *
*/
ListaCircular * acomodarLista(Paciente nuevo, ListaCircular *pt){
	ListaCircular *aux = pt, *nodo_nuevo, *nodo_previo;
	nodo_nuevo = (ListaCircular *)malloc(sizeof(ListaCircular));
	nodo_nuevo->solicitud = nuevo;
	
	if (pt == NULL){
		nodo_nuevo->next = nodo_nuevo;
		pt = nodo_nuevo;
	}
	else if(pt == pt->next){
		if(strcmp(aux->solicitud.nombre, nodo_nuevo->solicitud.nombre) < 0){
			aux->next = nodo_nuevo;
			nodo_nuevo->next = pt;
		}
		else{
			nodo_nuevo->next = aux;
			aux->next = nodo_nuevo;
		}
	}
	else{
		while(aux->next != pt) aux = aux->next;

		nodo_previo = aux;
		aux = pt;

		do{
			printf("%s\t%s\t%s\t",nodo_previo->solicitud.nombre, aux->solicitud.nombre, nodo_nuevo->solicitud.nombre);
			printf("%d\n", strcmp(aux->solicitud.nombre, nodo_nuevo->solicitud.nombre));
			if(strcmp(aux->solicitud.nombre, nodo_nuevo->solicitud.nombre) < 0){
				nodo_previo = aux;
				aux = aux->next;
			}
			else{
				nodo_nuevo->next = aux;
				nodo_previo->next = nodo_nuevo;
				if(aux == pt){
					pt = nodo_nuevo;
				}
				break;
			}
		}while(aux != pt);
		if (aux == pt){
			nodo_nuevo->next = aux;
			nodo_previo->next = nodo_nuevo;
		}
	}
	
	return pt;
}

/*
*	@brief: Lee archivo de texto que contiene pacientes y los guarada en una lista circular.
*	@autor: Equipo <3
*	@param string nombre_file
* 	@param Paciente *pt
*	@return Paciente *
*/
ListaCircular * leerTxt(char nombre_file[], ListaCircular *pt){
	FILE *fp;
	fp = fopen(nombre_file, "r");
	if (fp == NULL){
		printf("File no encontrado\n");
		exit(1);
	}

	Paciente nuevo;
	while(fscanf(fp, "%[^\t]\t%[^\t]\t%i\t%c\n", nuevo.nombre, nuevo.direccion, &nuevo.telefono, &nuevo.covid) > 1){
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
*	@param:  
*	@return
*/
int imprimirPaciente(ListaCircular *pt){

}

/*
*	@brief: Imprime todos los nodos de una lista circular.
*	@autor: Equipo <3
*	@param ListaCircular *pt
*	@return int
*/
int imprimirLista(ListaCircular *pt){
	ListaCircular *aux = pt;
	
	if (pt == NULL){
		printf("La lista está vacía.\n");
	}
	else{
		do{
			printf("Nombre:%s\tDireccion:%s\tTel:%i\tCovid:%c\n", aux->solicitud.nombre, aux->solicitud.direccion, aux->solicitud.telefono, aux->solicitud.covid);
			aux = aux->next;
		}while(aux != pt);
	}
	return 1;
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

