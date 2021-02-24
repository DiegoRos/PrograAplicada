#Creación del executable
alumnos.exe: funciones.o pacientes.o
	gcc funciones.o pacientes.o -o pacientes.exe

#Objeto de main
main.o: pacientes.c
	gcc -c pacientes.c

#Objeto de funciones
funciones.o: funciones.c
	gcc -c funciones.c
