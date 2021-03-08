#include "listaDoble.h"

ListaDoble * crearLista(ListaDoble *inicio, char nombre_file[]);
ListaDoble *popLd(ListaDoble * pt);
void imprimirActualStatusNavegador(Navegador *p_nav);
int imprimirLDIzquierda(ListaDoble *pt);
int imprimirLDDerecha(ListaDoble *pt);
ListaDoble * borrarNodoNav(Navegador *p_nav);

int main(int argc, char *argv[]){
	ListaDoble *inicio;
	Navegador nav;
	char opcion;

	printf("\nEl Nodo tiene %li bytes.\n", sizeof(inicio));
	inicio = NULL;
	inicio = crearLista(inicio, argv[1]);
	
	printf("\nRecorrido de la lista a la Derecha: \n");
	imprimirLDDerecha(inicio);
	
	printf("\nRecorride de la lista a la Izquierda:\n");
	imprimirLDIzquierda(inicio);
	
	nav.ref = inicio;
	nav.mover = inicio;

	
	strcpy(nav.pal_actual, nav.mover->val);
	nav.num_chars = strlen(nav.mover->val);
	printf("\n");
	do{
		imprimirActualStatusNavegador(&nav);
		printf("\nDame la opción deseada: [b]orrar, [p]revio, [n]ext, [s]alir: ");
		scanf(" %c", &opcion);
		
		switch(opcion){
			case 'b':
				inicio = borrarNodoNav(&nav);
				if(nav.mover == NULL){
					nav.ref = nav.mover;
				}
				else{
					strcpy(nav.pal_actual, nav.mover->val);
					nav.num_chars = strlen(nav.mover->val);
				}
				break;

			case 'p':
				if (nav.mover != NULL){
					strcpy(nav.pal_actual, nav.mover->prev->val);
					nav.num_chars = strlen(nav.mover->prev->val);
					nav.mover = nav.mover->prev;
				}
				break;

			case 'n':
				if(nav.mover != NULL){
					strcpy(nav.pal_actual, nav.mover->next->val);
					nav.num_chars = strlen(nav.mover->next->val);
					nav.mover = nav.mover->next;
				}
				break;

			case 's':
				printf("Saliendo.\n");
				break;

			default:
				printf("Opción entrada inválida, intente de nuevo.\n");
		}
		
	}while(opcion != 's');
	return 0;

}
