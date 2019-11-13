#include <stdio.h>
#include <stdlib.h>

#define TAM 6 

void GerarTransposto (float mat[][TAM]){
    float matT[TAM][2];
    for (int i = 0; i < TAM;i++){
        for (int j = 0; j < 2; j++){
            matT[i][j] = mat[j][i];
        }
    }
    printf ("\n MATRIZ TRANSPOSTA: \n\n");
    for (int i = 0; i < TAM; i++){
        printf ("\n");
        for (int j = 0; j < 2; j++){
            printf ("%f  ",matT[i][j]);
        }
    }
}

void LeArquivo(FILE *input){
    float mat[2][TAM];
    char virgula;
    int i, j;
    for (i = 0; i < 2; i++){
        for (j = 0; j < TAM; j++){
            fscanf (input,"%f %c",&mat[i][j], &virgula);
        }
    }
    printf ("\n\n MATRIZ ORIGINAL: \n\n");
    for (i = 0; i < 2; i++){
        printf ("\n");
        for (j = 0; j < TAM; j++){
            printf ("%f  ",mat[i][j]);
        }
    }
    GerarTransposto(mat);
    printf ("\n");
}
 

  // 6 dados que serão lidos, separados por virgulas
int main(){
    FILE *input = fopen ("input.txt","r");
    LeArquivo(input);
}