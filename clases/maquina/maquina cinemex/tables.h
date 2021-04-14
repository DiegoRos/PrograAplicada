/************************************************************************
 *									*
 * Archivo:	tables.h						*
 * Descripcion: Tablas para la maquina de estados y funciones externas	*
 *		Aqui se definen todos las tablas que se utilizan	*
 *		en el programa						*
 *									*
 ************************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include "local.h"
#include <stdio.h>


/*************** FUNCIONES EXTERNAS *********************
 * En esta seccion se declaran los encabezados de 	*
 * todas las funciones que se utilizan en las     	*
 * tablas del programa. Todas las funciones deben 	*
 * ser de tipo entero y no deben recibir parametros	*
 ********************************************************/ 
int imprime_c_h_p(void);
int default_(void);
int subtotal_3D(void);
int subtotal_4X(void);
int mensaje_error_b(void);
int pre_impresion(void);
int mensaje_error_h(void);
int saldo(void);
int sin_saldo(void);
int imprime_b_s(void);
int pre_carga(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
        /*etype    accion    bandera   sigEdo. */    
    { ENTRADA_0,  imprime_c_h_p,   	-1,	ESTADO_1},
    { ENTRADA_1,     default_,	-1,	ESTADO_0},
    { ENTRADA_2,     subtotal_3D,	-1,	ESTADO_2},
    { ENTRADA_3,     subtotal_4X,	-1,	ESTADO_2},    
    { ENTRADA_4,   mensaje_error_b,	 -1,	ESTADO_1},
    { ENTRADA_5,     pre_impresion,	0,	-1},
    { ENTRADA_6,     pre_impresion,	0,	-1}, 
    { ENTRADA_7,     pre_impresion,	0,	-1},
    { ENTRADA_8,     mensaje_error_h,	-1,	2},               
};

/*************** TABLA AUXILIAR ***************/  
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
    { saldo,        0,          -1},
    { pre_carga,        -0,          -1},
    { sin_saldo,        -1,          ESTADO_0},
    { imprime_b_s,	       -1,          ESTADO_0},
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {ESTADO_0,     0,      1},   
    {ESTADO_1,     2,      4},
    {ESTADO_2,     5,      8},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
