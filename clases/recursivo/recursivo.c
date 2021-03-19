#include <stdio.h>

int factorial(int n){
	int fact;
	if(n == 0)
		return 1;
	fact = n * factorial(n-1);

	return fact;
}

int fibonacci(int n){
	if (n <= 1)
		return n;

	return fibonacci(n - 1) + fibonacci(n - 2);
}

int fibonacciNormal(int n){
	int n1=0, n2=1, res = 0;
	for(int i = 0; i < n-1; ++i){
		res = n1 + n2;
		n1 = n2;
		n2 = res;
	}
	
	return res;
}

int main(){
	int n;

	printf("Insertar Número: ");
	scanf(" %d", &n);

	printf("%d! = %d\n", n, factorial(n));

	printf("Insertar Número: ");
	scanf(" %d", &n);

	printf("Fibonacci en profundidad %d = %d\n", n, fibonacci(n));
	printf("Fibonacci (Func normal) en profundidad %d = %d\n", n, fibonacciNormal(n));
	return 0;
}
