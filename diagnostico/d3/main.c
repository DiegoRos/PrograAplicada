/*
*	@file: main.c	
*	@brief: Lee un archivo de n números enteros y los coloca en un arreglo para ordenarlos.
*	@author: Equipo 3
*	@date: 07/04/2021
*/

#include <stdio.h>
#include <stdlib.h>

void quickSort(int arr[], int low, int high);
int repetido(int arr[], int cont, int num);
void hacerArchivo(int arr[], int n);

int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Número de entradas incorrectas\n");
		exit(1);
	}

	FILE *fp;
	int num;
	int *num_array;
	int cantidad = 0, contador = 0;
	
	fp = fopen(argv[1], "r");
	while(fscanf(fp, "%d", &num) > 0){
		cantidad++;
	}
	fclose(fp);

	printf("Cantidad con Duplicados: %d\n", cantidad);

	num_array = (int *)malloc(sizeof(int) * cantidad);
	
	fp = fopen(argv[1], "r");
	while(fscanf(fp, "%d", &num) > 0){
		if (repetido(num_array, contador, num)){
			num_array[contador] = num;
			contador++;
		}
	}
	
	printf("Cantidad sin duplicados: %d\n", contador);

	fclose(fp);
	quickSort(num_array, 0, contador - 1);

	hacerArchivo(num_array, contador);	
	printf("Arreglo ordenado, ver en archivo ordenado.txt\n");
	return 0;
}

/*
*	@brief: Checa si un número está repetido en el arreglo
*	@author: Equipo 3
*	@param int arr[]
*	@param int cont
*	@param int num
*	@return booleano
*/
int repetido(int arr[], int cont, int num){
	for(int i = 0; i < cont; i++){
		if(arr[i] == num)
			return 0;
	}
	
	return 1;
}

/*
*	@brief: Invierte la posición de dos valores
*	@author: Equipo 3
*	@param int *a
*	@param int *b
*	@return void
*/
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

/*
*	@brief: Revisa la partición del arreglo para ver si están en el orden correcto
*	@author: Equipo 3
*	@param int arr[]
*	@param int low
*	@param int high
*	@return int
*/
int partition (int arr[], int low, int high){
	int pivot = arr[high];
	int i = low - 1;

	for (int j = low; j <= high; ++j){
		if (arr[j] < pivot){
			++i;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	
	return i + 1;
}

/*
*	@brief: Función de ordenamiento quicksort
*	@author: Equipo 3
*	@param int arr[]
*	@param int low
*	@param int high
*	@return  void
*/
void quickSort(int arr[], int low, int high){
	
	if (low < high){
		int pi = partition(arr, low, high);
		
		quickSort(arr, low, pi-1);
		quickSort(arr, pi + 1, high);
	}
}

/*
*	@brief: Imprime los valores de un arreglo a un archivo
*	@author: Equipo 3
*	@param int arr[]
*	@param int n
*	@return void
*/
void hacerArchivo(int arr[], int n){
	int i;
	FILE *fp;
	fp = fopen("ordenado.txt", "w");
	
	if(fp == NULL){
		printf("No se pudo abrir archivo\n");
		exit(1);
	}
	
	for(i = 0; i < n; ++i)
		fprintf(fp, "%d\n", arr[i]);

	fclose(fp);
}
