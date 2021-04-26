/*
*	@file: capturaArreglo.c	
*	@brief: Ejercicio de Memoria Dinámica
*	@author:
*	@date:
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define True 1
#define False 0

int isInt(char *string);
int isFloat(char *string);

int main(int argc, char *argv[]){
	float *arreglo;
	char temp[100];
	int n, i;
	
	//if(!isInt(argv[1])){
		//printf("Valor ingresado no era un entero\n");
		//return 1;
	//}
	
	//Alternativa
	if (sscanf(argv[1], "%i", &n) <= 0){
		printf("Valor ingresado no era un entero\n");
		return 1;
	}
	
	//sscanf(argv[1], "%i", &n);
	arreglo = (float *)malloc(sizeof(float) * n);
	
	if(!arreglo){
		printf("\nMemoria no disponible.\n");
		exit(1);
	}
	
	printf("Captura de %i datos reales\n", n);
	i = 0;
	while(i < n){
		printf("Dame un dato %i:", i);
		scanf("%s", temp);
		if(isFloat(temp)){
			sscanf(temp, "%f", arreglo + i);
			i++;		
		}
		/*
		// Alternativa
		if(scanf("%f", arreglo + i) > 0){
		 		i++;
		}
		*/
		else{
			printf("Valor metido no es un número real, intentar de nuevo\n");
		}

	}

	printf("Los datos capturados son: \n");
	for(i = 0; i < n; i++){
		printf("El dato arreglo[%i] es: %f\n", i, arreglo[i]);
	}

	free(arreglo);
	return 0;
}

/*
*	@brief: Checks if a string enered is a number
*	@author: Diego Rosenberg
*	@param char* string: string to check; 
*	@return int 
*/
int isInt(char *string){
	int i, length = strlen(string);

	for (i = 0; i < length; i++){
		if (!isdigit(string[i])){
			return False;
		}

	return True;
	}
}

/*
*	@brief: Checks if a string enered is a valid float
*	@author: Diego Rosenberg
*	@param char* string: string to check; 
*	@return int 
*/
int isFloat(char *string){
	int i, length = strlen(string);
	int decimal_counter = 0;

	for (i = 0; i < length; i++){
		if (!(isdigit(string[i]) || (string[i] == '.'))){
			return False;
		}

		if (string[i] == '.'){
			decimal_counter++;
		}
	
		if(decimal_counter > 1){
			return False;
		}
	}

	return True;
}
