#include <stdio.h>

int main(){
    int idade = 0;
    float peso = 0;

    printf("Digite sua idade e seu peso: \n");
    scanf("%d", &idade);
    scanf("%f", &peso);

    printf("A idade informada foi: %d.\n", idade);
    printf("O peso informado foi: %.2f.\n", peso);
}