#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Comprime um texto usando RLE.
   A função retorna uma string alocada dinamicamente. */
char *comprimirRLE(const char *texto) {
    int tamanho = strlen(texto);

    // Espaço suficiente para o pior caso: "1A1B1C..."
    char *comprimido = malloc(tamanho * 2 + 1);

    if (comprimido == NULL)
        return NULL;

    int j = 0;

    for (int i = 0; i < tamanho; ) {
        int contador = 1;

        // Conta quantas vezes o caractere se repete
        while (i + contador < tamanho &&
               texto[i] == texto[i + contador]) {
            contador++;
        }

        // Adiciona a quantidade à string
        j += sprintf(comprimido + j, "%d", contador);

        // Adiciona o caractere
        comprimido[j] = texto[i];
        j++;

        // Avança para o próximo grupo
        i += contador;
    }

    comprimido[j] = '\0';

    return comprimido;
}


/* Descomprime uma string no formato RLE.
   Exemplo: 4A3B2C -> AAAABBBCC */
char *descomprimirRLE(const char *comprimido) {
    int tamanho = strlen(comprimido);

    // Primeiro, calculamos o tamanho do texto original
    int tamanhoOriginal = 0;

    for (int i = 0; i < tamanho; ) {
        int quantidade = 0;

        // Lê números com mais de um dígito
        while (i < tamanho && isdigit(comprimido[i])) {
            quantidade = quantidade * 10 + (comprimido[i] - '0');
            i++;
        }

        // Pula o caractere correspondente
        if (i < tamanho) {
            tamanhoOriginal += quantidade;
            i++;
        }
    }

    // Aloca memória para o texto descomprimido
    char *texto = malloc(tamanhoOriginal + 1);

    if (texto == NULL)
        return NULL;

    int j = 0;

    // Descomprime
    for (int i = 0; i < tamanho; ) {
        int quantidade = 0;

        // Converte os dígitos em número
        while (i < tamanho && isdigit(comprimido[i])) {
            quantidade = quantidade * 10 + (comprimido[i] - '0');
            i++;
        }

        // O próximo caractere é aquele que será repetido
        if (i < tamanho) {
            char caractere = comprimido[i];

            for (int k = 0; k < quantidade; k++) {
                texto[j] = caractere;
                j++;
            }

            i++;
        }
    }

    texto[j] = '\0';

    return texto;
}


void mostrarTamanhoString(char string[]) {
    printf("String: %s Tamanho: %lu\n", 
           string, 
           strlen(string));
}

int main() {
    char texto[200];

    printf("Digite um texto: ");
    scanf("%199s", texto);
    // Comprime
    char *comprimido = comprimirRLE(texto);

    if (comprimido == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }
    printf("-----------------------------------------\n");
    printf("\nTexto original: %s\n", texto);
    printf("-----------------------------------------\n");
    printf("Texto comprimido: %s\n", comprimido);
    printf("-----------------------------------------\n");
    mostrarTamanhoString(comprimido);

    // Descomprime
    char *descomprimido = descomprimirRLE(comprimido);

    if (descomprimido == NULL) {
        printf("Erro ao alocar memoria.\n");
        free(comprimido);
        return 1;
    }
    printf("-----------------------------------------\n");
    printf("Texto descomprimido: %s\n", descomprimido);
    printf("-----------------------------------------\n");
    mostrarTamanhoString(descomprimido);
    printf("-----------------------------------------\n");

    // Libera a memória
    free(comprimido);
    free(descomprimido);

    return 0;
}