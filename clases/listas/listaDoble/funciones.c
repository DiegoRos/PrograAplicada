#include "defLista.h"

//Esto de aqui es para una lista dobre CIRCULAR
ListaDoble * enQueueLD(char val[], ListaDoble *pt){
	ListaDoble *nuevo; 
	nuevo = (ListaDoble *)malloc(sizeof(ListaDoble));
	strcpy(nuevo->val, val);

	if (pt == NULL){
		nuevo->prev = nuevo;
		nuevo->next = nuevo;
		pt = nuevo;
	}

	else{
		nuevo->prev = pt->prev;
        pt->prev->next = nuevo;
		nuevo->next = pt;
		pt->prev = nuevo;
	}

	return pt;
}

ListaDoble * pushLD(char val[], ListaDoble *pt){
	ListaDoble *nuevo;
	nuevo = (ListaDoble *)malloc(sizeof(ListaDoble));
	strcpy(nuevo->val, val);
	if (pt == NULL){
		nuevo->prev = nuevo;
		nuevo->next = nuevo;
		pt = nuevo;
	}
	else{
		nuevo->prev = pt->prev;
		nuevo->next = pt;
		pt->prev->next = nuevo;
		pt->prev = nuevo;
	}

	return pt;
	
}

ListaDoble * popLD(ListaDoble *pt){
	ListaDoble *aux = pt;

	if (pt == NULL){
		printf("La lista está vacía\n");
	}
	else{
		pt->next = pt->prev;
		pt->prev = pt->next;
		pt = pt->next;
		free(aux);
	}

	return pt;
}

int imprimeLD(ListaDoble *pt){
	ListaDoble *aux = pt;
	if(pt == NULL){
		printf("La lista está vacía\n");
	}
	else{
		do{
			printf("En la dirección %p está la palabra: %s\n", aux, aux->val);
			aux = aux->next;
		}while(aux != pt);
	}

	return 1;
}