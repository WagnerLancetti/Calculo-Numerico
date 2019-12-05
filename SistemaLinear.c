#include <stdio.h>
#include <stdlib.h>
#include "SistemaLinear.h"

void ArrumaLinha(double **Matriz, double *Funcao, int i){
    double Divisor;
    if (Matriz[i][i] != 1 && Matriz[i][i] != 0){
        Divisor = Matriz[i][i];
        for (int j = 0; j < 6; j++){
            Matriz[i][j] = Matriz[i][j] / Divisor; 
        }
        Funcao[i] = Funcao[i] / Divisor;
    }
}

void ArrumaColuna (double **Matriz, double *Funcao, int i){
    double Multiplicador;
    for (int j = 0; j < 6; j++){
        if (Matriz[j][i] != 0 && i != j){
            Multiplicador = Matriz[j][i];
            for(int h = 0; h < 6; h++){
                Matriz[j][h] = Matriz[j][h] - Matriz[i][h] * Multiplicador; 
            }
            Funcao[j] = Funcao[j] - Funcao[i] * Multiplicador;
        }
    }
}

double* ResolveSistemaLinear (double **Matriz, double *Funcao){
    for (int i = 0; i < 6; i++){        
        ArrumaLinha(Matriz,Funcao,i);
        ArrumaColuna(Matriz,Funcao,i);
    }
    return Funcao;
} 