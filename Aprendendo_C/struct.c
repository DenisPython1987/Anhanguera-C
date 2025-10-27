#include <stdio.h>
#include <string.h>
#include <locale.h>

#define TAM 50

struct tipo_pessoa
{
    int idade;
    float peso;
    char nome[TAM];
};

typedef struct tipo_pessoa tipo_pessoa;

int main(){
    setlocale(LC_ALL, "Portuguese");
    int c;

    //Criando e inicializando
    tipo_pessoa pesssoa = {0, 0.0, "teste"};

    printf("Início:\n");
    printf("pes.idade: %d\n", pesssoa.idade);
    printf("pes.peso: %.2f\n", pesssoa.peso);
    printf("pes.nome: %s\n", pesssoa.nome);

    //Atribuínco valores aos campos
    pesssoa.idade = 10;
    pesssoa.peso = 99.99;
    strcpy(pesssoa.nome, "Texto");

    printf("\nAlterando os campos via código:\n");
    printf("pes.idade: %d\n", pesssoa.idade);
    printf("pes.peso: %.2f\n", pesssoa.peso);
    printf("pes.nome: %s\n", pesssoa.nome);

    //solicitando inserções via teclado
    printf("\nInsíra um número inteiro:\n");
    scanf("%d", &pesssoa.idade);
    while((c = getchar()) != '\n' && c != EOF);

    printf("Insira um número real:\n");
    scanf("%f", &pesssoa.peso);
    while((c = getchar()) != '\n' && c != EOF);

    printf("Insira uma palavra:\n");
    scanf("%s", &pesssoa.nome);
    while((c = getchar()) != '\n' && c != EOF);

    printf("\nAlterando com dados do usuário:\n");
    printf("pes.idade: %d\n", pesssoa.idade);
    printf("pes.peso: %.2f\n", pesssoa.peso);
    printf("pes.nome: %s\n", pesssoa.nome);
}
