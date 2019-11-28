#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM 7

void Transposta_X_Funcao(float Matriz_Transposta[][TAM],float y[],float *resultado2){
     for (int h = 0; h < 6; h++){ // h = LINHAS RESULTADO (Linha da transposta)
        resultado2[h] = 0;
        for (int k = 0; k < TAM; k++){ // K = FATOR QUE PERMITE A OPERACAO ENTRE AS MATRIZES (Coluna da transposta E Linha da original)
            resultado2[h] += Matriz_Transposta[h][k] * y[k]; 
        }
    }
}


void Transposta_X_Original(float Matriz_Transposta[][TAM], float Matriz_Original[][6], float **resultado){
    // MULTIPLICACAO TRANSPOSTA X MATRIZ ORIGINAL
    for (int h = 0; h < 6; h++){ // h = LINHAS RESULTADO (Linha da transposta)
        for (int y = 0; y < 6; y++){  // Y = COLUNAS RESULTADO (Coluna da original)
            resultado[h][y] = 0;
            for (int k = 0; k < TAM; k++){ // K = FATOR QUE PERMITE A OPERACAO ENTRE AS MATRIZES (Coluna da transposta E Linha da original)
                resultado[h][y] += Matriz_Transposta[h][k] * Matriz_Original[k][y]; 
            }
        }
    }
}   

void GerarTransposta (float Matriz_Original[][6], float Matriz_Transposta[][TAM]){
    for (int i = 0; i < 6;i++){
        for (int j = 0; j < TAM; j++){
            Matriz_Transposta[i][j] = Matriz_Original[j][i];
        }
    }
}

void LeArquivo(FILE *input, float *y, float **Matriz_Original){
    char virgula;
    int i, j, tam, para;
    tam = TAM;
    // ___________________ LER O ARQUIVO ___________________ //
    for (i = 0; i < tam; i++){
        Matriz_Original[i][0] = 1;
        para  = 0;
        fscanf (input, "%f %c",&y[i], &virgula);
        if (y[i] < 0 ){
            para++;
        }
        for (j = 1; j < 6; j++){
            fscanf (input,"%f %c",&Matriz_Original[i][j], &virgula);
            if (Matriz_Original[i][j] < 0){
                para++;
            }
        }
        if (para != 0){
            i = i - 1;
        }
    }
}
    // ___________________ FIM DA LEITURA DE ARQUIVOS ___________________ //
/*
    GerarTransposta(Matriz_Original,Matriz_Transposta);
    printf ("\n\n MATRIZ TRANSPOSTA:");
    for (i = 0; i < 6; i++){
        printf ("\n");
        for (j = 0; j < TAM; j++){
            printf ("%.3f  ",Matriz_Transposta[i][j]);
        }
    }
    resultado = (float **)malloc (6 * sizeof(float*));
    for (int i = 0; i < 6; i++){
        resultado[i] = (float*)malloc (6 * sizeof(float));
    }
    Transposta_X_Original(Matriz_Transposta,Matriz_Original,resultado);
    printf ("\n\nTRANSPOSTA X ORIGINAL: ");
    for (i = 0; i < 6; i++){
        printf ("\n");
        for (j = 0; j < 6; j++){
            printf ("%f  ",resultado[i][j]);
        }
    }
    resultado2 = (float*)malloc (6 * sizeof(float));
    Transposta_X_Funcao(Matriz_Transposta,y,resultado2);
    printf ("\n\nTRANSPOSTA X FUNCAO: \n");
    for (i = 0; i < 6; i++){
        printf ("%f\n",resultado2[i]);
    }
    
}*/
 
/* *************************************************** FIM ARQUIVOS *************************************************** */

float **Inicializa_Matriz(float **Matriz_Original){
    Matriz_Original = (float**) malloc (TAM*sizeof(float*));
    for (int i = 0; i < TAM; i++){
        Matriz_Original[i] = (float*) malloc (6 *  sizeof(float));
    }
    return Matriz_Original;
}

float *Inicializa_Vetor (float *y){
    return (float*) malloc (TAM*sizeof(float));
}

int main(){
    float *y = NULL;
    y = Inicializa_Vetor(y);
    float **Matriz_Original = NULL;
    Matriz_Original = Inicializa_Matriz(Matriz_Original);
    FILE *input = fopen ("input.txt","r");
    LeArquivo(input,y,Matriz_Original);
    printf ("\nVALORES DE F:\n");
    for (int i = 0; i < TAM; i++){
        printf ("%.3f\n",y[i]);
    }
    printf ("\nMATRIZ ORIGINAL:");
    for (int i = 0; i < TAM; i++){
        printf ("\n");
        for (int j = 0; j < 6; j++){
            printf ("%.3f  ",Matriz_Original[i][j]);
        }
    }
    fclose (input);
}