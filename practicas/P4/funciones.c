#include "def.h"

void generarTxtNums(int n){
    // srand((unsigned)time(NULL)); // Set random seed
    srand(0);
    int i;
    FILE *fp;
    fp = fopen("numeros.txt", "w");
    if (fp == NULL){
        printf("No se pudo abrir el archivo.\n");
        exit(1);
    }
    for(i = 0; i < n; ++i){
        fprintf(fp, "%d\n", rand());
    }
    fclose(fp);
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
nodo * pushLD(int val, nodo *pt){
	nodo *nuevo, *aux = pt;
	nuevo = (nodo *)malloc(sizeof(nodo));
    if(nuevo == NULL){
        printf("\n no hay memoria disponible");
        exit(1);
    }

	nuevo->num = val;
	if (pt == NULL){
		nuevo->izq = nuevo;
		nuevo->der = nuevo;
		pt = nuevo;
	}
    else if (pt->der == pt){
        nuevo->izq = aux;
        nuevo->der = aux;
        aux->izq = nuevo;
        aux->der = nuevo;
        if (aux->num > val){
            pt = nuevo;
        }
    }
	else{
        while(aux->der != pt){
                if(aux->num == val){
                    free(nuevo);
                    break;
                }
                else if(aux->num > val)
                {
                    nuevo->izq = aux->izq;
                    nuevo->der = aux;
                    aux->izq->der = nuevo;
                    aux->izq = nuevo;
                    if(aux == pt)
                        pt = nuevo;
                    break;
                }
                else{
                    aux = aux->der;
                }
            }
        if (aux->der == pt){
            if (aux->num > val){
                nuevo->izq = aux->izq;
                nuevo->der = aux;
                aux->izq->der = nuevo;
                aux->izq = nuevo;
            }
            else if(aux->num == val){
                free(nuevo);
            }
            else{
                nuevo->der = aux->der;
                nuevo->izq = aux;
                aux->der->izq = nuevo;
                aux->der = nuevo;
            }
        }
	}

	return pt;
}

extern nodo *crearLista(nodo *pt, char nomArch[])
{
    FILE *fp;
    int numero, cont = 1;

    fp = fopen(nomArch, "r");
    if (fp == NULL)
    {
        printf("\nArchivo no disponible.");
        exit(1);
    }

    while(fscanf(fp, "%i\n", &numero) == 1)
    {
        pt = pushLD(numero, pt);
    }
    fclose(fp);
    return pt;
}

extern void imprimirListaDer(nodo *pt)
{
    nodo *imprime;
    if(pt != NULL)
    {
        imprime = pt;
        do
        {
            printf("%d\n", imprime->num);
            imprime = imprime->der;
        }while(imprime != pt);
    }
    else printf("\nLa lista doble  esta vacia :(\n");
    return;
}

nodo * buscarNodo(nodo *pt, int num){
    nodo *aux = pt;
    if(pt == NULL){
        return NULL;
    }

    do{
        if(aux->num == num){
            return aux;
        }
        aux = aux->der;
    }while(aux != pt);
    
    return NULL;
}