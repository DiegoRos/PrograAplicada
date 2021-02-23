#Creación del executable
alumnos.exe: funciones.o main.o
	gcc funciones.o main.o -o alumnos.exe

#Objeto de main
main.o: main.c
	gcc -c main.c

#Objeto de funciones
funciones.o: funciones.c
	gcc -c funciones.c
