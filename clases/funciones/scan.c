/*
*	@file:	
*	@brief:
*	@author:
*	@date:
*/

#include <stdio.h>

int main(int arc, char *argv[]){
	char s[30] = "123 456\n98.765";
	char f[40];
	int i, j;
	double x;

	sscanf(s, "%d %d %lf", &i, &j, &x);
	printf("\nValor de i:%d\nValor de j:%d\nValor de x:%lf\n", i, j, x);
	
	sprintf(f, "SUm: %6.3f Difference: %6.3f\n", 45+2.89, 45-2.89);	

	return 0;
}

