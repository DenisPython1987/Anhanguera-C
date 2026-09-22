#include <stdio.h>

const float TAXA_JUROS = 0.05;

int main(){
    float valor_inicial;
    float valor_final;
    int anos;

    int vetor[3] = {}

    printf("Digite o valor inicial do investimento: ");
    scanf("%f", &valor_inicial);

    printf("Digite o tempo em anos do investimento: ");
    scanf("%d", &anos);

    valor_final = valor_inicial * (1 + (TAXA_JUROS * anos));

    printf("Valor final do investimento: %f", valor_final);

}



