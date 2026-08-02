#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

struct Node{
    int opt;
    int resultado;
    float resultado_f;
    struct Node *prox;
};

typedef struct Node node;

int tam = 0;
bool var_control = true;
int var;

void operacao_push(node **head, int opt, int resultado, float resultado_f){
    node* novo = (node *)malloc(sizeof(node));
    novo -> opt = opt;
    novo -> resultado = resultado;
    novo -> resultado_f = resultado_f;
    novo -> prox = NULL;

    if (*head == NULL){
        *head = novo;
        return;
    }

    node *atual = *head;
    while (atual->prox != NULL){
        atual = atual->prox;
    }
    atual-> prox = novo;

    tam++;
}

int soma(int num1, int num2){
    return num1 + num2;
}

int subt(int num1, int num2){
    return num1 - num2;
}

float divisao(int num1, int num2){
    return (float)num1 / num2;
}

int mult(int num1, int num2){
    return num1 * num2;
}

int menu_calculadora(void){
    setlocale(LC_ALL, "Portuguese");
    int x;

    printf("*** CALCULADORA ***\n");
    printf("Escolha uma opção\n");
    printf("1 - soma\n");
    printf("2 - subtração\n");
    printf("3 - divisão\n");
    printf("4 - multiplicação\n");
    printf("5 - desfazer\n");
    printf("6 - imprimir pilha\n");
    printf("7 - verificar pilha vazia\n");
    printf("8 - sair\n");
    scanf("%d", &x);

    return x;
}

int pega_x(void){
    int x;

    printf("Digite um número inteiro:\n");
    scanf("%d", &x);

    return x;
}

int pega_y(void){
    int y;

    printf("Digite outro número inteiro:\n");
    scanf("%d", &y);
    return y;
}

void mostra_resul(int x){
    printf("Resultado: %d\n", x);
}

void mostra_resul_f(float y){
    printf("Resultado: %.2f\n", y);
}

int vazia(node *pilha){
    return(pilha == NULL);
}

void operacao_pop(node **pilha){
    if(*pilha == NULL){
        printf("Pilha já está vazia!\n\n");
        return;
    }

    node *remover = *pilha;
    *pilha = remover->prox;
    free(remover);
    tam--;

    printf("Última operação desfeita!\n\n");
}

void imprimir_pilha(node* inicio){
    node* atual = inicio;
    int i = 1;

    while (atual != NULL){
        printf("Elemento %d\n:", i);
        printf("Operação: %d\n", atual->opt);
        printf("Resultado int: %d\n", atual->resultado);
        printf("Resultado float: %.2f\n\n", atual->resultado_f);
        atual = atual->prox;
        i++;
    }
    
}


int main(){

    node *pilha = NULL;

    int oper, resultado, x, y;
    float resultado_f = 0.0;

    while (var_control == true){
        oper = menu_calculadora();

        if(oper == 8){
            var_control = false;
            break;
        }

        if(oper == 6){
            imprimir_pilha(pilha);
            continue;
        }

        if(oper == 7){
            var = vazia(pilha);
            if(var == 0){
                printf("Pilha contém elementos!\n");
                continue;
            }else{
                printf("Pilha vazia!\n");
                continue;
            }
        }

        if(oper == 5){
            operacao_pop(&pilha);
            continue;
        }
        x = pega_x();
        y = pega_y();

        switch (oper)
        {
        case 1:
            resultado = soma(x, y);
            mostra_resul(resultado);      
            break;

        case 2:
            resultado = subt(x, y);
            mostra_resul(resultado);
            break;

        case 3:
            resultado_f = divisao(x, y);
            mostra_resul_f(resultado_f);
            break;

        case 4: 
            resultado = mult(x, y);
            mostra_resul(resultado);
            break;            

        default:
            printf("Opção inválida!");
        } 

        if(oper != 3){
            resultado_f = 0.0;
        }

        operacao_push(&pilha, oper, resultado, resultado_f);
    }
    

    
    return 0;

}