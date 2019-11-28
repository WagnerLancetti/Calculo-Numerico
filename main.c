#include <stdio.h>
#include <stdlib.h>
#include "Arquivos.h"
#include "Multiplicacao.h"
#include "SistemaLinear.h"

#define TAM 7

int main(){
    float *y = NULL;
    y = Inicializa_Vetor(y,TAM);
    float **Matriz_Original = NULL;
    Matriz_Original = Inicializa_Matriz(Matriz_Original,TAM,6);
    float **Matriz_Transposta = NULL;
    float **Resultado1 = NULL;
    float *Resultado2 = NULL;
    FILE *input = fopen ("input.txt","r");
    LeArquivo(input,y,Matriz_Original);
    Matriz_Transposta = GerarTransposta(Matriz_Original);
    Resultado1 = Inicializa_Matriz(Resultado1,6,6);
    Resultado2 = Inicializa_Vetor(Resultado2,6);
    Resultado1 = Transposta_X_Original(Matriz_Transposta,Matriz_Original,Resultado1);
    Resultado2 = Transposta_X_Funcao(Matriz_Transposta,y,Resultado2);
    Resultado2 = ResolveSistemaLinear(Resultado1,Resultado2);
    printf ("\nIntercept = %f",Resultado2[0]);
    printf ("\nð1 = %f",Resultado2[1]);
    printf ("\nð2 = %f",Resultado2[2]);
    printf ("\nð3 = %f",Resultado2[3]);
    printf ("\nð4 = %f",Resultado2[4]);
    printf ("\nð5 = %f\n\n",Resultado2[5]);
    free (Resultado1);
    free(Resultado2);
    free(Matriz_Transposta);
    free(Matriz_Original);
    free(y);
    fclose (input);
}