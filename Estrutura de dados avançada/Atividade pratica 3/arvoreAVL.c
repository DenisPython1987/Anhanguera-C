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

