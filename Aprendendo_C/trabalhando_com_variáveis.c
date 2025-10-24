#include <stdio.h>

#define texto "Entrada e saída de dados"

int main(){
    printf("%s\n", texto);

    int idade = 0;
    float altura = 0;
    char nome[50] = "";

    printf("Digite sua idade: \n");
    scanf("%d", &idade);

    printf("Digite sua altura: \n");
    scanf("%f", &altura);

    printf("Digite seu nome: \n");
    scanf("%s", &nome);

    printf("Dados informados: \n");
    printf("idade: %d.\n", idade);
    printf("Altura: %.2f.\n", altura);
    printf("Nome: %s,\n", &nome);
}