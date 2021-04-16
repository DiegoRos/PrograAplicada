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
extern int preguntarColor(void);
extern int darMensajeError(void);
extern int preImprimirSolicitud(void);
extern int indicarErrorColor(void);
extern int revisarSaldo(void);
extern int entregarChicleYActualizarSaldo(void);
extern int indicarErrorSaldo(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 //Operación = -1
 //Condicional = 0

/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
/*	etype		accion    			bandera	sigEdo. */
	{ENTRADA_0,	indicarErrorMoneda,	-1, 	ESTADO_0},
	{ENTRADA_1,	pregutnarColor,		-1,		ESTADO_1},
	{ENTRADA_2, indicarErrorColor,	-1		ESTADO_1},
	{ENTRADA_3,	preImprimirSolicitud, 0,	-1},
};

/*************** TABLA AUXILIAR ***************/  
//Se utiliza para condicionales
    AUX_TAB aux_table[]={        
/*	accion								bandera		sigEdo */
	{revisarSaldo,						0,			-1},
	{entregarChicleYActualizarSaldo,	-1,			ESTADO_0},
	{indicarErrorSaldo,					-1,			ESTADO_0},
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
/*	estado		inicio	fin */
	{ESTADO_0,	1,		0},
	{ESTADO_1,	3,		2},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
