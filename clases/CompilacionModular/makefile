#Este es un ejemplo del uso de Make
#Las líneas con # con comentarios
#Las líneas que comienzan con un idntificador y : son objetivos de make
#Las líneas que empiezan con un Tabulador son comandos de shell

#Esta línea tiene como objetivo "final" es decir compila todos los objetos y da un executable
final: principal.o funciones.o funciones2.o funciones3.o
	gcc principal.o funcioens.o funciones2.o funciones3.o -o final -lm

#En estos comandos se compilan los módulos necesarios
principal.o: principal.c
	gcc -c principal.c

#En estos comandos se compilan los módulos necesarios
funciones.o: funciones.c
	gcc -c funciones.c

#En estos comandos se compilan los módulos necesarios
funciones2.o: funciones2.c
	gcc -c funciones2.c

#En estos comandos se compilan los módulos necesarios
funciones3.o: funciones3.c
	gcc -c funciones3.c



