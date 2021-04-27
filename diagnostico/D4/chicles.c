/****************************************************************
 *								*

 * Archivo:	state_mach1.c					*
 * Descripcion: Codigo Fuente para implementar el programa	*
 *		de maquina de estados.			 	*
 *								*
 ****************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tables.h"


/*************** VARIABLES GLOBALES ***************/ 
EVENT event;
int state;
char buf[BUFFER];

/*************** PROTOTIPOS DE FUNCION ***************/ 
void initialise(void);
void getevent(void);

/*************** FUNCION PRINCIPAL ***************/ 
int main(int argc, char **argv){
    int actx, auxx, outcome;

    initialise();
    
    while (1) {    /* loop infinito para la MFE */
        getevent();

        for ((actx = state_table[state].start);(action_table[actx].event != event.etype) && (actx < state_table[state].end);actx++)
		; //NO BORRAR ESTE ;
		outcome = (*(action_table[actx].action))();
		if(action_table[actx].moreacts == -1)
			state = action_table[actx].nextstate;
		else {
			auxx = action_table[actx].moreacts + outcome;
			while (auxx != -1){
				outcome = (*(aux_table[auxx].action))();
				if (aux_table[auxx].moreacts == -1 ){
					state = aux_table[auxx].nextstate;
					auxx = -1;
				}
				else
					auxx = aux_table[auxx].moreacts + outcome;

			}
		}

	} /* while(1) */
}

/*
*	@brief: Sets the state of the machine to its base state.
*	@author: Equipo 3
*	@return int
*/
void initialise(void){
	FILE *fp;
	int i;
	state = 0;

    /* Mensaje de Inicio*/
	
	system("clear");
	printf("\nQuieres un chicle? Cuesta $1.00, Ingresa tu tarjeta: [M:****]\n");

    /* Alta de usuarios en el sistema*/
	fp = fopen("clientes.txt", "r");
	//Obviamente esto ser√≠a mejor con una lista o alguna otra estructura
	for(i = 0; i < 2; ++i){
		fscanf(fp, " %[^\t] %[^\t] %f\n",clientes_totales[i].nombre, clientes_totales[i].num_cliente, &clientes_totales[i].saldo);
	}

	fclose(fp);
	return;
}

/*
*	@brief: Lectura de evento. M para entrar a las tarjetas y C para seleccionar color.
*	@author: Equipo 3
*	@return int
*/
void getevent(void)
{
    char *ptmp;
    ptmp = &buf[2];
    
#ifdef DEBUG
    printf("wait event \n");
#endif
    scanf("%s",buf);
         switch (buf[0]){
         	case 'M':
				event.etype = ENTRADA_1;
				strcpy(event.args,ptmp);
				break;
			case 'C':
				event.etype = ENTRADA_3;
				strcpy(event.args, ptmp);
				break;

		     //NO BORRAR ESTE DEFAULT QUE YA ENVIA A TODA OTRA COSA A -1
			default:
				event.etype=-1;
				break;
                     
		}//switch
   return;
}// getevent
 

/* FUNCIONES DE IMPLEMENTACION */

/*
*	@brief: FunciÛn que imprime las opciones de colores de chicles
*	@author: Equipo 3
*	@return int
*/
int preguntarColor(void){
	int i;
	system("clear");
	for(i = 0; i < 2; ++i){
		if(strcmp(event.args, clientes_totales[i].num_cliente) == 0){
			cliente_temp = &clientes_totales[i];
			break;
		}
	}
	printf("\nChicles: 1 = Amarillo, 2 = Verde, 3 = Rojo\n");
	printf("Hola %s, escoge un color de Chicle C:[1|2|3]", cliente_temp->nombre);
	
	return 0;
}

/*
*	@brief: FunciÛn que imprime error de monedero y se espera antes de dar opciÛn de trajeta.
*	@author: Equipo 3
*	@return int
*/
int indicarErrorMoneda(void){
	system("clear");
	printf("\nSe ingresÛ un monedero inv·lido, intente de nuevo.\n");
	
	sleep(2);
	
	system("clear");
	printf("\nQuieres un chicle? Cuesta $1.00, Ingresa tu tarjeta: [M:****]\n");
	return 0;
}

/*
*	@brief: Imprime color de chicle escogido.
*	@author: Equipo 3
*	@return int
*/
int preImprimirSolicitud(void){
	int color;
	sscanf(event.args, " %i", &color);
	system("clear");
	printf("\nUsted ha elejido el chicle de color: %s\n", (color == 1) ? "Amarillo" : ((color == 2) ? "Verde" : (color == 3 ? "Rojo": "Color no v·lido")));
	
	sleep(2);
	return 0;
}

/*
*	@brief: Indica que no se diÛ opciÛn de color v·lido
*	@author: Equipo 3
*	@return int
*/
int indicarErrorColor(void){
	system("clear");
	printf("\nEscoge un color v·lido\n");
	sleep(2);

	system("clear");
	printf("\nChicles: 1 = Amarillo, 2 = Verde, 3 = Rojo\n");
	printf("Hola %s, escoge un color de Chicle C:[1|2|3]", cliente_temp->nombre);	
	system("clear");
	return 0;
}

/*
*	@brief: Revisa saldo de usuario, si no hay sufuciente regresa a Estado_0, en el otro caso se cobra el chicle.
*	@author: Equipo 3.
*	@return int
*/
int revisarSaldo(void){
	int flag_saldo = 0;
	if(cliente_temp->saldo >= 1){//Alcanza
		flag_saldo = 1; // Posici√≥n en arreglo de aux_table
	}
	else{
		flag_saldo = 2; // Posici√≥n en arreglo de aux_table
	}
	return flag_saldo;
}

/*
*	@brief: ImpresiÛn de entrega de chicle y se actualiza el saldo de los usuarios.
*	@author: Equipo 3
*	@return int
*/
int entregarChicleYActualizarSaldo(void){
	FILE *fp;
	int i;
	cliente_temp->saldo -= 1;
	
	system("clear");
	printf("\nToma tu chicle y tu nuevo saldo es: %f\n", cliente_temp->saldo);
	fp = fopen("clientes.txt", "w");
	//Obviamente esto ser√≠a mejor con una lista o alguna otra estructura
	for(i = 0; i < 2; ++i){
		fprintf(fp, "%s\t%s\t%f\n",clientes_totales[i].nombre, clientes_totales[i].num_cliente, clientes_totales[i].saldo);
	}

	fclose(fp);
	
	sleep(2);
	system("clear");
	printf("\nQuieres un chicle? Cuesta $1.00, Ingresa tu tarjeta: [M:****]\n");
	return 0;
}

/*
*	@brief: Si no hay suficiente saldo en el monedero se corre esta funciÛn.
*	@author: Equipo 3
*	@return int
*/
int indicarErrorSaldo(void){
	char esperar;
	system("clear");
	printf("\nNo hay suficiente saldo en el monedero, intentar de nuevo.\n");

	sleep(2);
	system("clear");
	printf("\nQuieres un chicle? Cuesta $1.00, Ingresa tu tarjeta: [M:****]\n");
	return 0;
}

/*
*	@brief: Se libera el chicle y se regresa a el ESTADO_0
*	@author: Equipo 3
*	@return int
*/
int liberarChicleAviso(void){
	system("clear");
	printf("Tu chicle ha sido dispendado, tÛmalo de la charola.\n");
	printf("\nSi deseas otro chicle ingresa $1.00\n");
	return 0;
}
