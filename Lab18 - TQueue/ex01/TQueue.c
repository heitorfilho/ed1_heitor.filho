#include <stdio.h>
#include <stdlib.h>
#include "TQueue.h"
#include "TLinkedList.h"

struct list_node
{
    struct aluno data;
    list_node *next;
};

struct TLinkedList
{
    list_node *head;
};

struct TQueue{
    TLinkedList *list;
    int qtd;
};

TQueue *queue_create(){

    TQueue *qe;
    qe = malloc(sizeof(TQueue));
    if (qe != NULL){
        qe->list = list_create();
        if (qe == NULL){
            free(qe);
            return NULL;
        }
    }
    qe->qtd = 0;
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
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_push_back(qe->list, al);
        qe->qtd++;
        return SUCCESS;
    }

}

int queue_pop(TQueue *qe){

    if (qe == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (qe->list == NULL)
        {
            return ELEM_NOT_FOUND;
        }
        else
        {
            list_pop_front(qe->list);
            qe->qtd--;
            return SUCCESS;
        }
    }
}

int queue_top(TQueue *qe, struct aluno *al){
    if (qe == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_front(qe->list,al);
    }    
}

int queue_empty(TQueue *qe)
{
    if (qe == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (qe->list->head == NULL)
        {
            return SUCCESS;
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
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (qe == NULL)
        {
            return 0;
        }
        else
        {
            return -1;
        }       
    }
}

int queue_print(TQueue *qe)
{
    if (qe == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else if (qe->list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    
    else
    {
        list_print(qe->list);
    }
}