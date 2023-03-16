#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto
{
    float x;
    float y;
}ponto;

void inc_dir(ponto *X, char c){

    if (c == 'n')
    {
        X->y = X->y + 1;
    }
    else if (c == 's')
    {
        X->y = X->y - 1;
    }
    else if (c == 'l')
    {
        X->x = X->x + 1;
    } 
    else if (c == 'o')
    {
        X->x = X->x - 1;
    } 

    }


int main(){
    
ponto X = {1,3};
ponto Y = {2,4};

    printf("(%.0f,%.0f) norte => ", X.x,X.y);
    inc_dir(&X,'n');
    printf("(%.0f,%.0f)\n", X.x,X.y);

    printf("(%.0f,%.0f) leste => ", Y.x,Y.y);
    inc_dir(&Y,'l');
    printf("(%.0f,%.0f)\n", Y.x,Y.y);


    return 0;
}

/*
=> Faça um procedimento chamado inc_dir, que faz o ponto 
andar uma unidade para leste, oeste, norte, sul (passar como 
referência e retorno void)

Exemplo de chamada:
inc_dir(p,'l'); // anda uma unidade para o leste (incrementa x)
inc_dir(p,'o'); // anda uma unidade para o oeste (decrementa x)

-------------------------------------------------------------------------------
Exemplo de Saída:

(1,3) norte => (1,4)
(2,4) leste => (3,4)
-------------------------------------------------------------------------------
*/