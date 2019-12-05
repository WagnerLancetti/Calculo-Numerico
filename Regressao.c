#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Regressao.h"


void TesteRegressaoLinear(double **Matriz_Regressao,double *Resultado2, int TAM2){
    int i, j;
    double *soma,erro,maxerro=0;
    soma = (double*) calloc (TAM2,sizeof(double));
    for (i = 0; i < TAM2; i++){
        soma[i] = Resultado2[0];
        for (j = 1; j < 6; j++){
            soma[i] = soma[i] + Matriz_Regressao[i][j] * Resultado2[j];
        }
    }
    char str[] = "Valor REAL  |  Valor REGRESSAO  |  ERRO";
    FILE *output = fopen("output.txt","w");
    fprintf(output,"%s %s",str, "\n");
    char str1[] = "                  ";
    char str3[] = "                  ";
    for (i = 0; i < TAM2; i++){
        erro = soma[i] - Matriz_Regressao[i][0];
        erro = fabs(erro);
        if (maxerro < erro){
            maxerro = erro;
        }
        fprintf(output,"%lf %s %lf %s %lf",Matriz_Regressao[i][0],str1, soma[i],str3,erro);
        fprintf(output,"%s", "\n");
    }
    char str2[] = "Maior erro: ";
    fprintf(output,"%s%s%lf","\n",str2,maxerro);
    printf ("\n TAM = %i \n",TAM2);
}