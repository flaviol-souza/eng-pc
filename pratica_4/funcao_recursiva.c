#include<stdio.h>
double fatorial(double n){
    if(n <= 1){
        return 1;
    }
    return n * fatorial(n-1);
}

void main(){
    double f = fatorial(4);
    printf("%d", f);
}