#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de dados para representar uma tarefa
typedef struct TASK {
    char description[100];
    int priority;
    struct TASK* next;
} TASK;

// Função para inserir uma tarefa na lista encadeada em ordem de prioridade
void insertTask(TASK** head, char* description, int priority) {
    TASK* newTask = (TASK*)malloc(sizeof(TASK));
    strcpy(newTask->description, description);
    newTask->priority = priority;
    newTask->next = NULL;

    if (*head == NULL || priority < (*head)->priority) {
        newTask->next = *head;
        *head = newTask;
    } else {
        TASK* current = *head;
        while (current->next != NULL && priority >= current->next->priority) {
            current = current->next;
        }
        newTask->next = current->next;
        current->next = newTask;
    }
}

// Função para remover uma tarefa da lista
void removeTask(TASK** head, char* description) {
    if (*head == NULL) {
        return;
    }

    if (strcmp((*head)->description, description) == 0) {
        TASK* temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    TASK* current = *head;
    while (current->next != NULL && strcmp(current->next->description, description) != 0) {
        current = current->next;
    }

    if (current->next != NULL) {
        TASK* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

// Função para exibir todas as tarefas na lista
void displayTasks(TASK* head) {
    if (head == NULL) {
        printf("Lista de tarefas vazia.\n");
        return;
    }

    printf("Tarefas:\n");
    while (head != NULL) {
        printf("Descrição: %s, Prioridade: %d\n", head->description, head->priority);
        head = head->next;
    }
}

void main() {
    TASK* taskList = NULL;
    int choice;
    char description[100];
    int priority;

    do {
        printf("\nMenu:\n");
        printf("1. Adicionar Tarefa\n");
        printf("2. Remover Tarefa\n");
        printf("3. Exibir Tarefas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &choice);

        switch (choice) {
            case 0:
                printf("Saindo do programa.\n");
                break;
            case 1:
                printf("Digite a descrição da tarefa: ");
                scanf(" %[^\n]", description);
                printf("Digite a prioridade da tarefa: ");
                scanf("%d", &priority);
                insertTask(&taskList, description, priority);
                break;
            case 2:
                printf("Digite a descrição da tarefa a ser removida: ");
                scanf(" %[^\n]", description);
                removeTask(&taskList, description);
                break;
            case 3:
                displayTasks(taskList);
                break;            
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (choice != 4);

    // Liberar a memória alocada
    while (taskList != NULL) {
        TASK* temp = taskList;
        taskList = taskList->next;
        free(temp);
    }
}
