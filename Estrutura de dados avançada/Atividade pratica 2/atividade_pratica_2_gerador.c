#include <stdlib.h>
#include "atividade_pratica_2_gerador.h"

void gerar_vetor(int vetor[], int tamanho){
    srand(12345);
    for (int i = 0; i < tamanho; i++){
        vetor[i] = rand() % 10000;
    }
}

