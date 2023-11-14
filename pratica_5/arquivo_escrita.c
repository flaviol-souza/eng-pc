#include<stdio.h>

void main(){
    FILE *arquivo = fopen("exemplo.txt", "a");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo");
        return;
    }

    fprintf(arquivo, "Olá Mundo!\n");
    fclose(arquivo);
}