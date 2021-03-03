/*
*	@file: Funciones.c
*	@brief: Contiene todas las funciones para correr el valor de main entero
*	@author: Equipo 3
*	@date: 01/03/2021
*/

#include "defLista.h" 

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
Lista * enQueue(Ciudadano nuevo, Lista *q){
	Lista *aux;
	aux = q;

	Lista *nodo_nuevo = (Lista *)malloc(sizeof(Lista));
	nodo_nuevo->solicitud = nuevo;
	nodo_nuevo->next = NULL;
	if (aux == NULL){
		return nodo_nuevo;
	}	

	while (aux->next != NULL){
		aux = aux->next;
	}
	aux->next = nodo_nuevo;
	
	return q;	
}

Lista * leerTxt(char nombre_archivo[], Lista *pt){
	FILE *fp;
	fp = fopen(nombre_archivo, "r");
	if (fp == NULL){
		printf("File no encontrado\n");
		exit(1);
	}

	Ciudadano nuevo;
	while (fscanf(fp, "%[^\t]\t%i\t%i\n", nuevo.nombre, &nuevo.cp, &nuevo.edad) > 1){
		if ((nuevo.edad >= 10) && (nuevo.edad <= 29)){
			strcpy(nuevo.mes, "septiembre");
		}
		else if ((nuevo.edad >= 20) && (nuevo.edad <= 49)){
			strcpy(nuevo.mes, "octubre");
		}
		else if ((nuevo.edad >= 50) && (nuevo.edad <= 79)){
			strcpy(nuevo.mes, "noviembre");
		}
		else if (nuevo.edad > 79){
			strcpy(nuevo.mes, "diciembre"); 
		}

		pt = enQueue(nuevo, pt);
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
Lista * deQueue(Lista *q){
	Lista *aux;
	if (q == NULL){
		printf("Lista vacía\n");
	}
	else{
		aux = q;
		q = q->next;
		free(aux);
	}
	return q;
}

/*
*	@brief: Esta función imprime un queue entero
*	@author: Equipo 3
*	@param Stack *q
*	@return Stack *q
*/
int imprimirLista(Lista *q){
	while (q != NULL){
		printf("Ciudadano:\n\tNombre: %s\t Código Postal: %i\t Edad: %i\t Mes Vacunación: %s\n", q->solicitud.nombre, q->solicitud.cp, q->solicitud.edad, q->solicitud.mes);
		q = q->next;
	}

	return 1;
}

/*
*	@brief: Inserta un nuevo nodo en la lista LIFO circular con un Ciudadano 
*	@author: Diego Rosenberg de Angoitia
*	@param Ciudadano nuevo
*	@param Lista *s
*	@return Lista *
*/
Lista * pushCirc(Ciudadano nuevo, Lista *pt){
	Lista *aux1 = (Lista *)malloc(sizeof(Lista));
	aux1->solicitud = nuevo;
	if (pt == NULL){
		aux1->next = aux1;
	}
	else if (pt->next == pt){
		aux1->next = pt;
		pt->next = aux1;
	} 
	else{
		while(pt->next != pt){
			pt = pt->next;
		}
		aux1->next = pt;
		pt->next = aux1;
	}

	pt = aux1;
	return pt;
}

/*
*	@brief: Esta función imprime un stack cicular entero
*	@author: Diego Rosenberg de Angoitia
*	@param Lista *pt
*	@return Lista *pt
*/
int imprimirStackCirc(Lista *pt){
	Lista *aux = pt;

	if (pt == NULL){
		printf("La lista está vacía\n");
	}
	else{
		do{
			printf("Ciudadano:\n\tNombre: %s\t Código Postal: %i\t Edad: %i\t Mes Vacunación: %s\n", aux->solicitud.nombre, aux->solicitud.cp, aux->solicitud.edad, aux->solicitud.mes);
			aux = aux->next;
		}while (aux != pt);
	}
	return 1;
}

Lista * reducirEdades(Lista *inicio1, Lista *inicio4){	
	Lista *aux = inicio1;
	int edad1, edad2;
	char opcion;
	if (inicio1 == NULL){
		inicio4 = NULL;
	}
	else{
		do{
			printf("\nIntroducir rango inferior de edades: ");
			scanf(" %i", &edad1);

			printf("Introducir rango superior de edades: ");
			scanf(" %i", &edad2);
			
			if (edad1 < edad2){
				printf("El rango es entre %i y %i\n", edad1, edad2);
				printf("Esto es correcto? [s/n] ");
				scanf(" %c", &opcion);
			}
			else{
				printf("Orden de operadores es incorrecto\n");
				opcion = 'n';
			}
		}while(opcion != 's');
		do{
			if ((aux->solicitud.edad > edad1) && (aux->solicitud.edad < edad2)){
				inicio4 = pushCirc(aux->solicitud, inicio4);
			}
			aux = aux->next;
		}while(aux != NULL);
	}

	
	return inicio4;
}
