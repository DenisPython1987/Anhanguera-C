#include <stdio.h>

void imprime_1(int vetor[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}

void imprime_2(int vetor[5]){
    int i;
    for(i = 0; i < 5; i++){
        printf("%d ", vetor[i]);
    }
}

void imprime_3(int *vetor, int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
}

int main(){
    int vetor[5] = {1, 2, 3, 4, 5};

    puts("Primeiro imprime:");
    imprime_1(vetor, 5);

    puts("\nSegundo imprime:");
    imprime_2(vetor);

    puts("\nTerceiro imprime:");
    imprime_3(vetor, 5);
}