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
extern int liberarChicleAviso(void);
extern int darMensajeError(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
        /*etype		accion    		bandera		sigEdo. */
		{ENTRADA_0,	liberarChicleAviso, -1,		ESTADO_0},
		{ENTRADA_1,	darMensajeError,	-1,		ESTADO_0}, 
};

/*************** TABLA AUXILIAR ***************/  
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado		inicio		fin */
	{ESTADO_0,	1,			0},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
