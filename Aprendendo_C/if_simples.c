#include <stdio.h>

int main(){
    float m;

    printf("Insira a nota do aluno: \n");
    scanf("%f", &m);

    if(m >= 7.0){
        printf("Aprovado(a)!\n");
    }
}