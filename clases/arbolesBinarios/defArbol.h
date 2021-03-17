#include <stdio.h>
#include <stdlib.h>

typedef struct Arbol{
	int val;
	struct Arbol *left, *right;
}Arbol;

Arbol * insertar(Arbol *pt, int num){
	
	if (pt == NULL){
		Arbol *nuevo = (Arbol *)malloc(sizeof(Arbol));
	
		nuevo->val = num;
		nuevo->left = NULL;
		nuevo->right = NULL;
		return nuevo;
	}

	if (pt->val < num){
		pt->right = insertar(pt->right, num);
	}
	else{
		pt->left = insertar(pt->left, num);	
	}

	return pt;
}

int depthTree(Arbol *pt){
	if(pt == NULL) return 0;

	int left_depth = depthTree(pt->left);
	int right_depth = depthTree(pt->right);

	if(left_depth > right_depth)
		return left_depth + 1;
	else
		return right_depth + 1;
}


void recorrer(Arbol *pt){
	if(pt == NULL) return;

	recorrer(pt->left);
	printf("%i\n", pt->val);
	recorrer(pt->right);
}

int buscarNumero(Arbol *pt, int num){
	if(pt == NULL){
		printf("Nodo no encontrado\n");
		return 1;
	}
	
	if (pt->val == num){
		char num1[20], num2[20];
		(pt->left != NULL) ? sprintf(num1, "%d", pt->left->val) : sprintf(num1,"NULL");
		(pt->right != NULL) ? sprintf(num2, "%d", pt->right->val) : sprintf(num2,"NULL");
		
		printf("Nodo: %d \t Hijos: %s, %s\n", pt->val, num1, num2);
		return 0;
	}
	
	if(pt->val < num){
		buscarNumero(pt->right, num);
	}
	else{
		buscarNumero(pt->left, num);
	}
	

}

void encontrarPares(Arbol *pt){

}

int buscarDiercto(Arbol *pt, int num){

}

int recorrerDescendente(Arbol *pt){

}

