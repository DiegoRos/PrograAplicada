extern void modulo2(GtkWidget *boton,base *pt)
{
  
  gtk_button_ser_label(GTK_BITTON(boton),"Abdiel Cuevas");

  nodo *aux; 

  char nomMayuscula;
  int edad;
  int contadorMayuscula = 0;
  int contadorEdad = 0;
  char buffer;
  
  aux = pt->ref; 
  edad = aux->edad;
  strcpy(nomMayuscula,aux->nombre[0]);


  if(aux == NULL)
  {
    gtk_label_set_text(GTK_LABEL(pt->label3),"no hay nada");
  }else{
 
   do{
    if( isupper(nomMayuscula) == 1)
    {
      contadorMayuscula++;
    }else{
      contadorMayuscula += 0;
    }
    if(edad > 20)
    {
      contadorEdad++;
    }else{
      contadorEdad += 0;
    }
  
    aux -> next;

   }while(aux != NULL);

   sprintf(buffer, "Con Mayusculas: %i, Mayores de 20: %i",contadorMayusculas,contadorEdad);
   gtk_label_set_text(GTK_LABEL(pt->label3),buffer);
 }
 return;
}
