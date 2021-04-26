/*
*	@file: principal.c	
*	@brief: Calcula el cuadrado, cubo, y la raíz de un número entrado por un usuario utilizando una función externa
*	@author: Clases Guillermo Gómez Abascal
*	@date: 20/01/2021
*/

#include "misDefiniciones.h" //stdio.h y PI se definen aqui

extern int cuadrado(int dato); // extern ya no es necesario pero todavia se puede utilizar
extern int cubo(int dato);
extern float raiz(int dato);
extern int incremento(int dato);
float areaEsfera(int radio);

int main(int argc, char *argv[]){
	int num;

	printf("Este programa calcula el cuadrado, cubo y raíz de un número.\n");
	printf("Dame un número:");
	scanf("%i", &num);
	printf("El cuadrado del número es: %i\n",cuadrado(num));
	printf("El cubo del número es: %i\n",cubo(num));
	printf("La raiz del número es: %f\n", raiz(num));

//	#ifdef DEBUG
		printf("El incremento del número es %d\n", incremento(num));
		printf("El área de una esfera de radio %i es %f\n", num, areaEsfera(num));
//	#endif
	
	return 0;
}

float areaEsfera(int radio){
	float area;
	
	area = 4 * PI * radio * radio;

	return(area);
}
