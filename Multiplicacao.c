#include <stdio.h>
#include <stdlib.h>
#include "Multiplicacao.h"


double **Inicializa_Matriz(double **Matriz, int linhas, int colunas){
    Matriz = (double**) malloc (linhas * sizeof(double*));
    for (int i = 0; i < linhas; i++){
        Matriz[i] = (double*) malloc (colunas *  sizeof(double));
    }
    return Matriz;
}


double *Inicializa_Vetor (double *y, int linhas){
    return (double*) malloc (linhas*sizeof(double));
}


double* Transposta_X_Funcao(double **Matriz_Transposta,double *y,double *resultado2, int TAM){
     for (int h = 0; h < 6; h++){ // h = LINHAS RESULTADO (Linha da transposta)
        resultado2[h] = 0;
        for (int k = 0; k < TAM; k++){ // K = FATOR QUE PERMITE A OPERACAO ENTRE AS MATRIZES (Coluna da transposta E Linha da original)
            resultado2[h] += Matriz_Transposta[h][k] * y[k]; 
        }
    }
    return resultado2;
}


double **Transposta_X_Original(double **Matriz_Transposta, double **Matriz_Original, double **resultado, int TAM){
    for (int h = 0; h < 6; h++){ // h = LINHAS RESULTADO (Linha da transposta)
        for (int y = 0; y < 6; y++){  // Y = COLUNAS RESULTADO (Coluna da original)
            resultado[h][y] = 0;
            for (int k = 0; k < TAM; k++){ // K = FATOR QUE PERMITE A OPERACAO ENTRE AS MATRIZES (Coluna da transposta E Linha da original)
                resultado[h][y] += Matriz_Transposta[h][k] * Matriz_Original[k][y]; 
            }
        }
    }
    return resultado;
}  

double** GerarTransposta (double **Matriz_Original, int TAM){
    double **Matriz_Transposta = NULL;
    Matriz_Transposta = Inicializa_Matriz(Matriz_Transposta,6,TAM);
    for (int i = 0; i < 6;i++){
        for (int j = 0; j < TAM; j++){
            Matriz_Transposta[i][j] = Matriz_Original[j][i];
        }
    }
    return Matriz_Transposta;
}
   
