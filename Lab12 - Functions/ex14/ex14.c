#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto
{
    float x;
    float y;
}ponto;

void multiplica(ponto *X, float c){

X->x = X->x * c;
X->y = X->y * c;

}

int main(){

    ponto X;
    float c;

    printf("Digite o ponto: ");
    scanf("%f, %f", &X.x, &X.y);
    printf("Digite a constante: ");
    scanf("%f", &c);

    printf("Resultado: (%.0f,%.0f) * %.0f = ", X.x,X.y, c);
    multiplica(&X,c);
    printf("(%.0f,%.0f)\n", X.x,X.y);

    return 0;
}

/*
=> Faça um procedimento que multiplique o valor de um ponto 
por uma constante e altere o valor do ponto. Deve ser usada 
passagem por referência e retorno void.


-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o ponto: 1,2
Digite a constante: 5
Resultado: (1,2) * 5 = (5,10)
-------------------------------------------------------------------------------
*/