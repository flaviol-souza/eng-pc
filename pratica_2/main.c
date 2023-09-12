#include<stdio.h>

void introducao_pointeiro()
{
    int a = 42;
    printf("\nValor da variavial a = %d", a);
    printf("\nEndereco de memoria da variavel a -> %p", &a);
    int *ponteiro = &a; //declaracao de um ponteiro *
    printf("\nEndereco de memoria do ponteiro -> %p", &ponteiro);    
    printf("\nValor final do ponteiro %d", *ponteiro); //int tmp = *ponteiro;
    printf("\nEndereco armazenado no ponteiro %p", ponteiro);
    
    printf("\nIncrementa a = %d", a++);
    printf("\nNovo valor de a = %d", a);
    printf("\nNovo valor final do ponteiro %d", *ponteiro);

}

void ponteiro_como_array (){
    char title[] = "IFSP";
    char *p = title;
    printf("\nTitle=%s",p);
    while(*p != '\0'){
        printf("\n%c",*p);
        p++;
    }
}

void troca(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void main(){
    int x = 5;
    int y = 10;
    printf("\nAntes da troca: x=%d e y=%d",x,y);
    troca(&x, &y);
    printf("\nDepois da troca: x=%d e y=%d",x,y);    
}