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

void inc_dir2(ponto *X, char c[20]){

    if (strcmp(c, "sudeste") == 0)
    {
        X->x = X->x + 1;
        X->y = X->y - 1;
    }
    else if (strcmp(c, "sudoeste") == 0)
    {
        X->x = X->x - 1;
        X->y = X->y - 1;
    }
    else if (strcmp(c, "nordeste") == 0)
    {
        X->x = X->x + 1;
        X->y = X->y + 1;
    }
    else if (strcmp(c, "noroeste") == 0)
    {
        X->x = X->x - 1;
        X->y = X->y + 1;
    }

}


int main(){
    
ponto X = {1,3};
ponto Y = {2,4};

    printf("(%.0f,%.0f) sudeste => ", X.x,X.y);
    inc_dir2(&X,"sudeste");
    printf("(%.0f,%.0f)\n", X.x,X.y);

    printf("(%.0f,%.0f) sudoeste => ", Y.x,Y.y);
    inc_dir2(&Y,"sudoeste");
    printf("(%.0f,%.0f)\n", Y.x,Y.y);


    return 0;
}

/*
=> Crie um procedimento para andar na diagonal (sudeste, 
sudoeste, nordeste, noroeste). Use obrigatoriamente as funções do 
exercício anterior.

Exemplo de chamada:
ind_diag(p,"sudeste"); 
ind_diag(p,"sudoeste");

-------------------------------------------------------------------------------
Exemplo de Saída:

(1,3) sudeste => (2,2)
(2,4) sudoeste => (1,3)
-------------------------------------------------------------------------------
*/