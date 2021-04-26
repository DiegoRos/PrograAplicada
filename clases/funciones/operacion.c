/*
*	@file: calculadora.c	
*	@brief: Este código toma dos números y un operando de la teminal y hace la operación deseada. Utilizando
*			el siguiente formato ./operacion.exe op1 operacion op2
*			Ejemplo: ./opearacion 3.4 + 5.7 \\ formato válido
*	@author: Notas Clase Gómez Ortiz
*	@date: 18/01/2021
*/

#include <stdio.h>

int main(int argc, char *argv[]){
	double operando1, operando2, resultado;
	char operador;
	if (argc != 4){
		printf("Número de entradas incorrectas \n");
		return 1;
	}	
	sscanf(argv[1], "%lf", &operando1);	
	sscanf(argv[3], "%lf", &operando2);
	operador = argv[2][0]; // Eso se hace para no meter el character nulo "\0"

	switch(operador){
		case '+':
			resultado = operando1 + operando2;
			break;

		case '-':
			resultado = operando1 - operando2;
			break;

		case 'x': // '*' cannot be utilized because
			resultado = operando1 * operando2;
			break;

		case '/':
			resultado = operando1 / operando2;
			break;
		
		default:
			printf("Operador no válido.\n");
			return 1;
			break;
	}
	
	printf("Resultado: %lf\n", resultado);	

	return 0;
}
