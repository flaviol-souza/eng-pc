/*Implemente uma estrutura para representar um nó 
da lista com um campo inteiro para armazenar os 
dados e um ponteiro para o próximo nó.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
    int data;
    struct NODE* next;
} NODE;

NODE* insertNode(int value, NODE* head){
    NODE* newNode = malloc(sizeof(NODE));
    newNode->data = value;
    newNode->next = head;
    return newNode;
}

void printNode(NODE* head){
    NODE* current = head;
    while(current != NULL){
        printf("|%d|%p|->", current->data, current->next);   
        current = current->next;
    }
}

void main(){
    NODE* list = NULL;
    list = insertNode(12, list);
    list = insertNode(5, list);
    list = insertNode(7, list);

    printNode(list);
}