#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"

typedef struct dqnode DQNode;

struct TQueue {
    DQNode *begin;
    DQNode *end;
    int size;
};

struct dqnode {
    struct aluno data;
    DQNode *next;
};


TQueue *queue_create(){

    TQueue *qe;
    qe = malloc(sizeof(TQueue));
    if (qe != NULL){
        if (qe == NULL){
            free(qe);
            return NULL;
        }
    }
    qe->size= 0;
    return qe;
}

int queue_free(TQueue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }else
    {
        free(qe);
        return 0;
    }
    
}

int queue_push(TQueue *qe, struct aluno al)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        DQNode *node;
        node = malloc(sizeof(DQNode));
        node->data = al;
        node->next = NULL;

        if(qe->begin == NULL)
        {
            qe->begin = node;
            qe->size++;
        }
        else if (qe->size == 1)
        {
            DQNode *aux;
            aux = qe->begin;
            aux->next = node;
            qe->end = node;
        }
      
        else
        {
            DQNode *aux;
            aux = qe->end;
            aux->next = node;
            qe->end = node;
            node->next = NULL;
            qe->size++;
        }
        return 0;
    }

}

int queue_pop(TQueue *qe){

    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        DQNode *node;
        node = malloc(sizeof(DQNode));
        if (node == NULL){
            return -1;
        }

    node = qe->begin;
    qe->begin = node->next;
    qe->size--;
                  
    }
}

int queue_top(TQueue *qe, struct aluno *al){
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        (*al) = qe->begin->data;
    }    
}

int queue_empty(TQueue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        if (qe->begin == NULL)
        {
            return 0;
        }
        else
        {
            return 1;
        }     
    }  
}

int queue_full(TQueue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        return 0;     
    }
}

int queue_print(TQueue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else if (qe->begin == NULL)
    {
        return -1;
    }
    
    else
    {
        DQNode *aux;
        aux = qe->begin;
        printf("\nImprimindo a fila (tamanho %d)\n", qe->size);

        while (aux != NULL)
        {
            printf("\n------------------\n");
            printf("Matricula: %d\n", aux->data.matricula);
            printf("Nome: %s\n", aux->data.nome);
            printf("Notas: %f; %f; %f;\n", aux->data.n1, aux->data.n2, aux->data.n3);

            aux = aux->next;
        }
        printf("\nFim da fila \n");
    }
}