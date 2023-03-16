#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"

struct queue{
    int front;
    int rear;
    int size;
    int tam;
    struct aluno *data;
};

queue *queue_create(int qtd){

    queue *qe;
    qe->data = malloc(qtd * sizeof(struct aluno));
    qe = malloc(sizeof(queue));
    if (qe != NULL){

        if (qe == NULL){
            free(qe);
            return NULL;
        }
    }
    qe->tam = qtd;
    qe->front = 0;
    qe->size = 0;
    qe->rear = 0;
    return qe;
}

int queue_free(queue *qe)
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

int queue_push(queue *qe, struct aluno al)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        int rear = (qe->rear + 1)%qe->tam;
        int front = (front+1)%qe->tam;

        if (qe->rear == qe->tam)
        {
            while (rear != qe->front)
            {
                rear++;
            }
            qe->rear = rear - 1;
            int x = qe->rear;
            qe->data[x] = al;
            qe->rear++;
            qe->size++;  
            return 0;
        }
        else if(qe->size == qe->tam)
        {
            realoca(qe);
            int x = qe->rear;
            qe->data[x] = al;
            qe->rear++;
            qe->size++;     
            return 0;    
        }
        else if (qe->front == qe->tam)
        {
            qe->front = (front+1)%qe->tam;
            int x = qe->front;
            qe->data[x] = al;
            qe->size++;
            return 0;
        }
        else
        {
            int x = qe->rear;
            qe->data[x] = al;
            qe->rear++;
            qe->size++;
            return 0;
        }
        
    }
}

int queue_pop(queue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        qe->front++;
        qe->size--;
        return 0;
    }
}

int queue_top(queue *qe, struct aluno *al){
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        int x = qe->front;
        (*al) = qe->data[x];
    }    
}

int queue_empty(queue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        if (qe->size == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
        
        
    }
}

int queue_full(queue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else
    {
        if (qe->size == qe->tam)
        {
            return 0;
        }
        else
        {
            return 1;
        }     
    }
}

int queue_print(queue *qe)
{
    if (qe == NULL)
    {
        return -1;
    }
    else if (qe->front == 0)
    {
        return -1;
    }
    else
    {
        int i;
        for(i = qe->front; i < qe->size; i++)
        {
            printf("Matricula: %d\n",qe->data[i].matricula);
            printf("Nome: %s\n",qe->data[i].nome);
            printf("Notas: %f %f %f\n",qe->data[i].n1, qe->data[i].n2, qe->data[i].n3);
            printf("-------------------------------\n");
        }
        return 0;
    }
}

int realoca(queue *qe)
{
    qe->data = (struct aluno *) realloc( qe, qe->tam * sizeof(struct aluno));
    return 0;
}
