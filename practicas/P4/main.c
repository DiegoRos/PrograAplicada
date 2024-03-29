/*
*	@file: main.c
*	@brief: Contiene las funciones para generar n numeros aleatorios, guardarlos y colocarlos en una lista doble circular
*	@author: Equipo 3
*	@date: 16/04/2021
*/

#include "def.h"

void generarTxtNums(int n);
Nodo *crearLista(Nodo *pt, char nomArch[]);
void imprimirListaDer(Nodo *pt);
Nodo * buscarNodo(Nodo *pt, int num);

int main(int argc, char *argv[])
{
    double tiempo;
    clock_t principio, fin;
    Nodo *inicio = NULL, *aux = NULL;
    int num;
    if (argc == 2){
        int cantidad;
        if(sscanf(argv[1], " %d", &cantidad) == 1)
            generarTxtNums(cantidad);
        else{
            printf("Entrada incorrecta, saliendo del programa.\n");
            exit(1);
        }
    }

    principio = clock();
    inicio = crearLista(inicio, "numeros.txt");
    fin = clock();
    tiempo = (double)(fin - principio) / CLOCKS_PER_SEC;
    printf("Tiempo tardado: %lf segundos\n", tiempo);

    printf("Insertar Número a buscar en lista entre (0 y %i): ", RAND_MAX);
    scanf(" %i", &num);

    principio = clock();
    aux = buscarNodo(inicio, num);
    fin = clock();
    tiempo = (double)(fin - principio) / CLOCKS_PER_SEC;
    printf("Timepo tardado: %lf segundos\n", tiempo);
    if(aux == NULL)
        printf("Nodo no encontrado en la lista.\n");
    else
        printf("Nodo en dirección %p, con valor: %i\n\tNodo Derecha: %i, Nodo Izquierda: %i\n", aux, aux->num, aux->der->num, aux->izq->num);

    return 0;
}

