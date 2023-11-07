#include<stdio.h>

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int a_main = 3;
    int b_main = 7;
    printf("a=%d b=%d", a_main,b_main);
    troca(a_main, b_main);
    printf("a=%d b=%d", a_main,b_main);
}