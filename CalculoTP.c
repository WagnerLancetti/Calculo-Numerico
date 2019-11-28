#include <stdio.h>
#include <stdlib.h>

#define TAM 7


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


float* Transposta_X_Funcao(float **Matriz_Transposta,float *y,float *resultado2){
     for (int h = 0; h < 6; h++){ // h = LINHAS RESULTADO (Linha da transposta)
        resultado2[h] = 0;
        for (int k = 0; k < TAM; k++){ // K = FATOR QUE PERMITE A OPERACAO ENTRE AS MATRIZES (Coluna da transposta E Linha da original)
            resultado2[h] += Matriz_Transposta[h][k] * y[k]; 
        }
    }
    return resultado2;
}


float **Transposta_X_Original(float **Matriz_Transposta, float **Matriz_Original, float **resultado){
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

float** GerarTransposta (float **Matriz_Original){
    float **Matriz_Transposta = NULL;
    Matriz_Transposta = Inicializa_Matriz(Matriz_Transposta,6,TAM);
    for (int i = 0; i < 6;i++){
        for (int j = 0; j < TAM; j++){
            Matriz_Transposta[i][j] = Matriz_Original[j][i];
        }
    }
    return Matriz_Transposta;
}

void LeArquivo(FILE *input, float *y, float **Matriz_Original){
    char virgula;
    int i, j, para;
    // ___________________ LER O ARQUIVO ___________________ //
    for (i = 0; i < TAM; i++){
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

void ArrumaLinha(float **Matriz, float *Funcao, int i){
    float Divisor;
    if (Matriz[i][i] != 1 && Matriz[i][i] != 0){
        Divisor = Matriz[i][i];
        for (int j = 0; j < 6; j++){
            Matriz[i][j] = Matriz[i][j] / Divisor; 
        }
        Funcao[i] = Funcao[i] / Divisor;
    }
}

void ArrumaColuna (float **Matriz, float *Funcao, int i){
    float Multiplicador;
    for (int j = 0; j < 6; j++){
        if (Matriz[i][j] != 0 && i != j){
            Multiplicador = Matriz[i][j];

        }
    }
}

void ResolveSistemaLinear (float **Matriz, float *Funcao){
    for (int i = 0; i < 6; i++){        
        ArrumaLinha(Matriz,Funcao,i);
        //ArrumaColuna(Matriz,Funcao,i);
    }
    for (int i = 0; i < 6; i++){
        printf ("\n");
        for (int j = 0; j < 6; j++){
            printf ("%.3f  ",Matriz[i][j]);
        }
    }
}

    // ___________________ FIM DA LEITURA DE ARQUIVOS ___________________ //
 
/* *************************************************** FIM ARQUIVOS *************************************************** */

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

    /*printf ("\nVALORES DE F:\n");
    for (int i = 0; i < TAM; i++){
        printf ("%.3f\n",y[i]);
    }
    printf ("\nMATRIZ ORIGINAL:");
    for (int i = 0; i < TAM; i++){
        printf ("\n");
        for (int j = 0; j < 6; j++){
            printf ("%.3f  ",Matriz_Original[i][j]);
        }
    }*/
    Matriz_Transposta = GerarTransposta(Matriz_Original);
    /*
    printf ("\n\n MATRIZ TRANSPOSTA:");
    for (int i = 0; i < 6; i++){
        printf ("\n");
        for (int j = 0; j < TAM; j++){
            printf ("%.3f  ",Matriz_Transposta[i][j]);
        }
    }*/
    Resultado1 = Inicializa_Matriz(Resultado1,6,6);
    Resultado2 = Inicializa_Vetor(Resultado2,6);
    Resultado1 = Transposta_X_Original(Matriz_Transposta,Matriz_Original,Resultado1);
    Resultado2 = Transposta_X_Funcao(Matriz_Transposta,y,Resultado2);
    //ResolveSistemaLinear(Resultado1,Resultado2);
    /*
    printf ("\n Resultado2 \n");
    for (int i = 0; i < 6; i++){
        printf ("\n");
        for (int j = 0; j < 6; j++){
            printf ("%f  ",Resultado1[i][j]);
        }
    }

    printf ("\n\n Resultado1 \n");
    for (int i = 0; i < 6; i++){
        printf ("%f\n",Resultado2[i]);
    }*/

    free (Resultado1);
    free(Resultado2);
    free(Matriz_Transposta);
    free(Matriz_Original);
    free(y);
    fclose (input);
}
