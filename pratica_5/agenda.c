#include<stdio.h>
#include<string.h>

#define NOME_ARQUIVO_AGENDA "agenda.csv"

char *manipuladorAgenda = "w";
int contadorContatosAgenda = 0;

typedef struct {
    int id;
    char nome[100];
    char telefone[15]; //(XX)9XXXX-XXXX
} CONTATO;

int contaContatosAgenda(){
    FILE *arquivo = fopen(NOME_ARQUIVO_AGENDA, "r");
    if(arquivo == NULL){
        printf("Erro ao ler o arquivo!");
        return -1;
    }

    int cont = 0;
    char linha[120];
    while(fgets(linha, sizeof(linha), arquivo) != NULL){
        if(strcmp(linha, "\n") != 0){
            cont++;
        }
    }
    fclose(arquivo);
    return cont;
}

FILE* manipularArquivo(){
    return fopen(NOME_ARQUIVO_AGENDA, manipuladorAgenda);
}

void cadastaContato(){
    FILE *agenda = manipularArquivo();
    if(agenda == NULL){
        printf("Erro ao abrir o arquivo da agenda!");
        return;
    }

    CONTATO novoContato;
    novoContato.id = ++contadorContatosAgenda;
    printf("\n\n\tDigite o nome do contato: ");
    scanf("%99s", novoContato.nome);
    printf("\tDigite o numero do telefone: ");
    scanf("%14s", novoContato.telefone);

    fprintf(agenda, "%d,%s,%s\n", novoContato.id, novoContato.nome, novoContato.telefone);

    fclose(agenda);
    printf("Cadastro realizado com sucesso!");
}

void listaConstatos(){
    FILE *arquivo = fopen(NOME_ARQUIVO_AGENDA, "r");
    if(arquivo == NULL){
        printf("Erro ao ler o arquivo!");
        return;
    }
    //rewind(arquivo);//reposiciona o arquivo para o inicio
    CONTATO contato;

    printf("\nLista de Contatos 2023\n");
    printf("|%-3s|%-20s|%-15s|\n", "Id", "Nome", "Telefone");
    printf("|---|--------------------|---------------|\n");

    while(fscanf(arquivo, "%d,%99[^,],%14[^\n]",&contato.id, contato.nome, contato.telefone) == 3){
        printf("|%-3d|%-20s|%-15s|\n", contato.id, contato.nome, contato.telefone);
    }

    fclose(arquivo);
}

void buscarContatoNome(){
    char nome[100];
    printf("\n\n\tDigite o nome do contato:");
    scanf("%s", nome);
    
    FILE *arquivo = fopen(NOME_ARQUIVO_AGENDA, "r");
    if(arquivo == NULL){
        printf("Erro ao ler o arquivo");
        return;
    }

    CONTATO contato;
    int encontrado = 0;
    while(fscanf(arquivo, "%d,%99[^,],%14[^\n]", &contato.id, contato.nome, contato.telefone) == 3){
        if(strstr(contato.nome, nome)){
            if(!encontrado){
                printf("|%-3s|%20s|%-15s|\n","Id", "Nome", "Telefone");
                printf("|---|--------------------|---------------|\n");
            }                
            printf("|%-3d|%-20s|%15s|\n", contato.id, contato.nome, contato.telefone);
            encontrado++;
        }
    }

    if(!encontrado){
        printf("\n\nNenhum contato encontrado!");
    } else{
        printf("\n\n%d Contato(s) encontrado(s)", encontrado);
    }

    fclose(arquivo);    
}

void main(){
    int qtdContatos = contaContatosAgenda();
    if(qtdContatos > 0){
        manipuladorAgenda = "a";
        contadorContatosAgenda = qtdContatos;
    }
    int opcao;
    do {
        printf("\nEscolha uma opcao:");
        printf("\n\t1. Cadastre um contato.");
        printf("\n\t2. Consulte a agenda de contatos.");
        printf("\n\t3. Consulte o contato por nome.");
        printf("\n\t0. Sair.\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 0:
                printf("\nSaindo...");
                break;
            case 1:
                cadastaContato();
                break;
            case 2:
                listaConstatos();
                break; 
            case 3:
                buscarContatoNome();
                break;
            default:
                printf("\nOpcao invalida!");
        }
    }while(opcao != 0);
}