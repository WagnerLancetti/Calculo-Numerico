#include <stdio.h>
#include <stdlib.h>
#include "Arquivos.h"


void LeArquivo(FILE *input, double *y, double **Matriz_Original, int TAM){
    char virgula;
    int i, j;
    for (i = 0; i < TAM; i++){
        Matriz_Original[i][0] = 1;
        fscanf (input, "%lf %c",&y[i], &virgula);
        for (j = 1; j < 6; j++){
            if (j == 5){
                fscanf(input,"%lf",&Matriz_Original[i][j]);
            }else{
                fscanf (input,"%lf %c",&Matriz_Original[i][j], &virgula);
            }
        }
    }
}

double **MatrizTesteRegressaoLinear(double **Matriz_Original, int TAM2, FILE *input){
    char virgula;
    int i,j;
    for (i = 0; i < TAM2; i++){
        for (j = 0; j < 6; j++){
            if (j == 5){
                fscanf(input,"%lf",&Matriz_Original[i][j]);
            }else{
                fscanf (input,"%lf %c",&Matriz_Original[i][j], &virgula);
            }
        }
    }
    return Matriz_Original;
}
