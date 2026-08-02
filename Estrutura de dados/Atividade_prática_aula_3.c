#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

#define TAMANHO 20

//Criando a estrutura dos elementos
struct Elemento{
    char nome_usuario[50];
    char senha[50];
};

struct Elemento* criarTabelaHash(){
    struct Elemento* tabela = (struct Elemento*) malloc(TAMANHO * sizeof(struct Elemento));
    for(int i = 0; i < TAMANHO; i++){
        strcpy(tabela[i].nome_usuario, "");
        strcpy(tabela[i].senha, "");
    }
    return tabela;
};

int calcularHash(char* chave){
    int hash = 0;
    for(int i = 0; i < strlen(chave); i++){
        hash += chave[i];
    }
    return hash % TAMANHO;
}

void inserir(struct Elemento* tabela, char* nome_usuario, char* senha){
    int indice = calcularHash(nome_usuario);
    int inicial = indice;
    while (strcmp(tabela[indice].nome_usuario, "") != 0){
        indice = (indice + 1) % TAMANHO;
        if (indice == inicial){
            printf("Tabela cheia\n");
            return;
        }
    }
    strcpy(tabela[indice].nome_usuario, nome_usuario);
    strcpy(tabela[indice].senha, senha);
}

void pesquisar(struct Elemento* tabela, char* nome_usuario){

    int indice = calcularHash(nome_usuario);
    int inicial = indice;

    while (strcmp(tabela[indice].nome_usuario, "") != 0){
        if(strcmp(tabela[indice].nome_usuario, nome_usuario) == 0){
            printf("Usuário: %s | senha: %s\n", tabela[indice].nome_usuario, tabela[indice].senha);
        }
        indice = (indice + 1) % TAMANHO;
        if(indice == inicial) break;
    }
}

char pega_usuario(char* nome_usuario){
    printf("Digite seu nome de usuário:\n");
    fgets(nome_usuario, 50, stdin);

    nome_usuario[strcspn(nome_usuario, "\n")] = '\0';
}

char pega_senha(char* senha){
    printf("Digite sua senha:\n");
    fgets(senha, 50, stdin);

    senha[strcspn(senha, "\n")] = '\0';
}

int menu(){
    int x;

    printf("Digite uma das opções abaixo:\n");
    printf("1 - Cadastrar novo usuário\n");
    printf("2 - Pesquisar usuário\n");
    printf("3 - sair\n");
    scanf("%d", &x);
    getchar();

    return x;
}

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    struct Elemento* tabela = criarTabelaHash();

    int x;
    bool y = true;
    char usuario[50];
    char senha[50];
    
    while (y == true){
        x = menu();

        switch (x){
        case 1:
            pega_usuario(usuario);
            pega_senha(senha);

            inserir(tabela, usuario, senha);
            break;

        case 2:
            pega_usuario(usuario);

            pesquisar(tabela, usuario);
            break;

        case 3:
            y = false;
            break;
        
        default:
            printf("Opção inválida!");
            break;
        }
    }
    free(tabela);
    return 0;
}