#include <stdio.h>
#include <stdlib.h>

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
        printf("0 - Sair\n");
        printf("=======================\n");
        printf("Escolha uma opcao: ");
        
        scanf("%d", &opcao);

        limparTela();

        switch (opcao) {
            case 1:
                printf(">> Voce escolheu a Opcao 1.\n\n");
                break;
            case 2:
                printf(">> Voce escolheu a Opcao 2.\n\n");
                break;
            case 3:
                printf(">> Voce escolheu a Opcao 3.\n\n");
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
