/*Neste exercício, crie um tipo abstrato de dados (TAD) 
em C para representar uma pilha de números inteiros.*/
#include<stdio.h>

#define MAX_STACK 100
typedef struct STACK {
    int data[MAX_STACK];
    int top;
} STACK;

void initStack(STACK *stack){
    stack->top = -1; //Pilha vazia
}

int isEmpty(STACK *stack) {
    return stack->top == -1; // 0 = Falso / 0 != Verdadeiro
}

int isFull(STACK *stack){
    return stack->top == MAX_STACK - 1;
}

void push(STACK* stack, int value){
    if(isFull(stack)){
        printf("A pilha esta cheia\n");
    } else {
       //stack->data[++stack->top] = value; 
       stack->top = stack->top + 1; //++stack->top
       stack->data[stack->top] = value; 
    }
}

int pop(STACK* stack){
    if(isEmpty(stack)){
        printf("A pilha esta vazia!\n");
        return -1;
    } else {
        //return stack->data[stack->top--];
        int data_temp = stack->data[stack->top];
        stack->top = stack->top - 1; //stack->top--;
        return data_temp;
    }
}

void printStack(STACK *stack){
    int i = stack->top;
    while(i >= 0){
        printf("\n|%d|",stack->data[i]);
        i--;
    }
}

void main(){
    STACK stack;
    initStack(&stack);
    push(&stack, 12);
    push(&stack, 5);
    push(&stack, 7);
    push(&stack, 9);
    push(&stack, 42);
    printStack(&stack);

    printf("\n\npop values");
    pop(&stack);
    pop(&stack);
    printStack(&stack);
}