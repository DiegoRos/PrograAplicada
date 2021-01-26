/*
*	@file: swap.c	
*	@brief: Tomando dos números de un usuario se intercambian los valores, se cambian
*			de dos maneras, por referencia y por valor.
*	@author: Diego Rosenberg
*	@date: 15/ene/2021
*/

#include <stdio.h>

int swapValor(int *a, int *b);
int swapRef(int *a, int *b);

int main(int arc, char *argv[]){
	int a, b;

	printf("Introducir Valor 1: ");
	scanf("%d", &a);

	printf("Introducir Valor 2: ");
	scanf("%d", &b);

	printf("a: %d, b: %d\n", a, b);

	swapValor(&a, &b);
	
	printf("a: %d, b: %d\n", a, b);
	
	return 0;
}

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
int swapValor(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;

	return 0;
}

