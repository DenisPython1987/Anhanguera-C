#include <stdio.h>
#include <time.h>

int main(){

    //Inicializando a biblioteca <time.h>
    clock_t inicio, fim;

    //Inicializando as variáveis do programa
    int n, contador;
    
    //Pedindo um número para o usuário
    printf("Digite um número: ");
    scanf("%d", &n);

    //Começando a contagem de tempo
    inicio = clock();

    //Loop for para executar o programa principal
    for(contador = 1; contador < n; contador++){

        //Testando se o número é par
        if(contador % 2 == 0){
            printf("%d\n", contador);
        }
    }

    //Finalizando a contagem de tempo
    fim = clock();

    //Calculando o tempo gasto
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    
    //Imprimindo o tempo gasto

    printf("tempo: %.3f segundos\n", tempo);

    return 0;
}