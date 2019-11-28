#include <stdio.h>
#include <stdlib.h>


void LeArquivo(FILE *input, float *y, float **Matriz_Original, int TAM){
    char virgula;
    int i, j, para;
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
