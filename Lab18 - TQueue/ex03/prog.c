#include <stdio.h>
#include "TQueue.h"

int main(){
    struct aluno a = {1,"JOAO",10,10,10};
    queue *qe;
    struct aluno b = {2,"MARIA",20,20,20}, c;

    qe = queue_create(10);

    queue_push(qe, a);

    queue_print(qe);

    queue_push(qe,b);

    queue_top(qe,&c);

    queue_print(qe);

    queue_push(qe,c);

    queue_pop(qe);

    queue_print(qe);

    queue_free(qe);

    return 0;
}