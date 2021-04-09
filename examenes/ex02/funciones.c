#include "defex02.h"

extern void imprimirPacientes(ListaPacientes *start);

int tieneCovid(Paciente temp){
    if ((temp.fiebre == 'S') && (temp.tos == 'S') && (temp.moco == 'N')) 
        return True;

    return False;
}

/*
*	@brief: Inserta un nuevo nodo en la lista
*	@author: Equipo 3
*	@param ListaPacientes *pt
*	@param Paciente temp
*	@return ListaCiudad*
*/
ListaPacientes * pushPaciente(ListaPacientes *pt, Paciente temp){
	ListaPacientes *aux = (ListaPacientes *)malloc(sizeof(ListaPacientes));
    aux->val = temp;

    aux->next = pt;
    pt = aux;
	
	return pt;
}

ArbolCiudad * insertar(ArbolCiudad *pt, Paciente temp){
	
	if (pt == NULL){
		ArbolCiudad *nuevo = (ArbolCiudad *)malloc(sizeof(ArbolCiudad));

		strcpy(nuevo->ciudad, temp.ciudad);
		nuevo->left = NULL;
		nuevo->right = NULL;
        nuevo->num_covid = tieneCovid(temp);
        nuevo->pacientes_covid = NULL;
        nuevo->pacientes_gripa = NULL;
        nuevo->pacientes_resfriado = NULL;
        if ((temp.fiebre == 'S') && (temp.tos == 'S') && (temp.moco == 'N')){
            nuevo->pacientes_covid = pushPaciente(nuevo->pacientes_covid, temp);
        }

        else if ((temp.fiebre == 'S') && (temp.tos == 'S') && (temp.moco == 'S')){
            nuevo->pacientes_gripa = pushPaciente(nuevo->pacientes_gripa, temp);
        }

        else if ((temp.fiebre == 'N') && (temp.tos == 'S') && (temp.moco == 'N')){
            nuevo->pacientes_resfriado = pushPaciente(nuevo->pacientes_resfriado, temp);
        }

		return nuevo;
	}

    if (strcmp(pt->ciudad, temp.ciudad) == 0){
        pt->num_covid += tieneCovid(temp);

        if ((temp.fiebre == 'S') && (temp.tos == 'S') && (temp.moco == 'N')){
            pt->pacientes_covid = pushPaciente(pt->pacientes_covid, temp);
        }

        else if ((temp.fiebre == 'S') && (temp.tos == 'S') && (temp.moco == 'S')){
            pt->pacientes_gripa = pushPaciente(pt->pacientes_gripa, temp);
        }

        else if ((temp.fiebre == 'N') && (temp.tos == 'S') && (temp.moco == 'N')){
            pt->pacientes_resfriado = pushPaciente(pt->pacientes_resfriado, temp);
        }
    
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
    
    while(fscanf(fp, " %[^\t]\t%c\t%c\t%c\t %[^\n]", temp.nombre, &temp.fiebre, &temp.tos, &temp.moco, temp.ciudad) > 1){
		root = insertar(root, temp);
        memset(temp.nombre, 0, 80);
        memset(temp.ciudad, 0, 80);
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
    ListaCiudad *mover = pt, *prev = NULL;
	ListaCiudad *aux = (ListaCiudad *)malloc(sizeof(ListaCiudad));
    aux->num_covid = root->num_covid;
    strcpy(aux->ciudad, root->ciudad);

    if(mover == NULL){
        aux->next = mover;
        pt = aux;
    }
    else{
        while(mover != NULL){
            if (aux->num_covid > mover->num_covid){
                if (prev != NULL)
                    prev->next = aux;
                aux->next = mover;
                break;
            }
            if (mover->next == NULL){
                mover->next = aux;
                aux->next = NULL;
            }
            prev = mover;
            mover = mover->next;
        }
    }
	
	return pt;
}


extern ListaCiudad * generarContagiosTodas(ArbolCiudad *root, ListaCiudad *pt){
    if (root == NULL){
    }
    else{
        pt = push(root, pt);

        pt = generarContagiosTodas(root->left, pt);
        pt = generarContagiosTodas(root->right, pt);
    }
    return pt;
}

extern void imprimirListaCiudades(ListaCiudad *pt){
    FILE *fp;
    fp = fopen("ciudades.txt", "w");
    ListaCiudad *aux = pt;
    do{
        printf("Ciudad: %s\tContagiados: %i\n", aux->ciudad, aux->num_covid);
        fprintf(fp,"%s\t%i\n", aux->ciudad, aux->num_covid);
        aux = aux->next;
    }while (aux != NULL);

    fclose(fp);
}

ListaPacientes * unirListas(ListaPacientes *pt, ListaPacientes *nueva){
    ListaPacientes *aux = pt;
    if (nueva == NULL){
        nueva = pt;
    }
    else{
        while(aux->next != NULL)
            aux = aux->next;
        aux->next = nueva;
        nueva = aux;
    }
    
    return nueva;
}
extern ListaPacientes * unirPacientesGripe(ArbolCiudad *root, ListaPacientes *pt){
    if (root == NULL){
    }
    else{
        pt = unirListas(root->pacientes_gripa, pt);

        pt = unirPacientesGripe(root->left, pt);
        pt = unirPacientesGripe(root->right, pt);
    }
}

extern ListaPacientes * unirPacientesResfriado(ArbolCiudad *root, ListaPacientes *pt){
    if (root == NULL){
    }
    else{
        pt = unirListas(root->pacientes_gripa, pt);

        pt = unirPacientesResfriado(root->left, pt);
        pt = unirPacientesResfriado(root->right, pt);
    }

}



void swap(ListaPacientes *a, ListaPacientes *b){
    char temp[80];
    strcpy(temp, a->val.nombre);
    strcpy(a->val.nombre, b->val.nombre);
    strcpy(b->val.nombre, temp);
}

extern void bubbleSort(ListaPacientes *start){
    int swapped, i;
    ListaPacientes *ptr1;
    ListaPacientes *lptr = NULL;
  
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

extern void imprimirPacientes(ListaPacientes *start){
    ListaPacientes *aux = start;
    while (aux != NULL){
        printf("Nombre: %s", aux->val.nombre);
        aux = aux->next;
    }

}

extern void imprimirCiudad(ArbolCiudad *aux){

}


// ListaPacientes * enListaPacientes(char val, ListaPacientes *q){
// 	ListaPacientes *aux;
// 	aux = q;

// 	ListaPacientes *nodo_nuevo = (ListaPacientes *)malloc(sizeof(ListaPacientes));
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
*	@brief: Esta función imprime un ListaPacientes entero
*	@author: Equipo 3
*	@param Stack *q
*	@return Stack *q
*/
// int imprimirListaPacientes(ListaPacientes *q){
// 	while (q != NULL){
// 		printf("La letra es: %c\n", );
// 		q = q->next;
// 	}

// 	return 1;
// }

extern ArbolCiudad * ciudadEnArbol(ArbolCiudad *root, char ciudad[])
{

ArbolCiudad *aux;

if(root != NULL)
{
 aux = ciudadEnArbol(root->left,ciudad);
 if (strcmp(ciudad, root->ciudad) == 0)
  {
   aux = root;
  }
 aux = ciudadEnArbol(root->right, ciudad);
}

return aux;
}