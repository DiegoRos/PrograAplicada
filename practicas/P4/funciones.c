/*
*	@file: funciones.c
*	@brief: Funciones utilizadas para completar la práctica 4
*	@author: Equipo 3
*	@date: 07/04/2021
*/


/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
ListaDoble * pushLD(int val, ListaDoble *pt){
	ListaDoble *nuevo;
	nuevo = (ListaDoble *)malloc(sizeof(ListaDoble));
	nuevo->val = val;
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

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
int imprimeLD(ListaDoble *pt){
	ListaDoble *aux = pt;
	if(pt == NULL){
		printf("La lista está vacía\n");
	}
	else{
		do{
			printf("Val: %d", aux->val);
			aux = aux->next;
		}while(aux != pt);
	}

	return 1;
}
