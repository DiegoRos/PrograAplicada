/****************************************************************
 *								*
 * Archivo:	local.h						*
 * Descripcion: Archivo de encabezado para maquina de estados	*
 *		Aqui se definen todos los tipos de datos y 	*
 *		constantes que se utilizan en el programa	*
 *								*
 ****************************************************************/

/******************* CONSTANTES *******************
 * En esta seccion se declaran todas las 	  *
 * las constantes que se necesiten en el programa *
 **************************************************/ 
#define BUFFER        128
#define L_EVENT_ARGS  21

/* Definidas para Cinemex */

#define TRESD 145.00
#define CUATROX 180.00


/****************** ESTRUCTURAS *****************
 * En esta seccion se declarar todas las	*
 * estructuras que se necesiten en el programa	*
 ************************************************/ 

// Este tipo de datos se utiliza para leer la informacion
// que teclea el usuario 
struct event_s
{
    int etype;
    char args[L_EVENT_ARGS];
};
typedef struct event_s EVENT;

// Este tipo de datos se utiliza para implementar 
// la tabla auxiliar
struct aux_table_s 
{
    int (*action)();
    int moreacts;
    int nextstate;
};
typedef struct aux_table_s AUX_TAB;

// Este tipo de datos se utiliza para implementar
// la tabla de accion
struct action_tab_s 
{
    int event;
    int (*action)();
    int moreacts;
    int nextstate;
};
typedef struct action_tab_s ACTION_TAB;

// Este tipo de datos se utiliza para implementar
// la tabla de estados
struct state_tab_s 
{
    int state;
    int start;
    int end;
};
typedef struct state_tab_s STATE_TAB;

/* Datos definidos por el programador*/

struct cliente
{ char nombre[40];
  float saldo;
  char numCliente[10];
};

typedef struct cliente clienteCine;

/********************* GLOBALES ***********************
 * En esta seccion se pueden declarar todas	      *
 * variables globales que se necesiten en el programa *
 ******************************************************/ 
FILE *fp;
clienteCine baseClientes[2];
clienteCine clienteActual;
int i, posicion, boletos, horario;
float venta;
char pelicula[40];



/********************* EVENTOS *******************
 * En esta seccion se declarar como constantes	 *
 * los eventos (entradas) que recibe el programa *
 *************************************************/ 
#define ENTRADA_0   0
#define ENTRADA_1   -1
#define ENTRADA_2   2
#define ENTRADA_3   3
#define ENTRADA_4   4
#define ENTRADA_5   5
#define ENTRADA_6   6
#define ENTRADA_7   7
#define ENTRADA_8   -1



/********************* ESTADOS ******************
 * En esta seccion se declarar como constantes	*
 * los estados de que consta el programa 	*
 ************************************************/ 
#define ESTADO_0     0
#define ESTADO_1     1
#define ESTADO_2     2







