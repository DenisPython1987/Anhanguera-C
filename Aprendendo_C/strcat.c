#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 50

int main(){
    setlocale(LC_ALL, "Portuguese");

    char string_1[N] = {"Lógica de "};
    char string_2[N] = {"Programação."};

    printf("Antes do strcat:\n");
    printf("string_1: %s\n", string_1);
    printf("string_2: %s\n", string_2);

    strcat(string_1, string_2);

    printf("Depois do strcat:\n");
    puts(string_1);
}