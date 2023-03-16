#include <stdio.h>
#include "TStack.h"

int main(){
    struct aluno a = {1,"JOAO",10,10,10};
    TStack *st;
    struct aluno b = {2,"MARIA",20,20,20}, c;

    st = stack_create();

    stack_push(st, a);

    stack_push(st,b);

    stack_top(st,&c);

    stack_print(st);

    stack_push(st,c);

    stack_print(st);

    stack_free(st);

    return 0;
}