#include "defLista.h"

ListaDoble * enQueueLD(char val[], ListaDoble *pt);
ListaDoble * pushLD(char val[], ListaDoble *pt);
ListaDoble * popLD(ListaDoble *pt);
int imprimeLD(ListaDoble *pt);

int main(int argc, char *argv[]){
    ListaDoble *inicio;
    char nombre[40];
    
    printf("El Nodo tiene %li bytes de tamaño\n", sizeof(inicio));
    inicio = NULL;
    
    FILE *fp;
    fp = fopen(argv[1], "r");

    if(fp == NULL){
        printf("Archivo no disponible\n");
        exit(1);
    }

    while(fscanf(fp, "%s", nombre) == 1){
        printf("%s\n", nombre);
        inicio = enQueueLD(nombre, inicio);
    }
    fclose(fp);

    imprimeLD(inicio);

    return 0;
}