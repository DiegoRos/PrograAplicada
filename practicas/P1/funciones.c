/*
*	@file: funciones.c	
*	@brief: Este file contiene las funciones requeridas para leer las entradas de
*		calcula.c, tomar un número binario y pasarlo a decimal y un valor decimal
*		y pasarlo a octald.
*	@author: Equipo 3
*	@date: 25/01/2021
*/

#include "misDefiniciones.h"

/*
*	@brief: Función que revisa si string entrada es un número binario, regresa un booleano
*	@author: Equipo 3
*	@param char *arg: Primera entrada que no sea un operador
*	@return int
*/

int esBinario(char *arg){
	int i;

	if ((arg[0] == '0') && (arg[1] == 'b')){
		for(i = 2; i < strlen(arg); i++){
			if(!((arg[i] == '0') || (arg[i] == '1'))){
				return False;
			}
		}	
	} 
	
	else{
		for(i = 0; i < strlen(arg); i++){
			if(!((arg[i] == '0') || (arg[i] == '1'))){
				return False;
			}		
		}
	}
	
	return True;
}

/*
*	@brief: Función que revisa si string entrada es un número hexadecimal, regresa un booleano
*	@author: Equipo 3
*	@param char *arg: String a revisar
*	@return int
*/
int esHexadecimal(char *arg){
	int i;
	if ((arg[0] == '0') && (arg[1] == 'x')){
		for(i = 2; i < strlen(arg); i++){
			if(!isxdigit(arg[i])){
				return False;
			}		
		}
	}
	
	else{
		for(i = 0; i < strlen(arg); i++){
			if(!isxdigit(arg[i])){
				return False;
			}		
		}
	}
	
	return True;
}

/*
*	@brief: Función que toma una entrada binaria y lo cambia a decimal
*	@author: Equipo 3
*	@param char *arg1: Número binario
*	@return int
*/
int binarioADecimal(char *arg){
	int cantidad = strlen(arg), i;
	int resultado = 0;
	for(i = 0; i < cantidad; i++){
		if(arg[i] == '1'){
			resultado += pow(2, cantidad - 1 - i);
		}
	}
	return resultado;
}
/*
*	@brief: Función que asigna el valor correcto hexadecimal o binario al valor de operador1 y operador2
*	@author: Equipo 3
*	@param char *arg1: Primera entrada que no sea un operador, es un número binario
*	@param char *arg2: Segunda entrada que no sea un operador, es un número hexadecimal
*	@param int *operador1: Número binario en forma decimal
* 	@param int *operador2: Número hexadecimal en forma decimal
*	@return int
*/

int parseEntradas(char *arg1, char *arg2, int *operador1, int *operador2){
	if ((esBinario(arg1)) && (esHexadecimal(arg2))){
		*operador1 = binarioADecimal(arg1);
		sscanf(arg2, "%x", operador2);
	}

	else if ((esBinario(arg2)) && (esHexadecimal(arg1))){
		*operador2 = binarioADecimal(arg2);
		sscanf(arg1, "%x", operador1);
	}
	
	else{
		printf("Las entradas numéricas no son correctas\n");
	}
	
	return 0;
}


/*
*	@brief: Función que toma un número decimal y lo cambia a octal
*	@author: Equipo 3
*	@param int valor_decimal: Número en base 10
*	@return int
*/
int decimalAOctal(int valor_decimal){
	int numero_octal = 0, i = 1;

	while (valor_decimal > 0){
		numero_octal += (valor_decimal % 8) * i;
		valor_decimal = (int) (valor_decimal / 8);
		i *= 10;
	}

	return numero_octal;	
}
