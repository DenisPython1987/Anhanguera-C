#include <stdio.h>


int main(){

    float notas[10];
    float parcial;
    float soma;
    float media;
    float maior;
    float menor;
    int contador = 1;
    int aprovados;
    int reprovados;

    while (contador <= 10){
        printf("Digite a nota do %dº aluno: ", contador);
        scanf("%f", &parcial);

        if (parcial < 0 | parcial > 10){
            printf("Nota inválida! Digite uma nota entre 0 e 10\n");
        } else {
            notas[contador - 1] = parcial;
            contador++;
        }
    }

    for (int i = 0; i < 10; i++){
        soma += notas[i];
    }

    media = soma / 10;

    for (int j = 0; j < 10; j++){
        if (j == 0){
            maior = notas[j];
            menor = notas[j];
        }
        if (notas[j] > maior){
            maior = notas[j];
        }
        if (notas[j] < menor){
            menor = notas[j];
        }
        
    }

    for (int v = 0; v < 10; v++){
        if (notas[v] < 6.0){
            reprovados++;
        } else {
            aprovados++;
        }
    }
    
    printf("As notas cadastradas foram: ");
    for (int m = 0; m < 10; m++){
        printf("%.2f ", notas[m]);
    }
    printf("\n");

    printf("A maior nota foi: %.2f\n", maior);
    printf("A menor nota foi: %.2f\n", menor);
    printf("A médias das notas foi: %.2f\n", media);
    printf("O total de alunos aprovados foi: %d\n", aprovados);
    printf("O total de alunos reprovados foi: %d\n", reprovados);

    return 0;
    
}