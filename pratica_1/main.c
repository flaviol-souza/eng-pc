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
    printf("\n%-10s %-20s %-10s %-10s\n","Codigo","Nome","Quantidade", "V. Unitario");
    struct COMPONENT comp;
    int i;
    for(i = 0; i < lastComponent; i++){
        comp = components[i];
        printf("\n%-10i %-20s %-10d %-10.2f",comp.code, comp.name, comp.quantity, comp.unit_value);
    }
}

struct COMPONENT* findComponent(struct COMPONENT components[], int code){
    int i = 0;    
    for(i = 0; i < lastComponent; i++){
        if(components[i].code == code){
            return &components[i];
        }
    }
    return NULL;
}

void searchComponent(struct COMPONENT components[]){
    int code;
    printf("\n\tInforme o codigo do componente desejado:");
    scanf("%d", &code);
    struct COMPONENT* component = findComponent(components, code);
    if(component != NULL){
        printf("\n\tComponente (%d) %s contem %d quantidades de valor %f.", component->code, component->name, component->quantity, component->unit_value);
    } else {
        printf("\n\tNao foi encontrado nenhum componente com o codigo %d", code);
    }
}

void editComponent(struct COMPONENT components[]){
    int code;
    printf("\n\tEDICAO DE COMPONENTE");
    printf("\n\tInforme o codigo do componente desejado:");
    scanf("%d", &code);
    struct COMPONENT* editComp = findComponent(components, code);
    if(editComp == NULL){
        printf("COMPONENT NAO ENCONTRADO");    
    } else {
        printf("COMPONENT ENCONTRADO");
        printf("\n\tInforme o novo nome do componente %s:",editComp->name);
        scanf("%s",editComp->name);
        printf("\n\tInforme a nova quantidade do componente:");
        scanf("%d", &editComp->quantity);
        printf("\n\tInforme o novo valor unitario do componente:");
        scanf("%f", &editComp->unit_value);  
        printf("\n\nComponente %s (%d) Editado com Sucesso!",editComp->name, editComp->code);
    }  
}

void deleteComponent(struct COMPONENT components[]){
    int code;
    printf("\n\nEXCLUSAO DE COMPONENTE");
    printf("\n\tInforme o codigo do componente a ser excluido:");
    scanf("%d", &code);
    int i = 0;
    for(i=0; i < lastComponent; i++){
        if(components[i].code >= code){
           components[i] = components[i+1];            
        }
    }
    lastComponent--;
    printf("\n\tComponente de codigo %d excluido com sucesso!", code);    
}

void main()
{
    struct COMPONENT components[MAX_COMPONENTS];
    int opcao; // receberá a seleção do usuário
    do {
        printf("\n1. Adicionar Componente");
        printf("\n2. Listar Componentes");
        printf("\n3. Buscar Componente");
        printf("\n4. Editar Componente");
        printf("\n5. Excluir Componente");
        printf("\n0. Sair\n");

        printf("\tEscolha uma opcao:");
        scanf("%d", &opcao);
        printf("\nA opcao escolhida foi %d\n", opcao);
        switch (opcao)
        {
            case 1:
                addComponent(components);
                break;
            case 2:
                listComponents(components);
                break;
            case 3:
                searchComponent(components);
                break;
            case 4:
                editComponent(components);
                break;
            case 5:
                deleteComponent(components);
                break;
            case 0:
                printf("\ntchau e benca");
                break;
            default:
                printf("\nOpcao invalida");
                break;
        }
    }while (opcao != 0);
}