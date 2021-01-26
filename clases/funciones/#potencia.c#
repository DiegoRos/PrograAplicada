/*
*	@file: potencia.c
*	@brief: Este programa estima la potnecia del los números 2 y 3 del 0 al 9.
*	@author: Apuntes de Andrés Tortolero	
*	@date: 15/ene/2021
*/

#include <stdio.h>

int power(int x, int n);

int main(void){
	for(int i = 0; i < 10; i++){
		printf("%d %d %d \n", i, power(2, i), power(3, i));
	}

	return 0;
}

/*
*	@brief: Esta función calcula la potencia de un número
*	@date 15/ene/2021
*	@author: Apuntes de Andrés Tortolero
*	@param int x: Número entero que va a ser elevado a una potencia.
*	@param int n: Potencia a la cual el número va a ser elevado.
*	@return int
*/
int power(int x, int n){
	int p = 1;

	for(int i = 1; i < n; i++){
		p *= x;
	}

	return p;
}

