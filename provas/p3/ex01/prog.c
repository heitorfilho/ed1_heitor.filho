#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TDLinkedList.h"

int main(){

    struct aluno a,b,c,d,e;
    int x;
    strcpy(a.nome,"Joao");
    a.matricula = 1;
    a.n1 = 0;    a.n2 = 2;    a.n3 = 0;

    strcpy(b.nome,"Maria");
    b.matricula = 2;
    b.n1 = 2;    b.n2 = 0;    b.n3 = 0;

    strcpy(c.nome,"Jose");
    c.matricula = 3;
    c.n1 = 0;    c.n2 = 0;    c.n3 = 0;

    strcpy(d.nome,"Ana");
    d.matricula = 4;
    d.n1 = 0;    d.n2 = 0;    d.n3 = 2;



    TDLinkedList *dest;
    dest = list_create();
    list_push_back(dest,a);
    list_push_back(dest,b);
    list_push_back(dest,c);
    list_push_back(dest,d);   

    TDLinkedList *source;
    source = list_create();
    list_push_back(source,a);
    list_push_back(source,b);
    list_push_back(source,c);
    list_push_back(source,d); 

    list_splice(dest, source, 2);

    //list_erase_zeros(dest);

    list_print_forward(dest);
    //list_print_forward(source);

return 0;
}