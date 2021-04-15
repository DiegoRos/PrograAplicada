/*
*	@file: main.c
*	@brief: Contiene las funciones para generar n numeros aleatorios, guardarlos y colocarlos en una lista doble circular
*	@author: Equipo 3
*	@date: 16/04/2021
*/

#include "def.h"

/*
*	@brief: Función que genera n números aleatorios
*	@author: Equipo 3
*	@param int n
*	@return void
*/
void generarTxtNums(int n){
    srand((unsigned)time(NULL)); // Set random seed
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
*	@brief: Función que agrega un nodo a la lista doble circular, si el valor es repetido se descarta.
*	@author: Equipo 3
*	@param int val
*	@param nodo *pt
*	@return noto *pt
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

/*
*	@brief: Función que lee el archivo de números aleatorios y crea la lista doble
*	@author: Equipo 3
*	@param nodo *pt
*	@param char nomArch[]
*	@return nodo *
*/
nodo *crearLista(nodo *pt, char nomArch[])
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

/*
*	@brief: Función que imprime la lista doble ciruclar (solo se uso para depurar)
*	@author: Equipo 3
*	@param nodo *pt
*	@return void
*/
void imprimirListaDer(nodo *pt)
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

/*
*	@brief: Función que busca un número en la lista y regresa su posición en memoria o NULL si no lo encuentra
*	@author: Equipo 3
*	@param nodo *pt
*	@param int num
*	@return nodo * 
*/
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