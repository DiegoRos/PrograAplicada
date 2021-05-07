#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
void mostrarResultado(GtkWidget *boton, gpointer estructura);
void closeTheApp(GtkWidget *window, gpointer estructura);
float calcularResultado(char op1[], char operador[], char op2[]);
struct datosOperacion{
    GtkWidget *operando1;
    GtkWidget *operador;
    GtkWidget *operando2;
    GtkWidget *labelResultado;
};
typedef struct datosOperacion datOp ;

typedef struct Stack{
	char operacion[100];
	struct Stack *next;
}Stack;

int imprimirStack(Stack *s);
Stack *s;

//nodo *inicio;
int main(int argc, char *argv[])
{
	s = NULL;
    datOp datosIn;
    /*0. Declaración de variables */
    GtkWidget *window, *vbox, *hbox, *labelOp1, *labelOperador, *labelOp2, *boton;
    /*1. Inicializar el ambiente*/
    gtk_init(&argc,&argv);
    /*2. Creación de los objetos y modificación de atributos */
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title (GTK_WINDOW(window), "Ejemplo operación de 2 datos");
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    labelOp1 = gtk_label_new("Dame operando 1:");
    labelOp2 = gtk_label_new("Dame operando 2:");
    labelOperador = gtk_label_new("Dame operador:");
    boton = gtk_button_new_with_label("Calcular");
    datosIn.operando1 = gtk_entry_new();
    datosIn.operando2 = gtk_entry_new();
    datosIn.operador = gtk_entry_new();
    datosIn.labelResultado = gtk_label_new("Aquí va el resultado :)");
    /*3. Registro de los Callbacks */
    g_signal_connect(GTK_OBJECT(window), "destroy", GTK_SIGNAL_FUNC(closeTheApp), NULL);
    g_signal_connect(GTK_OBJECT(boton), "clicked", GTK_SIGNAL_FUNC(mostrarResultado), &datosIn);

    /* 4. Define jerarquía de instancias (pack the widgets)*/
    hbox = gtk_vbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), labelOp1);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), datosIn.operando1);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), labelOperador);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), datosIn.operador);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), labelOp2);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), datosIn.operando2);
    gtk_box_pack_start_defaults(GTK_BOX(hbox), datosIn.labelResultado);
    vbox = gtk_vbox_new(FALSE, 5);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), hbox);
    gtk_box_pack_start_defaults(GTK_BOX(vbox), boton);
    gtk_container_add(GTK_CONTAINER(window),vbox);
    /* 5. Mostrar los widgets */
    gtk_widget_show_all(window);
    /* 6. El programa se queda en loop */
    gtk_main();
    return 0;
}

void mostrarResultado(GtkWidget *boton, gpointer estructura)
{
    float resultado;
    char op1[20],op[20],op2[20],res[20];
    datOp *pt = (datOp *)estructura;
    strcpy(op1, gtk_entry_get_text(GTK_ENTRY(pt->operando1)));
    strcpy(op, gtk_entry_get_text(GTK_ENTRY(pt->operador)));
    strcpy(op2, gtk_entry_get_text(GTK_ENTRY(pt->operando2)));
    resultado = calcularResultado(op1, op, op2);
    sprintf(res, "%f", resultado);
    gtk_label_set_text(GTK_LABEL(pt->labelResultado),res);
    return;
}

Stack * push(char *operacion, struct Stack *s){
	Stack *aux = (Stack *)malloc(sizeof(Stack));
	
	strcpy(aux->operacion, operacion);
	aux->next = s;
	s = aux;
	return s;
}

int imprimirStack(Stack *s){
	while (s != NULL){
		printf("%s\n", s->operacion);
		s = s->next;
	}

	return 0;
}

float calcularResultado(char op1[], char operador[], char op2[])
{
    float operador1, operador2, resultado=0.0;
    char operacion = operador[0];
    char string_operacion[100];

    sscanf(op1, "%f", &operador1);
    sscanf(op2, "%f", &operador2);
    
    if (operacion == '+'){
        resultado = operador1 + operador2;
        sprintf(string_operacion, "Suma: %f + %f = %f", operador1, operador2, resultado);
	    s = push(string_operacion, s);
    }
    else if (operacion == '-'){
        resultado = operador1 - operador2;
        sprintf(string_operacion, "Resta: %f - %f = %f", operador1, operador2, resultado);
        s = push(string_operacion, s);
    }
    else if (operacion == 'x'){
        resultado = operador1 * operador2;
        sprintf(string_operacion, "Multiplica: %f x %f = %f", operador1, operador2, resultado);
        s = push(string_operacion, s);
    }
    else if (operacion == '/'){
        resultado = operador1/operador2;
        sprintf(string_operacion, "Divide: %f / %f = %f", operador1, operador2, resultado);
        s = push(string_operacion, s);
    }
        
	return resultado;
}



void closeTheApp(GtkWidget *window, gpointer estructura){
    imprimirStack(s);
    gtk_main_quit();
    return;
}
