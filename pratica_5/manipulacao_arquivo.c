#include<stdio.h>
#include<string.h>

void main(){
    FILE *arquivo = fopen("dados.csv", "r");
    if(arquivo == NULL){
        printf("Erro ao abrir o arquivo!");
        return;
    }

    char cabecalho[100];    
    if(fgets(cabecalho, sizeof(cabecalho), arquivo) == NULL){
        printf("Erro ao ler o cabecalho!");
        return;
    }
    
    char linha[100];
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        char *nome = strtok(linha, ",");
        char *idade = strtok(NULL, ",");
        char* cidade = strtok(NULL, ",");
        printf("Nome:%s Idade:%s Cidade: %s\n", nome, idade, cidade);
    }

    fclose(arquivo);
}