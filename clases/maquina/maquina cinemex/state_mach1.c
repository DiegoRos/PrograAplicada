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

    /* Mensaje de Inicio del Sistema CineTerminal */
    venta = 0;
    boletos = 0;
    horario = 0;

    system("clear");
    printf("\nInicio del Sistema. Bienvenido a la CineTerminal, ingresa tu tarjeta [T:****] ");

    /* Alta de usuarios en el sistema*/
    fp = fopen("clientes.txt", "r");
    if (fp==NULL)
      {
	printf("\nArchivo no disponible.");
	exit(1);
      }
    for(i=0;i<2;i++)
      {
	fscanf(fp," %[^\t]",baseClientes[i].nombre);
	fscanf(fp,"%f\t",&baseClientes[i].saldo);
	fscanf(fp,"%s\n",baseClientes[i].numCliente);
      }
    fclose(fp);

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
		     strcpy(event.args,ptmp);
                     break;
                 case 'D' :
                     event.etype=ENTRADA_2;
		     strcpy(event.args,ptmp);
                     break;
                 case 'X' :
                     event.etype=ENTRADA_3;
		     strcpy(event.args,ptmp);			
                     break;
                 case 'A' :
                     event.etype=ENTRADA_5;
		     horario = 20;
                     break;
                 case 'B' :
                     event.etype=ENTRADA_6;
		     horario = 18;
                     break;
                 case 'C' :
                     event.etype=ENTRADA_7;
		     horario = 16;
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

  for(i=0;i<2;i++)
    { if (strcmp(event.args,baseClientes[i].numCliente) == 0)
	{
	  clienteActual = baseClientes[i];
	  posicion = i;
	}
    }

  system("clear");
  printf("\nEstimado %s tienes %f de saldo. \n", clienteActual.nombre, clienteActual.saldo);
  printf("\nLas Pelìculas son:\n");
  printf("\nAnimales Fantásticos 4X, 16:00 18:00 y 20:00 horas.\n");
  printf("\nDr. Stange 3D, 16:00 18:00 y 20:00 horas.\n");
  printf("\nIngresa la opción seguida por el número de boletos: D:# ó X:# \n");
  return 0;
}

int default_(void)
{
  system("clear");
  printf("\nDato erróneo, ingresa tu tarjeta [T:****] ");
  return 0;
}

int subtotal_3D(void)
{
  sscanf(event.args,"%i",&boletos);
  venta = boletos * TRESD;
  strcpy(pelicula,"Dr. Strange");
  system("clear");
  printf("\nEstimado %s estás comprando %i boletos por un total de $%f. \n", clienteActual.nombre, boletos, venta);
  printf("\n%s\n", pelicula);
  printf("\nIngresa un horario válido: 16:00 horas [C],  18:00 horas [B] y 20:00 horas [A].\n");

  return 0;
}

int subtotal_4X(void)
{
  sscanf(event.args,"%i",&boletos);
  venta = boletos * CUATROX;
  strcpy(pelicula,"Animales Fantásticos");
  system("clear");
  printf("\nEstimado %s estás comprando %i boletos por un total de $%f. \n", clienteActual.nombre, boletos, venta);
  printf("\n%s\n", pelicula);
  printf("\nIngresa un horario válido: 16:00 horas [C],  18:00 horas [B] y 20:00 horas [A].\n");
  
  return 0;
}

int mensaje_error_b(void)
{
  printf("\nOpción inválida. \n");
  printf("\nIngresa la opción seguida por el número de boletos: D:# ó X:# \n");
  return 0;
}

int pre_impresion(void)
{
  printf("\n Estás comprando %i para %s por un total de $%.2f para el horario de %.2i horas\n", boletos, pelicula, venta, horario);
  return 0;
}

int mensaje_error_h(void)
{
   printf("\nOpción inválida. \n");
   printf("\nIngresa un horario válido: 16:00 horas [C],  18:00 horas [B] y 20:00 horas [A].\n");
   return 0;
}

int saldo(void)
{
  if (clienteActual.saldo < venta) return 1;
  else return 3;
}

int pre_carga(void)
{
  printf("\nRevisando si puedo recargar... \n");
  if (strcmp(clienteActual.numCliente, "1234") == 0)
    {
      clienteActual.saldo += 1000.00;
      return 3;
    }
  else return 2;
}

int sin_saldo(void)
{
  printf("\nNo tiene saldo tu tarjeta.\n");
  return 0;
}

int imprime_b_s(void)
{
 printf("\n Boletos impresos %i para %s por un total de $%.2f para el horario de %.2i horas\n", boletos, pelicula, venta, horario);
 clienteActual.saldo -= venta;
 baseClientes[posicion] = clienteActual;

 fp = fopen("clientes.txt", "w");
    if (fp==NULL)
      {
	printf("\nArchivo no disponible.");
	exit(1);
      }
    for(i=0;i<2;i++)
      {
	fprintf(fp,"%s\t",baseClientes[i].nombre);
	fprintf(fp,"%f\t",baseClientes[i].saldo);
	fprintf(fp,"%s\n",baseClientes[i].numCliente);
      }
    fclose(fp);

  return 0;
}
