#include<stdio.h>

int quadrado(int valor){
    valor = valor * valor;
    return valor;
}

void main(){
    int q = quadrado(2);
    printf("%d", q);
}