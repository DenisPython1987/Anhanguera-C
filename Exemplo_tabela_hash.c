#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 10

//Estrutura de cada elemento na tabela hash
struct Elemento
{
    char chave[50];
    char valor[50];
};

//Função para criar uma tabela de hash vazia
struct Elemento* criartabelahash(){
    struct Elemento* tabela = (struct Elemento*) malloc(TAMANHO * sizeof(struct Elemento));
    for(int i = 0; i < TAMANHO; i++){
        strcpy(tabela[i].chave, "");
        strcpy(tabela[i].valor, "");
    }
    return tabela;
}
int calcularHash(char* chave){
    int hash = 0;
    for(int i = 0; i < strlen(chave); i++){
        hash += chave[i];
    }
    return hash % TAMANHO;  
}

void inserir(struct Elemento* tabela, char* chave, char* valor){
    int indice = calcularHash(chave);
    while(strcmp(tabela[indice].chave, "") != 0){
        indice = (indice + 1) % TAMANHO;
    }
    strcpy(tabela[indice].chave, chave);
    strcpy(tabela[indice].valor, valor);
}

//Função para buscar elemento na tabela hash
char* pesquisar(struct Elemento* tabela, char* chave){
    int indice = calcularHash(chave);
    while (strcmp(tabela[indice].chave, "") != 0){
        if(strcmp(tabela[indice].chave, chave) == 0){
            return tabela[indice].valor;
        }
    indice = (indice + 1) % TAMANHO;
    }
    return NULL;
    
}
int main(){
    struct Elemento* tabela = criartabelahash();

    inserir(tabela, "chave1", "Professor");
    inserir(tabela, "chave2", "Advogado");
    inserir(tabela, "chave3", "Médico");

    printf("%s\n", pesquisar(tabela, "chave1"));
    printf("%s\n", pesquisar(tabela, "chave2"));
    printf("%s\n", pesquisar(tabela, "chave3"));

    free(tabela);
}