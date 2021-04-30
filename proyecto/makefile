main.exe: main.o funciones.o
	gcc main.o funciones.o -o reporteAlumons.exe `pkg-config --cflags gtk+-2.0`

main.o: main.c
	gcc -c main.c `pkg-config --libs gtk+-2.0`

funciones.o: funciones.c
	gcc -c funciones.c

clean:
	rm *.o

