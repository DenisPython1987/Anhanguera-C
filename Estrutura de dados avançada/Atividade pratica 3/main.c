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

int main() {
    int opcao;

    do {
        printf("=======================\n");
        printf("     ÁRVORE AVL   \n");
        printf("=======================\n");
        printf("1 - Criar árvore\n");
        printf("2 - Inserir elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Consultar elemento\n");
        printf("0 - Sair\n");
        printf("=======================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);

        limparTela();

        switch (opcao) {
            case 1:
                printf(">> Árvore AVL criada.\n\n");
                break;
            case 2:
                printf(">> Elemento inserido.\n\n");
                break;
            case 3:
                printf(">> Elemento removido.\n\n");
                break;
            case 4:
                printf(">> O elemento %d já está na lista.\n\n");
            case 0:
                printf(">> Saindo do programa...\n");
                break;
            default:
                printf(">> Opcao invalida! Tente novamente.\n\n");
        }

    } while (opcao != 0);

    return 0;
}
