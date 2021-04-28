menu.out: menu.o
	gcc -o menu.out menu.o `pkg,config --libs gtk+-2.0`
menu.o: menu.c 
	gcc -o menu.c `pkg,config --cflags gtk+-2.0`
clean:
	rm *.o

ventana.out: ventana.o
	gcc -o ventana.exe menu.o `pkg,config --libs gtk+-2.0`
ventana.o: ventana.c
	gcc -c ventana.c `pkg,config --cflags gtk+-2.0`

clean:
	rm *.o
