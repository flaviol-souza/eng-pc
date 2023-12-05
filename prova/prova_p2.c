#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codigoCliente;
    char codigoOperacao; // 'V' para Venda, 'C' para Compra
    int quantidadeTitulos;
    float valorUnitario;
} OPERACAO;

void lerOperacoes(OPERACAO operacoes[], int *totalOperacoes) {
    FILE *arquivo = fopen("operacoes.csv", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de operacoes.\n");
        return;
    }

    fscanf(arquivo, "%*s"); // Ignora o cabeçalho

    while (fscanf(arquivo, "%d,%c,%d,%f", &operacoes[*totalOperacoes].codigoCliente,
                  &operacoes[*totalOperacoes].codigoOperacao,
                  &operacoes[*totalOperacoes].quantidadeTitulos,
                  &operacoes[*totalOperacoes].valorUnitario) == 4) {
        (*totalOperacoes)++;
    }

    fclose(arquivo);
}

float calcularSaldo(OPERACAO operacoes[], int totalOperacoes, int codigoCliente) {
    float saldo = 0.0;

    for (int i = 0; i < totalOperacoes; i++) {
        if (operacoes[i].codigoCliente == codigoCliente) {
            if (operacoes[i].codigoOperacao == 'C') {
                saldo += operacoes[i].quantidadeTitulos * operacoes[i].valorUnitario;
            } else if (operacoes[i].codigoOperacao == 'V') {
                saldo -= operacoes[i].quantidadeTitulos * operacoes[i].valorUnitario;
            }
        }
    }

    return saldo;
}

void listarResultados(OPERACAO operacoes[], int totalOperacoes) {
    printf("\nNúmero Cliente | Saldo Apurado | Tipo de Saldo\n");
    printf("----------------------------------------------\n");

    for (int i = 0; i < totalOperacoes; i++) {
        float saldo = calcularSaldo(operacoes, totalOperacoes, operacoes[i].codigoCliente);
        char tipoSaldo = (saldo >= 0) ? 'C' : 'D';

        printf("%-15d | %-13.2f | %-12c\n",
               operacoes[i].codigoCliente, saldo, tipoSaldo);
    }
}

void gerarArquivoResultados(OPERACAO operacoes[], int totalOperacoes) {
    FILE *arquivo = fopen("resultados.txt", "w");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de resultados.\n");
        return;
    }

    fprintf(arquivo, "Número Cliente | Saldo Apurado | Tipo de Saldo\n");
    fprintf(arquivo, "----------------------------------------------\n");

    for (int i = 0; i < totalOperacoes; i++) {
        float saldo = calcularSaldo(operacoes, totalOperacoes, operacoes[i].codigoCliente);
        char tipoSaldo = (saldo >= 0) ? 'C' : 'D';

        fprintf(arquivo, "%-15d | %-13.2f | %-12c\n",
                operacoes[i].codigoCliente, saldo, tipoSaldo);
    }

    fclose(arquivo);
}

int main() {
    OPERACAO operacoes[100]; // Assumindo que teremos no máximo 100 operações
    int totalOperacoes = 0;

    lerOperacoes(operacoes, &totalOperacoes);

    int escolha;
    do {
        printf("\nMenu Interativo\n");
        printf("a) Gerar relatório de saldo de operações por cliente.\n");
        printf("b) Listar saldo de operações por cliente.\n");
        printf("c) Sair do programa.\n");
        printf("Escolha: ");
        scanf(" %c", &escolha);

        switch (escolha) {
            case 'a':
                gerarArquivoResultados(operacoes, totalOperacoes);
                printf("Relatório gerado com sucesso! (Veja o arquivo resultados.txt)\n");
                break;
            case 'b':
                listarResultados(operacoes, totalOperacoes);
                break;
            case 'c':
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (escolha != 'c');

    return 0;
}