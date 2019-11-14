#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str1[200],str2[100];
    FILE *input = fopen ("input.txt","r");
    FILE *output = fopen ("output.txt","w");
    int tam, k,i;
    while (!feof(input)){
        fscanf (input, "%s",str1);
        tam  = strlen(str1);
        k = 0;
        if (str1[0] == ','){
            i = 1;
        }
        else if (str1[1] == ','){
            i = 2;
        }else{
            i = 0;
        }
        for (;i < tam; i++){
            if (str1[i] == ','){
                str2[k] = ',';
                k++;
                str2[k] = 32;
            }else{
                str2[k] = str1[i];
            }
            k++;
        }
        str2[k] = '\0';
        fputs (str2,output);
        fputs ("\n",output);
        
    }
    fclose (input);
    fclose (output);
}