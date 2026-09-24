#include <stdio.h>

const float TAXA_JUROS = 0.05;

int main(){
    float valor_inicial;
    float valor_final;
    int anos;

    int *ponteiro_vetor;

    int vetor[3] = {1, 2, 3};

    int matriz[2][2] = {{1, 2}, {3, 4}};

    ponteiro_vetor = &vetor[0];
    printf("------------------------------------------------------------\n");
    printf("Digite o valor inicial do investimento: ");
    scanf("%f", &valor_inicial);

    printf("------------------------------------------------------------\n");
    printf("Digite o tempo em anos do investimento: ");
    scanf("%d", &anos);

    valor_final = valor_inicial * (1 + (TAXA_JUROS * anos));

    printf("Valor final do investimento: %.2f\n", valor_final);

    for (int i = 0; i < 3; i++)
    {
        printf("------------------------------------------------------------\n");
        printf("Valor do vetor: %d\n", vetor[i]);
        printf("Endereço de memória: %p\n", (void*)&vetor[0]);
    }
    
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            printf("------------------------------------------------------------\n");
            printf("Valor na posição [%d][%d] = %d\n", i, j, matriz[i][j]);
            printf("Endereço de memória da posição [%d][%d] = %p\n", i, j, (void*)&matriz[i][j]);
        }
        
    }
    printf("------------------------------------------------------------\n");


}
