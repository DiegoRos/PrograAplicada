/*
*	@file: calcula.c	
*	@brief: Este file toma dos entradas numéricas, una hexadecimal y una binaria, 
*		y un operador (+, -, x, /) y calcula el resultado entre los dos.
*	@author: Equipo 3
*	@date: 25/01/2021
*/
#include "misDefiniciones.h"

extern int parseEntradas(char *arg1, char *arg2, int *operador1, int *operador2);
extern int esBinario(char *arg);
extern int esHexadecimal(char *arg);
extern int binarioADecimal(char *arg);
extern int decimalAOctal(int valor_decimal);

int main(int argc, char *argv[]){
	if(argc != 4){
		printf("Número incorrecto de entradas, se esperan 3 (sin incluir el ejecutable) y se encontraron %d\n", argc);
	}
	
	else{
		float resultado;
		int i, print = True;
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
		
		//Revisa si ambos operadores tienen espacio alocado
		if(operador1 && operador2){
		
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

				default:
					printf("No se metió un operador válido\n");
					print = False;
					break;
			}

			free(operador1);
			free(operador2);
			

			if(print){
				printf("Resultado en Decimal: %f\n", resultado);
				printf("Resultado en Octal: %d\n", decimalAOctal((int) resultado));
			}
		}
	}
	return 0;
}

