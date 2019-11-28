#include <stdio.h>
#include <stdlib.h>


float **Inicializa_Matriz(float **Matriz, int linhas, int colunas){
    Matriz = (float**) malloc (linhas * sizeof(float*));
    for (int i = 0; i < linhas; i++){
        Matriz[i] = (float*) malloc (colunas *  sizeof(float));
    }
    return Matriz;
}

float *Inicializa_Vetor (float *y, int linhas){
    return (float*) malloc (linhas*sizeof(float));
}


float* Transposta_X_Funcao(float **Matriz_Transposta,float *y,float *resultado2,int TAM){
     for (int h = 0; h < 6; h++){ // h = LINHAS RESULTADO (Linha da transposta)
        resultado2[h] = 0;
        for (int k = 0; k < TAM; k++){ // K = FATOR QUE PERMITE A OPERACAO ENTRE AS MATRIZES (Coluna da transposta E Linha da original)
            resultado2[h] += Matriz_Transposta[h][k] * y[k]; 
        }
    }
    return resultado2;
}


float **Transposta_X_Original(float **Matriz_Transposta, float **Matriz_Original, float **resultado, int TAM){
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

float** GerarTransposta (float **Matriz_Original, int TAM){
    float **Matriz_Transposta = NULL;
    Matriz_Transposta = Inicializa_Matriz(Matriz_Transposta,6,TAM);
    for (int i = 0; i < 6;i++){
        for (int j = 0; j < TAM; j++){
            Matriz_Transposta[i][j] = Matriz_Original[j][i];
        }
    }
    return Matriz_Transposta;
}
   
