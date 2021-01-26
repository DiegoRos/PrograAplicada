/*
*	@file: funciones2.c	
*	@brief: Contiene las funciones utilizadas en principal.c para sacar la raiz cuadrada..
*	@author: Notas Guillermo Gómez Abascal
*	@date: 20/01/2021
*/
#include "misDefiniciones.h"

// Para las funciones

/*
*	@brief: Esta función saca la raiz cuadrada un número
*	@author: Guillermo Gómez Abascal
*	@param int dato: valor que se le va a sacar su raiz cuadrada
*	@return float
*/
extern float raiz(int dato){
	float resultado;

	printf("\n Hoy es 20 de enero del 2021.\n");
	resultado = sqrt(dato);	
	
	return(resultado);	
}


