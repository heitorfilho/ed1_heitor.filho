#include <stdio.h>
#include "TStack.h"

    int main(){
    char a = 'a';
    TStack *st;
    char b = 'b';
    char c;

    st = stack_create(10);

    stack_push(st, a);

    stack_top(st,&c);

    stack_push(st,b);

    stack_print(st);

    stack_push(st,c);

    stack_print(st);

    stack_free(st);

    return 0;
}
