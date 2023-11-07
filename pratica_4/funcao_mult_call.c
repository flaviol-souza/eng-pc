#include<stdio.h>

int soma(int a, int b){
    return a + b;
}

int multiplicacao(int c, int d){
    return c * d;
}

int operacao(int z, int w, int (*funcao)(int, int)){
    return funcao(z, w);
}

void main(){
    int x = 5;
    int y = 3;

    int resp = operacao(x, y, soma);    
    printf("Soma=%d\n", resp);
    resp = operacao(x, y, multiplicacao);
    printf("Multiplicacao=%d\n", resp);
}