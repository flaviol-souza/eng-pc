#include <stdio.h>
#define MAX_COMPONENTS 100

int sequenceCode = 0;
int lastComponent = 0;

struct COMPONENT {
    int code;
    char name[50];
    int quantity;
    float unit_value;
};

void addComponent(struct COMPONENT components[]){
        struct COMPONENT newComponent;
        newComponent.code = ++sequenceCode;
        printf("\n Informe o nome do componente (no maximo de 50 letras):\t");
        scanf("%s", newComponent.name);
        printf("\n Informe a quantidade do componente %s:\t", newComponent.name); 
        scanf("%d", &newComponent.quantity);
        printf("\n Informe o valor unitario do componente %s:\t", newComponent.name);
        scanf("%f", &newComponent.unit_value);

        printf("\n\n RESUMO do novo componente");
        printf("\n\t-Nome:(%d) %s", newComponent.code, newComponent.name);
        printf("\n\t-Quantidade:%d", newComponent.quantity);
        printf("\n\t-Valor Unitario:%2f", newComponent.unit_value);

        components[lastComponent++] = newComponent;
}

void listComponents(struct COMPONENT components[]){
    printf("\n\nLista de Componentes");
    //printf("\nCodigo,Nome,Quantidade");
    printf("\n%-10s %-20s %-10s %-10s\n","Codigo","Nome","Quantidade", "V. Unitario");
    struct COMPONENT comp;
    int i;
    for(i = 0; i < lastComponent; i++){
        comp = components[i];
        //printf("\n%i,%s,%d",comp.code, comp.name, comp.quantity);
        printf("\n%-10i %-20s %-10d %-10.2f",comp.code, comp.name, comp.quantity, comp.unit_value);
    }
}

void main()
{
    struct COMPONENT components[MAX_COMPONENTS];
    int opcao; // receberá a seleção do usuário
    do {
        printf("\n1. Adicionar Componente");
        printf("\n2. Listar Componentes");
        printf("\n3. Editar Componente");
        printf("\n4. Excluir Componente");
        printf("\n0. Sair\n");

        printf("\tEscolha uma opcao:");
        scanf("%d", &opcao);
        printf("\nA opcao escolhida foi %d\n", opcao);
        switch (opcao)
        {
            case 1:
                addComponent(components);
                printf("%d", opcao);
                break;
            case 2:
                listComponents(components);
                break;
            case 3:
                printf("\nEscolhe editar");
                break;
            case 4:
                printf("\nEscolhe excluir");
                break;
            case 0:
                printf("\ntchau e bencao");
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opcao != 0);

}