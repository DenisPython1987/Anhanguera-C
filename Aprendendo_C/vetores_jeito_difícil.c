#include <stdio.h>

int main(){
    int vet[5];

    float media;

    vet[0] = 50;
    vet[1] = 40;
    vet[2] = 30;
    vet[3] = 20;
    vet[4] = 10;

    media = (vet[0] + vet[1] + vet[2] + vet[3] + vet[4]) / 5;

    printf("Resultado: %f\n", media);
}