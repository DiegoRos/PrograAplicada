#include "listaDoble.h"

//Esto de aqui es para una lista dobre CIRCULAR
extern ListaDoble * enQueueLD(char val[], ListaDoble *pt){
	ListaDoble *nuevo, *aux = pt; 
	nuevo = (ListaDoble *)malloc(sizeof(ListaDoble));
	strcpy(nuevo->val, val);

	if (pt == NULL){
		nuevo->prev = nuevo;
		nuevo->next = nuevo;
		pt = nuevo;
	}

	else{
		aux = pt ->prev;
		nuevo->prev = aux;
		nuevo->next = pt;
		pt->prev = nuevo;
		aux->next = nuevo;
	}

	return pt;
}

extern ListaDoble * pushLD(char val[], ListaDoble *pt){
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

extern ListaDoble * popLD(ListaDoble *pt){
	ListaDoble *borrar = pt;

	if (pt == NULL){
		printf("La lista está vacía\n");
	}
	else if(pt == pt->next){
		free(borrar);
		pt = NULL;
	}
	else{
		borrar->prev->next = borrar->next;
		pt->next->prev = borrar->prev;
		pt = pt->next;
		free(borrar);
	}
	return pt;
}


extern int imprimirLDIzquierda(ListaDoble *pt){
	ListaDoble *aux = pt;
	if(pt == NULL){
		printf("La lista está vacía\n");
	}
	else{
		do{
			printf("Val: %s\n", aux->val);
			aux = aux->prev;
		}while(aux != pt);
	}

	return 1;
}

extern int imprimirLDDerecha(ListaDoble *pt){
	ListaDoble *aux = pt;
	if(pt == NULL){
		printf("La lista está vacía\n");
	}
	else{
		do{
			printf("Val: %s\n", aux->val);
			aux = aux->next;
		}while(aux != pt);
	}

	return 1;
}

extern ListaDoble * crearLista(ListaDoble *inicio, char nombre_file[]){ 
	char nombre[40];
    FILE *fp;
    fp = fopen(nombre_file, "r");

    if(fp == NULL){
        printf("Archivo no disponible\n");
        exit(1);
    }

    while(fscanf(fp, "%s", nombre) == 1){
        inicio = enQueueLD(nombre, inicio);
    }
    fclose(fp);
	return inicio;
}

extern void imprimirActualStatusNavegador(Navegador *p_nav){
	if (p_nav->mover == NULL){
		printf("La lista está vacía\n");
	}
	else{
		strcpy(p_nav->pal_actual, p_nav->mover->val);
		printf("Palabra: %s\n", p_nav->pal_actual);
		printf("Inicia con: %c y tiene %d letras.\n", p_nav->mover->val[0], p_nav->num_chars);
	}
	return;
}

extern ListaDoble * borrarNodoNav(Navegador *p_nav){
	ListaDoble * borrar = p_nav->mover;
	
	if (p_nav->mover == NULL){
		printf("\nNavegador vacío.\n");
		return NULL;
	}

	if(p_nav->ref == p_nav->mover){
		p_nav->mover = popLD(p_nav->mover);
		p_nav->ref = p_nav->mover;
	}

	else{
		p_nav->mover = popLD(p_nav->mover);
	}

	return p_nav->ref;
}









