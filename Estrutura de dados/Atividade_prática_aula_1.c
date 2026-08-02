#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criando a estrutura do códgio, aqui o Chat GPT corrigiu sugerindo o acréscimo
// de "Node;" depois do fechamento da chave
typedef struct Node {
    int id;
    char tarefa[20];
    struct Node *next;
} Node;

//Aqui eu crio a função para crias um novo nó. Aqui o Chat GPT mostrou erros na 
//declaração da função, que não tinha "void", e inconsistências nos nomes das
//variáveis.
void criarNovoNode(Node **head, int novoId, const char *novaTarefa){
    Node* novo = (Node *)malloc(sizeof(Node));
    novo -> id = novoId;
    strcpy(novo -> tarefa, novaTarefa);
    novo -> next = NULL;

    if (*head == NULL){
        *head = novo;
        return;
    }

    Node *atual = *head;
    while (atual->next != NULL){
        atual = atual->next;
    }
    atual->next = novo;
}

//Aqui eu crio a função para remover elementos com correções pontuais do chat GPT
void removerElemento(Node **head, int id){
    struct Node* temp = head;
    struct Node* prev = NULL;
    
    if(temp != NULL && temp->id == id){
        head = temp->next;
        free(temp);
        return;
    }
    
    while(temp != NULL && temp->id != id){
        prev = temp;
        temp = temp->next;
    }
    
    if(temp == NULL) return;
    
    prev->next = temp->next;
    free(temp);
}

//Aqui eu crio a função para imprimir a lista. A linha de código que contém printf
//foi parcialmente corrigida pelo chat GPT.
void imprimirLista(Node *head){
    Node *atual = head;
    
    while(atual != NULL){
        printf("ID: %d | Tarefa: %s\n", atual->id, atual->tarefa);
        atual = atual->next;
    }
}

//Aqui eu crio o método Main(), aqui eu não tinha colocado o & antes do head,
//O chat GPT sugeiro acrescentá-lo.
int main(){
    struct Node* head = NULL;
    
    criarNovoNode(&head, 1, "Tarefa 1");
    criarNovoNode(&head, 2, "Tarefa 2");
    criarNovoNode(&head, 3, "Tarefa 3");
    criarNovoNode(&head, 4, "Tarefa 4");
    
    printf("Lista antes da exclusão\n");
    imprimirLista(head);
    
    removerElemento(head, 2);
    
    printf("Lista após a exclusão\n");
    imprimirLista(head);
}