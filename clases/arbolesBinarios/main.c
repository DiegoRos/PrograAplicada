#include "defArbol.h"

int main(int argc, char *argv[]){
	if(argc != 2) exit(1);

	FILE *fp;
	Arbol *root = NULL;	
	int num;

	fp = fopen(argv[1], "r");
	while(fscanf(fp, "%i", &num) == 1){
		root = insertar(root, num);
	}
	fclose(fp);	
	printf("Max depth: %d\n", depthTree(root));	

	recorrer(root);
	
	int val = 9;
	buscarNumero(root, val);

	remove("pares.txt");
	encontrarPares(root);
	
	return 0;
}
