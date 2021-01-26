/*
*	@file: calcula.c	
*	@brief: Este file toma dos entradas numéricas, una hexadecimal y una binaria, 
*		y un operador (+, -, x, /) y calcula el resultado entre los dos.
*	@author: Equipo 3
*	@date: 25/01/2021
*/
#include "misDefiniciones.h"
#define True 1
#define False 0

extern int parseEntradas(char *arg1, char *arg2, int *operador1, int *operador2);
extern int esBinario(char *arg);
extern int esHexadecimal(char *arg);
extern int binarioADecimal(char *arg);
extern int decimalAOctal(int valor_decimal);

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Número incorrecto de entradas, se esperan 3 (sin incluir el ejecutable) y se encontraron %d\n", argc);
		return 1;
	}
	
	int i, resultado;
	int *operador1 = (int *)malloc(sizeof(int)), *operador2 = (int *)malloc(sizeof(int));
	char operacion;

	for(i = 1; i < argc; i++){
		if((*argv[i] == 'x') || (*argv[i] == '/') || (*argv[i] == '+') || (*argv[i] == '-')){
			operacion = argv[i][0];
			break;
		}
	}
	
	if(i == 1){
		parseEntradas(argv[2], argv[3], operador1, operador2);
	}

	else if(i == 2){
		parseEntradas(argv[1], argv[3], operador1, operador2);
	}

	else{
		parseEntradas(argv[1], argv[2], operador1, operador2);
	}
		
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
			resultado =(*operador1) / (*operador2);
			break;

		default:
			printf("No se metió un operador válido\n");
			exit(1);
			break;
	}

	free(operador1);
	free(operador2);

	printf("Resultado en Decimal: %d\n", resultado);
	printf("Resultado en Octal: %d\n", decimalAOctal(resultado));

	return 0;
}

