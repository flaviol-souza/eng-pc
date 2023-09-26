/*Neste exercício, você irá criar um programa em C para trabalhar
    com um vetor de números inteiros. O objetivo é praticar 
    o uso de vetores para armazenar e manipular dados.
    Identifique o valor Máx e Mín no Vetor (10 unidades)*/
#include <stdio.h>
#define TAMANHO_MAX_VETOR 10
void main(){
    int i=0, vec[] = {1,2,3,4,5,6,7,8,9,0};
    //int vec[TAMANHO_MAX_VETOR];
    int max = vec[0], min = vec[0];
    for(i=1; i<TAMANHO_MAX_VETOR; i++){
        printf("%d ", vec[i]);
        if(vec[i] > max){
            max = vec[i];
        }
        if(vec[i] < min){
            min = vec[i];
        }
    }
    printf("\nO maior valor = %d", max);
    printf("\nO menor valor = %d", min);
}