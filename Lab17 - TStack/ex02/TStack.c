#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"
#include "TDLinkedList.h"

typedef struct list_node list_node;

struct list_node
{
    struct aluno data;
    list_node *prev;
    list_node *next;
};

struct TDLinkedList
{
    list_node *begin;
    list_node *end;
    int size;
};

struct TStack{

    TDLinkedList *list;
};

TStack *stack_create(){
    TStack *st;
    st = malloc(sizeof(TStack));
    if (st != NULL){
        st->list = list_create();
        if (st == NULL){
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
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        list_push_front(st->list, al);
        return SUCCESS;
    }

}

int stack_pop(TStack *st){

    if (st == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    else
    {
        if (st->list->begin == NULL)
        {
            return ELEM_NOT_FOUND;
        }
        else
        {
            list_pop_front(st->list);
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
        list_front(st->list,al);
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
        if (st->list->begin == NULL)
        {
            return SUCCESS;
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
        if (st == NULL)
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
    else if (st->list == NULL)
    {
        return INVALID_NULL_POINTER;
    }
    
    else
    {
        list_print_forward(st->list);
    }
}
