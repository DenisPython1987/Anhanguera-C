#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 3

struct tipo_pessoa
{
    int idade;
    float peso;
    char nome[50];
};

typedef struct tipo_pessoa tipo_pessoa;

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    tipo_pessoa lista[TAM];
    int i, c;

    for ( i = 0; i < TAM; i++)
    {
        printf("Insira os dados (%d):\n", i + 1);
        puts("Nome: ");
        scanf(" %50[^\n]", &lista[i].nome);
        while((c = getchar()) != '\n' && c != EOF);

        puts("Idade: ");
        scanf("%d", &lista[i].idade);
        while((c = getchar()) != '\n' && c != EOF);

        puts("Peso: ");
        scanf("%f", &lista[i].peso);
        while((c = getchar()) != '\n' && c != EOF);

    }
    system("clear");

    puts("Seus dados: \n");
    for ( i = 0; i < TAM; i++)
    {
        printf("---------- Pessoa %d ----------- \n", i + 1);
        printf("\tNome: %s\n", lista[i].nome);
        printf("\tIdade: %d\n", lista[i].idade);
        printf("\tPeso: %.2f\n", lista[i].peso);
    }
    printf("----------------------------------------\n");
}