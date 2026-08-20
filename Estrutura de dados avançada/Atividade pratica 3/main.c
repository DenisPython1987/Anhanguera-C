#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}


int valor, elemento, consulta, status;

int main() {
    ArvAVL *arvore = cria_ArvAVL();
    int opcao;

    do {
        printf("=======================\n");
        printf("     ÁRVORE AVL   \n");
        printf("=======================\n");
        printf("1 - Inserir elemento\n");
        printf("2 - Mostrar árvore\n");
        printf("3 - Remover elemento\n");
        printf("4 - Consultar elemento\n");
        printf("0 - Sair\n");
        printf("=======================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);

        limparTela();

        switch (opcao) {
            case 1:
                printf("Digite o elemento a ser inserido: ");
                scanf("%d", &valor);
                insere_ArvAVL(arvore, valor);
                printf(">> Elemento %d inserido.\n\n", valor);
                break;
            case 2:
                emOrdem_ArvAVL(arvore);
                break;
            case 3:
                printf("Digite o elemento a ser removido: ");
                scanf("%d", &elemento);
                remove_ArvAVL(arvore, elemento);
                printf(">> Elemento %d removido.\n\n", elemento);
                break;
            case 4:
                printf("Digite o elemeno a consultar: ");
                scanf("%d", &consulta);
                status = consulta_ArvAVL(arvore, consulta);
                if(status == 1)
                    printf(">> O elemento %d está na árvore.\n\n", consulta);
                else
                    printf(">> O elemento %d não está na árvore.\n\n", consulta);                    
                break;
            case 0:
                printf(">> Saindo do programa...\n");
                break;
            default:
                printf(">> Opcao invalida! Tente novamente.\n\n");
        }

    } while (opcao != 0);

    return 0;
}
