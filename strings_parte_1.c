#include <stdio.h>

int main(){
    char str[10];
    int c;

    printf("Digite algo (scanf convencional):\n");
    scanf("%9s", str);
    while ((c = getchar()) != '\n' && c != EOF);


    printf("Resultado: %s\n\n", str);
    
    printf("Digite algo (scanf aprimorado):\n");
    scanf("%9[^\n]", str);
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Resultado: %s\n\n", str);
}