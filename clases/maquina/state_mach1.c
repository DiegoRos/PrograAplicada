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
}


void getevent(void)
{
    char *ptmp;
    ptmp = &buf[2];
    
#ifdef DEBUG
    printf("wait event \n");
#endif
    gets(buf);
         switch (buf[0])
             {
                 case 'T' :
                     event.etype=ENTRADA_0;
                     break;
                 case 'D' :
                     event.etype=ENTRADA_2;
                     break;
                 case 'X' :
                     event.etype=ENTRADA_3;			
                     break;
                 case 'A' :
                     event.etype=ENTRADA_5;			
                     break;
                 case 'B' :
                     event.etype=ENTRADA_6;			
                     break;
                 case 'C' :
                     event.etype=ENTRADA_7;			
                     break;


		     //NO BORRAR ESTE DEFAULT QUE YA ENVIA A TODA OTRA COSA A -1
		default:
		     event.etype=-1;
		     break;
                     
             }//switch
}// getevent
 

/* FUNCIONES DE IMPLEMENTACION */

int imprime_c_h_p(void)
{
 return 0;
}

int default_(void)
{
  return 0;
}

int subtotal_3D(void)
{
  return 0;
}

int subtotal_4X(void)
{
  return 0;
}

int mensaje_error_b(void)
{
  return 0;
}

int pre_impresion(void)
{
  return 0;
}

int mensaje_error_h(void)
{
  return 0;
}

int saldo(void)
{
  return 2;
}

int sin_saldo(void)
{
  return 0;
}

int imprime_b_s(void)
{
  return 0;
}
