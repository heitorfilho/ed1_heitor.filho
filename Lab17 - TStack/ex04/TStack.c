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

TStack *stack_create(){

    TStack *st ;
    st = malloc(sizeof(TStack));
    st->list = malloc(100 * sizeof(lista));

    if (st == NULL)
    {
        return NULL;
    }
    else
    {
        st->qtd = 0;
        st->tam = 100;
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

char stack_pop(TStack *st){

    if (st == NULL)
    {
        return -1;
    }
    else
    {
        int x = st->qtd - 1;
        return st->list[x].c;
        st->qtd --;
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
        if (st->qtd <= 0)
        {
            return st->qtd;
        }
        else
        {
            return 0;
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

int bemFormada (char *s){

   TStack *st; 
   st = stack_create();
   for (int i = 0; s[i] != '\0'; ++i) {
      char c;
      switch (s[i]) {
         case ')': if(stack_empty(st)){return stack_empty(st);}
                    
                    c = stack_pop(st);

                    if(c != '('){stack_push(st,c);}
                    
                    break;

                    //stack_pop(st);

         case ']': if(stack_empty(st)){return stack_empty(st);}
                    
                    c = stack_pop(st);

                   if(c != '['){stack_push(st,c);}

                   break;
         default:  stack_push(st,s[i]);
      }
   }
   printf("%c",st->list[0].c);
   return stack_empty(st);
   
   }
   