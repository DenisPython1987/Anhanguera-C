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

    
}
