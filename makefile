all: main clean

main: main.o Arquivos.o Multiplicacao.o SistemaLinear.o Regressao.o
	gcc -Wall Arquivos.o Multiplicacao.o SistemaLinear.o Regressao.o main.o -o tp -lm

main.o: main.c Arquivos.h Multiplicacao.h SistemaLinear.h Regressao.h
	gcc -Wall -c main.c

Arquivos.o: Arquivos.c Arquivos.h
	gcc -Wall -c Arquivos.c

Multiplicacao.o: Multiplicacao.c Multiplicacao.h
	gcc -Wall -c Multiplicacao.c

SistemaLinear.o: SistemaLinear.c SistemaLinear.h
	gcc -Wall -c SistemaLinear.c

Regressao.o: Regressao.c Regressao.h
	gcc -Wall -c Regressao.c -lm

clean: 
	rm *.o