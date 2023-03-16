#include <stdio.h>
#include <stdlib.h>
#include "TStack.h"

typedef struct lista lista;

struct lista{

    char c;
};

struct TStack{
    int qtd;
    int tam;
    lista *list;
};

TStack *stack_create(int tam){

    TStack *st ;
    st = malloc(sizeof(TStack));
    st->list = malloc(tam * sizeof(lista));

    if (st == NULL)
    {
        return NULL;
    }
    else
    {
        st->qtd = 0;
        st->tam = tam;
        return st;
    }
}

int stack_free(TStack *st){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        free(st);
        return 0;
    }
}

int stack_push(TStack *st, char c){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        if (st->qtd == 0)
        {
            st->list[0].c = c;
            st->qtd++;
            return 0;
        }
        else if(st->qtd < st->tam)
        {
            int x = (st->qtd);
            st->list[x].c = c;
            st->qtd++;
            return 0;
        }   
        else if(st->qtd == st->tam)
        {
            return -2;
        }
    }
}

int stack_pop(TStack *st){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        st->qtd --;
        return 0;
    }
}

int stack_top(TStack *st, char *c){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        int x = (st->qtd) - 1;
        (*c) = st->list[x].c;
        return 0;
    }

}

int stack_empty(TStack *st){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        if (st->list == NULL)
        {
            return 0;
        }
        else
        {
            return -1;
        }
    }
}

int stack_full(TStack *st){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        if (st->qtd == st->tam)
        {
            return 0;
        }
        else
        {
            return -2;
        }      
    }
}

int stack_print(TStack *st){

    if (st == NULL)
    {
        printf("erro");
        return -1;
    }
    else
    {
        int x = (st->qtd) - 1;
        printf("Imrpimindo os caracteres: \n\n");

        while (x >= 0)
        {
            printf("%c / ", st->list[x].c);
            x--;
        }

        printf("\n\nFim da Pilha\n");
        return 0;
    }
}
