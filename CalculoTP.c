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


float* Transposta_X_Funcao(float **Matriz_Transposta,float *y,float *resultado2, int TAM){
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

void LeArquivo(FILE *input, float *y, float **Matriz_Original, int TAM){
    char virgula;
    int i, j;
    for (i = 0; i < TAM; i++){
        Matriz_Original[i][0] = 1;
        fscanf (input, "%f %c",&y[i], &virgula);
        for (j = 1; j < 6; j++){
            if (j == 5){
                fscanf(input,"%f",&Matriz_Original[i][j]);
            }else{
                fscanf (input,"%f %c",&Matriz_Original[i][j], &virgula);
            }
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
        if (Matriz[j][i] != 0 && i != j){
            Multiplicador = Matriz[j][i];
            for(int h = 0; h < 6; h++){
                Matriz[j][h] = Matriz[j][h] - Matriz[i][h] * Multiplicador; 
            }
            Funcao[j] = Funcao[j] - Funcao[i] * Multiplicador;
        }
    }
}

float* ResolveSistemaLinear (float **Matriz, float *Funcao){
    for (int i = 0; i < 6; i++){        
        ArrumaLinha(Matriz,Funcao,i);
        ArrumaColuna(Matriz,Funcao,i);
    }
    return Funcao;
} 

float **MatrizTesteRegressaoLinear(float **Matriz_Original, int TAM2, FILE *input){
    char virgula;
    int i,j;
    for (i = 0; i < TAM2; i++){
        for (j = 0; j < 6; j++){
            if (j == 5){
                fscanf(input,"%f",&Matriz_Original[i][j]);
            }else{
                fscanf (input,"%f %c",&Matriz_Original[i][j], &virgula);
            }
        }
    }
    return Matriz_Original;
}

void TesteRegressaoLinear(float **Matriz_Regressao,float *Resultado2, int TAM2){
    int i, j;
    double *soma;
    soma = (double*) calloc (TAM2,sizeof(double));
    for (i = 0; i < TAM2; i++){
        soma[i] = Resultado2[0];
        for (j = 1; j < 6; j++){
            soma[i] = soma[i] + Matriz_Regressao[i][j] * Resultado2[j];
        }
    }
    char str[] = "Valor REAL |  Valor REGRESSAO";
    
    FILE *output = fopen("output.txt","w");
    fprintf(output,"%s %s",str, "\n");
    char str1[] = "               ";
    for (i = 0; i < TAM2; i++){
        fprintf(output,"%f %s %f",Matriz_Regressao[i][0],str1, soma[i]);
        fprintf(output,"%s", "\n");
    }
    printf ("\n TAM = %i \n",TAM2);
}


int main(){
    int Tamanho = 5000,TAM,TAM2;
    TAM = Tamanho * 0.7;
    TAM2 = Tamanho - TAM;
    float *y = NULL;
    y = Inicializa_Vetor(y,TAM);
    float **Matriz_Original = NULL;
    Matriz_Original = Inicializa_Matriz(Matriz_Original,TAM,6);
    float **Matriz_Transposta = NULL;
    float **Resultado1 = NULL;
    float *Resultado2 = NULL;
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
    printf ("\nIntercept = %f",Resultado2[0]);
    printf ("\na1 = %f",Resultado2[1]);
    printf ("\na2 = %f",Resultado2[2]);
    printf ("\na3 = %f",Resultado2[3]);
    printf ("\na4 = %f",Resultado2[4]);
    printf ("\na5 = %f\n\n",Resultado2[5]);
    Matriz_Original = Inicializa_Matriz(Matriz_Original,TAM2,6);
    Matriz_Original = MatrizTesteRegressaoLinear(Matriz_Original,TAM2,input);
    TesteRegressaoLinear(Matriz_Original,Resultado2,TAM2);
    
    free(Resultado2);
    fclose(input);
}
