#include <stdio.h>
#include <stdarg.h>
  
int calculaMedia(int qtdElementos, ...) {
    va_list listaNumeros;
    va_start(listaNumeros, qtdElementos);
  
    int resultado = 0;
    for (int i = 0; i < qtdElementos; i++){
        resultado += va_arg(listaNumeros, int);
    }       
    printf("%d\n", qtdElementos);
    printf("%d\n", resultado);
    va_end(listaNumeros);  
    return resultado/qtdElementos;
}
  
void main() {
    int quantidade = 5;
    int resultado = calculaMedia(quantidade, 10, 15, 20, 25, 30);
    printf("%d\n", resultado);
}