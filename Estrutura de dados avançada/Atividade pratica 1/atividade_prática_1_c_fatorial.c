#include <stdio.h>
#include <time.h>

int main(){
    //Inicializando a biblioteca <time.h>
    clock_t inicio, fim;

    //Inicializando as variáveis do programa principal
    int n, contador;

    /*A variável "resultado" precisa ser "long long" para
    calcular o fatorial de 20. Eu decidi calcular até esse valor*/
    long long resultado = 1;

    //Aqui eu peço um número ao usuário
    printf("Digite um número para ver seu fatorial: ");
    scanf("%d", &n);

    //Aqui eu inicio a contagem de tempo
    inicio = clock();

    //Aqui o programa calcula o fatorial
    for(contador = 1; contador <= n; contador++){
        resultado *= contador;
    }

    //Aqui eu apresento o resultado do fatorial
    printf("Resultado = %lld\n", resultado);

    //Aqui eu termino o contagem de tempo
    fim = clock();

    //Aqui eu calculo o tempo total
    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    //Aqui eu apresento o tempo calculado
    printf("tempo: %.3f segundos\n", tempo);
}