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
*	@param int argc: Número de entradas
*	@param char *argv[]: Entradas de la línea de comando
*	@param char *operacion: Puntero a la operación entrada por el usuario
*	@param int *error_val: Valor de error para el algoritmo
*	@return int
*/
int encontrarOperacion(int argc, char *argv[], char *operacion, int *error_val){
	int i;
	int condicion_longitud, condicion_operador;
	for(i = 1; i < argc; i++){
		condicion_longitud = strlen(argv[i]) == 1;
		condicion_operador = (*argv[i] == 'x') || (*argv[i] == '/') || (*argv[i] == '+') || (*argv[i] == '-') || (*argv[i] == '^');	

		if(condicion_longitud && condicion_operador){
			*operacion = argv[i][0];
			break;
		}
	}
	
	if (*operacion == '\0'){
		printf("No se metión un operador válido\n");
		*error_val = 1;
	}

	return i;
}

/*
*	@brief: Función que revisa si string entrada es un número binario, regresa un booleano
*	@author: Equipo 3
*	@param char *arg: Primera entrada que no sea un operador
*	@return int
*/
int esBinario(char *arg){
	int i = 0;
	if (arg[i] == '-') 
		i++;

	if ((arg[i] == '0') && (arg[i + 1] == 'b')){
		for(i = i + 2; i < strlen(arg); i++){
			if(!((arg[i] == '0') || (arg[i] == '1'))){
				return False;
			}
		}	
	} 
	
	else{
		for(i = i; i < strlen(arg); i++){
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
*	@param char *arg: Primera entrada que no sea un operador
*	@return int
*/
int esHexadecimal(char *arg){
	int i = 0;
	if (arg[i] == '-') 
		i++;

	if ((arg[i] == '0') && (arg[i + 1] == 'x')){
		for(i = i + 2; i < strlen(arg); i++){
			if(!isxdigit(arg[i])){
				return False;
			}
		}	
	} 
	
	else{
		for(i = i; i < strlen(arg); i++){
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
	int cantidad = strlen(arg), i = 0;
	int resultado = 0;

	if (arg[i] == '-') i++;

	for(i = i; i < cantidad; i++){
		if(arg[i] == '1'){
			resultado += pow(2, cantidad - 1 - i);
		}
	}
	if (arg[0] == '-') resultado *= -1;

	return resultado;
}

/*
*	@brief: Función que asigna el valor correcto hexadecimal o binario al valor de operador1 y operador2
*	@author: Equipo 3
*	@param char *arg1: Primera entrada que no sea un operador, es un número binario
*	@param char *arg2: Segunda entrada que no sea un operador, es un número hexadecimal
*	@param int *operador1: Número binario en forma decimal
* 	@param int *operador2: Número hexadecimal en forma decimal
*	@param int *error_val: Valor de error para el algoritmo
*	@return int
*/
int parseEntradas(char *arg1, char *arg2, int *operador1, int *operador2, int *error_val){
	if (esBinario(arg1) && esHexadecimal(arg2)){
		*operador1 = binarioADecimal(arg1);
		sscanf(arg2, "%x", operador2);
	}

	else if (esBinario(arg2) && esHexadecimal(arg1)){
		*operador2 = binarioADecimal(arg2);
		sscanf(arg1, "%x", operador1);
	}
	
	else{
		printf("Las entradas numéricas no son correctas\n");
		*error_val = 1;
	}
	
	return 0;
}

/*
*	@brief: Que hace la operación pedida por el usuario
*	@author: Equipo 3
*	@param int *operador1: Primer valor numérico
*	@param int *operador2: Segundo valor numérico
*	@param char operacion: Operación a hacer
*	@param int *error_val: Valor de error para el algoritmo
*	@return int
*/
float hacerOperacion(int *operador1, int *operador2, char operacion, int *error_val){
	float resultado;
	//Revisa si ambos operadores tienen espacio alocado
	switch(operacion){
		case '+':	
			resultado = *operador1 + *operador2;
			break;

		case '-':
			resultado = *operador1 - *operador2;
			break;

		case 'x':
			resultado = (*operador1) * (*operador2);
			break;

		case '/':
			resultado = (float)(*operador1) / (float)(*operador2);
			break;

		case '^':
			resultado = pow((*operador1), (*operador2));
			break;
		}

	return resultado;
}

/*
*	@brief: Función que toma un número decimal y lo cambia a octal
*	@author: Equipo 3
*	@param int valor_decimal: Número en base 10
*	@return int
*/
int decimalAOctal(int valor_decimal){
	int numero_octal = 0, i = 1;
	int es_negativo = 1;

	if (valor_decimal < 0){
		es_negativo = -1;
		valor_decimal *= -1;
	}

	while (valor_decimal > 0){
		numero_octal += (valor_decimal % 8) * i;
		valor_decimal = (int) (valor_decimal / 8);
		i *= 10;
	}

	numero_octal *= es_negativo;

	return numero_octal;	
}
