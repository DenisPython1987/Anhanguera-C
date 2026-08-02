#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

//Aqui eu defino o tamanho do mapa
#define TAMANHO 100

//Aqui eu crio a estrutura do nó
struct Cliente{
    char nome[50];
    char telefone[14];
    bool removido;
};

//Aqui eu crio a função que vai criar a tabela hash
struct Cliente* criarTabelaHash(){
    struct Cliente* cliente = malloc(TAMANHO * sizeof(struct Cliente));
    for(int i = 0; i < TAMANHO; i++){
        strcpy(cliente[i].nome, "");
        strcpy(cliente[i].telefone, "");
    }
    return cliente;
}

//Aqui eu crio a função que calcula o hash
int calcularHash(char* chave){
    int hash = 0;
    for(int i = 0; i < strlen(chave); i++){
        hash += chave[i];
    }
    return hash % TAMANHO;
}

//Aqui eu crio a função pesquisar que não funciona, por mais que eu tentasse
void pesquisar(struct Cliente* cliente, char* nome){

    int indice = calcularHash(nome);
    int inicial = indice;

    while (strcmp(cliente[indice].nome, "") != 0){
        if(!cliente[indice].removido && strcmp(cliente[indice].nome, nome) == 0){
            printf("Usuário: %s | Telefone: %s\n", cliente[indice].nome, cliente[indice].telefone);
            return;
        }
        indice = (indice + 1) % TAMANHO;
        if(indice == inicial) break;
    }
    printf("Cliente %s não encontrado\n", nome);
}

//Aqui eu crio a função inserir
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

//Aqui eu crio a função excluir
void excluir(struct Cliente* cliente,char *nome){
    int indice = calcularHash(nome);
    int inicial = indice;
    while (strcmp(cliente[indice].nome, "") != 0){
        if(strcmp(cliente[indice].nome, nome) == 0){
            cliente[indice].removido = true;
            strcpy(cliente[indice].nome, "");
            strcpy(cliente[indice].telefone, "");
            printf("Cliente %s removido\n", nome);
            return;
        }
        indice = (indice + 1) % TAMANHO;
        if(indice == inicial) break;
    }
    printf("Cliente %s não encontrado\n", nome);
}

//Aqui eu crio a função para pegar o nome do cliente
void pega_nome(char* nome){
    printf("Digite o nome do cliente:\n");
    fgets(nome, 50, stdin);

    nome[strcspn(nome, "\n")] = '\0';
}

//Aqui eu crio a função para pegar o telefone do cliente
void pega_telefone(char* telefone){
    printf("Digite o telefone do cliente:\n");
    fgets(telefone, 50, stdin);

    telefone[strcspn(telefone, "\n")] = '\0';
}

//Aqui eu crio o menu da aplicação
int menu(){
    char opcao[5];
    printf("Digite uma das opções abaixo:\n");
    printf("1 - Cadastrar novo cliente\n");
    printf("2 - Buscar cliente\n");
    printf("3 - Remover cliente\n");
    printf("4 - sair\n");
    fgets(opcao, 5, stdin);
    return atoi(opcao);
    
}

//Aqui eu crio a função principal
int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8");

    struct Cliente* cliente = criarTabelaHash();

    bool y = true;
    int x;
    char nome[50];
    char telefone[14];

    while (y == true){
        x = menu();

        switch (x)
        {
        case 1:
            pega_nome(nome);
            pega_telefone(telefone);
            inserir(cliente, nome, telefone);
            break;
        
        case 2:
            pega_nome(nome);
            pesquisar(cliente, nome);
            break;

        case 3:
            pega_nome(nome);
            excluir(cliente, nome);
            break;

        case 4:
            y = false;
            break;

        default:
            printf("Opção inválida!\n");
            break;
        }
    }
    free(cliente);
    return 0;
    

}