/*
*	@file: funciones.c	
*	@brief: Cotine las funciones que se van a correr en el main.c
*	@author: Equipo 3
*	@date: 16/03/2021
*/

#include "P3def.h"

Queue * enQueue(Alumno temp, Queue *q){
	Queue *aux = q;
	Queue *nuevo = (Queue *)malloc(sizeof(Queue));

	nuevo->val = temp;
	nuevo->next = NULL;

	if(aux == NULL){
		q = nuevo;
	}
	
	else{
		while(aux->next != NULL){
			aux = aux->next;
		}
		aux->next = nuevo;
	}

	return q;
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
ListaDoble *pushLD(ListaDoble *nuevo, ListaDoble *pt){
	ListaDoble *aux = pt;

	if(aux == NULL){
		nuevo->next = nuevo;
		nuevo->prev = nuevo;
		pt = nuevo;
	}
	else if(aux == aux->next){
		aux->next = nuevo;
		aux->prev = nuevo;
		nuevo->next = aux;
		nuevo->prev = aux;
		if(strcmp(nuevo->carrera, aux->carrera) > 0){
			pt = aux;		
		}
		else{
			pt = nuevo;
		}
	}
	else{
		while(strcmp(nuevo->carrera, aux->carrera) > 0){
			aux = aux->next;
		}
		nuevo->next = aux;
		nuevo->prev = aux->prev;
		aux->prev->next = nuevo;
		aux->prev = nuevo;

		if(aux == pt){
			pt = nuevo;
		}
	}


	return pt;
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return bool
*/
int carreraExistente(char carrera[], ListaDoble *pt){
	ListaDoble *aux = pt;
	if(aux == NULL){
		return False;
	}
	
	do{
		if(strcmp(carrera, aux->carrera) == 0){
			return True;
		}
		
		aux = aux->next;
	}while(aux != pt);
	
	return False;
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
ListaDoble * colocarListaDoble(Alumno temp, ListaDoble *pt){
	ListaDoble *aux = pt;
	int existe_carrera;

	existe_carrera = carreraExistente(temp.carrera, pt);

	if(existe_carrera){
		while(strcmp(temp.carrera, aux->carrera) != 0){
			aux = aux->next;	
		}
		aux->num_alumnos++;
		aux->promedio = (((aux->num_alumnos - 1) * aux->promedio) + temp.promedio) / aux->num_alumnos;
		if(temp.promedio > aux->mejor_alumno.promedio){
			aux->mejor_alumno = temp;
		}
		aux->alumnos = enQueue(temp, aux->alumnos);
	}
	else{
		ListaDoble *nuevo = (ListaDoble *)malloc(sizeof(ListaDoble));
		nuevo->num_alumnos = 1;
		nuevo->promedio = temp.promedio;
		nuevo->mejor_alumno = temp;
		nuevo->alumnos = enQueue(temp, NULL);
		strcpy(nuevo->carrera, temp.carrera);

		pt = pushLD(nuevo, pt);
	}

	return pt;
}


/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
extern ListaDoble * readTxt(char file_name[]){
	ListaDoble *pt = NULL;
	Alumno temp; 

	FILE *fp;
	fp = fopen(file_name, "r");
	
	while(fscanf(fp, "%i\t%[^\t]\t%[^\t]\t%f\n", &temp.num_cuenta, temp.nombre, temp.carrera, &temp.promedio) > 1){
		pt = colocarListaDoble(temp, pt);
	}
	return pt;
}


/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
extern int imprimirAlumno(Queue *pt){

	return 0;
}


/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
extern int imprimirCarrera(Queue *pt){
	
	return 0;
}


/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
extern int generarTxt(ListaDoble *pt){

	return 0;
}

