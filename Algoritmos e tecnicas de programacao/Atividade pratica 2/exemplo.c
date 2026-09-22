#include <stdio.h>
#include <string.h>
#define MAX_STRING_LENGTH 50

const int CONST_NUM = 100;


int main(){

    // variáveis primárias
    int num_1, num_2;
    float num_3;
    char str[MAX_STRING_LENGTH];

    // variáveis compostas
    int vetor[3] = {1, 2, 3};
    int matriz[2][2] = {{1, 2}, {3, 4}};

    // ponteiros
    int *ptr_num_1;

    // atribuição inicial
    num_1 = 10;
    num_2 = 20;
    num_3 = 15.5;
    strcpy(str, "Exemplo");

    // atribuição de ponteiro
    ptr_num_1 = &num_1;

    // Entrada do usuário
    printf("Digite um número inteiro: ");
    scanf("%d", &num_1);

    printf("Digite outro número inteiro: ");
    scanf("%d", &num_2);

    printf("Digite um número real: ");
    scanf("%f", &num_3);

    printf("Digite uma string: ");
    scanf("%s", str);

    // Operações matemáticas
    int soma = num_1 + num_2;
    float media = (num_1 + num_2 + num_3) / 3;

    // Operações booleanas
    int resultado_bool = (num_1 > num_2) && (num_3 > CONST_NUM);

    // Exibição dos resultados
    printf("Soma de num_1 e num_2: %d\n", soma);
    printf("Média dos números: %.2f\n", media);
    printf("Resultado da operação booleana: %d\n", resultado_bool);

    // Exibição dos elementos do vetor
    printf("Elementos do vetor: %d, %d, %d\n", vetor[0], vetor[1], vetor[2]);

    // Exibição dos elementos da matriz
    printf("Elementos da matriz: %d, %d, %d, %d\n", matriz[0][0], matriz[0][1], matriz[1][0], matriz[1][1]);

    // Manipulação e exibição do ponteiro
    printf("Valor de num_1: %d\n", *ptr_num_1);
    printf("Endereço de num_1: %p\n", ptr_num_1);
    printf("Endereço de str: %p\n", (void*)&str);

    return 0;
}
