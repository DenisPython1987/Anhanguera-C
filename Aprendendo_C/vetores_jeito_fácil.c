#include <stdio.h>

int main(){
    int vetor[5] = {10, 20, 30, 40, 50};
    int i;
    int soma = 0;
    
    for ( i = 0; i < 5; i++)
    {
        soma += vetor[i];
    }

    printf("Resultado: %d\n", soma/5);
    
}