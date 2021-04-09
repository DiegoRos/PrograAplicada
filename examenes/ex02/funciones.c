#include "defex02.h"

int tieneCovid(Paciente temp){
    if ((temp.fiebre == 'S') && (temp.tos == 'S')) 
        return True;

    return False;
}

ArbolCiudad * insertar(ArbolCiudad *pt, Paciente temp){
	
	if (pt == NULL){
		ArbolCiudad *nuevo = (ArbolCiudad *)malloc(sizeof(ArbolCiudad));

		strcpy(nuevo->ciudad, temp.ciudad);
		nuevo->left = NULL;
		nuevo->right = NULL;
        nuevo->num_covid = tieneCovid(temp);

        //Agregar a listas generales
		return nuevo;
	}

    if (strcmp(pt->ciudad, temp.ciudad) == 0){
        pt->num_covid += tieneCovid(temp);
        
        //Agregar a listas generales
    }
	else if (strcmp(pt->ciudad, temp.ciudad) < 0){
		pt->right = insertar(pt->right, temp);
	}
	else{
		pt->left = insertar(pt->left, temp);	
	}

	return pt;
}

extern ArbolCiudad * leerTxt(char nombre_file[]){
    ArbolCiudad *root = NULL;
    Paciente temp;
    FILE *fp;
    fp = fopen(nombre_file, "r");
    if (fp == NULL){
        printf("No se pudo abrir el file.\n");
        exit(1);
    }
    fscanf(fp, " %[^\t]\t%c\t%c\t%c\t %[^\n]", temp.nombre, &temp.fiebre, &temp.tos, &temp.moco, temp.ciudad);
    printf("%s\n", temp.nombre);
    while(fscanf(fp, " %[^\t]\t%c\t%c\t%c\t %[^\n]", temp.nombre, &temp.fiebre, &temp.tos, &temp.moco, temp.ciudad) > 1){
		root = insertar(root, temp);
	}

    fclose(fp);
    return root;
}

/*
*	@brief: Inserta un nuevo nodo en la lista
*	@author: Equipo 3
*	@param ArbolCiudad *root
*	@param ListaCiudad *pt
*	@return ListaCiudad*
*/
ListaCiudad * push(ArbolCiudad *root, ListaCiudad *pt){
	ListaCiudad *aux = (ListaCiudad *)malloc(sizeof(ListaCiudad));
	
	aux->num_covid = root->num_covid;
    strcpy(aux->ciudad, root->ciudad);
	aux->next = pt;
	pt = aux;
	return pt;
}


extern ListaCiudad * generarContagiosTodas(ArbolCiudad *root, ListaCiudad *pt){
    if (root == NULL) return NULL;

    pt = push(root, pt);

    pt = generarContagiosTodas(root->left, pt);
	pt = generarContagiosTodas(root->right, pt);
    return pt;
}

extern void imprimirListaCiudades(ListaCiudad *pt){
    ListaCiudad *aux = pt;
    while (aux != NULL){
        printf("Ciudad: %s \t Contagiados: %i", aux->ciudad, aux->num_covid);
    }

}
extern Queue * unirPacientesGripe(ArbolCiudad *root){


}

extern Queue * unirPacientesResfriado(ArbolCiudad *root){


}



void swap(Queue *a, Queue *b){
    char temp[80];
    strcpy(temp, a->val.nombre);
    strcpy(a->val.nombre, b->val.nombre);
    strcpy(b->val.nombre, temp);
}

extern void bubbleSort(Queue *start){
    int swapped, i;
    Queue *ptr1;
    Queue *lptr = NULL;
  
    if (start == NULL)
        return;
  
    do{
        swapped = 0;
        ptr1 = start;
  
        while (ptr1->next != lptr){
            if (strcmp(ptr1->val.nombre, ptr1->next->val.nombre) > 0){ 
                swap(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    }while (swapped);
}

extern void imprimirPacientes(Queue *start){


}

extern ArbolCiudad * ciudadEnArbol(ArbolCiudad *root, char ciudad[]){


}

extern void imprimirCiudad(ArbolCiudad *aux){

}


// Queue * enQueue(char val, Queue *q){
// 	Queue *aux;
// 	aux = q;

// 	Queue *nodo_nuevo = (Queue *)malloc(sizeof(Queue));
// 	nodo_nuevo->val = val;
// 	nodo_nuevo->next = NULL;
// 	if (aux == NULL){
// 		return nodo_nuevo;
// 	}	

// 	while (aux->next != NULL){
// 		aux = aux->next;
// 	}
// 	aux->next = nodo_nuevo;
	
// 	return q;	
// }


/*
*	@brief: Esta función imprime un queue entero
*	@author: Equipo 3
*	@param Stack *q
*	@return Stack *q
*/
// int imprimirQueue(Queue *q){
// 	while (q != NULL){
// 		printf("La letra es: %c\n", );
// 		q = q->next;
// 	}

// 	return 1;
// }
