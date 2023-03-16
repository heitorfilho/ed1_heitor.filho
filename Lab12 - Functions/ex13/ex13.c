#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto
{
    float x;
    float y;
}ponto;

void area(ponto X, ponto Y, double *Z){

double a, b, s;

a = X.x - Y.x;
b = X.y - Y.y;

a = abs(a);
b = abs(b);

s = (a * b);
*Z = s;

}

int main(){
ponto X, Y;
double Z;

    printf("Digite o valor de x1: ");
    scanf("%f", &X.x);
    printf("Digite o valor de y1: ");
    scanf("%f", &X.y);
    printf("Digite o valor de x2: ");
    scanf("%f", &Y.x);
    printf("Digite o valor de y2: ");
    scanf("%f", &Y.y);

    area(X,Y,&Z);
    printf("A area do retangulo definido por (%.2f, %.2f) e (%.2f, %.2f) eh %.2lf\n",X.x,X.y,Y.x,Y.y, Z);

    return 0;

}

/*
Observação: Lembre-se de utilizar a struct chamada ponto, que 
armazena dois números reais que representam coordenadas cartesianas.

=> Faça uma função que calcule a área do retângulo definido por 
dois pontos. 

Cabeçalho: area = calc_area(p1,p2)


-------------------------------------------------------------------------------
Exemplo de Saída:

<< Calculo de Area >>
Digite a coordenada x do ponto 1: 1
Digite a coordenada y do ponto 1: 4
Digite a coordenada x do ponto 2: 4
Digite a coordenada y do ponto 2: 2

A area do retangulo definido por (1.00, 4.00) e (4.00, 2.00) eh 6.00
-------------------------------------------------------------------------------
*/
