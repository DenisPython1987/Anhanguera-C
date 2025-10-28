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
    setlocale(LC_ALL, "pt_BR.UTF-8");

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

char* pesquisar(struct Elemento* tabela, char* nome_usuario){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int indice = calcularHash(nome_usuario);
    int inicial = indice;

    while (strcmp(tabela[indice].nome_usuario, "") != 0){
        if(strcmp(tabela[indice].nome_usuario, nome_usuario) == 0){
            printf("Usuário: %s | senha: %s", tabela[indice].nome_usuario, tabela[indice].senha);
            return NULL;
        }
        indice = (indice + 1) % TAMANHO;
        if(indice == inicial) break;
    }
}

char pega_usuario(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char nome_usuario[50];

    printf("Digite seu nome de usuário:\n");
    fgets(nome_usuario, 50, stdin);

    return nome_usuario;
}

char pega_senha(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    char senha[50];

    printf("Digite sua senha:\n");
    fgets(senha, 50, stdin);

    return senha;
}

int menu(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int x;

    printf("Digite uma das opções abaixo:\n");
    printf("1 - Cadastrar novo usuário\n");
    printf("2 - Pesquisar usuário\n");
    printf("3 - sair\n");
    scanf("%d", &x);

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
            strcpy(usuario, pega_usuario());
            strcpy(senha, pega_senha());

            inserir(tabela, usuario, senha);
            break;

        case 2:
            strcpy(usuario, pega_usuario());

            pesquisar(tabela, usuario);
            break;

        case 3:
            y == false;
            break;
        
        default:
            break;
        }
    }
}