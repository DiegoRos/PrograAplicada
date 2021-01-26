/*
*	@file: OperadorCondicional.c	
*	@brief: Explicación de operador condicional
*	@author: Notas Guillermo Gómez Abascal
*	@date: 21/ene/2021
*/

#include <stdio.h>

int main(int arc, char *argv[]){
	int minimo, dato1, dato2;
	printf("Dame dos valores enteros: ");
	scanf("%i %i", &dato1, &dato2);

	minimo = (dato1 < dato2) ? dato1 : dato1 < dato2;
	
	printf("%d\n",minimo);
	return 0;
}

// Para las funciones

/*
*	@brief:
*	@author:
*	@param 
*	@param
*	@return
*/
