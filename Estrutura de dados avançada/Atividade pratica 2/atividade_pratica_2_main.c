#include <stdio.h>
#include <time.h>
#include "atividade_pratica_2_gerador.h"
#include "atividade_pratica_2_heap_sort.h"
#include "atividade_pratica_2_insertion_sort.h"
#include "atividade_pratica_2_merge_sort.h"
#include "atividade_pratica_2_quick_sort.h"

int main(){
    int numeros[1000];
    clock_t inicio_1, inicio_2, inicio_3, inicio_4, inicio_5;
    clock_t fim_1, fim_2, fim_3, fim_4, fim_5;

    inicio_1 = clock();
    gerar_vetor(numeros, 1000);
    fim_1 = clock();
    double tempo_1 = (double)(fim_1 - inicio_1) / CLOCKS_PER_SEC;
    printf("Tempo de execução da geração de vetor: %.6f segundos\n", tempo_1);
    
    inicio_2 = clock();
    insertionSort(numeros, 1000);
    fim_2 = clock();

    inicio_3 = clock();
    mergeSort(numeros, 0, 999);
    fim_3 = clock();

    inicio_4 = clock();
    quickSort(numeros, 0, 999);
    fim_4 = clock();

    inicio_5 = clock();
    heapSort(numeros, 1000);
    fim_5 = clock();

    return 0;
}