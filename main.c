#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Arquivos.h"
#include "Multiplicacao.h"
#include "SistemaLinear.h"
#include "Regressao.h"

int main(){
    int Tamanho = 43444,TAM,TAM2;
    TAM = Tamanho * 0.7;
    TAM2 = Tamanho - TAM;
    double *y = NULL;
    y = Inicializa_Vetor(y,TAM);
    double **Matriz_Original = NULL;
    Matriz_Original = Inicializa_Matriz(Matriz_Original,TAM,6);
    double **Matriz_Transposta = NULL;
    double **Resultado1 = NULL;
    double *Resultado2 = NULL;
    FILE *input = fopen ("input.txt","r");
    LeArquivo(input,y,Matriz_Original,TAM);
    Matriz_Transposta = GerarTransposta(Matriz_Original,TAM);
    Resultado1 = Inicializa_Matriz(Resultado1,6,6);
    Resultado2 = Inicializa_Vetor(Resultado2,6);
    Resultado1 = Transposta_X_Original(Matriz_Transposta,Matriz_Original,Resultado1,TAM);
    Resultado2 = Transposta_X_Funcao(Matriz_Transposta,y,Resultado2,TAM);
    free(Matriz_Transposta);
    free(y);
    Resultado2 = ResolveSistemaLinear(Resultado1,Resultado2);
    free(Resultado1);
    free(Matriz_Original);
    printf ("\nIntercept = %lf",Resultado2[0]);
    printf ("\na1 = %lf",Resultado2[1]);
    printf ("\na2 = %lf",Resultado2[2]);
    printf ("\na3 = %lf",Resultado2[3]);
    printf ("\na4 = %lf",Resultado2[4]);
    printf ("\na5 = %lf\n\n",Resultado2[5]);
    Matriz_Original = Inicializa_Matriz(Matriz_Original,TAM2,6);
    Matriz_Original = MatrizTesteRegressaoLinear(Matriz_Original,TAM2,input);
    TesteRegressaoLinear(Matriz_Original,Resultado2,TAM2);
    
    free(Resultado2);
    fclose(input);
}
