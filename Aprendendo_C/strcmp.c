#include <stdio.h>
#include <string.h>
#include <locale.h>

#define N 50

int main(){
    setlocale(LC_ALL, "Portuguese");

    char hardtext[N] = {"exit"};
    char senha_usr[N];
    int ok;

    printf("Digite um texto: \n");
    gets(senha_usr);
    ok = strcmp(hardtext, senha_usr);

    if(ok == 0){
        printf("textos iguais.\n");
    }else{
        printf("Textos diferentes.\n");
    }
}