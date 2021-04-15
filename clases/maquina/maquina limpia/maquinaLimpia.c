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
#include "tables.h"


/*************** VARIABLES GLOBALES ***************/ 
EVENT event;
int state;
char buf[BUFFER];

/*************** PROTOTIPOS DE FUNCION ***************/ 
void initialise(void);
void getevent(void);

/*************** FUNCION PRINCIPAL ***************/ 
int main(int argc, char **argv)
{
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

void initialise(void)
{
    state = 0;

    /* Mensaje de Inicio*/
	
    system("clear");
    printf("\nQuieres un chicle? Ingresa una moneda de $1.00\n");

    /* Alta de usuarios en el sistema*/
   
   return;
}


void getevent(void)
{
    char *ptmp;
    ptmp = &buf[2];
    
#ifdef DEBUG
    printf("wait event \n");
#endif
    scanf("%s",buf);
         switch (buf[0])
             {
                 case 'M' :
                    event.etype=ENTRADA_0;
		    	 	strcpy(event.args,ptmp);
                    break;
		     //NO BORRAR ESTE DEFAULT QUE YA ENVIA A TODA OTRA COSA A -1
		default:
		     event.etype=-1;
		     break;
                     
             }//switch
   return;
}// getevent
 

/* FUNCIONES DE IMPLEMENTACION */

int liberarChicleAviso(void){
	system("clear");
	printf("Tu chicle ha sido dispendado, tómalo de la charola.\n");
	printf("\nSi deseas otro chicle ingresa $1.00\n");
	return 0;
}

int darMensajeError(void){
	system("clear");

	printf("Error ingresa una moneda de $1.00...\n");
	return 0;
}
