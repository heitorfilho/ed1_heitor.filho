#include <stdio.h>
#include <stdlib.h>

typedef struct ponto
{
    float x;
    float y;
}ponto;

void imprime_ponto(ponto p){

printf("(%.0f,%.0f)\n", p.x,p.y);

}

void soma(ponto x, ponto y, ponto *Z){

Z->x = x.x + y.x;
Z->y = x.y + y.y;

}

int main(){

ponto X, Y, Z;

    printf("Digite o valor de x1: ");
    scanf("%f", &X.x);
    printf("Digite o valor de y1: ");
    scanf("%f", &X.y);
    printf("Digite o valor de x2: ");
    scanf("%f", &Y.x);
    printf("Digite o valor de y2: ");
    scanf("%f", &Y.y);

    soma(X,Y,&Z);

    printf("A soma de (%.0f,%.0f) com (%.0f,%.0f) eh (%.0f,%.0f)\n", X.x,X.y,Y.x,Y.y,Z.x,Z.y);

    return 0;
}

/*
Observação: Lembre-se de utilizar a struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Faca uma função que some dois pontos e retorne o resultado 
da soma. Mostre os 3 pontos usando a função imprime_ponto.

Exemplo:
ponto p1, p2, p3;
p3= soma_ponto(p1,p2);

-------------------------------------------------------------------------------
Exemplo de Saída:

Digite o valor de x1: 1
Digite o valor de y1: 2
Digite o valor de x2: 3
Digite o valor de y2: 4
A soma de (1,2) com (3,4) eh (4,6)
-------------------------------------------------------------------------------
*/