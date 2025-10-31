#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAMANHO 100

struct Cliente{
    char nome[50];
    char telefone[14];
}Cliente;

typedef struct Cliente cliente;

struct Cliente* criarTabelaHash(){
    struct Cliente* cliente = (struct Cliente*) malloc(TAMANHO * sizeof(cliente));
    for(int i = 0; i < TAMANHO; i++){
        strcpy(cliente[i].nome, "");
        strcpy(cliente[i].telefone, "");
    }
    return cliente;
}

int vazia(cliente *hash){
    return(hash == NULL);
}

int calcularHash(char* chave){
    int hash = 0;
    for(int i = 0; i < strlen(chave); i++){
        hash += chave[i];
    }
    return hash % TAMANHO;
}

void pesquisar(struct Cliente* cliente, char* nome){

    int indice = calcularHash(nome);
    int inicial = indice;

    while (strcmp(cliente[indice].nome, "") != 0){
        if(strcmp(cliente[indice].nome, nome) == 0){
            printf("Usuário: %s | senha: %s\n", cliente[indice].nome, cliente[indice].telefone);
        }
        indice = (indice + 1) % TAMANHO;
        if(indice == inicial) break;
    }
}

void inserir(struct Cliente* cliente, char* nome, char* telefone){
    int indice = calcularHash(nome);
    int inicial = indice;
    while (strcmp(cliente[indice].nome, "") != 0){
        indice = (indice + 1) % TAMANHO;
        if (indice == inicial){
            printf("Tabela cheia\n");
            return;
        }
    }
    strcpy(cliente[indice].nome, nome);
    strcpy(cliente[indice].telefone, telefone);
}

int menu(){
    int x;
    printf("Digite uma das opções abaixo:\n");
    printf("1 - Cadastrar novo cliente\n");
    printf("2 - Buscar cliente\n");
    printf("3 - Remover cliente\n");
    printf("4 - sair\n");
    scanf("%d", &x);

    return x;
}