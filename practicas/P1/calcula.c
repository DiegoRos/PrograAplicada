/*
*	@file: calcula.c	
*	@brief: Este file toma dos entradas numéricas, una hexadecimal y una binaria, 
*		y un operador (+, -, x, /) y calcula el resultado entre los dos.
*	@author: Equipo 3
*	@date: 25/01/2021
*/
#include "misDefiniciones.h"

extern int encontrarOperacion(int argc, char *argv[], char *operacion, int *error_operacion);
extern int parseEntradas(char *arg1, char *arg2, int *operador1, int *operador2, int *error_val);
extern float hacerOperacion(int *operador1, int *opeardor2, char operacion, int *error_val);
extern int decimalAOctal(int valor_decimal);

int main(int argc, char *argv[]){
	int *error_val = (int *)malloc(sizeof(int));

	if(argc != 4){
		printf("Número incorrecto de entradas, se esperan 3 (sin incluir el ejecutable) y se encontraron %d\n", argc);
	}
	
	else{
		float resultado;
		int i;
		int *operador1 = (int *)malloc(sizeof(int)), *operador2 = (int *)malloc(sizeof(int));
		char *operacion = (char *)malloc(sizeof(char));
		*error_val = 0;
		
		i = encontrarOperacion(argc, argv, operacion, error_val);
		if (*error_val == 0){
			if (i == 1){
				parseEntradas(argv[2], argv[3], operador1, operador2, error_val);
			}

			else if (i == 2){
				parseEntradas(argv[1], argv[3], operador1, operador2, error_val);
			}

			else{
				parseEntradas(argv[1], argv[2], operador1, operador2, error_val);
			}
		
		
			resultado = hacerOperacion(operador1, operador2, *operacion, error_val);
		}

		free(operador1);
		free(operador2);
		free(operacion);
		
		if(*error_val == 0){
			printf("Resultado en Decimal: %f\n", resultado);
			printf("Resultado en Octal: %d\n", decimalAOctal((int) resultado));
		}
	}
	
	free(error_val);
	return 0;
}

