/*
*	@file: funciones.c	
*	@brief: Contiene las funciones utilizadas en principal.c para elevar al cuadrado y al cubo.
*	@author: Notas Guillermo Gómez Abascal
*	@date: 20/01/2021
*/

// Para las funciones

/*
*	@brief: Esta función eleva un entero al cuadrado
*	@author: Guillermo Gómez Abascal
*	@param int dato: valor que va a ser elevado al cuadrado
*	@return int
*/
extern int cuadrado(int dato){
	return(dato * dato);

}

/*
*	@brief: Esta función eleva un entero al cubo
*	@author: Guillermo Gómez Abascal
*	@param int dato: valor que se eleva al cuadrado
*	@return int
*/
extern int cubo(int dato){
	return(dato * dato * dato);

}
