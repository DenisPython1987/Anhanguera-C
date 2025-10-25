#include <stdio.h>

int main(){
    int vetor[5];
    int i;

    for(i = 0; i < 5; i++){
        printf("Insira um número inteiro: \n");
        scanf("%d", &vetor[i]);
    }

    printf("Números inseridos: \n");
    for (i = 0; i < 5; i++)
    {
        printf("%d ", vetor[i]);   
    }
    
}