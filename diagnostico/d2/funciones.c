/*
*	@file: funciones.c	
*	@brief: Contiene las funciones necesarias para correr el examen diagnóstico 2.
*	@author: Equipo 3
*	@date: 26/03/2021
*/
#include "Diag02def.h"

/*
*	@brief: Inserta un nuevo nodo en un árbol existente
*	@author: Equipo 3
*	@param Arbol *pt
*	@param char *palabra
*	@return Arbol *
*/
Arbol * insertar(Arbol *pt, char *palabra){
	if (pt == NULL){
		Arbol *nuevo = (Arbol *)malloc(sizeof(Arbol));
			
		strcpy(nuevo->val, palabra);
		nuevo->left = NULL;
		nuevo->right = NULL;
		nuevo->tamanio = (int) strlen(palabra);
		nuevo->repeticion = 1;
		return nuevo;
	}

	if(strcmp(pt->val, palabra) == 0){
		printf("%s es una palabra repetida, no fue agregado.\n", pt->val);
		pt->repeticion++;
	}

	else if (strcmp(pt->val, palabra) < 0){
		pt->right = insertar(pt->right, palabra);
	}
	else{
		pt->left = insertar(pt->left, palabra);	
	}

	return pt;
}

/*
*	@brief: Inserta un nuevo nodo en un árbol existente
*	@author: Equipo 3
*	@param Arbol *pt
*	@param char *palabra
*	@return Arbol *
*/
Arbol * readTxt(char *nombre_file){
	Arbol *root = NULL;
	char palabra[40];
	FILE *fp;
	fp = fopen(nombre_file, "r");
	if (fp == NULL){
		printf("Archivo no leido, error.\n");
		exit(1);
	}
	
	while(fscanf(fp, "%s", palabra) == 1){
		root = insertar(root, palabra);
	}


	fclose(fp);
	return root;
}

/*
*	@brief: Encuentra la profundidad máxima de un árbol
*	@author: Equipo 3
*	@param Arbol *pt
*	@return int
*/
int depthTree(Arbol *pt){
	if(pt == NULL) return 0;

	int left_depth = depthTree(pt->left);
	int right_depth = depthTree(pt->right);

	if(left_depth > right_depth)
		return left_depth + 1;
	else
		return right_depth + 1;
}

/*
*	@brief: Recorre un árbol entero en orden.
*	@author: Equipo 3
*	@param Arbol *pt
*	@return void
*/
void recorrer(Arbol *pt){
	if(pt == NULL) return;

	recorrer(pt->left);
	printf("%s: \t %d repeticiones \t %d letras\n", pt->val, pt->repeticion, pt->tamanio);
	recorrer(pt->right);
}

/*
*	@brief: Busca un elemento en un árbol de manera organiada
*	@author: Equipo 3
*	@param Arbol *pt
*	@param char *palabra
*	@return Arbol *
*/
/*
int buscarPalabra(Arbol *pt, char *palabra){
	if(pt == NULL){
		printf("Nodo no encontrado\n");
		return 1;
	}
	
	if (strcmp(pt->val, num) == 0){
		char palabra1[20], palablra2[20];
		(pt->left != NULL) ? sprintf(palabra1, "%s", pt->left->val) : sprintf(num1,"NULL");
		(pt->right != NULL) ? sprintf(palabra2, "%s", pt->right->val) : sprintf(num2,"NULL");
		
		printf("Nodo encontrado: %s \t Hijos: %s, %s\n", pt->val, palabra1, palabra2);
		return 0;
	}
	
	if(strcmp(pt->val, num) < 0){
		buscarPalabra(pt->right, num);
	}
	else{
		buscarPalabra(pt->left, num);
	}
}
*/	

