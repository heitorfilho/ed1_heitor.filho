#include <stdio.h>
#include "TStack.h"

int main(){
    struct aluno a = {1,"JOAO",10,10,10};
    TStack *st;
    struct aluno b;

    st = stack_create();

    stack_push(st, a);

    stack_top(st,&b);

    stack_push(st,b);

    stack_print(st);

    stack_pop(st);

    stack_print(st);

    stack_free(st);

    return 0;
}
