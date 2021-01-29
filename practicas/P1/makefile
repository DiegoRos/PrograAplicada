#Esta línea tiene como objetivo crear el ejecutable calcula.exe 
calcula.exe: calcula.o funciones.o
	gcc calcula.o funciones.o -o calcula.exe -lm

#Crear objeto de main file calcula.c
calcula.o: calcula.c
	gcc -c calcula.c

#Crear objeto de funciones file funciones.c
funciones.o: funciones.c
	gcc -c funciones.c 
