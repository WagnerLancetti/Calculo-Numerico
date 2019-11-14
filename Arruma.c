#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[50],str2[50];// str2[50];
    FILE *input = fopen ("input.txt","r");
    FILE *output = fopen ("output.txt","w");
    int tam, k;
    while (!feof(input)){
        fgets(str1,50,input);
        tam  = strlen(str1);
        k = 0;
        for (int i = 1; i < tam-2; i++){
            if (str1[i] == ','){
                str2[k] = ',';
                k++;
                str2[k] = 32;
            }else{
                str2[k] = str1[i];
            }
            k++;
        }
        str1[0] = '\n';
        printf ("%s \n",str2);
        fputs (str2,output);
        fputs ("\n",output);
    }
    fclose (input);
    fclose (output);
    printf ("\n");
}