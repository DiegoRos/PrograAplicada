/*
*	@file: funciones.c	
*	@brief: Cotine las funciones que se van a correr en reporteAlumnos.c
*	@author: Equipo 3
*	@date: 16/03/2021
*/

#include "P3def.h"

/*
*	@brief: Función que agrega un nodo a una lista FIFO
*	@author: Equipo 3
*	@param Alumno temp: alumno a agregar al queue
*	@param Queue *q: Lista LIFO existente (o NULL)
*	@return Queue *
*/
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
*	@brief: Agrega un nuevo nodo a la lista doble
*	@author: Equipo 3
*	@param ListaDoble *nuevo: Nuevo elemento a agregar de la ListaDoble
*	@param ListaDoble *pt: Lista doble existente o NULL
*	@return ListaDoble *
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
*	@brief: Revisa si la carrera ya existe dentro de la lista doble
*	@author: Equipo 3
*	@param char carrera[]: String conteniendo nombre de carrera a revisar
*	@param ListaDoble *pt: Lista Doble existente o NULL
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
*	@brief: Función que coloca a un alumno dentro de la lista doble (crea un nuevo nodo o lo coloca en uno existente)
*	@author: Equipo 3
*	@param Alumno temp: Alumno a colocar
*	@param ListaDoble *pt: Lista doble existente o null
*	@return ListaDoble *
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
*	@brief: Función que lee file de estudiantes y los coloca en una lista doble.
*	@author: Equipo 3
*	@param char file_name[]: nombre de archivo
*	@return ListaDoble *
*/
extern ListaDoble * readTxt(char file_name[]){
	ListaDoble *pt = NULL;
	Alumno temp; 

	FILE *fp;
	fp = fopen(file_name, "r");
	
	while(fscanf(fp, "%i\t%[^\t]\t%[^\t]\t%f\n", &temp.num_cuenta, temp.nombre, temp.carrera, &temp.promedio) > 1){
		pt = colocarListaDoble(temp, pt);
	}
	fclose(fp);
	return pt;
}


/*
*	@brief: Imprmie lista FIFO entera conteniendo a todos los estudiantes de una carrea.
*	@author: Equipo 3
*	@param Queue *pt: Lista FIFO de alumnos a imprmir
*	@return int
*/
extern int imprimirCarrera(Queue *pt){
	Queue *aux = pt;
	int i = 1;

	if (aux == NULL) printf("La lista está vacía.\n");
	else{
		printf("\tLista de alumnos en carrera %s:\n", pt->val.carrera);
		while (aux != NULL){
			printf("\tAlumno %d:\n\t\tNo. de Cuenta: %i\n\t\tNombre: %s\n\t\tPromedio: %f\n", i, pt->val.num_cuenta, pt->val.nombre, pt->val.promedio);
			aux = aux->next;
			++i;
		}
	}
	
	return 0;
}

/*
*	@brief: Función que genera archivo de texto de los estudiantes final.
*	@author: Equipo 3
*	@param ListaDoble *pt: Lista doble contendieno a todas las carreras y estudiantes.
*	@return int
*/
extern int generarTxt(ListaDoble *pt){
	ListaDoble *aux = pt;
	Queue *alumnos = pt->alumnos;
	char nombre_file[] = "listas.txt";
	FILE *fp;

	fp = fopen(nombre_file, "w");
	do{
		fprintf(fp, "%s\t%d\t%f\t%s\n", aux->carrera, aux->num_alumnos, aux->promedio,aux->mejor_alumno.nombre);
		while(alumnos != NULL){
			fprintf(fp, "\t%i\t%s\t%f\n", alumnos->val.num_cuenta, alumnos->val.nombre, alumnos->val.promedio);
			alumnos = alumnos->next;
		}
		aux = aux->next;
		alumnos = aux->alumnos;
	}while(aux != pt);
	
	fclose(fp);	

	return 0;
}

