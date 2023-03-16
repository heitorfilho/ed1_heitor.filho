#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"
#include "TSeqList.h"



// é possível criar a lista
struct TStack{
    Lista *list;
};


TStack *stack_create(){
    TStack *st;
    st = malloc(sizeof(TStack));
    if (st != NULL){
        st->list = cria_Lista();
        if (st->list == NULL){
            free(st);
            return NULL;
        }
    }
    return st;
}

int stack_free(TStack *st)
{
    if (st == NULL)
    {
        return -1;
    }else
    {
        free(st);
        return 0;
    }
    
    
}

int stack_push(TStack *st, struct aluno al)
{
    if (st == NULL)
        return INVALID_NULL_POINTER;
    
    
    insere_lista_inicio(st->list, al);
    return 0;

}

int stack_pop(TStack *st)
{
    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (st->list->qtd == 0)
        {
            return ELEM_NOT_FOUND;
        }
        else
        {
            remove_lista_inicio(st);
            return SUCCESS;
        } 
        
    }
}

int stack_top(TStack *st, struct aluno *al)
{
    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        (*al) = st->list->dados[0];
        return SUCCESS;
    }

}

int stack_empty(TStack *st)
{
    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (st->list->qtd == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }   
        
    }  
    
}

int stack_full(TStack *st)
{
    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (st->list->qtd == MAX)
        {
            return 0;
        }
        else
        {
            return -1;
        }       
    }
}

int stack_print(TStack *st)
{
    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        printf("A pilha eh:\n");

        for (int i = 0; i < st->list->qtd; i++)
        {
            printf("Matricula: %d\n",st->list->dados[i].matricula);
            printf("Nome: %s\n",st->list->dados[i].nome);
            printf("Notas: %f %f %f\n",st->list->dados[i].n1, st->list->dados[i].n2, st->list->dados[i].n3);
            printf("-------------------------------\n");
        }
        
    }

}

