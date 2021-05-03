#include <gtk/gtk.h>
#include <string.h>
void ponNum(GtkButton *button, gpointer data);
int main(int argc, char *argv[]){
    GtkWidget *window, *table, *resultado, *botonAC, *botonMM, *botonPor, *botonDiv
    , *boton7, *boton8, *boton9, *botonX;
    GtkWidget *boton4, *boton5, *boton6, *botonMenos;
    GtkWidget *boton1, *boton2, *boton3, *botonMas;
    GtkWidget *boton0, *botonP, *botonEq;
    gtk_init (&argc, &argv);
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Calculadora");
    gtk_container_set_border_width(GTK_CONTAINER(window),10);
    gtk_widget_set_size_request(window, 155, 200);
    table = gtk_table_new(4, 6, TRUE);
    resultado = gtk_label_new("0");//resultado = gtk_entry_new();
    botonAC = gtk_button_new_with_label("AC");
    botonMM = gtk_button_new_with_label("+/-");
    botonPor = gtk_button_new_with_label("%");
    botonDiv = gtk_button_new_with_label("/");
    boton7 = gtk_button_new_with_label("7");
    boton8 = gtk_button_new_with_label("8");
    boton9 = gtk_button_new_with_label("9");
    botonX = gtk_button_new_with_label("X");
    boton4 = gtk_button_new_with_label("4");
    boton5 = gtk_button_new_with_label("5");
    boton6 = gtk_button_new_with_label("6");
    botonMenos = gtk_button_new_with_label("-");
    boton1 = gtk_button_new_with_label("1");
    boton2 = gtk_button_new_with_label("2");
    boton3 = gtk_button_new_with_label("3");
    botonMas = gtk_button_new_with_label("+");
    boton0 = gtk_button_new_with_label("0");
    botonP = gtk_button_new_with_label(".");
    botonEq = gtk_button_new_with_label("=");
    gtk_signal_connect(GTK_OBJECT(boton7),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton8),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton9),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton4),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton5),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);

    gtk_signal_connect(GTK_OBJECT(boton6),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton1),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton2),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton3),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_signal_connect(GTK_OBJECT(boton0),"clicked",GTK_SIGNAL_FUNC(ponNum),
    resultado);
    gtk_table_attach(GTK_TABLE(table), resultado, 0, 4, 0, 1, GTK_FILL, GTK_FILL, 0
    , 0);
    gtk_table_attach(GTK_TABLE(table), botonAC, 0, 1, 1, 2, GTK_FILL, GTK_FILL, 0,
    0);
    gtk_table_attach(GTK_TABLE(table), botonMM, 1, 2, 1, 2, GTK_FILL, GTK_FILL, 0,
    0);
    gtk_table_attach(GTK_TABLE(table), botonPor, 2, 3, 1, 2, GTK_FILL, GTK_FILL, 0,
    0);
    gtk_table_attach(GTK_TABLE(table), botonDiv, 3, 4, 1, 2, GTK_FILL, GTK_FILL, 0,
    0);
    gtk_table_attach(GTK_TABLE(table), boton7, 0, 1, 2, 3, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton8, 1, 2, 2, 3, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton9, 2, 3, 2, 3, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), botonX, 3, 4, 2, 3, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton4, 0, 1, 3, 4, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton5, 1, 2, 3, 4, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton6, 2, 3, 3, 4, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), botonMenos, 3, 4, 3, 4, GTK_FILL, GTK_FILL,
    0, 0);
    gtk_table_attach(GTK_TABLE(table), boton1, 0, 1, 4, 5, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton2, 1, 2, 4, 5, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), boton3, 2, 3, 4, 5, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), botonMas, 3, 4, 4, 5, GTK_FILL, GTK_FILL, 0,
    0);
    gtk_table_attach(GTK_TABLE(table), boton0, 0, 2, 5, 6, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), botonP, 2, 3, 5, 6, GTK_FILL, GTK_FILL, 0, 0
    );
    gtk_table_attach(GTK_TABLE(table), botonEq, 3, 4, 5, 6, GTK_FILL, GTK_FILL, 0,
    0);

    gtk_table_set_row_spacings(GTK_TABLE(table), 5);
    gtk_table_set_col_spacings(GTK_TABLE(table), 5);
    gtk_container_add(GTK_CONTAINER(window), table);
    gtk_widget_show_all(window);
    gtk_main();
    return 0;
}

void ponNum(GtkButton *button, gpointer data){
    char num[2];
    strcpy(num,gtk_button_get_label (button));
    gtk_label_set_text(GTK_LABEL(data),num);
    return;
}