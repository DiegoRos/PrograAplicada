/*
*	@file: funciones.c	
*	@brief: Cotine las funciones que se van a correr en reporteAlumnos.c
*	@author: Equipo 3
*	@date: 16/03/2021
*/

#include "Proyectodef.h"

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
			if (aux == pt)
				break;
		}
		nuevo->next = aux;
		nuevo->prev = aux->prev;
		aux->prev->next = nuevo;
		aux->prev = nuevo;

		if((aux == pt) && (strcmp(nuevo->carrera, aux->carrera) < 0)){
			pt = nuevo;
		}
	}


	return pt;
}

/*
*	@brief: Borra un nodo de la lista doble
*	@author: Equipo 3
*	@param ListaDoble *nuevo: Nuevo elemento a agregar de la ListaDoble
*	@param ListaDoble *pt: Lista doble existente o NULL
*	@return ListaDoble *
*/
Navegador * popLD(Navegador *nav){
	ListaDoble *borrar = nav->aux_lista;
	if (nav->inicio == NULL) printf("La lista está vacía\n");
	else if (nav->aux_lista == nav->aux_lista->next){
		free(borrar);
		nav->inicio = NULL;
		nav->aux_lista = NULL;
	}
	else{
		nav->aux_lista = nav->aux_lista->next;
		borrar->prev->next = borrar->next;
		borrar->next->prev = borrar->prev;

		if (borrar == nav->inicio){
			nav->inicio = nav->inicio->next;
		}
		free(borrar);
	}
	return nav;
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
ListaDoble * readTxtLista(const char file_name[]){
	ListaDoble *pt = NULL;
	Alumno temp; 

	FILE *fp;
	fp = fopen(file_name, "r");
	if (fp == NULL){
		printf("No se pude leer file.\n");
		exit(1);
	}
	
	while(fscanf(fp, "%i\t%[^\t]\t%[^\t]\t%f\n", &temp.num_cuenta, temp.nombre, temp.carrera, &temp.promedio) > 1){
		pt = colocarListaDoble(temp, pt);
	}
	fclose(fp);
	return pt;
}

/*
*	@brief: Función que coloca a un alumno dentro de un árbol binario ordenado por número de cuenta.
*	@author: Equipo 3
*	@param nodo *pt: Arbol existente o nulls
*	@param Alumno temp: Alumno a colocar
*	@return ListaDoble *
*/
nodo * insertarArbol(nodo *pt, Alumno temp){	
	if (pt == NULL){
		nodo *nuevo = (nodo *)malloc(sizeof(nodo));
	
		nuevo->alumno = temp;
		nuevo->izq = NULL;
		nuevo->der = NULL;
		return nuevo;
	}

	if (pt->alumno.num_cuenta < temp.num_cuenta){
		pt->der = insertarArbol(pt->der, temp);
	}
	else{
		pt->izq = insertarArbol(pt->izq, temp);	
	}

	return pt;
}

/*
*	@brief: Función que lee file de estudiantes y los coloca en una lista doble.
*	@author: Equipo 3
*	@param char file_name[]: nombre de archivo
*	@return ListaDoble *
*/
nodo * readTxtArbol(const char file_name[]){
	nodo *root = NULL;
	Alumno temp;
	
	FILE *fp;
	fp = fopen(file_name, "r");

	if (fp == NULL){
		printf("No se pude leer file.\n");
		exit(1);
	}

	while(fscanf(fp, "%i\t%[^\t]\t%[^\t]\t%f\n", &temp.num_cuenta, temp.nombre, temp.carrera, &temp.promedio) > 1){
		root = insertarArbol(root, temp);
	}
	fclose(fp);

	return root;
}


/*
*	@brief: Imprmie lista FIFO entera conteniendo a todos los estudiantes de una carrea.
*	@author: Equipo 3
*	@param Queue *pt: Lista FIFO de alumnos a imprmir
*	@return int
*/
int imprimirCarrera(const char *file_name, Queue *pt){
	FILE *fp;
	fp = fopen(file_name, "w");
	
	Queue *aux = pt;
	int i = 1;

	if (aux == NULL) fprintf(fp, "La lista está vacía.\n");
	else{
		fprintf(fp, "<span size='xx-large' weight='ultrabold'>Lista de alumnos en carrera %s:</span>\n\n", pt->val.carrera);
		while (aux != NULL){
			fprintf(fp, "<span weight='bold'>Alumno %d:</span>\n\tNo. de Cuenta: %i\n\tNombre: %s\n\tPromedio: %f\n", i, aux->val.num_cuenta, aux->val.nombre, aux->val.promedio);
			aux = aux->next;
			++i;
		}
	}
	
	fclose(fp);
	return 0;
}

/*
*	@brief: Busca y regresa un estudiante dentro de un árbol binario.
*	@author: Equipo 3
*	@param nodo *root
*	@return nodo *
*/
nodo * buscarNodo(nodo *root, int num_cuenta){
	nodo *aux =  NULL;
	if(root == NULL)
		return NULL;
	
	if(root->alumno.num_cuenta == num_cuenta){
		return root;
	}

	if (root->alumno.num_cuenta < num_cuenta){
		aux = buscarNodo(root->der, num_cuenta);
		if(aux)
			return aux; // Ya no hay necesidad de buscar más
	}
	else{
		aux = buscarNodo(root->izq, num_cuenta);
		if(aux)
			return aux; // Ya no hay necesidad de buscar más
	}
		
	return aux;
}


/*
*	@brief: Función que genera archivo de texto de los estudiantes final.
*	@author: Equipo 3
*	@param ListaDoble *pt: Lista doble contendieno a todas las carreras y estudiantes.
*	@return int
*/
int generarTxt(Navegador *nav){
	ListaDoble *pt = nav->inicio;
	ListaDoble *aux = pt;
	char nombre_file[] = "alumnos.txt";
	FILE *fp;
	fp = fopen(nombre_file, "w");
	if (pt){
		Queue *alumnos = pt->alumnos;
		do{
			while(alumnos != NULL){
				fprintf(fp, "%i\t%s\t%s\t%f\n", alumnos->val.num_cuenta, alumnos->val.nombre, alumnos->val.carrera, alumnos->val.promedio);
				alumnos = alumnos->next;
			}
			aux = aux->next;
			alumnos = aux->alumnos;
		}while(aux != pt);
	}
	fclose(fp);	

	return 0;
}


/*
*	@brief: Función que genera archivo de texto de los mejores alumnos con cierto promedio.
*	@author: Equipo 3
*	@param char *nombre_file: nombre de archivo 
*	@param float promedio: promedio mínimo 
*	@param Navegador *nav: Navegador con lista doble
*	@return int
*/
int buscarLDPromedio(char *nombre_file, float promedio, Navegador *nav){
	ListaDoble *pt = nav->inicio;
	ListaDoble *aux = pt;
	int cont = 0;
	FILE *fp;
	fp = fopen(nombre_file, "w");

	if (pt){
		do{
			if (aux->mejor_alumno.promedio >= promedio){
				fprintf(fp, "<span weight='ultrabold'>Nombre:</span> %s\n\t<span weight='bold'>Número de Cuenta:</span> %i\n\t<span weight='bold'>Carrera:</span> %s\n\t<span weight='bold'>Promedio:</span> %f\n\n", aux->mejor_alumno.nombre, aux->mejor_alumno.num_cuenta, aux->mejor_alumno.carrera, aux->mejor_alumno.promedio);
				++cont;
			}
			aux = aux->next;
		}while(aux != pt);
	}
	else{
		fprintf(fp,"<span weight='ultrabold'>No hay carreras en la lista</span>\n");
	}

	if (cont == 0){	
		fprintf(fp,"<span weight='ultrabold'>No hay ningún mejor \nestudiante con ese promedio</span>\n");
	}
	fclose(fp);

	return 0;
}

