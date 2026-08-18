#include <stdio.h>
#include <stdlib.h>
#include "arvoreAVL.h"
struct NO{
    int info;
    int alt;
    struct NO *esq;
    struct NO *dir;
};

/*Essa função cria uma árvore AVL*/
ArvAVL* cria_ArvAVL(){
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if (raiz != NULL){
        *raiz = NULL;
    return raiz;
    }
    
}

/*Essa função libera um nó do espaço de memória*/
void libera_NO(struct NO* no){
    if(no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    free(no);
    no = NULL;
}

/*Essa função libera a árvore AVL inteira da memória*/
void libera_ArvAVL(ArvAVL* raiz){
    if (raiz == NULL)
        return;
        libera_NO(*raiz); //Libera cada nó
        free(raiz); //Libera a raiz
}

/*Esta função verifica se a árvore está vazia*/
int estaVAzia_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)//Retorna 1 caso não exista árvore, ou haja um erro na criação
        return 1;
    if(*raiz == NULL)//Retorna 1 caso a árvore exista e esteja vazia
        return 1;
    return 0;//Retorna 0 caso a árvore não esteja vazia
}

/*Esta função calcula o total de nós em uma árvore AVL*/
int totalNO_ArvAVL(ArvAVL *raiz){
    if(raiz == NULL)//Retorna 0 caso a árvore não exista
        return 0;
    if(*raiz == NULL)//Retorna 0 caso a árvore esteja vazia
        return 0;

    //Analisa a subárvore da esquerda
    int total_esq = totalNO_ArvAVL(&((*raiz)->esq));

    //Analisa a subárvore da direita
    int total_dir = totalNO_ArvAVL(&((*raiz)->dir));
    return(total_esq + total_dir + 1);
}

/*Esta função calcula a altura de uma árvore*/
int altura_ArvAVL(ArvAVL *raiz){
    /*Esses dois blocos if verificam se a árvore é válida e se ela está vazia*/
    if(raiz == NULL)
        return 0;
    if(*raiz == NULL)
        return 0;

    //Verifica a subárvore esquerda
    int alt_esq = altura_ArvAVL(&((*raiz)->esq));

    //Verifica a subárvore direita
    int alt_dir = altura_ArvAVL(&((*raiz)->dir));

    /*Verifica a diferença de altura entre as subárvores da direita e esquerda
    e retorna o valor apropriado acrescido de 1*/
    if(alt_esq > alt_dir)
        return (alt_esq + 1);
    else
        return (alt_dir + 1);
}

/*Esta função percorre a árvore começando pela raiz*/
void preOrdem_ArvAVL(ArvAVL *raiz){
    //Verifica se a árvore não é inválida
    if(raiz == NULL)
        return;

    //Imprime o valor no nó atual e para para o próximo
    //Primiero o da esquerda e depois o da direita
    if(*raiz != NULL){
        printf("%d\n", (*raiz)->info);
        preOrdem_ArvAVL(&((*raiz)->esq));
        preOrdem_ArvAVL(&((*raiz)->dir));
    }
}

/*Esta função percorre a árvore começando pelo nó da esquerda*/
void emOrdem_ArvAVL(ArvAVL *raiz){
    //Verifica se a árvore é válida
    if(raiz == NULL)
        return;

    /*Caso a árvore seja válida, começa pelo nó da esquerda, imprime o valor 
    associado e depois, passa para o nó da direita.*/
    if(*raiz != NULL){
        emOrdem_ArvAVL(&((*raiz)->esq));
        printf("%d\n", (*raiz)->info);
        emOrdem_ArvAVL(&((*raiz)->dir));
    }
}

/*Esta função percorre a árvore começando pelo nó da direita, imprime o valor
associado e depois, passa para o nó da esquerda.*/
void posOrdem_ArvAVL(ArvAVL *raiz){
    //Verifica se a árvore é válida
    if(raiz == NULL)
        return;
    
    /*Se a árvore for válida, começa pelo nó da esquerda, passa para o da direita
    e depois imprime o valor associado.*/
    if(*raiz != NULL){
        posOrdem_ArvAVL(&((*raiz)->esq));
        posOrdem_ArvAVL(&((*raiz)->dir));
        printf("%d\n", (*raiz)->info);
    }
}

//Retorna a altura de uma árvore
int alt_NO(struct NO* no){
    if(no == NULL)
        return -1;
    else
        return no->alt;
}

//Retorna o fator de balanceamento de um nó
int fatorBalanceamento_NO(struct NO* no){
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

//Retorna o maior dentre dois valores
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}

/*Função de rotação simples à direita. Recebe como parâmetro o nó da árvore
que está desbalanceado.*/
void RotacaoLL(ArvAVL *A){

    //Associa o nó B ao filho esquerdo de A
    struct NO *B;
    B = (*A)->esq;

    //coloca o novo filho à direita de B como novo filho à esquerda de A
    (*A)->esq = B->dir;

    //A se torna filho da direita de B
    B->dir = *A;

    //Recalculando a altura da árvore após as modificações
    (*A)->alt = maior(alt_NO((*A)->esq), alt_NO((*A)->dir));
    B->alt = maior(alt_NO(B->esq), (*A)->alt) + 1;

    //A raiz A para a apontar para B
    *A = B;
}

/*Função de rotação simples à esquerda, recebe como parâmetro o nó desbalanceado
da árvore como se fosse a raiz*/
void RotacaoRR(ArvAVL *A){

    //Aqui é associado o nó B ao filho da direita do nó A
    struct NO *B;
    B = (*A)->dir;

    /*Aqui, o filho da esqueda de B é colocado à direita de A*/
    (*A)->dir = B->esq;

    /*Aqui, o nó A se torna o filho à esquerda de B.*/
    B->esq = (*A);

    //Aqui é recalculada a altura da árvore
    (*A)->alt = maior(alt_NO((*A)->esq), alt_NO((*A)->dir)) + 1;
    B->alt = maior(alt_NO(B->dir), (*A)->alt) + 1;

    //Agora a raiz é B
    (*A) = B;
}

/*Função de rotação dupla à direita*/
void RotacaoLR(ArvAVL *A){

    //Usando uma rotação simples à esquerda no filho à esquerda de A
    RotacaoRR(&(*A)->esq);

    //Usando uma rotação simples à direita no nó A
    RotacaoLL(A);
}

//Função de rotação dupla à esquerda
void RotacaoRL(ArvAVL *raiz){

    //Usando uma rotação simples à direita no filho da direita da raiz
    RotacaoLL(&(*raiz)->dir);

    //Usando uma rotação simples à esquerda na raiz
    RotacaoRR(raiz);
}

