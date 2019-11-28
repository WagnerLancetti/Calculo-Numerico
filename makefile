all: main clean

main: main.o Arquivos.o Multiplicacao.o SistemaLinear.o
	gcc -Wall Arquivos.o Multiplicacao.o SistemaLinear.o main.o -o tp

main.o: main.c Arquivos.h Multiplicacao.h SistemaLinear.h
	gcc -Wall -c main.c

Arquivos.o: Arquivos.c Arquivos.h
	gcc -Wall -c Arquivos.c

Multiplicacao.o: Multiplicacao.c Multiplicacao.h
	gcc -Wall -c Multiplicacao.c

SistemaLinear.o: SistemaLinear.c SistemaLinear.h
	gcc -Wall -c SistemaLinear.c

clean: 
	rm *.o